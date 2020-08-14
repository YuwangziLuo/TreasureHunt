# TreasureHunt
This is a tiny command-line C program searching for 
reachable treasures in a maze described in a **.txt** map. 

## Features
+ Tiny and simple
+ Using DFS algorithm
+ For exercise

## Platform
Windows 10(64 bit)

## Instructions
### 1. Create a Map File
In the directory of the program, create a new file: **Map.txt**. 
Then fill in with legal characters: 
| Legal Char | Meaning |
| :-: |:- |
| **x** or **X** | Block |
| **t** or **T** | Treasure |
| (space) | Available path |
| **s** or **S** | Start point |

**Note**
+ A unique start point is required. 
+ The maze must be rectangular. 
+ The maze may not be too big. 

**Example**
```
xxx  xxt xt x tt x x x   txtxt xx xt
x   x x xt     xxxxttx xx txtxxt  t 
xttx x  txtxxt  t xttx   xtxtxxt  t 
xx   t  x    xt x     x x  t     xxx
 x x x t txt xx xt      x xt     xxx
xt  xx  xx  xxx  txttx x  txtxxt  t 
xxtxt tt xt  xtt x    x x xt     xxx
xtt    t  x    xx  s  x x xt     xxx
t t t   x xxx xxt xttx x  txtxxt  t 
xxx tx xt xt t xt     x x xt     xxx
x   x x xt     xxx    x x xt     xxx
xttx x  txtxxt  t xttx x  txtxxt  t 
xx   t  x    xt x  x x xt     xxxxt 
xxx  xxt xt x tt x x x xt     xxxxtx
x   x x xt     xxxxttx x  txtxxt  t 
```

### 2. Run the Program
Launch **cmd.exe** or **powershell.exe** in the directory, execute: 
```
TreasureHunt.exe [option]
```
| Option | Argument | Specification |
| :-: | :-: | :- |
| -h | No | Print out this help message.  |
| -p | Optional | Get process of treasure-hunt. Optional argument must be a positive integer as rough interval(millisecond) between two status. (Default value: 5)  |
| -r | No | Get only result of treasure-hunt.  |
| -s | No | Get step of treasure-hunt.  |

**Note**
+ The default mode is '-p'.
+ The 'bug' triggered by option **-b** is merely AMUSING.
+ If **-p** or **-s** options are specified, certain chars(shown below) will appear on the console to show the process or step: 

| Char | Meaning |
| :-: | :- |
| @ | Treasure hunter. |
| (space) | Not-yet-taken available path |
| . | Already-taken available path |
| $ | Not-yet-taken treasure |
| # | Already-taken treasure |