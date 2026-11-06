# C Expression Calculator

A command-line mathematical expression evaluator built from scratch in C. The project aims to implement a custom lexer and recursive descent parser to understand and evaluate mathematical expressions.

Rather than relying on existing expression-evaluation libraries, this project explores the fundamentals of lexical analysis, parsing, operator precedence, and expression evaluation.

## Features

### Implemented
- [x] Command-line input interface
- [x] Token representation using C structures and enums
- [x] Lexical analysis (tokenization)
- [x] Recognition of arithmetic operators
- [x] Recognition of parentheses
- [x] Integer and floating-point number parsing
- [x] Whitespace handling
- [x] Invalid character detection

### Planned
- [ ] Recursive descent parser
- [ ] Operator precedence and associativity
- [ ] Parenthesized expression evaluation
- [ ] Basic arithmetic operations
- [ ] Exponentiation and modulo
- [ ] Mathematical functions (`sqrt`, `sin`, `cos`, etc.)
- [ ] Mathematical constants (`pi`, `e`)
- [ ] Improved error handling

## Example

The intended calculator interface:

```text
>> 5 + 3 * 2
11

>> (10 + 5) / 3
5

>> 2 ^ 3 + 4
12

>> exit
Goodbye!
```

*Note: Expression evaluation is still under development. The examples above demonstrate the intended functionality.*

## Project Structure

```text
calculator/
│
├── main.c
├── lexer.c
├── lexer.h
├── parser.c
├── parser.h
├── evaluator.c
├── evaluator.h
│
└── README.md
```

The project is being developed using a modular structure:

| Component | Responsibility |
|---|---|
| `main.c` | Command-line interface and user input |
| `lexer.c` | Converts input expressions into tokens |
| `parser.c` | Parses tokens and understands expression structure |
| `evaluator.c` | Evaluates parsed mathematical expressions |

## How It Works

The calculator is designed around three main stages:

**1. Lexical Analysis**

The lexer scans the input expression and converts it into individual tokens.

For example:

```text
Input:  12 + 5 * (3 - 2)

Tokens:
NUMBER(12)
PLUS
NUMBER(5)
MULTIPLY
LPAREN
NUMBER(3)
MINUS
NUMBER(2)
RPAREN
END
```

**2. Parsing**

The parser will process the token sequence using recursive descent parsing, taking operator precedence and parentheses into account.

**3. Evaluation**

The evaluator will perform the mathematical operations and return the final result.

## Technologies

- **Language:** C
- **Standard Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `ctype.h`, `math.h`
- **Build Tools:** GCC / MinGW

## Building and Running

Clone the repository:

```bash
git clone https://github.com/vedrecide/calculator.git
cd calculator
```

Compile the project (adjust source files as implementation progresses):

```bash
gcc main.c lexer.c -o calculator
```

Run:

```bash
./calculator
```

On Windows:

```bash
calculator.exe
```

## Learning Objectives

This project is also an exploration of fundamental computer science concepts through C:

- String manipulation and pointer arithmetic
- Dynamic memory allocation
- Structures, enums, and modular programming
- Lexical analysis and tokenization
- Recursive descent parsing
- Operator precedence and associativity
- Memory management and error handling

## Development Status

<sub>Currently under development 🚧</sub>

The lexer is being implemented and tested. Parser and evaluator components are planned next.

---
