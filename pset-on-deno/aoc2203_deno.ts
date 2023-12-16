const day = 3

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
    let res = 0
    let res2 = 0
    let i = -1
    while (++i < len) {
        const s: string = lines[i]
        const n = s.length
        const l: string = s.slice(0, Math.floor(n / 2))
        const r: string = s.slice(Math.floor(n / 2))
        for (const c of l) {
            if (r.includes(c)) {
                res += calc(c)
                break
            }
        }
        if (i > len - 3 || i % 3)
            continue;
        const d = lines[i + 1]
        const dd = lines[i + 2]
        let ok = false
        let ok2 = false
        for (const c of s) {
            if (ok && ok2) {
                break
            }
            ok = false
            ok2 = false
            if (d.includes(c)) {
                ok = true
            }
            if (dd.includes(c)) {
                ok2 = true
            }
            if (ok && ok2) {
                res2 += calc(c)
                // console.log(c)
            }
        }
    }
    console.log('part 1:', res)
    console.log('part 2:', res2)

}).catch((err) => { throw err })

const calc = (c: string): number => {
    const cc = c.charCodeAt(0)
    if ('a' <= c && c <= 'z')
        return cc - 'a'.charCodeAt(0) + 1
    return cc - 'A'.charCodeAt(0) + 27
}

