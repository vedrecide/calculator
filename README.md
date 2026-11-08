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

- **Interactive REPL** — Continuously evaluate expressions through a command-line interface.
- **Custom Lexer** — Converts raw input into a sequence of tokens.
- **Recursive Descent Parser** — Parses and evaluates expressions using a grammar-based approach.
- **Operator Precedence** — Correctly handles multiplication and division before addition and subtraction.
- **Parentheses** — Supports grouped and nested mathematical expressions.
- **Floating-Point Arithmetic** — Handles both integer and decimal numbers.
- **Syntax Error Detection** — Identifies invalid characters and unexpected tokens.

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
gcc -std=c11 -Wall -Wextra main.c lexer.c parser.c -o calculator
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

>> exit
Goodbye!
```

### Supported Operators

| Operator | Description | Example |
|:---:|---|:---:|
| `+` | Addition | `5 + 3` |
| `-` | Subtraction | `10 - 4` |
| `*` | Multiplication | `6 * 2` |
| `/` | Division | `15 / 3` |
| `()` | Parentheses | `(5 + 3) * 2` |

## ⚙️ How It Works

The calculator processes expressions in two stages.

### 1. Lexical Analysis

The lexer scans the input and converts it into tokens.

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

The parser uses three functions to understand and evaluate the expression.

| Function | Responsibility |
|---|---|
| `parse_expression()` | Handles addition and subtraction |
| `parse_term()` | Handles multiplication and division |
| `parse_factor()` | Handles numbers and parenthesized expressions |

The parser follows this grammar:

```text
expression → term (('+' | '-') term)*
term       → factor (('*' | '/') factor)*
factor     → NUMBER | '(' expression ')'
```

This structure naturally enforces mathematical operator precedence.

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
- Dynamic Memory Allocation
- Pointers and Structures
- Modular Programming in C

## 🛠️ Future Improvements

- [ ] Unary operators (`-5`, `+3`)
- [ ] Exponentiation and modulo
- [ ] Mathematical functions (`sqrt`, `sin`, `cos`)
- [ ] Mathematical constants (`pi`, `e`)
- [ ] Division-by-zero handling
- [ ] Improved syntax validation and error recovery
- [ ] Better error messages without terminating the REPL

---

<p align="center">
  <sub>If you have any improvements, feel free to create a PR :D</sub>
</p>