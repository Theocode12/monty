# Monty Interpreter

A language interpreter made in the C programming language to manage stacks(LIFO) and queues(FIFO). The objective of this project is to interpret Monty bytecodes files. [Monty](http://montyscoconut.github.io/) is a language that aims to close the gap between scripting and programming languages.

# Compilation

To compile this project, you can use the following command:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

# Option Codes

## Push opcode

The opcode `push` pushes an element to the stack.

**Usage:** `push <int>`, where *int* is an integer.

## Pall opcode

The opcode `pall` prints all the values on the stack, starting from the top of the stack.

**Usage:** `pall`. If the stack is empty, `pall` don’t print anything.

```
$ Theo@ubuntu:~/monty$ cat -e bytecodes/push_pall_0.m
push 3$
push 2$
push 1$
pall$
$ Theo@ubuntu:~/monty$ ./monty bytecodes/push_pall_0.m
1
2
3
$ Theo@ubuntu:~/monty$
```

## Pint opcode

The opcode `pint` prints the value at the top of the stack, followed by a new line.

**Usage:** `pint`.

**Note:** If the stack is empty, `pint` print an error message.

```
$ Eka@ubuntu:~/monty$ cat -e bytecodes/pint.m
push 1$
push 2$
pint$
push 3$
pint$
$ Eka@ubuntu:~/monty$ ./monty bytecodes/pint.m
2
3
$ Eka@ubuntu:~/monty$
```

## Pop opcode

The opcode `pop` pops(removes) the top element of the stack.

**Usage:** `pop`. 

**Note:** If the stack is empty, `pop` print an error message.

```
$ Theo@ubuntu:~/monty$ cat -e bytecodes/pop.m
push 1$
push 2$
push 3$
pall$
pop$
pall$
pop$
pall$
pop$
pall$
$ Theo@ubuntu:~/monty$ ./monty bytecodes/pop.m
3
2
1
2
1
1
$ amonkeyprogrammer@ubuntu:~/monty$
```

## Swap opcode

The opcode `swap` swaps the top two elements of the stack.

**Usage:** `swap`.

**Note:** If the stack contains less than two elements, `swap` print an error message.

```
$ valentine@ubuntu:~/monty$ cat -e bytecodes/swap.m
push 1$
push 2$
push 3$
pall$
swap$
pall$
$ valentine@ubuntu:~/monty$ ./monty bytecodes/swap.m
3
2
1
2
3
1
$ valentine@ubuntu:~/monty$
```

## Add opcode

The opcode `add` adds the top two elements of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

* The top element of the stack contains the result
* The stack is one element shorter

**Usage:** `add`.

**Note:** If the stack contains less than two elements, `add` print an error message.

```
$ Essien@ubuntu:~/monty$ cat -e bytecodes/add.m
push 1$
push 2$
push 3$
pall$
add$
pall$
$ Essien@ubuntu:~/monty$ ./monty bytecodes/swap.m
3
2
1
5
1
$ Essien@ubuntu:~/monty$
```

## Nop opcode

The opcode `nop` does nothing.

**Usage:** `nop`.

```
$ holberton@ubuntu:~/monty$ cat -e bytecodes/nop.m
nop$
push 1$
push 2$
push 3$
nop$
pall$
nop$
pall$
$ holberton@ubuntu:~/monty$ ./monty bytecodes/nop.m
3
2
1
3
2
1
$ holberton@ubuntu:~/monty$
```

## Sub opcode

The opcode `sub` subtracts the top element of the stack from the second top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

* The top element of the stack contains the result
* The stack is one element shorter

**Usage:** `sub`. 

**Note:** If the stack contains less than two elements, `sub` print an error message.

```
$ valentine@ubuntu:~/monty$ cat -e bytecodes/sub.m
push 1$
push 2$
push 9$
push 3$
sub$
pall$
$ valentine@ubuntu:~/monty$ ./monty bytecodes/sub.m
6
2
1
$ valentine@ubuntu:~/monty$
```

## Div opcode

The opcode `div` divides the second top element of the stack by the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

* The top element of the stack contains the result
* The stack is one element shorter

**Usage:** `div`.

**Note:** If the stack contains less than two elements, `div` print an error message. Also it checks zero division error.

```
$ Theocode@ubuntu:~/monty$ cat -e bytecodes/div.m
push 1$
push 2$
push 10$
push 5$
div$
pall$
$ Theocode@ubuntu:~/monty$ ./monty bytecodes/div.m 
2
2
1
$ Theocode@ubuntu:~/monty$
```
## Mul opcode

The opcode `mul` multiplies the second top element of the stack with the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

* The top element of the stack contains the result
* The stack is one element shorter

**Usage:** `mul`.

**Note:** If the stack contains less than two elements, `mul` print an error message.

```
$ Theo@ubuntu:~/monty$ cat -e bytecodes/mul.m
push 1$
push 2$
push 20$
push 5$
mul$
pall$
$ Theo@ubuntu:~/monty$ ./monty bytecodes/mul.m 
100
2
1
$ Theo@ubuntu:~/monty$
```

## Mod opcode

The opcode `mod` computes the rest of the division of the second top element of the stack by the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

* The top element of the stack contains the result
* The stack is one element shorter

**Usage:** `mod`.

**Note:** If the stack contains less than two elements, `mod` print an error message. It also checks zero division errors.

```
$ valentine@ubuntu:~/monty$ cat -e bytecodes/mod.m
push 1$
push 2$
push 20$
push 5$
mod$
pall$
$ valentine@ubuntu:~/monty$ ./monty bytecodes/mul.m 
0
2
1
$ valentine@ubuntu:~/monty$
```

## Comments

Every good language comes with the capability of commenting. When the first non-space character of a line is `#`, treat this line as a comment (don’t do anything).

```
$ valentine@ubuntu:~/monty$ cat -e bytecodes/comments.m
#montyisfun$
push 10$
push 2$
push 8$
push 5$
#cisfun$
pall$
$ valentine@ubuntu:~/monty$ ./monty bytecodes/comments.m 
5
8
2
10
$ valentine@ubuntu:~/monty$
```

## Pchar opcode

The opcode `pchar` prints the char at the top of the stack, followed by a new line. The integer stored at the top of the stack is treated as the ascii value of the character to be printed.

**Usage:** `pchar`

* If the value is not in the ascii table (`man ascii`), `pchar` print an error message.
* If the stack is empty, `pchar` print an error message.

```
$ valentine@ubuntu:~/monty$ cat -e bytecodes/pchar.m
push 65$
pchar$
$ valentine@ubuntu:~/monty$ ./monty bytecodes/pchar.m 
A
$ valentine@ubuntu:~/monty$
```

## Pstr opcode

The opcode `pstr` prints the string starting at the top of the stack, followed by a new line. The integer stored in each element of the stack is treated as the ascii value of the character to be printed.

**Usage:** `pstr`. If the stack is empty, `pstr` print only a new line

```
$ valentine@ubuntu:~/monty$ cat -e bytecodes/pstr.m
push 1$
push 2$
push 3$
push 4$
push 0$
push 110$
push 0$
push 121$
push 116$
push 110$
push 111$
push 77$
pstr$
$ valentine@ubuntu:~/monty$ ./monty bytecodes/pstr.m 
Monty
$ valentine@ubuntu:~/monty$
```

## Rotl opcode

The opcode `rotl` rotates the stack to the top. The top element of the stack becomes the last one, and the second top element of the stack becomes the first one. It never fails.

**Usage:** `rotl`

```
$ Eka@ubuntu:~/monty$ cat -e bytecodes/rotl.m
push 2$
push 3$
push 4$
push 5$
push 6$
push 7$
push 8$
push 9$
push 1$
pall$
rotl$
pall$
$ Eka@ubuntu:~/monty$ ./monty bytecodes/rotl.m 
1
9
8
7
6
5
4
3
2
9
8
7
6
5
4
3
2
1
$ Eka@ubuntu:~/monty$
```

## Rotr opcode

The opcode `rotr` rotates the stack to the bottom. The last element of the stack becomes the top element of the stack.

**Usage:** `rotr`

```
$ valentine@ubuntu:~/monty$ cat -e bytecodes/rotr.m
push 1$
push 2$
push 3$
push 4$
push 5$
push 6$
push 7$
push 8$
push 9$
pall$
rotr$
pall$
$ valentine@ubuntu:~/monty$ ./monty bytecodes/rotr.m 
9
8
7
6
5
4
3
2
1
1
9
8
7
6
5
4
3
2
$ valentine@ubuntu:~/monty$
```

## Stack opcode

The opcode `stack` sets the format of the data to a stack (LIFO). This is the default behavior of the program.

**Usage:** `stack`

## Queue opcode

The opcode `queue` sets the format of the data to a queue (FIFO).

**Usage:** `queue`

### Switching mode

* The top of the stack becomes the front of the queue
* The front of the queue becomes the top of the stack

```
$ Theocode@ubuntu:~/monty$ cat -e bytecodes/queue_stack.m
queue$
push 1$
push 2$
push 3$
pall$
stack$
push 4$
push 5$
push 6$
pall$
add$
pall$
queue$
push 11111$
add$
pall$
$ Theocode@ubuntu:~/monty$ ./monty bytecodes/queue_stack.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
$ Theocode@ubuntu:~/monty$
```

## Some Brainfuck Tasks

[Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) is an esoteric programming language created in 1993 by Urban Müller. Here are some testing scripts.

## Print School

Write a Brainf\*ck script that prints Holberton, followed by a new line.

* All your Brainf\*ck files should be stored inside the bf sub directory
* You can install the bf interpreter to test your code: `sudo apt-get install bf`

**Source:** [bf/1000-holberton.bf](https://github.com/Theocode12/monty/blob/main/bf/1000-school.bf)

```
$ valentine@ubuntu:~/monty/bf$ bf 1000-school.bf 
School
$ valentine@ubuntu:~/monty/bf$ 
```

## Add two digits

Add two digits given by the user.

* Read the two digits from stdin, add them, and print the result
* The total of the two digits with be one digit-long (<10)

**Source:** [bf/1001-add.bf](https://github.com/Theocode12/monty/blob/main/bf/1001-add.bf)

```
$ valentine@ubuntu:~/monty/bf$ bf ./1001-add.bf
81
9$ valentine@ubuntu:~/monty/bf$ 
```

## Multiply two digit

 Multiply two digit given by the user.

 * Read the two digits from stdin, add them, and print the result
 * The total of the product of the two digit must be one digit long

 **Source:** [bf/1002-mul.bf](https://github.com/Theocode12/monty/blob/main/bf/1002-mul.bf)

 ```
julien@ubuntu:~/monty/bf$ bf 1002-mul.bf
24
8julien@ubuntu:~/monty/bf$
 ```

**Contributors:** Dr. Eka Essien and Maduagwu Valentine

**Courtesy:** ALX Software Engineering Program