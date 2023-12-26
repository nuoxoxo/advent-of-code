package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main () {
    var s string
    r1 := 0
    r2 := 0
    D := map [string]int {
        "one": 1, "two": 2, "three": 3,
        "four": 4, "five": 5, "six": 6,
        "seven": 7, "eight": 8, "nine": 9,
        "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9,
    }
    scanner := bufio.NewScanner(os.Stdin)
    var i int
    for scanner.Scan () {
        s = scanner.Text()
        var L, R byte
        i = 0
        for i < len(s) {
            c := s[i]
            if '0' <= c && c <= '9' {
                L = s[i]
                break
            }
            i++
        }
        i = len(s) - 1
        for i > -1 {
            c := s[i]
            if '0' <= c && c <= '9' {
                R = s[i]
                break
            }
            i--
        }
        ss := string( []byte {L, R} )
        n, e := strconv.Atoi(ss)
        if e == nil {
            r1 += n
        }
        // part 2
        var a [][]int
        for k, v := range D {
            l := strings.Index(s, k)
            r := strings.LastIndex(s, k)
            if l != -1 {
                a = append(a, []int {l, v})
            }
            if r != -1 {
                a = append(a, []int {r, v})
            }
        }
        sort.Slice(a, func(x, y int) bool { return a[x][0] < a[y][0] })
        ll := strconv.Itoa(a[0][1])
        rr := strconv.Itoa(a[len(a) - 1][1])
        n, e = strconv.Atoi(ll + rr)
        if e == nil {
            r2 += n
        }
    }
    fmt.Println("part 1:", r1)
    fmt.Println("part 2:", r2)
}

