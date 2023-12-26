package main

import (
    "math"
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {

    F := 0
    var r1, r2 int
    A := make([][2][]int, 0)
    d := make(map[int]int)

    file, err := os.Open("04." + strconv.Itoa(F))
    if err != nil {
        panic(err)
    }

    defer file.Close()

    scanner := bufio.NewScanner(file)

    for scanner.Scan() {

        line := scanner.Text()
        line = strings.Split(line, ":")[1]
        parts := strings.Split(line, "|")
        L := parser(parts[0])
        R := parser(parts[1])
        A = append(A, [2][]int{L, R})
    }

    if err := scanner.Err(); err != nil { panic(err) }

    idx := 1

    for _, LR := range A {

        L := LR[0]
        R := LR[1]

        // part 1

        w := 0
        for _, l := range L {
            if contains(R, l) {
                w++
            }
        }

        r1 += int(math.Pow(2, float64(w - 1)))

        // part 2

        d[idx]++
        for i := 1; i <= w; i++ {
            d[idx+i] += d[idx]
        }

        idx++
    }

    for _, v := range d {
        r2 += v
    }

    fmt.Println("part 1:", r1)
    fmt.Println("part 2:", r2)
}

func parser (s string) []int {

    arr := strings.Fields(s)
    res := make([]int, len(arr))

    for i, n := range arr {
        res[i], _ = strconv.Atoi(n)
    }

    return res
}

func contains ( arr []int, elem int) bool {

    for _, e := range arr {
        if e == elem {
            return true
        }
    }
    return false
}


