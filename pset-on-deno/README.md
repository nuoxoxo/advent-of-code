# <img src='https://deno.com/images/artwork/HypnoDeno.gif?__frsh_c=dad2' width='22px' /> __Denon__ 
###### Denon is used here mainly for HMR 
Run
```
✗ denon start Filename.ts
```
Prep
```
✗ deno install --allow-read --allow-run -f https://deno.land/x/denon/denon.ts
```
denon.json
```
{
  "scripts": {
    "start": {
      "cmd": "deno run",
      "watch": true,
      "allow": ["read", "net", "env"],
      "ext": "ts",
      "unstable": true
    }
  }
}
```
# <img src='https://deno.com/images/artwork/hashrock_simple.png?__frsh_c=dad21828de649d12df5a23c572b88f3a3a73d0dc' width='23px' /> __Deno__
Run  
```
✗ sh deno.sh day{1|2|...|10|...}
```
Walk
###### Token will have to be exported
```
✗ curl -fsSL https://deno.land/x/install/install.sh | sh
✗ which deno
✗ export AOC_SESSION=abc123
✗ printenv
✗ deno run --allow-read --allow-env --allow-net template_deno.ts
```

# <img src='https://static.npmjs.com/attachments/ck3uwed1cmso79y74pjugy10f-gak-2x.png' width='24px' /> __Node__
Run 
```
✗ sh node.sh day{1|2|...|11|...}
```
Walk
###### Token is required inside a .env 
```
✗ npm i @types/node axios dotenv
✗ tsc template.ts && node template.js
```

&#8203;


