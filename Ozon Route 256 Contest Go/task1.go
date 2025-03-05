/*
 Рекомендуется использовать быстрый (буферизованный) ввод и вывод
var in *bufio.Reader
var out *bufio.Writer
in = bufio.NewReader(os.Stdin)
out = bufio.NewWriter(os.Stdout)
defer out.Flush()

var a, b int
fmt.Fscan(in, &a, &b)
fmt.Fprint(out, a + b)
*/

package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader
var out *bufio.Writer

type Flashlight struct {
	x, y int
	dir  string
}

func solve() {
	var t int
	fmt.Fscan(in, &t)

	for test := 0; test < t; test++ {
		var n, m int
		fmt.Fscan(in, &n, &m)

		// Множество для отслеживания освещённых клеток
		illuminated := make(map[[2]int]bool)
		result := []Flashlight{}

		// Функция для добавления освещённых клеток
		addIllumination := func(x, y int, dir string) {
			switch dir {
			case "D":
				for i := x; i <= n; i++ {
					illuminated[[2]int{i, y}] = true
					if y-1 >= 1 {
						illuminated[[2]int{i, y - 1}] = true
					}
					if y+1 <= m {
						illuminated[[2]int{i, y + 1}] = true
					}
				}
			case "U":
				for i := x; i >= 1; i-- {
					illuminated[[2]int{i, y}] = true
					if y-1 >= 1 {
						illuminated[[2]int{i, y - 1}] = true
					}
					if y+1 <= m {
						illuminated[[2]int{i, y + 1}] = true
					}
				}
			}
		}

		// Устанавливаем фонарики
		isLower := true // Начинаем с нижней строки
		for len(illuminated) < n*m {
			var x, y int

			if isLower {
				x = n
			} else {
				x = 1
			}

			// Ищем первый неосвещённый столбец
			found := false
			for col := 1; col <= m; col++ {
				if !illuminated[[2]int{x, col}] {
					y = col
					found = true
					break
				}
			}

			// Если все клетки освещены, выходим из цикла
			if !found {
				break
			}

			// Добавляем фонарик
			dir := "D"
			if !isLower {
				dir = "U"
			}
			result = append(result, Flashlight{x, y, dir})
			addIllumination(x, y, dir)
			isLower = !isLower
		}

		// Выводим результат
		fmt.Fprintln(out, len(result))
		for _, flash := range result {
			fmt.Fprintln(out, flash.x, flash.y, flash.dir)
		}
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solve()
}
