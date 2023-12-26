package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func hashing(a string) int {

    res := 0
    for _, c := range a {
        res = (res + int(c)) * 17 % 256
    }
    return res
}

func main () {

    /*
    F := 0
    file, err := os.Open(fmt.Sprintf("15.%d", F))
    if err != nil { panic(err) }
    defer file.Close()
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
		line := scanner.Text()
    }
    */
    var line string
    scanner := bufio.NewScanner( os.Stdin )
    if scanner.Scan() {
        line = scanner.Text()
    }
    if len(line) < 1 {
        os.Exit(0)
    }
    A := strings.Split(line, ",")
    p1 := 0
    for _, a := range A {
        p1 += hashing(a)
    }

    fmt.Println("part 1:", p1)

    p2 := 0
    var hsh int
    var key string
    B := make ([][]struct {key string; val int}, 256)
    for i := range B {
        B[i] = make([]struct {key string; val int}, 0)
    } // fill it
    for _, a := range A {
        if strings.Contains(a, "-") {
            key = a[ : len(a) - 1]
            hsh = hashing(key)
            for i, sub := range B[hsh] {
                if sub.key == key {
                    B[hsh] = append(B[hsh][ : i], B[hsh][i + 1 : ]...)
                    break
                }
            }
        } else if strings.Contains(a, "=") {
            pair := strings.Split(a, "=")
            key = pair[0]
            hsh = hashing(key)
            leng, err := strconv.Atoi(pair[1])
            if err != nil {
                panic(err)
            }
            found := false
            for i := range B[hsh] {
                if B[hsh][i].key == key {
                    found = true
                    B[hsh][i].val = leng
                    break
                }
            }
            if ! found {
                B[hsh] = append(B[hsh], struct { key string; val int }{ key, leng })
            }
        }
    }
    for i, sub := range B {
        for slot, kv := range sub {
            p2 += (i + 1) * (slot + 1) * kv.val
        }
    }

    fmt.Println("part 2:", p2)
}

