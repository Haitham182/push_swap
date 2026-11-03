*This project was created as part of the 42 curriculum by **hmuqasqu** and **aborabi**.*

![42 Badge](https://img.shields.io/badge/42-push__swap-000000?style=flat&logo=42&logoColor=white)
![Language](https://img.shields.io/badge/Language-C-blue?style=flat&logo=c)
![Status](https://img.shields.io/badge/Status-Completed-success?style=flat)

## 📖 Description

**push_swap** is a sorting algorithm project from the 42 Common Core.

The objective is to sort a stack of integers in ascending order using a limited set of stack operations while minimizing the total number of instructions.

The program works with two stacks:

- **Stack A:** Initially contains all input integers.
- **Stack B:** Initially empty and used as temporary storage during sorting.

Unlike traditional sorting algorithms, push_swap does not directly modify array elements. Instead, it generates a sequence of instructions that manipulate the two stacks until Stack A is sorted and Stack B is empty.

This project focuses on algorithm design, data structures, optimization, complexity analysis, input validation, and memory management.

---



## 🎯 Project Objectives

Through this project, we practiced and developed our understanding of:


- Sorting algorithms and algorithmic optimization.
- Stack manipulation and data structures.
- Doubly linked lists and pointer management.
- Algorithm complexity (Time and Space Complexity).
- Binary representation and bitwise operations.
- Input parsing and error handling.
- Dynamic memory allocation and deallocation.
- Adaptive algorithm selection.
- Writing efficient and maintainable C code.
- Following the 42 Norm.

---


## ⚙️ How push_swap Works

The program receives a sequence of integers and generates instructions to sort them.

The general workflow is:

```text
              Input Arguments
                     |
                     v
             Parsing & Validation
                     |
                     v

              Initialize Stack A
                     |
                     v
              Assign Indexes
                     |
                     v
             Calculate Disorder
                     |
                     v
            Select Sorting Strategy
                     |
          +----------+----------+
          |          |          |

          v          v          v
       Simple      Medium     Complex
          |          |          |
          v          v          v
     Selection     Chunk      Radix
       Sort         Sort       Sort
          |          |          |
          +----------+----------+
                     |
                     v
             Generated Operations
                     |
                     v

             Stack A is Sorted
             Stack B is Empty
```

The program uses a strategy selection mechanism to choose an appropriate sorting approach depending on the disorder of the input.

---

## 🔄 Allowed Operations

The project provides eleven operations to manipulate the two stacks.

| Operation | Description |

|---|---|
| `sa` | Swap the first two elements of Stack A. |
| `sb` | Swap the first two elements of Stack B. |
| `ss` | Execute `sa` and `sb` simultaneously. |
| `pa` | Push the top element of Stack B onto Stack A. |
| `pb` | Push the top element of Stack A onto Stack B. |
| `ra` | Rotate Stack A upward. |
| `rb` | Rotate Stack B upward. |

| `rr` | Execute `ra` and `rb` simultaneously. |
| `rra` | Reverse rotate Stack A. |
| `rrb` | Reverse rotate Stack B. |
| `rrr` | Execute `rra` and `rrb` simultaneously. |

### Understanding Stack Operations

Consider the following Stack A:

```text
A:
  3
  8

  1
  5
```

**Swap (`sa`)**

Swaps the first two elements:

```text
Before:       After:


  3             8
  8             3
  1             1
  5             5
```


**Push (`pb`)**

Moves the first element of A to B:

```text
Before:       After:


A: 3          A: 8
   8             1
   1             5

B: empty      B: 3
```

**Rotate (`ra`)**

Moves the first element to the bottom:

```text
Before:       After:

  3             8
  8             1

  1             5
  5             3
```

**Reverse Rotate (`rra`)**

Moves the last element to the top:

```text
Before:       After:

  3             5
  8             3
  1             8
  5             1
```

---


## 🧠 Sorting Algorithms

One of the most important parts of this project is choosing an appropriate sorting algorithm.

Different input sequences require different approaches. A strategy that performs well with a small number of elements might be inefficient with hundreds of elements.

Our implementation includes several sorting approaches.

### 1. Small Sorting

Small sorting handles inputs containing only a few elements.

For very small stacks, implementing a complicated algorithm is unnecessary. Instead, we use simple conditional logic to identify the current arrangement and apply the required
 operations.

For example, with three elements, there are only six possible permutations:

```text
1 2 3   Already sorted

1 3 2   Needs rearrangement

2 1 3   Needs rearrangement

2 3 1   Needs rearrangement


3 1 2   Needs rearrangement

3 2 1   Needs rearrangement
```

By checking the positions of the elements, we can determine the appropriate operations without running a general-purpose sorting algorithm.

**Why use it?**

- Very few operations for small inputs.
- No unnecessary loops.
- Simple implementation.
- Better performance than using a general sorting strategy for tiny stacks.

### 2. Selection Sort

Selection Sort is a comparison-based sorting algorithm.

The main idea is to repeatedly find the smallest element and move it into its correct position.

In a two-stack implementation, the general approach is:

1. Find the smallest element in Stack A.
2. Calculate its position.
3. Move it to the top using rotations.
4. Push it to Stack B using `pb`.
5. Repeat until the required elements have been extracted.
6. Push the elements back to Stack A using `pa`.

**Example**

Initial Stack A:

```text
A: 4  2  5  1  3

B: empty
```

First, locate the smallest element:


```text
Smallest = 1
```

Rotate Stack A until `1` reaches the top:

```text
A: 1  3  4  2  5
```

Push it to B:

```text
A: 3  4  2  5

B: 1

```

Repeat the process to extract the remaining elements in the required order.

The final result is:

```text
A: 1  2  3  4  5

B: empty
```

**Complexity**

- Time Complexity: O(n²) in a straightforward implementation.

The actual number of push_swap instructions also depends on the number and direction of rotations.


### 3. Chunk-Based Sorting

Chunk-based sorting is designed to improve sorting performance for medium and large inputs.

Instead of repeatedly searching for the smallest element, we divide the sorted index range into smaller groups called **chunks**.

The general idea is to distribute elements from Stack A into Stack B according to their indexes.

#### Step 1: Divide the Elements into Chunks

First, determine the number of chunks.

A common approach is to use the square root of the input size:


For example, with 100 elements:

\[
\sqrt{100} = 10
\]

We can divide the indexes into approximately ten groups.

Each chunk represents a range of indexes.

```text
Chunk 0:   0 - 9
Chunk 1:  10 - 19
Chunk 2:  20 - 29
Chunk 3:  30 - 39
Chunk 4:  40 - 49
Chunk 5:  50 - 59
Chunk 6:  60 - 69
Chunk 7:  70 - 79
Chunk 8:  80 - 89
Chunk 9:  90 - 99
```

#### Step 2: Distribute Elements to Stack B

We examine the indexes in Stack A.

When an element belongs to the current chunk, we move it to Stack B using `pb`.

Otherwise, we rotate Stack A using
 `ra` to examine the next element.

Conceptually:

```text
             Stack A
                |
                v
       Check element index
                |
         +------+------+
         |             |
      In Chunk      Not in Chunk
         |             |

         v             v
        pb             ra
         |             |
         v             |
      Stack B          |
         |             |
         +-------------+
                |
                v
          Next Element
```

This process continues until the elements belonging to the current chunk have been distributed.

Then we move to the next chunk.

#### Step 3: Push Elements Back to Stack A

After distributing the elements, Stack B contains the values that need to be returned to A.

The next objective is to extract the largest remaining index from Stack B.

For each extraction:

1. Find the largest index in B.
2. Determine its position.
3. Decide whether `rb` or `rrb` requires fewer rotations.
4. Rotate the element to the top.
5. Execute `pa` to return it to Stack A.

This process continues until Stack B becomes empty.

The resulting Stack A is sorted in ascending order.

**Why use Chunk Sort?**

- Reduces unnecessary element searches compared with basic selection sorting.
- Groups elements by index ranges.
- Uses both stacks efficiently.
- Provides a practical strategy for medium-sized inputs.

**Complexity**

- Time Complexity: O(n√n) in a straightforward implementation.


### 4. Binary Radix Sort

Radix Sort is a non-comparison-based sorting algorithm.

Instead of comparing elements directly, it sorts them according to individual digits or bits.

Our complex sorting strategy uses **Binary Radix Sort**, which processes the binary representation of each element's index.

This is especially useful for larger inputs because it provides predictable behavior.

#### Step 1: Indexing

Before applying Radix Sort, we assign an index to every element.

The index represents the element's position in the sorted order.

For example:

```text
Original Numbers:

  40   10   30   50   20

After Indexing:

  3    0    2    4    1
```

The smallest number receives index `0`, the second smallest receives index `1`, and so on.

This technique is also called coordinate compression.

It is important because the algorithm now works with a small range of non-negative integers instead of arbitrary integer values.

#### Step 2: Convert Indexes to Binary

Each index can be represented using binary digits.

For the previous example:

| Index | Binary |
|---|---|
| 0 | 000 |
| 1 | 001 |
| 2 | 010 |
| 3 | 011 |
| 4 | 100 |

Radix Sort examines these bits starting from the least significant bit (LSB).

#### Step 3: Determine the Number of Bits

We calculate how many bits are required to represent the largest index.

For `n` elements, the maximum index is `n - 1`.

For example, with 100 elements:

\[
max\_index = 99
\]

Since:

\[
99 = 1100011
\]

We need seven bits.

Therefore, the algorithm performs 
seven passes.

#### Step 4: Process Each Bit

For every pass, we examine the current bit of the top element in Stack A.

There are two possible cases:

**Case 1: The current bit is 0**

Move the element from A to B:

```text
pb
```

**Case 2: The current bit is 1**

Rotate Stack A:


```text
ra
```

This ensures that elements with a zero bit are temporarily separated from those with a one bit.

#### Step 5: Return Elements to Stack A

After processing every element for the current bit, all elements in B are pushed back to A using:

## 📁 Project Structure

```text
.
├── algo_sorts/

│   ├── chunk_sort.c
│   ├── chunk_utils.c
│   ├── indexing.c
│   ├── selection_sort.c
│   ├── sort_complex.c
│   └── sort_small.c
│
├── main.c
├── Makefile
│
├── operations/
│   ├── op1.c
│   ├── op2.c
│   ├── op3.c
│   ├── stack_utils.c
│   └── stack_utils2.c
│
├── parsing/

│   ├── ft_split.c
│   ├── parsing.c
│   ├── parsing_utils.c
│   └── parsing_utils2.c
│
├── push_swap.h
├── README.md
│
└── strategy_disorder/
    ├── disorder.c
    ├── Print_bench.c
    └── strategy.c
```


#### Example: One Radix Pass

Consider:

```text
A: 4  0  3  1  2
B: empty
```

We examine the least significant bit (bit 0).

| Index | Binary | Bit 0 | Operation |
|---|---|---|---|
| 4 | 100 | 0 | pb |
| 0 | 000 | 0 | pb |
| 3 | 011 | 1 | ra |
| 1 | 001 | 1 | ra |
| 2 | 010 | 0 | pb |

After processing all five elements
:

```text
A: 3  1

B: 2  0  4
```

Now return the elements from B:

```text
pa
pa
pa
```


The resulting Stack A:

```text
A: 4  0  2  3  1
```

Notice that elements with bit `0` were moved to B and then returned before elements with bit `1` that were rotated in A.

This completes the first pass.

The algorithm repeats the same procedure for bit 1, bit 2, and any remaining bits.

After all passes, the indexes are sorted.

#### Understanding the Bitwise Condition


The central operation in our implementation is:

```c
(data->a->head->index >> i) & 1
```

Let's break it down.

**1. Right Shift (`>>`)**

```c
index >> i
```

Moves the binary bits to the right by `i` positions.


For example:

```text
index = 5

Binary: 101

5 >> 0 = 101
5 >> 1 = 010
5 >> 2 = 001
```

**2. Bitwise AND (`&`)**

```c
value & 1
```

Checks the least significant bit.

- Result `0`: The bit is zero.
- Result `1`: The bit is one.

Combining both operations allows us to inspect any individual bit.

For example:

```c
(index >> 2) & 1
```

Checks bit number 2.

#### Understanding the Implementation

The following function represents the core logic of our Radix Sort:

```c
static void radix_pass(t_data *dat
a, int size, int max_bits)
{
    int i;
    int j;

    i = -1;
    while (++i < max_bits)
    {
        j = -1;
        while (++j < size)
        {
            if ((data->a->head->index >> i) & 1)
                op_ra(data);
            else
                op_pb(data);
        }
        while (data->b && data->b->size > 0)
            op_pa(data);
    }
}
```

The outer loop processes the bits.

The inner loop processes every element.

The final loop returns all elements from B to A.

**Complexity**

- Time Complexity: O(n log n).


Consequently, the total operation count depends on the number of zero bits across the indexes.

---

## 📊 Algorithm Complexity Comparison

| Algorithm | Time Complexity | Main Use |
|---|---|---|
| Small Sort | Constant for a fixed small input size | Very small inputs |
| Selection Sort | O(n²) |
| Chunk Sort | O(n√n) | Medium/large inputs |
| Binary Radix Sort | O(n log n) | Large inputs |

The complexities describe the general algorithmic work. Push_swap operation counts are a separate performance measure because each stack instruction has a specific cost.

---

## 📈 Disorder Calculation

One of the important features of our project is measuring how disordered the input sequence is before selecting a sorting strategy.

Disorder represents how far the current sequence is from being sorted.

A sequence that is already sorted has minimal disorder, while a sequence with many elements in the wrong relative order has greater disorder.

For example:

```text
Low Disorder:

1  2  3  5  4  6  7  8

High Disorder:

8  2  6  1  7  3  5  4
```

The disorder measurement helps the program decide which sorting strategy is more appropriate.

It is used as an input characteristic, not as a replacement for the sorting algorithm itself.

---

## 🧠 Adaptive Strategy Selection

Instead of always using the same sorting algorithm, our implementation includes an adaptive strategy mechanism.

The program calculates the disorder value and uses it to determine which strategy to execute.


The strategy selection follows these thresholds:

| Disorder | Selected Strategy |
|---|---|
| Less than 0.2 | SIMPLE |
| From 0.2 to less than 0.5 | MEDIUM |
| 0.5 or greater | COMPLEX |

The general decision process:

```text
             Calculate Disorder
                     |
                     v
             Is disorder < 0.2?
                /        \
              Yes         No
              |            |
              v            v
           SIMPLE      disorder < 0.5?
                       /        \
                     Yes         No
                     |            |
                     v            v
                   MEDIUM       COMPLEX
```

The purpose of adaptive selection is to avoid applying an unnecessarily expensive strategy when the input is already close to sorted.

### Why Adaptive Sorting?

Consider three different inputs:

**Input A:**

```text
1 2 3 4 5 6 8 7
```

This sequence is almost sorted. A simple strategy may be sufficient.

**Input B:**

```text
3 1 2 6 4 5 8 7
```

This sequence has a moderate level of disorder. A medium strategy may be more suitable.

**Input C:**

```text
8 3 6 1 7 2 5 4

```

This sequence has a higher level of disorder. A more systematic strategy such as Radix Sort may be preferable.

The main advantage is that the program does not need to use one sorting algorithm for every possible input.

---

## 📁 Project Structure

```text
.
├── algo_sorts
│   ├── chunk_sort.c
│   ├── chunk_utils.c
│   ├── indexing.c
│   ├── selection_sort.c
│   ├── sort_complex.c
│   └── sort_small.c
│
├── main.c
├── Makefile
├── push_swap.h
│
├── operations
│   ├── op1.c
│   ├── op2.c
│   ├── op3.c
│   ├── stack_utils.c
│   └── stack_utils2.c
│
├── parsing
│   ├── ft_split.c
│   ├── parsing.c
│   ├── parsing_utils.c
│   └── parsing_utils2.c
│
└── strategy_disorder
    ├── disorder.c
    ├── Print_bench.c
    └── strategy.c
```

### Directory Responsibilities

**algo_sorts/**

Contains the sorting algorithms, indexing functionality, and helper functions used by the sorting strategies.

**operations/**

Contains the implementation of the allowed stack operations and stack utility functions.

**parsing/**

Handles command-line arguments, splitting input strings, integer conversion, and input validation.

**strategy_disorder/**

Contains the disorder calculation, strategy selection, and benchmarking output.

**push_swap.h**

Contains shared structures, function prototypes, and project definitions.

---

## 🛡️ Input Parsing and Validation

Before sorting, the program must ensure that all arguments are valid.

The program handles:

- Valid positive and negative integers.
- Multiple arguments.
- Numbers provided inside a quoted string.
- Empty or invalid arguments.
- Duplicate numbers.
- Non-numeric characters.
- Integer overflow and underflow.
- Values outside the `int` range.

Examples of invalid input:

```bash
./push_swap 1 2 2 3
./push_swap 1 abc 3
./push_swap 2147483648
./push_swap -2147483649
```

Invalid input must produce:

```text
Error
```

The program must also avoid generating unnecessary operations when the input is already sorted.

---

## 🧱 Data Structures

Our implementation uses linked-list-based stacks.

Each node stores the integer value, its corresponding index, and pointers to neighboring nodes.

Conceptually:

```c
typedef struct s_node
{
    int             number;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;
```

The stack maintains information such as:

- `head`: Pointer to the first node.
- `last`: Pointer to the last node.
- `size`: Number of elements in the stack.

Using a doubly linked list provides access to both the next and previous nodes.

This is particularly useful when implementing rotations and reverse rotations.

---

## ⚙️ Compilation

Clone the repository:

```bash
git clone <repository-url>
cd push_swap
```

Compile:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove object files and the executable:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

---

## 🚀 Usage

Run the program with individual arguments:

```bash
./push_swap 4 67 3 87 23
```

Or provide the numbers as a single quoted string:

```bash
./push_swap "4 67 3 87 23"
```

The program outputs the operations required to sort Stack A.

### Example

Input:

```bash
./push_swap 2 1 3 6 5 8
```

Possible output:

```text
sa
```

The exact output depends on the selected strategy and implementation.

---

## 🧪 Testing

Testing is essential to ensure both correctness and efficiency.

### Already Sorted

```bash
./push_swap 1 2 3 4 5
```

Expected behavior: No operations are necessary.

### Reverse Sorted

```bash
./push_swap 5 4 3 2 1
```

### Random Numbers

```bash
./push_swap 42 7 19 3 88 12 55
```


### Using the Checker

The 42 checker verifies whether the generated operations correctly sort the input.

```bash
ARG="4 67 3 87 23"

./push_swap $ARG | ./checker_linux $ARG
```*This project was created as part of the 42 curriculum by **hmuqasqu** and **aborabi**.*

![42 Badge](https://img.shields.io/badge/42-push__swap-000000?style=flat&logo=42&logoColor=white)
![Language](https://img.shields.io/badge/Language-C-blue?style=flat&logo=c)
![Status](https://img.shields.io/badge/Status-Completed-success?style=flat)

## 📖 Description

**push_swap** is a sorting algorithm project from the 42 Common Core.

The objective is to sort a stack of integers in ascending order using a limited set of stack operations while minimizing the total number of instructions.

The program works with two stacks:

- **Stack A:** Initially contains all input integers.
- **Stack B:** Initially empty and used as temporary storage during sorting.

Unlike traditional sorting algorithms, push_swap does not directly modify array elements. Instead, it generates a sequence of instructions that manipulate the two stacks until Stack A is sorted and Stack B is empty.

This project focuses on algorithm design, data structures, optimization, complexity analysis, input validation, and memory management.

---



## 🎯 Project Objectives

Through this project, we practiced and developed our understanding of:


- Sorting algorithms and algorithmic optimization.
- Stack manipulation and data structures.
- Doubly linked lists and pointer management.
- Algorithm complexity (Time and Space Complexity).
- Binary representation and bitwise operations.
- Input parsing and error handling.
- Dynamic memory allocation and deallocation.
- Adaptive algorithm selection.
- Writing efficient and maintainable C code.
- Following the 42 Norm.

---


## ⚙️ How push_swap Works

The program receives a sequence of integers and generates instructions to sort them.

The general workflow is:

```text
              Input Arguments
                     |
                     v
             Parsing & Validation
                     |
                     v

              Initialize Stack A
                     |
                     v
              Assign Indexes
                     |
                     v
             Calculate Disorder
                     |
                     v
            Select Sorting Strategy
                     |
          +----------+----------+
          |          |          |

          v          v          v
       Simple      Medium     Complex
          |          |          |
          v          v          v
     Selection     Chunk      Radix
       Sort         Sort       Sort
          |          |          |
          +----------+----------+
                     |
                     v
             Generated Operations
                     |
                     v

             Stack A is Sorted
             Stack B is Empty
```

The program uses a strategy selection mechanism to choose an appropriate sorting approach depending on the disorder of the input.

---

## 🔄 Allowed Operations

The project provides eleven operations to manipulate the two stacks.

| Operation | Description |

|---|---|
| `sa` | Swap the first two elements of Stack A. |
| `sb` | Swap the first two elements of Stack B. |
| `ss` | Execute `sa` and `sb` simultaneously. |
| `pa` | Push the top element of Stack B onto Stack A. |
| `pb` | Push the top element of Stack A onto Stack B. |
| `ra` | Rotate Stack A upward. |
| `rb` | Rotate Stack B upward. |

| `rr` | Execute `ra` and `rb` simultaneously. |
| `rra` | Reverse rotate Stack A. |
| `rrb` | Reverse rotate Stack B. |
| `rrr` | Execute `rra` and `rrb` simultaneously. |

### Understanding Stack Operations

Consider the following Stack A:

```text
A:
  3
  8

  1
  5
```

**Swap (`sa`)**

Swaps the first two elements:

```text
Before:       After:


  3             8
  8             3
  1             1
  5             5
```


**Push (`pb`)**

Moves the first element of A to B:

```text
Before:       After:


A: 3          A: 8
   8             1
   1             5

B: empty      B: 3
```

**Rotate (`ra`)**

Moves the first element to the bottom:

```text
Before:       After:

  3             8
  8             1

  1             5
  5             3
```

**Reverse Rotate (`rra`)**

Moves the last element to the top:

```text
Before:       After:

  3             5
  8             3
  1             8
  5             1
```

---


## 🧠 Sorting Algorithms

One of the most important parts of this project is choosing an appropriate sorting algorithm.

Different input sequences require different approaches. A strategy that performs well with a small number of elements might be inefficient with hundreds of elements.

Our implementation includes several sorting approaches.

### 1. Small Sorting

Small sorting handles inputs containing only a few elements.

For very small stacks, implementing a complicated algorithm is unnecessary. Instead, we use simple conditional logic to identify the current arrangement and apply the required
 operations.

For example, with three elements, there are only six possible permutations:

```text
1 2 3   Already sorted

1 3 2   Needs rearrangement

2 1 3   Needs rearrangement

2 3 1   Needs rearrangement


3 1 2   Needs rearrangement

3 2 1   Needs rearrangement
```

By checking the positions of the elements, we can determine the appropriate operations without running a general-purpose sorting algorithm.

**Why use it?**

- Very few operations for small inputs.
- No unnecessary loops.
- Simple implementation.
- Better performance than using a general sorting strategy for tiny stacks.

### 2. Selection Sort

Selection Sort is a comparison-based sorting algorithm.

The main idea is to repeatedly find the smallest element and move it into its correct position.

In a two-stack implementation, the general approach is:

1. Find the smallest element in Stack A.
2. Calculate its position.
3. Move it to the top using rotations.
4. Push it to Stack B using `pb`.
5. Repeat until the required elements have been extracted.
6. Push the elements back to Stack A using `pa`.

**Example**

Initial Stack A:

```text
A: 4  2  5  1  3

B: empty
```

First, locate the smallest element:


```text
Smallest = 1
```

Rotate Stack A until `1` reaches the top:

```text
A: 1  3  4  2  5
```

Push it to B:

```text
A: 3  4  2  5

B: 1

```

Repeat the process to extract the remaining elements in the required order.

The final result is:

```text
A: 1  2  3  4  5

B: empty
```

**Complexity**

- Time Complexity: O(n²) in a straightforward implementation.

The actual number of push_swap instructions also depends on the number and direction of rotations.


### 3. Chunk-Based Sorting

Chunk-based sorting is designed to improve sorting performance for medium and large inputs.

Instead of repeatedly searching for the smallest element, we divide the sorted index range into smaller groups called **chunks**.

The general idea is to distribute elements from Stack A into Stack B according to their indexes.

#### Step 1: Divide the Elements into Chunks

First, determine the number of chunks.

A common approach is to use the square root of the input size:


For example, with 100 elements:

\[
\sqrt{100} = 10
\]

We can divide the indexes into approximately ten groups.

Each chunk represents a range of indexes.

```text
Chunk 0:   0 - 9
Chunk 1:  10 - 19
Chunk 2:  20 - 29
Chunk 3:  30 - 39
Chunk 4:  40 - 49
Chunk 5:  50 - 59
Chunk 6:  60 - 69
Chunk 7:  70 - 79
Chunk 8:  80 - 89
Chunk 9:  90 - 99
```

#### Step 2: Distribute Elements to Stack B

We examine the indexes in Stack A.

When an element belongs to the current chunk, we move it to Stack B using `pb`.

Otherwise, we rotate Stack A using
 `ra` to examine the next element.

Conceptually:

```text
             Stack A
                |
                v
       Check element index
                |
         +------+------+
         |             |
      In Chunk      Not in Chunk
         |             |

         v             v
        pb             ra
         |             |
         v             |
      Stack B          |
         |             |
         +-------------+
                |
                v
          Next Element
```

This process continues until the elements belonging to the current chunk have been distributed.

Then we move to the next chunk.

#### Step 3: Push Elements Back to Stack A

After distributing the elements, Stack B contains the values that need to be returned to A.

The next objective is to extract the largest remaining index from Stack B.

For each extraction:

1. Find the largest index in B.
2. Determine its position.
3. Decide whether `rb` or `rrb` requires fewer rotations.
4. Rotate the element to the top.
5. Execute `pa` to return it to Stack A.

This process continues until Stack B becomes empty.

The resulting Stack A is sorted in ascending order.

**Why use Chunk Sort?**

- Reduces unnecessary element searches compared with basic selection sorting.
- Groups elements by index ranges.
- Uses both stacks efficiently.
- Provides a practical strategy for medium-sized inputs.

**Complexity**

- Time Complexity: O(n√n) in a straightforward implementation.


### 4. Binary Radix Sort

Radix Sort is a non-comparison-based sorting algorithm.

Instead of comparing elements directly, it sorts them according to individual digits or bits.

Our complex sorting strategy uses **Binary Radix Sort**, which processes the binary representation of each element's index.

This is especially useful for larger inputs because it provides predictable behavior.

#### Step 1: Indexing

Before applying Radix Sort, we assign an index to every element.

The index represents the element's position in the sorted order.

For example:

```text
Original Numbers:

  40   10   30   50   20

After Indexing:

  3    0    2    4    1
```

The smallest number receives index `0`, the second smallest receives index `1`, and so on.

This technique is also called coordinate compression.

It is important because the algorithm now works with a small range of non-negative integers instead of arbitrary integer values.

#### Step 2: Convert Indexes to Binary

Each index can be represented using binary digits.

For the previous example:

| Index | Binary |
|---|---|
| 0 | 000 |
| 1 | 001 |
| 2 | 010 |
| 3 | 011 |
| 4 | 100 |

Radix Sort examines these bits starting from the least significant bit (LSB).

#### Step 3: Determine the Number of Bits

We calculate how many bits are required to represent the largest index.

For `n` elements, the maximum index is `n - 1`.

For example, with 100 elements:

\[
max\_index = 99
\]

Since:

\[
99 = 1100011
\]

We need seven bits.

Therefore, the algorithm performs 
seven passes.

#### Step 4: Process Each Bit

For every pass, we examine the current bit of the top element in Stack A.

There are two possible cases:

**Case 1: The current bit is 0**

Move the element from A to B:

```text
pb
```

**Case 2: The current bit is 1**

Rotate Stack A:


```text
ra
```

This ensures that elements with a zero bit are temporarily separated from those with a one bit.

#### Step 5: Return Elements to Stack A

After processing every element for the current bit, all elements in B are pushed back to A using:

## 📁 Project Structure

```text
.
├── algo_sorts/

│   ├── chunk_sort.c
│   ├── chunk_utils.c
│   ├── indexing.c
│   ├── selection_sort.c
│   ├── sort_complex.c
│   └── sort_small.c
│
├── main.c
├── Makefile
│
├── operations/
│   ├── op1.c
│   ├── op2.c
│   ├── op3.c
│   ├── stack_utils.c
│   └── stack_utils2.c
│
├── parsing/

│   ├── ft_split.c
│   ├── parsing.c
│   ├── parsing_utils.c
│   └── parsing_utils2.c
│
├── push_swap.h
├── README.md
│
└── strategy_disorder/
    ├── disorder.c
    ├── Print_bench.c
    └── strategy.c
```


#### Example: One Radix Pass

Consider:

```text
A: 4  0  3  1  2
B: empty
```

We examine the least significant bit (bit 0).

| Index | Binary | Bit 0 | Operation |
|---|---|---|---|
| 4 | 100 | 0 | pb |
| 0 | 000 | 0 | pb |
| 3 | 011 | 1 | ra |
| 1 | 001 | 1 | ra |
| 2 | 010 | 0 | pb |

After processing all five elements
:

```text
A: 3  1

B: 2  0  4
```

Now return the elements from B:

```text
pa
pa
pa
```


The resulting Stack A:

```text
A: 4  0  2  3  1
```

Notice that elements with bit `0` were moved to B and then returned before elements with bit `1` that were rotated in A.

This completes the first pass.

The algorithm repeats the same procedure for bit 1, bit 2, and any remaining bits.

After all passes, the indexes are sorted.

#### Understanding the Bitwise Condition


The central operation in our implementation is:

```c
(data->a->head->index >> i) & 1
```

Let's break it down.

**1. Right Shift (`>>`)**

```c
index >> i
```

Moves the binary bits to the right by `i` positions.


For example:

```text
index = 5

Binary: 101

5 >> 0 = 101
5 >> 1 = 010
5 >> 2 = 001
```

**2. Bitwise AND (`&`)**

```c
value & 1
```

Checks the least significant bit.

- Result `0`: The bit is zero.
- Result `1`: The bit is one.

Combining both operations allows us to inspect any individual bit.

For example:

```c
(index >> 2) & 1
```

Checks bit number 2.

#### Understanding the Implementation

The following function represents the core logic of our Radix Sort:

```c
static void radix_pass(t_data *dat
a, int size, int max_bits)
{
    int i;
    int j;

    i = -1;
    while (++i < max_bits)
    {
        j = -1;
        while (++j < size)
        {
            if ((data->a->head->index >> i) & 1)
                op_ra(data);
            else
                op_pb(data);
        }
        while (data->b && data->b->size > 0)
            op_pa(data);
    }
}
```

The outer loop processes the bits.

The inner loop processes every element.

The final loop returns all elements from B to A.

**Complexity**

- Time Complexity: O(n log n).


Consequently, the total operation count depends on the number of zero bits across the indexes.

---

## 📚 Resources

- [42 Push_swap Subject](https://cdn.intra.42.fr/pdf/pdf/960/push_swap.en.pdf) — Official project subject and requirements.
- [GeeksforGeeks – Radix Sort](https://www.geeksforgeeks.org/dsa/radix-sort/) — Understanding Radix Sort.
- [GeeksforGeeks – Selection Sort](https://www.geeksforgeeks.org/dsa/selection-sort/) — Understanding Selection Sort.
- [GeeksforGeeks – Linked Lists](https://www.geeksforgeeks.org/c/linked-list-in-c/) — Learning linked lists in C.
- [cppreference](https://en.cppreference.com/w/c) — C language documentation.
- [42 Norminette](https://github.com/42School/norminette) — Official Norminette repository.

## 📊 Algorithm Complexity Comparison

| Algorithm | Time Complexity | Main Use |
|---|---|---|
| Small Sort | Constant for a fixed small input size | Very small inputs |
| Selection Sort | O(n²) |
| Chunk Sort | O(n√n) | Medium/large inputs |
| Binary Radix Sort | O(n log n) | Large inputs |

The complexities describe the general algorithmic work. Push_swap operation counts are a separate performance measure because each stack instruction has a specific cost.

---

## 📈 Disorder Calculation

One of the important features of our project is measuring how disordered the input sequence is before selecting a sorting strategy.

Disorder represents how far the current sequence is from being sorted.

A sequence that is already sorted has minimal disorder, while a sequence with many elements in the wrong relative order has greater disorder.

For example:

```text
Low Disorder:

1  2  3  5  4  6  7  8

High Disorder:

8  2  6  1  7  3  5  4
```

The disorder measurement helps the program decide which sorting strategy is more appropriate.

It is used as an input characteristic, not as a replacement for the sorting algorithm itself.

---

## 🧠 Adaptive Strategy Selection

Instead of always using the same sorting algorithm, our implementation includes an adaptive strategy mechanism.

The program calculates the disorder value and uses it to determine which strategy to execute.


The strategy selection follows these thresholds:

| Disorder | Selected Strategy |
|---|---|
| Less than 0.2 | SIMPLE |
| From 0.2 to less than 0.5 | MEDIUM |
| 0.5 or greater | COMPLEX |

The general decision process:

```text
             Calculate Disorder
                     |
                     v
             Is disorder < 0.2?
                /        \
              Yes         No
              |            |
              v            v
           SIMPLE      disorder < 0.5?
                       /        \
                     Yes         No
                     |            |
                     v            v
                   MEDIUM       COMPLEX
```

The purpose of adaptive selection is to avoid applying an unnecessarily expensive strategy when the input is already close to sorted.

### Why Adaptive Sorting?

Consider three different inputs:

**Input A:**

```text
1 2 3 4 5 6 8 7
```

This sequence is almost sorted. A simple strategy may be sufficient.

**Input B:**

```text
3 1 2 6 4 5 8 7
```

This sequence has a moderate level of disorder. A medium strategy may be more suitable.

**Input C:**

```text
8 3 6 1 7 2 5 4

```

This sequence has a higher level of disorder. A more systematic strategy such as Radix Sort may be preferable.

The main advantage is that the program does not need to use one sorting algorithm for every possible input.

---

## 📁 Project Structure

```text
.
├── algo_sorts
│   ├── chunk_sort.c
│   ├── chunk_utils.c
│   ├── indexing.c
│   ├── selection_sort.c
│   ├── sort_complex.c
│   └── sort_small.c
│
├── main.c
├── Makefile
├── push_swap.h
│
├── operations
│   ├── op1.c
│   ├── op2.c
│   ├── op3.c
│   ├── stack_utils.c
│   └── stack_utils2.c
│
├── parsing
│   ├── ft_split.c
│   ├── parsing.c
│   ├── parsing_utils.c
│   └── parsing_utils2.c
│
└── strategy_disorder
    ├── disorder.c
    ├── Print_bench.c
    └── strategy.c
```

### Directory Responsibilities

**algo_sorts/**

Contains the sorting algorithms, indexing functionality, and helper functions used by the sorting strategies.

**operations/**

Contains the implementation of the allowed stack operations and stack utility functions.

**parsing/**

Handles command-line arguments, splitting input strings, integer conversion, and input validation.

**strategy_disorder/**

Contains the disorder calculation, strategy selection, and benchmarking output.

**push_swap.h**

Contains shared structures, function prototypes, and project definitions.

---

## 🛡️ Input Parsing and Validation

Before sorting, the program must ensure that all arguments are valid.

The program handles:

- Valid positive and negative integers.
- Multiple arguments.
- Numbers provided inside a quoted string.
- Empty or invalid arguments.
- Duplicate numbers.
- Non-numeric characters.
- Integer overflow and underflow.
- Values outside the `int` range.

Examples of invalid input:

```bash
./push_swap 1 2 2 3
./push_swap 1 abc 3
./push_swap 2147483648
./push_swap -2147483649
```

Invalid input must produce:

```text
Error
```

The program must also avoid generating unnecessary operations when the input is already sorted.

---

## 🧱 Data Structures

Our implementation uses linked-list-based stacks.

Each node stores the integer value, its corresponding index, and pointers to neighboring nodes.

Conceptually:

```c
typedef struct s_node
{
    int             number;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;
```

The stack maintains information such as:

- `head`: Pointer to the first node.
- `last`: Pointer to the last node.
- `size`: Number of elements in the stack.

Using a doubly linked list provides access to both the next and previous nodes.

This is particularly useful when implementing rotations and reverse rotations.

---

## ⚙️ Compilation

Clone the repository:

```bash
git clone <repository-url>
cd push_swap
```

Compile:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove object files and the executable:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

---

## 🚀 Usage

Run the program with individual arguments:

```bash
./push_swap 4 67 3 87 23
```

Or provide the numbers as a single quoted string:

```bash
./push_swap "4 67 3 87 23"
```

The program outputs the operations required to sort Stack A.

### Example

Input:

```bash
./push_swap 2 1 3 6 5 8
```

Possible output:

```text
sa
```

The exact output depends on the selected strategy and implementation.

---

## 🧪 Testing

Testing is essential to ensure both correctness and efficiency.

### Already Sorted

```bash
./push_swap 1 2 3 4 5
```

Expected behavior: No operations are necessary.

### Reverse Sorted

```bash
./push_swap 5 4 3 2 1
```

### Random Numbers

```bash
./push_swap 42 7 19 3 88 12 55
```


### Using the Checker

The 42 checker verifies whether the generated operations correctly sort the input.

```bash
ARG="4 67 3 87 23"

./push_swap $ARG | ./checker_linux $ARG
```

A successful result:

```text
OK

```

An incorrect result:

```text
KO
```

### Measuring the Number of Operations

To measure the number of instructions generated:

```bash
ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')

./push_swap $ARG | wc -l
```

This is useful when comparing the performance of different sorting strategies.

### Benchmarking

To evaluate algorithm performance, test multiple input sizes and different input arrangements.

Important metrics include:

- Total number of operations.
- Average operation count.
- Maximum operation count.
- Strategy selection.
- Correctness of the final result.

---

## 🧠 What We Learned

Working on push_swap helped us develop a deeper understanding of algorithmic problem-solving.

Some of the most important concepts we practiced were:

- Implementing sorting algorithms under strict constraints.
- Understanding the relationship between data structures and algorithms.
- Using linked lists to implement stacks.
- Working with pointers and memory management.
- Applying binary operations and bitwise manipulation.
- Understanding coordinate compression and indexing.
- Analyzing time and space complexity.
- Optimizing sorting strategies.
- Designing adaptive algorithms.
- Debugging and testing complex C programs.
- Working collaboratively on a software project.
- Following the 42 Norm.

---

## 🤖 AI Usage

AI tools were used as learning and assistance resources throughout the project.

They helped us:

- Understand algorithmic concepts.
- Explore different sorting strategies.
- Understand data structures and stack operations.
- Analyze errors and debugging approaches.
- Study algorithm optimization and complexity.
- Improve documentation and technical explanations.

The implementation and final code were written and understood by the authors.

---
## 👥 Team Contributions

This project was developed collaboratively by two students. Responsibilities were divided as follows:

### **aborabi**
- Error handling and input validation.
- Command-line argument parsing.
- Handling invalid inputs and duplicate values.
- Ensuring correct argument processing.

### **hmuqasqu**
- Implementation of stack operations.
- Development and organization of the project header (`push_swap.h`).
- Stack manipulation functionality.

### **Collaborative Work**
Both authors worked together on:
- Designing and implementing sorting algorithms.
- Small sorting strategies.
- Selection Sort.
- Chunk-based sorting.
- Binary Radix Sort.
- Disorder calculation and adaptive strategy selection.
- Testing, debugging, and algorithm optimization.

### **Authors**
- **hmuqasqu**
- **aborabi**

*This project was created as part of the 42 Common Core curriculum.*


A successful result:

```text
OK

```

An incorrect result:

```text
KO
```

### Measuring the Number of Operations

To measure the number of instructions generated:

```bash
ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')

./push_swap $ARG | wc -l
```

This is useful when comparing the performance of different sorting strategies.

### Benchmarking

To evaluate algorithm performance, test multiple input sizes and different input arrangements.

Important metrics include:

- Total number of operations.
- Average operation count.
- Maximum operation count.
- Strategy selection.
- Correctness of the final result.

---

## 🧠 What We Learned

Working on push_swap helped us develop a deeper understanding of algorithmic problem-solving.

Some of the most important concepts we practiced were:

- Implementing sorting algorithms under strict constraints.
- Understanding the relationship between data structures and algorithms.
- Using linked lists to implement stacks.
- Working with pointers and memory management.
- Applying binary operations and bitwise manipulation.
- Understanding coordinate compression and indexing.
- Analyzing time and space complexity.
- Optimizing sorting strategies.
- Designing adaptive algorithms.
- Debugging and testing complex C programs.
- Working collaboratively on a software project.
- Following the 42 Norm.

---

## 🤖 AI Usage

AI tools were used as learning and assistance resources throughout the project.

They helped us:

- Understand algorithmic concepts.
- Explore different sorting strategies.
- Understand data structures and stack operations.
- Analyze errors and debugging approaches.
- Study algorithm optimization and complexity.
- Improve documentation and technical explanations.

The implementation and final code were written and understood by the authors.

---
## 👥 Team Contributions

This project was developed collaboratively by two students. Responsibilities were divided as follows:

### **aborabi**
- Error handling and input validation.
- Command-line argument parsing.
- Handling invalid inputs and duplicate values.
- Ensuring correct argument processing.

### **hmuqasqu**
- Implementation of stack operations.
- Development and organization of the project header (`push_swap.h`).
- Stack manipulation functionality.

### **Collaborative Work**
Both authors worked together on:
- Designing and implementing sorting algorithms.
- Small sorting strategies.
- Selection Sort.
- Chunk-based sorting.
- Binary Radix Sort.
- Disorder calculation and adaptive strategy selection.
- Testing, debugging, and algorithm optimization.

### **Authors**
- **hmuqasqu**
- **aborabi**

*This project was created as part of the 42 Common Core curriculum.*
