// echo "1\n3\na 1\nb 2\nc 3\na:1,b:2,c:3" | go run task3.go

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var in *bufio.Reader
var out *bufio.Writer

func solve() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		var n int
		fmt.Fscan(in, &n)


		// Чтение товаров
		priceMap := make(map[string]int)
		for j := 0; j < n; j++ {
			var name string
			var price int
			fmt.Fscan(in, &name, &price)
			priceMap[name] = price
		}

		// Чтение результирующей строки
		var result string
		fmt.Fscan(in, &result)

		// Проверка формата результирующей строки
		if !validateString(priceMap, result) {
			fmt.Fprintln(out, "NO")
		} else {
			fmt.Fprintln(out, "YES")
		}
	}
}

func validateString(priceMap map[string]int, result string) bool {
	// Разделение строки
	pairs := strings.Split(result, ",")
	seen := make(map[string]bool)
	usedPrices := make(map[int]bool)

	for _, pair := range pairs {
		// Проверка формата: название:цены
		parts := strings.Split(pair, ":")
		if len(parts) != 2 {
			return false
		}
		name, priceStr := parts[0], parts[1]

		// Проверка на валидное число
		price := 0
		_, err := fmt.Sscanf(priceStr, "%d", &price)
		if err != nil || price <= 0 {
			return false
		}

		// Проверка, что товар существует и имеет правильную цену
		if priceMap[name] != price {
			return false
		}

		// Проверка уникальности товара и цены
		if seen[name] || usedPrices[price] {
			return false
		}
		seen[name] = true
		usedPrices[price] = true
	}

	// Проверка, что все товары перечислены
	if len(seen) != len(priceMap) {
		return false
	}

	return true
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solve()
}





