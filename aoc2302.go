package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
)

func main() {

    D := map[string]int{

        "red": 12,
        "blue": 14,
        "green": 13,
    }

    r1, r2 := 0, 0
    idx := 1
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {

        line := scanner.Text()
        temp := strings.Split(line, ":")[1]
        words := strings.Split(temp, ";")
        ok := true // part 1
        R, G, B := 0, 0, 0 // part 2
        for _, w := range words {
            sub := strings.Split(w, " ")[1:]
            i := 0
            for i < len(sub) - 1 {
                number, color := sub[i], sub[i + 1]
                if color[len(color) - 1] == ',' {
                    color = color[ : len(color) - 1]
                }
                n, _ := strconv.Atoi( number )
                // part 1
                if n > D[color] {
                    ok = false
                }
                // part 2
                if color == "red" {
                    R = max(R, n)
                }
                if color == "green" {
                    G = max(G, n)
                }
                if color == "blue" {
                    B = max(B, n)
                }
                i += 2
            }
        }
        // part 1
        if ok {
            r1 += idx
        }
        // part 2
        r2 += R * B * G
        idx += 1
    }

    fmt.Println("Part 1: ", r1)
    fmt.Println("Part 2: ", r2)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
