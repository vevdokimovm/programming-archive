package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"sort"
)

type Box struct {
	Name        string   `json:"name"`
	TopLeft     [2]int   `json:"-"` // Не включаем в JSON
	BottomRight [2]int   `json:"-"` // Не включаем в JSON
	Area        int      `json:"area,omitempty"`
	Children    []*Box   `json:"children,omitempty"`
}

// Проверка, вложена ли коробка A в коробку B
func isInside(a, b Box) bool {
	return a.TopLeft[0] > b.TopLeft[0] && a.TopLeft[1] > b.TopLeft[1] &&
		a.BottomRight[0] < b.BottomRight[0] && a.BottomRight[1] < b.BottomRight[1]
}

// Построение дерева вложенности
func buildHierarchy(boxes []Box) []*Box {
	sort.Slice(boxes, func(i, j int) bool {
		return boxes[i].Area > boxes[j].Area // Сортировка по площади
	})

	var roots []*Box
	for i := range boxes {
		isChild := false
		for j := range boxes {
			if i != j && isInside(boxes[i], boxes[j]) {
				boxes[j].Children = append(boxes[j].Children, &boxes[i])
				isChild = true
				break
			}
		}
		if !isChild {
			roots = append(roots, &boxes[i])
		}
	}

	return roots
}

func solve() {
	in := bufio.NewReader(os.Stdin)
	var t int
	fmt.Fscan(in, &t)

	for test := 0; test < t; test++ {
		var n, m int
		fmt.Fscan(in, &n, &m)

		matrix := make([]string, n)
		scanner := bufio.NewScanner(in)
		for i := 0; i < n; i++ {
			if !scanner.Scan() {
				fmt.Fprintln(os.Stderr, "Error: unable to read matrix row")
				return
			}
			matrix[i] = scanner.Text()
			if len(matrix[i]) != m {
				fmt.Fprintf(os.Stderr, "Error: row %d length mismatch, expected %d, got %d\n", i, m, len(matrix[i]))
				return
			}
		}

		var boxes []Box

		// Парсинг коробок
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				// Проверяем, не выходим ли за границы строки
				if j >= len(matrix[i]) {
					continue
				}
				if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z') || (matrix[i][j] >= 'a' && matrix[i][j] <= 'z') {
					name := string(matrix[i][j])
					bottom, right := i, j
					// Поиск нижней и правой границы
					for bottom < n && len(matrix[bottom]) > j && matrix[bottom][j] != '+' {
						bottom++
					}
					for right < m && matrix[i][right] != '+' {
						right++
					}
					// Добавляем коробку
					area := (bottom - i) * (right - j)
					boxes = append(boxes, Box{
						Name:        name,
						TopLeft:     [2]int{i, j},
						BottomRight: [2]int{bottom, right},
						Area:        area,
					})
				}
			}
		}

		// Построение дерева вложенности
		roots := buildHierarchy(boxes)

		// Генерация JSON
		output, err := json.MarshalIndent(roots, "", "  ")
		if err != nil {
			fmt.Fprintln(os.Stderr, "Error: unable to generate JSON")
			return
		}
		fmt.Println(string(output))
	}
}

func main() {
	solve()
}
