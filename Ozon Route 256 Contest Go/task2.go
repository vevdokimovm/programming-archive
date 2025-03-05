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

func solve() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		var n int
		fmt.Fscan(in, &n)

		// Подсчитываем цифры, которые используются в старшем разряде
		usedDigits := make(map[int]bool)
		temp := n
		for temp > 0 {
			digit := temp % 10
			usedDigits[digit] = true
			temp /= 10
		}

		// Количество табличек: 10 для младших разрядов + уникальные цифры старшего разряда
		result := 10 + len(usedDigits)
		fmt.Fprintln(out, result)
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solve()
}
