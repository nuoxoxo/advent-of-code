let day = 5
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
  let r1 = 0, r2 = 0
  let seeds: number[] = []
  let submap:number[][] = []
  let maps: number[][][] = []
  for (let line of lines) {
    if (line.includes('seeds')) {
      seeds = line.substr(7).split(' ').map(Number)
    } else if (line === '' && submap.length !== 0) {
      maps.push(submap)
      submap = [];
    } else if (line !== '' && ! line.includes('map')) {
      let temp: number[] = line.split(' ').map(Number)
      temp.reverse()
      submap.push(temp)
    }
  }
  maps.push(submap)
  let seeds_cp = [ ... seeds] // part 2
  console.log(maps)
  console.log(seeds)

  // part 1
  let i = -1
  while (++i < seeds.length) {
    for (let submaps of maps) {
      for (let submap of submaps) {
        let [ len, S, E ] = submap
        if (S <= seeds[i] && seeds[i] < S + len) {
          let offset = seeds[i] - S
          let dest = E + offset
          seeds[i] = dest
          break
        }
      }
    }
  }
  r1 = Math.min(...seeds)

  // part 2
  let seeds_2: number[] = []
  i = 0
  while (i < seeds_cp.length) {
    seeds_2.push([
      seeds_cp[i],
      seeds_cp[i] + seeds_cp[i + 1]
    ])
    i += 2
  }
  for (let submaps of maps) {
    let update: number[][] = []
    while ( seeds_2.length > 0 ) {
      let bounds: number[] = seeds_2.pop()
      let [ left_bound, right_bound ] = bounds
      let ok = false
      for (let submap of submaps) {
        let [ len, S, E ] = submap
        let real_left_bound = Math.max(S, left_bound)
        let real_right_bound = Math.min(S + len, right_bound)
        if ( ! (real_left_bound < real_right_bound) )
          continue
        let left_offset = real_left_bound - S
        let right_offset = real_right_bound - S
        update.push([
          E + left_offset,
          E + right_offset
        ])
        if (left_bound < real_left_bound)
          seeds_2.push([left_bound, real_left_bound])
        if (real_right_bound < right_bound)
          seeds_2.push([real_right_bound, right_bound])
        ok = true
      }
      if (!ok)
        update.push([left_bound, right_bound])
    }
    seeds_2 = update
  }
  seeds_2.sort((a, b) => a[0] - b[0])
  r2 = seeds_2[0][0]

  console.log("part 1:", r1)
  console.log("part 2:", r2)

}).catch((err) => { throw err })
