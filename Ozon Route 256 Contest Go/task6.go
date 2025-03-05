package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func solve() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for test := 0; test < t; test++ {
		var n, m int
		fmt.Fscan(in, &n, &m)

		throughput := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &throughput[i])
		}

		weight := make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscan(in, &weight[j])
		}

		// Сортируем серверы по пропускной способности
		sort.Ints(throughput)

		// Распределение изображений
		servers := make([]int, n)       // Время загрузки для каждого сервера
		assignment := make([]int, m)   // Сервер для каждого изображения

		for j := 0; j < m; j++ {
			bestServer := 0
			minTime := (weight[j] + throughput[0] - 1) / throughput[0] // Округление вверх

			for i := 1; i < n; i++ {
				currentTime := (weight[j] + throughput[i] - 1) / throughput[i]
				if servers[i]+currentTime < servers[bestServer]+minTime {
					bestServer = i
					minTime = currentTime
				}
			}

			servers[bestServer] += minTime
			assignment[j] = bestServer + 1 // Серверы нумеруются с 1
		}

		// Минимальная разница
		minTime, maxTime := servers[0], servers[0]
		for i := 1; i < n; i++ {
			if servers[i] < minTime {
				minTime = servers[i]
			}
			if servers[i] > maxTime {
				maxTime = servers[i]
			}
		}

		// Вывод результата
		fmt.Fprintln(out, maxTime-minTime)
		for j := 0; j < m; j++ {
			fmt.Fprint(out, assignment[j], " ")
		}
		fmt.Fprintln(out)
	}
}

func main() {
	solve()
}
