# Homework 2 (30 Points)

The deadline for Homework 2 is Monday, October X, 8pm. The late
submission deadline is Monday, October Y, 8pm.

## Getting the code template

Before you perform the next steps, you first need to create your own
private copy of this git repository. To do so, click on the link
provided in the announcement of this homework assignment on
Piazza. After clicking on the link, you will receive an email from
GitHub, when your copy of the repository is ready. It will be
available at
`https://github.com/nyu-cso-005-fa19/hw02-<YOUR-GITHUB-USERNAME>`.  
Note that this may take a few minutes.

* Open a browser at `https://github.com/nyu-cso-005-fa19/hw02-<YOUR-GITHUB-USERNAME>` with your Github username inserted at the appropriate place in the URL.
* Choose a place on your computer for your homework assignments to reside and open a terminal to that location.
* Execute the following git command: <br/>
  ```git clone https://github.com/nyu-sco-005-fa19/hw02-<YOUR-GITHUB-USERNAME>.git```<br/>
  ```cd hw02```

Put your answers to parts 7 and 8 into the text file `solution.md`.

## Submitting your solution

Once you have completed the assignment, you can submit your solution
by pushing the modified code template to GitHub. This can be done by
opening a terminal in the project's root directory and executing the
following commands in the :

```bash
git add .
git commit -m "solution"
git push
```

You can replace "solution" by a more meaningful commit message.

Refresh your browser window pointing at
```
https://github.com/nyu-cso-005-fa19/hw02-<YOUR-GITHUB-USERNAME>/
```
and double-check that your solution has been uploaded correctly.

You can resubmit an updated solution anytime by reexecuting the above
git commands. Though, please remember the rules for submitting
solutions after the homework deadline has passed.


## Part 1: Bits and Bytes (17 Points)

Complete the programming tasks specified in the files
`src/part1.c`.

* Test each part individually by executing
  
  ```bash
  make build/part1
  build/part1
  ```
  and similarly for the other parts.
  
We encourage you to write your own supplementary testing code.

**Hint**: If you want to copy a `float` variable `f` to an `int`
variable `x` while preserving the exact same bit-level representation
(i.e. reinterpreting the bits of `f` as if they were representing an
`int`), then this can be done as follows:

```c
float f = ...;
int x = *((int*) &f);
```


## Part 2: File handling (10 Points)

Write a C program that takes two command line arguments

1. A path to a text file, and

2. one of `-c`, `-w`, `-l`.

Your program should then print:

* the number of characters in the given text file, if the second
  argument is `-c`,
  
* the number of words in the given text file, if the second argument
  is `-w`, and
  
* the number of newlines in the given text file, if the second
  argument is `-l`.

This value should be followed by a single space character (`' '`) and
the given path to the text file. For example, assuming that the
executable of your program is `build/mywc`, then executing

```bash
build/mywc README.md -l
```
should print
```bash
XXX README.md
```
assuming `README.md` is this file.

In general, the output of your program should be *identical* to the
output produced by the `wc` command, given the same command line
arguments (the output of your program is allowed to differ from the
output of `wc` if the command line arguments are not as expected or
some other error occurs).

In the above specification, a word is a maximal sequence of characters
that does not include a white space character. For simplicity, the
only white space characters you need to consider are space (`' '`),
tab (`'\t'`), and newline (`'\n'`). If the last line in the file is
not terminated by a newline character, it is not counted for `-l`.

Make sure that your program handles error cases gracefully (e.g. if
the given file does not exist or the command line arguments are not as
expected).

Put your code into the file `src/mywc.c`. You can compile your code by
running 

```bash
make build/mywc
```

and run it e.g. by calling

```bash
build/mywc README.md -l
```

# Part 3: Two's complement

TODO

# Part 4: IEEE Floating Point

TODO
