# TreasureHunt
This is a tiny C program searching for reachable treasures in a maze described in a **.txt** map. 

## Platform
Windows

## Instructions
### 1. Create a Map File
In the directory of the program, create a new file: **Map.txt**. Then fill in with legal characters: 
| Legal Chars | Meaning |
| :-: |:- |
| **x**or**X** | Block |
| **t**or**T** | Treasure |
| (space) | Road |
| **s**or**S** | Start Point |
**Note**: 
+ A unique start point is required. 
+ The maze must be rectangular. 
+ The maze may not be too big. 

### 2. Run the Program
Launch **cmd.exe** or **powershell.exe** in the directory, execute: 
```
TreasureHunt.exe [option]
```
| Legal options | Argument | Specification |
| :-: | :-: | :- |
| -b | No | Trigger bug.  |
| -h | No | Print out this help message.  |
| -p | Optional | Get process of treasure-hunt. Optional argument must be a positive integer as rough interval(millisecond) between two status. (Default value: 5)  |
| -r | No | Get only result of treasure-hunt.  |
| -s | No | Get step of treasure-hunt.  |
**Note**: The default mode is '-p'. 