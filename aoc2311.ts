let day = 11
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
  let part1 = 0, part2 = 0

  console.log(lines[0])

  // Solver

  let coor: number[][] = []
  let R = lines.length, C = lines[0].length, r = -1, c 
  while (++r < R) {
    c = -1
    while (++c < C) {
      let node = lines[r][c]
      if (node == '#')
        coor.push([r, c])
    }
  }
  let EC:number[] = []
  let ER:number[] = []
  let IA:string[][] = []
  c = -1
  while (++c < C) {
    r = -1
    let temp: string[] = []
    while (++r < R) {
      temp.push(lines[r][c])
    }
    IA.push(temp)
  }
  r = -1
  while (++r < lines.length) {
    let ok = true
    for (let node of lines[r])
      if (node != '.')
        ok = false
    if (ok)
      ER.push(r)
  }
  c = -1
  while (++c < IA.length) {
    let ok = true
    for (let node of IA[c])
      if (node != '.')
        ok = false
    if (ok)
      EC.push(c)
  }

  const Calc = (coor: number[][], ER:number[], EC:number[], xp: number = 2): number => {

    // if (coor.length == 0) return 0
    let res = 0, i = -1
    while (++i < coor.length) {

      let [r, c] = coor[i]
      for (let node_next of coor.slice(0, i)) {

        let [next_r, next_c] = node_next
        let [s, e] = [ Math.min(r, next_r), Math.max(r, next_r) ]
        let node = s - 1
        while (++node < e) {
          if (ER.includes(node))
            res += xp - 1
        }
        res += e - s
        s = Math.min(c, next_c), e = Math.max(c, next_c)
        node = s - 1
        while (++node < e) {
          if (EC.includes(node))
            res += xp - 1
        }
        res += e - s
      }
    }
    return res
  }

  part1 = Calc (coor, ER, EC)
  part2 = Calc (coor, ER, EC, 1e6)
  console.log("part 1:", part1)
  console.log("part 2:", part2)

}).catch((err) => { throw err })

const checkTwoArraysAreEqual = (L:number[], R:number[]): boolean =>
{ return L.length === R.length && L.every((val, idx) => val === R[idx]) }

const checkSetHas = (set: Set<number[]>, this_array: number[]): boolean =>
{
  for (let that_array of set)
    if (checkTwoArraysAreEqual(this_array, that_array))
      return true
  return false
}


