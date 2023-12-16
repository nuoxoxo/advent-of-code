const day = 7

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
    console.log(lines)
    let res1 = 0
    let res2 = 1e9
    const lv: string[] = []
    const sls = '/'
    const D: {[key: string]: number} = {}
    D[sls] = 0

    // part 2
    const top: number = 4 * 1e7

    // Assuming 'a' is the input array
    for (const l of lines) {
        const a: string[] = l.split(' ')
        console.log(a)
        let c: string = a[0]
        if (c === '$') {
            c = a[1]
            if (c === 'cd') {
                c = a[2]
                if (c === '..') {
                    lv.pop()
                } else {
                    lv.push(c)
                }
            }
        } else if (!isNaN(parseInt(c))) {
            const ll: number = parseInt(c)
            D[sls] += ll
            let i = -1
            while (++i < lv.length) {
                let temp: string = sls
                let j = -1
                while (++j < i + 1) {
                    temp += lv[j] + sls
                }
                if ( ! (temp in D)) {
                    D[temp] = ll
                } else {
                    D[temp] += ll
                }
            }
        }
    }

    // part 2
    const togo: number = D[sls] - top

    for (const [_, v] of Object.entries(D)) {
        if (v < 100000) {
            res1 += v
        }

        if (v > togo) {
            res2 = Math.min(res2, v)
        }
    }
    console.log('part 1:', res1)
    console.log('part 2:', res2)

}).catch((err) => { throw err })

