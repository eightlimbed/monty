## Monty

**The Monty language**

Monty 0.98 is a scripting language that is first compiled into Monty byte codes 
(Just like Python). It relies on a unique stack, with specific instructions to 
manipulate it. The goal of this project is to create an interpreter for 
Monty ByteCodes files.

---

**Usage**
After cloning this repository, compile **monty** using `gcc` (preferably version
4.8.4):
`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

To run the program, enter: `./monty <file>`

---

**Operations**
List of monty operations this interpreted understands:
- `push <integer>`: pushes an integer on to the stack
- `pall`: prints the values of every node on the stack
- `pint`: prints the value of the node at the top of the stack
- `pop`: removes the node at the top of the stack
- `swap`: swaps the position of the top two nodes
- `add`: places the sum of the top two nodes into the 2nd node and removes the
  first
- `nop`: does nothing

---

File Name | Description
--- | ---
---
`monty.c` | Main program file
`monty.h` | Header file
`parser.c` | Parses each line of Monty file
`stack_functions.c` | Functions for manipulating and printing from the stack
`math_functions.c` | Functions that do mathematical operations to the stack
`etc_functions.` | Functions for error handling and memory management

---

This project was built by [http://github.com/vkalia602](Sue Kalia) and
[http://github.com/eightlimbed](Lee Gaines) at
[http://holbertonschool.com](Holberton School)
