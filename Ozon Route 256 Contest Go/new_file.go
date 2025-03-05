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

		illuminated := make(map[[2]int]bool)
		result := []Flashlight{}

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

		isLower := true
		for len(illuminated) < n*m {
			var x, y int
			if isLower {
				x = n
			} else {
				x = 1
			}

			y = 1
			for col := 1; col <= m; col++ {
				isIlluminated := false
				for row := 1; row <= n; row++ {
					if illuminated[[2]int{row, col}] {
						isIlluminated = true
						break
					}
				}
				if !isIlluminated {
					y = col
					break
				}
			}

			dir := "D"
			if !isLower {
				dir = "U"
			}
			result = append(result, Flashlight{x, y, dir})
			addIllumination(x, y, dir)

			isLower = !isLower
		}

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


