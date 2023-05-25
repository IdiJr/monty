# Monty
`monty` is an interpreter of Monty ByteCodes files, which is a scripting language just like Python.

## About the Monty language
Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

## Usage
To compile all files:

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$
```

The **synopsis** of the interpreter is the following:

```bash
$ ./monty [filename]
$
```

## Authors
* Ali Baba Idi: [GitHub](https://github.com/IdiJr)
