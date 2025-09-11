# IS2101 - Arithmetic Operations Assignment

## 👤 Student Details
- **Name:** Ritisha Suresh  
- **USN:** nnm24is184  
- **Section:** D 

## 📌 Assignment Title
**Implement Integer Multiplication and Division Algorithms in C**

## 📂 Repository Contents
This repository contains C programs simulating low-level arithmetic operations using binary algorithms.

| File Name                 | Description                                      |
|--------------------------|--------------------------------------------------|
| `shift_add_multiplication.c`  | Implements Sequential (Shift-Add) Multiplication with 2’s complement for signed integers |
| `restoring_division.c`        | Implements Restoring Division for positive integers |
| `non_restoring_division.c`    | Implements Non-Restoring Division with step-wise trace |

## 🧮 Algorithms Implemented

### ✅ Shift-Add Multiplication
- Supports signed integers using 2’s complement
- Implements register-level multiplication using shifting and conditional addition

### ✅ Restoring Division
- Operates on positive integers only
- Follows standard restoring division logic with step-wise subtraction and restore

### ✅ Non-Restoring Division
- Works with positive integers
- Eliminates the restore step to improve performance
- Displays step-wise values of Accumulator (A), Quotient (Q), and Dividend

## 🧑‍💻 How to Compile and Run

You can use any GCC-compatible compiler:

### 🛠️ Compile
```bash
gcc shift_add_multiplication.c -o multiply
gcc restoring_division.c -o restoring
gcc non_restoring_division.c -o nonrestoring
