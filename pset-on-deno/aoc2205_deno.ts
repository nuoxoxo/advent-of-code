const day = 5

import { config } from "https://deno.land/x/dotenv/mod.ts"

config()
const session = Deno.env.get("AOC_SESSION")

const fetch_input = (day: number): Promise<string> => {

    const url = `https://adventofcode.com/2022/day/${day}/input`
    const headers = new Headers({ 'Cookie': `session=${session}` })

    return fetch(url, { headers })
        .then ((resp) => resp.text())
        .catch ((err) => { throw err })
}

fetch_input(day).then((infile) => {

    const lines = infile.split('\n').map((bloc) => {
        return bloc
    })
    lines.pop()
    const len = lines.length
    console.log(lines, len)
    const a: string[] = []
    const op: string[] = []
    let ok = false
    for (const line of lines) {
        if (line === '')
            ok = true
        if ( ! ok) {
            a.push(line)
        } else {
            op.push(line)
        }
    }
    const lastline = a[a.length - 1] // get this line: " 1   2   3   4   5   6   7   8   9 "
    const tt = parseInt(lastline.charAt(lastline.length - 2))
    a.pop() // pop line " 1   2   3   4   5   6   7   8   9 "
    const a1: string[][] = Array.from({ length: tt }, () => [])
    const a2: string[][] = Array.from({ length: tt }, () => [])
    let i: number
    for (const s of a) {
        i = -1
        while (++i < tt) {
            const c: string = s[1 + 4 * i]
            if (c >= 'A' && c <= 'Z') {
                a1[i].unshift(c)
                a2[i].unshift(c)
            }
        }
    }
    console.log(a1, a2)
    for (const s of op) {
        const ss: string[] = s.split(' ')
        const m: number = parseInt(ss[1])
        const f: number = parseInt(ss[3]) - 1
        const t: number = parseInt(ss[5]) - 1

        // part 1

        i = -1
        while (++i < m) {
            if (a1[f].length === 0) {
                continue
            }
            a1[t].push(a1[f].pop() as string)
        }

        // part 2

        let E = ''
        i = -1
        while (++i < m) {
            if (a2[f].length === 0) {
                continue
            }
            E += a2[f].pop() as string
        }
        while (E !== '') {
            a2[t].push(E[E.length - 1])
            E = E.slice(0, -1)
        }
    }
    let res1 = ''
    let res2 = ''
    i = -1
    while (++i < tt) {
        res1 += a1[i][a1[i].length - 1]
        res2 += a2[i][a2[i].length - 1]
    }
    console.log('part 1:', res1)
    console.log('part 2:', res2)

}).catch((err) => { throw err })

