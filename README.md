*This activity has been created as part of the 42 curriculum by **hmuqasqu** and **aborabi**.*

# push_swap

![42 Badge](https://img.shields.io/badge/42-push__swap-000000?style=flat&logo=42&logoColor=white)
![Language](https://img.shields.io/badge/Language-C-blue?style=flat&logo=c)
![Status](https://img.shields.io/badge/Status-Completed-success?style=flat)

## 📖 Description

**push_swap** is a project from the 42 Common Core.

The goal of this project is to sort a stack of integers using a limited set of operations and the smallest possible number of instructions.

The project focuses on algorithm optimization, sorting strategies, and understanding data structures.

The program calculates and displays a sequence of operations that sorts the numbers in ascending order using two stacks: **Stack A** and **Stack B**.

---

## 🎯 Project Objectives

Through this project, I practiced and learned how to:

- Understand and implement sorting algorithms.
- Work with stacks and data structures.
- Manipulate linked lists or other stack representations.
- Optimize algorithm performance.
- Handle command-line arguments.
- Validate input and detect errors.
- Manage memory allocation and deallocation.
- Analyze algorithm complexity.
- Improve problem-solving skills.
- Follow the 42 Norm.

---

## 📋 Instructions

The project must follow the official **42 push_swap subject** and the **42 Norm**.

### General Rules

- The project must be written in C.
- The code must comply with the 42 Norm.
- The program must accept a list of integers as arguments.
- Duplicate numberw3schoolss must be handled as invalid input.
- Invalid arguments must produce an error.
- The program must sort the numbers in ascending order.
- The program must use only the operations allowed by the subject.
- The program must aim to minimize the number of operations.
- Memory must be properly allocated and freed.
- Only functions allowed by the official subject may be used.

---

## 🔄 Allowed Operations

The project provides a limited set of operations to manipulate two stacks.

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of Stack A |
| `sb` | Swap the first two elements of Stack B |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push the top element of Stack B onto Stack A |
| `pb` | Push the top element of Stack A onto Stack B |
| `ra` | Rotate Stack A upward |
| `rb` | Rotate Stack B upward |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate Stack A |
| `rrb` | Reverse rotate Stack B |
| `rrr` | Execute `rra` and `rrb` simultaneously |

---

## 🧠 Sorting Strategy

The objective is to find an efficient sequence of operations to sort the input.

Possible algorithmic concepts involved include:

- Small stack sorting.
- Indexing and ranking values.
- Chunk-based sorting.
- Radix sort.
- Stack rotation optimization.
- Position and cost calculations.

The actual strategy depends on the implementation.

---

## 📁 Project Structure

```text
.
├── algo_sorts
│   ├── chunk_sort.c
│   ├── chunk_utils.c
│   ├── indexing.c
│   ├── selection_sort.c
│   ├── sort_complex.c
│   └── sort_small.c
├── main.c
├── Makefile
├── operations
│   ├── op1.c
│   ├── op2.c
│   ├── op3.c
│   ├── stack_utils2.c
│   └── stack_utils.c
├── parsing
│   ├── ft_split.c
│   ├── parsing.c
│   ├── parsing_utils2.c
│   └── parsing_utils.c
├── push_swap.h
├── README.md
└── strategy_disorder
    ├── disorder.c
    ├── Print_bench.c
    └── strategy.c
```
---

## ⚙️ Compilation

Compile the project:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

---

## 🚀 Usage

Run the program with a list of integers:

```bash
./push_swap 4 67 3 87 23
```

Or pass the numbers as a single string:

```bash
./push_swap "4 67 3 87 23"
```

The program outputs the instructions needed to sort Stack A.

### Example

Input:

```bash
./push_swap 2 1 3 6 5 8
```

Possible output:

```text
sa
pb
ra
pa
```
---

## 🧪 Testing

You can test your program using different inputs:

### Already Sorted

```bash
./push_swap 1 2 3 4 5
```

### Reverse Sorted

```bash
./push_swap 5 4 3 2 1
```

### Random Numbers

```bash
./push_swap 42 7 19 3 88 12 55
```

### Invalid Input

```bash
./push_swap 1 2 2 3
./push_swap 1 abc 3
```

You can also use the 42 checker to verify the correctness of your instructions:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

A successful result should display:

```text
OK
```

---

## 📚 Resources

### Resources

- 42 push_swap Subject
- Programming Advice@
- w3schools

### C Documentation

Useful functions and concepts:

- `malloc()`
- `calloc()`
- `free()`
- `write()`
- `atoi()`
- Linked Lists
- Stacks
- Pointers
- Dynamic Memory Allocation

### Algorithm Resources

- Sorting Algorithms
- Radix Sort
- Binary Representation
- Algorithm Complexity
- Greedy Algorithms
- Stack Operations
- Data Structures

### Useful Documentation

```bash
man 3 malloc
man 3 free
man 2 write
man 3 atoi
```

---

## 🧠 What I Learned

The **push_swap** project helped me understand how to approach algorithmic problems under strict constraints.

The main concepts I practiced were:

- Sorting algorithms.
- Stack manipulation.
- Data structures.
- Algorithm optimization.
- Input validation.
- Memory management.
- Time and space complexity.
- Problem-solving and logical thinking.
- Writing efficient C code.
- Following the 42 Norm.

---

## 🤖 AI Usage

AI tools were used during this project as a learning and assistance resource.

They were mainly used to:

- Clarify algorithmic concepts.
- Explain sorting strategies.
- Understand data structures and stack operations.
- Analyze errors and debugging approaches.
- Explore algorithm optimization techniques.
- Provide documentation and learning resources.

The implementation and final code were written and understood by the authors.*This project has been created as part of the 42 curriculum by hmuqasqu aborabi.*
