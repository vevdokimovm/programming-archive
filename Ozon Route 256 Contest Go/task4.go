package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var in *bufio.Reader
var out *bufio.Writer

func normalizeString(s string) (string, string) {
	even := strings.Builder{}
	odd := strings.Builder{}

	for i, char := range s {
		if i % 2 == 0 {
			even.WriteRune(char)
		} else {
			odd.WriteRune(char)
		}
	}

	return even.String(), odd.String()
}

func solve() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		var n int 
		fmt.Fscan(in, &n)

		counter := make(map[string]int)
		for j := 0; j < n; j++ {
			var s string
			fmt.Fscan(in, &s)

			// Нормализуем строку
			even, odd := normalizeString(s)
			key := even + "|" + odd
			counter[key]++
		}

		// Подсчет количества пар
		result := 0
		for _, count := range counter {
			result += count * (count - 1) / 2
		}

		fmt.Fprintln(out, result)
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solve()
}






