package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	var A [][]string
	var line string

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line = scanner.Text()
		temp := make([]string, len(line))
		for i, c := range line {
			temp[i] = string(c)
		}
		A = append(A, temp)
	}
	if len(line) < 1 {
		os.Exit(0)
	}

	r1 := BFS(A, [2]int{0, -1}, [2]int{0, 1})

	var r2 int
	R := len(A)
	C := len(A[0])
	for r := 0; r < R; r++ {
		r2 = max(r2, BFS(A, [2]int{r, -1}, [2]int{0, 1}))
		r2 = max(r2, BFS(A, [2]int{r, C}, [2]int{0, -1}))
	}
	for c := 0; c < C; c++ {
		r2 = max(r2, BFS(A, [2]int{-1, c}, [2]int{1, 0}))
		r2 = max(r2, BFS(A, [2]int{R, c}, [2]int{-1, 0}))
	}
	fmt.Println("part 1:", r1)
	fmt.Println("part 2:", r2)
}

func BFS(A [][]string, curr [2]int, move [2]int) int {

	R, C := len(A), len(A[0])
	S := make(map[[2][2]int]bool)
	D := [][2][2]int{{curr, move}}

	for len(D) > 0 {

			curr, move := D[0][0], D[0][1]
		D = D[1:]
		r, c := curr[0], curr[1]
		r += move[0]
		c += move[1]

		if r < 0 || r > R-1 || c < 0 || c > C-1 {
			continue
		}

		curr = [2]int{r, c}
		t := A[r][c]
		var todo [][2][2]int

		if t == "." {

			coor := [2][2]int{curr, move}
			todo = append(todo, coor)
		} else if t == "/" {

			move = [2]int{-move[1], -move[0]}
			coor := [2][2]int{curr, move}
			todo = append(todo, coor)
		} else if t == "\\" {

			move = [2]int{move[1], move[0]}
			coor := [2][2]int{curr, move}
			todo = append(todo, coor)
		} else if t == "-" {

			if move[1] != 0 {

				coor := [2][2]int{curr, move}
				todo = append(todo, coor)
			} else { // split into 2 <--- moving horizontal

				move = [2]int{0, -1}
				coor := [2][2]int{curr, move}
				todo = append(todo, coor)
				move = [2]int{0, 1}
				coor = [2][2]int{curr, move}
				todo = append(todo, coor)
			}
		} else if t == "|" {

			if move[0] != 0 {
				coor := [2][2]int{curr, move}
				todo = append(todo, coor)
			} else {

				move = [2]int{1, 0}
				coor := [2][2]int{curr, move}
				todo = append(todo, coor)
				move = [2]int{-1, 0}
				coor = [2][2]int{curr, move}
				todo = append(todo, coor)
			}
		}

		for _, job := range todo {
			if S[job] {
				continue
			}
			D = append(D, job)
			S[job] = true
		}
	}

	SS := make(map[[2]int]bool)
	for p := range S {
		SS[p[0]] = true
	}
	return len(SS)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

