const day = 8

import { config } from "https://deno.land/x/dotenv/mod.ts"

config()
const session = Deno.env.get("AOC_SESSION")

const fetch_input = (day: number): Promise<string> => {

    const url = `https://adventofcode.com/2022/day/${day}/input`
    const headers = new Headers({ 'Cookie': `session=${session}` })
    return fetch(url, { headers })
        .then ((res1p) => res1p.text())
        .catch ((err) => { throw err })
}

fetch_input(day).then((infile) => {

    const a = infile.split('\n').map((bloc) => {
        if (bloc !== '') {
            const sub: number[] = []
            for (const n of bloc) {
                sub.push(Number(n))
            }
            return sub
        }
    })
    if ( ! a[a.length - 1])
        a.pop()
    console.log(a, a.length)
    const R: number = a.length;
    const C: number = a[0].length;
    const peri: number = R * 2 + C * 2 - 4;
    let res1 = peri
    let res2 = 0
    let r = 0, c, i
    while (++r < R - 1) {
        c = 0
        while (++c < C - 1) {
            const n: number = a[r][c];

            // up
            let ok = true;
            i = -1
            while (++i < r) {
                if (a[i][c] >= n) {
                    ok = false;
                }
            }
            if (ok) {
                res1 += 1;
                continue;
            }

            // down
            ok = true;
            i = -1
            while (++i < r) {
                if (a[i][c] >= n) {
                    ok = false;
                }
            }
            if (ok) {
                res1 += 1;
                continue;
            }

            // left
            ok = true;
            i = -1
            while (++i < r) {
                if (a[r][i] >= n) {
                    ok = false;
                }
            }
            if (ok) {
                res1 += 1;
                continue;
            }

            // right
            ok = true;
            i = -1
            while (++i < r) {
                if (a[r][i] >= n) {
                    ok = false;
                }
            }
            if (ok) {
                res1 += 1;
                continue;
            }
        }

        // part 2
        c = 0
        while (++c < C - 1) {
            const n: number = a[r][c];
            let u = 0;
            i = r
            while (--i > -1) {
                u += 1;
                if (a[i][c] >= n) {
                    break;
                }
            }
            let d = 0;
            i = r
            while (++i < R) {
                d += 1;
                if (a[i][c] >= n) {
                    break;
                }
            }
            let l = 0;
            i = c
            while (--i > -1) {
                l += 1;
                if (a[r][i] >= n) {
                    break;
                }
            }
            let rr = 0;
            i = c
            while (++i < C) {
                rr += 1;
                if (a[r][i] >= n) {
                    break;
                }
            }
            const temp = u * d * l * rr;
            res2 = res2 > temp ? res2 : temp;
        }
    }
    console.log('part 1:', res1)
    console.log('part 2:', res2)

}).catch((err) => { throw err })

