# 🧮 C Expression Calculator

<p align="center">
  A lightweight mathematical expression evaluator built from scratch in C.
  <br>
  Featuring a custom lexer and a recursive descent parser.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white" alt="Language: C">
  <img src="https://img.shields.io/badge/Compiler-GCC-00599C?style=for-the-badge&logo=gnu&logoColor=white" alt="Compiler: GCC">
  <img src="https://img.shields.io/badge/Status-In_Development-orange?style=for-the-badge" alt="Status: In Development">
</p>

---

## ✨ Features

- **Interactive REPL** — Continuously evaluate mathematical expressions through a command-line interface.
- **Custom Lexer** — Converts raw input into a sequence of tokens.
- **Recursive Descent Parser** — Parses and evaluates expressions using a grammar-based approach.
- **Operator Precedence** — Correctly handles exponentiation, multiplication, division, addition, and subtraction.
- **Exponentiation** — Supports power operations using the `^` operator.
- **Parentheses** — Supports grouped and nested mathematical expressions.
- **Unary Operators** — Supports unary plus and minus, including consecutive unary operators.
- **Floating-Point Arithmetic** — Handles integer and decimal numbers.
- **Syntax Error Detection** — Identifies invalid characters, unexpected tokens, and missing closing parentheses.

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- A terminal or command prompt

### Compilation

Clone the repository:

```bash
git clone https://github.com/vedrecide/calculator.git
cd calculator
```

Compile the source files:

```bash
gcc -std=c11 -Wall -Wextra main.c lexer.c parser.c -lm -o calculator
```

### Running

**Windows:**

```bash
calculator.exe
```

**Linux / macOS:**

```bash
./calculator
```

## 💻 Usage

Enter mathematical expressions directly into the REPL.

```text
>> 5 + 3 * 2
11.0000

>> (5 + 3) * 2
16.0000

>> 10 / 2 + 3.5
8.5000

>> 100 - (20 + 5) * 2
50.0000

>> -5 + 10
5.0000

>> --(2 + 3)
5.0000

>> 5 * -3
-15.0000

>> 2 ^ 3
8.0000

>> 2 ^ 3 * 4
32.0000

>> (2 + 3) ^ 2
25.0000

>> exit
Goodbye!
```

### Supported Operators

| Operator | Description | Example |
|:---:|---|:---:|
| `+` | Addition / Unary plus | `5 + 3`, `+5` |
| `-` | Subtraction / Unary minus | `10 - 4`, `-5` |
| `*` | Multiplication | `6 * 2` |
| `/` | Division | `15 / 3` |
| `^` | Exponentiation | `2 ^ 3` |
| `()` | Parentheses | `(5 + 3) * 2` |

## ⚙️ How It Works

The calculator processes expressions through two main stages.

### 1. Lexical Analysis

The lexer scans the input and converts it into a sequence of tokens.

For example:

```text
Input: 5 + 3 * 2

NUMBER(5)
PLUS
NUMBER(3)
MULTIPLY
NUMBER(2)
END
```

### 2. Recursive Descent Parsing

The parser uses four functions to understand and evaluate expressions.

| Function | Responsibility |
|---|---|
| `parse_expression()` | Handles addition and subtraction |
| `parse_term()` | Handles multiplication and division |
| `parse_exponents()` | Handles exponentiation |
| `parse_factor()` | Handles numbers, parentheses, and unary operators |

The parser follows this grammar:

```text
expression → term (('+' | '-') term)*
term       → exponents (('*' | '/') exponents)*
exponents  → factor ('^' factor)*
factor     → NUMBER
           | '(' expression ')'
           | ('+' | '-') factor
```

This grammar establishes operator precedence and supports recursive parsing of nested parentheses and unary operators.

**Note:** Exponentiation is currently evaluated left-to-right.

## 📁 Project Structure

```text
calculator/
│
├── main.c          # REPL and program entry point
│
├── lexer.c         # Tokenization implementation
├── lexer.h         # Token definitions and lexer declarations
│
├── parser.c        # Recursive descent parser
├── parser.h        # Parser structure and declarations
│
└── README.md
```

## 🧠 Concepts Explored

This project serves as a practical exploration of:

- Lexical Analysis and Tokenization
- Recursive Descent Parsing
- Context-Free Grammars
- Operator Precedence and Associativity
- Recursion
- Mathematical Expression Evaluation
- Dynamic Memory Allocation
- Pointers and Structures
- Modular Programming in C

## 🛠️ Future Improvements

- [ ] Right-associative exponentiation
- [ ] Mathematical functions (`sqrt`, `sin`, `cos`)
- [ ] Mathematical constants (`pi`, `e`)
- [ ] Modulo operator
- [ ] Division-by-zero handling
- [ ] Improved syntax validation
- [ ] Error recovery without terminating the REPL
- [ ] Memory management and cleanup improvements

---

<p align="center">
  <sub>If you have any improvements, feel free to create a PR :D</sub>
</p>