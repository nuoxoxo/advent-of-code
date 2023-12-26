let day = 1
import { config } from "https://deno.land/x/dotenv/mod.ts"
config()
let session = Deno.env.get("AOC_SESSION")

let get_stuff = (day): Promise<string> => {
  let url: string = `https://adventofcode.com/2023/day/${day}/input`
  console.log(session)
  let headers = new Headers({ 'Cookie': `session=${session}` })
  return fetch(url, { headers })
        .then((resp) => resp.text())
        .catch((err) => { throw err })
}

get_stuff(day).then((infile) => {
  let lines: string[] = infile.split('\n')
  lines.pop()
  let A: string[] = []
  let r1 = 0
  let r2 = 0
  let D: Record<string, int> = {
    "one": 1, "two": 2, "three": 3, "four": 4, "five": 5,
    "six": 6, "seven": 7, "eight": 8, "nine": 9,
    "1": 1, "2": 2, "3": 3, "4": 4, "5": 5,
    "6": 6, "7": 7, "8": 8, "9": 9
  }
  for (let s of lines) {
    A.push(s)
    let a: Array<[number, string]> = []
    let i = -1
    let L: string
    let R: string
    while (++i < s.length) {
      if ( ! isNaN(parseInt(s[i]))) {
        L = s[i]
        break
      }
    }
    i = s.length
    while (--i > -1) {
      if ( ! isNaN(parseInt(s[i]))) {
        R = s[i]
        break
      }
    }
    r1 += parseInt(L + R)
    for (let [key, value] of Object.entries(D)) {
      let l = s.indexOf(key)
      let r = s.lastIndexOf(key)
      if (l !== -1) {
        a.push([l, key])
      }
      if (r !== -1) {
        a.push([r, key])
      }
    }
    a.sort((x, y) => x[0] - y[0])
    let ll: string = D[a[0][1]]!.toString()
    let rr: string = D[a[a.length - 1][1]]!.toString()
    let ss: string = ll + rr
    r2 += parseInt(ss)
  }
  console.log("part 1:", r1)
  console.log("part 2:", r2)

}).catch((err) => { throw err })
