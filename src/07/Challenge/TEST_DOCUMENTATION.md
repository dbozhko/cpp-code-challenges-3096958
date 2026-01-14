# Complex Number Unit Tests Documentation

## Overview
This document describes the comprehensive unit tests for the `complex_num` class, which implements arithmetic operations on complex numbers.

## Test Coverage

### 1. **Addition Tests** (6 test cases)
Tests the `+` operator for complex number addition using the formula:
$$z + w = (a + ib) + (c + id) = (a + c) + i(b + d)$$

**Test Cases:**
- Basic addition: $(3 + 4i) + (2 + 1i) = (5 + 5i)$
- Addition with negative numbers: $(5 - 3i) + (2 + 1i) = (7 - 2i)$
- Addition with zero: $(4 + 5i) + (0 + 0i) = (4 + 5i)$
- Addition of negatives: $(-2 - 3i) + (-1 - 2i) = (-3 - 5i)$
- Pure real addition: $(5 + 0i) + (3 + 0i) = (8 + 0i)$
- Pure imaginary addition: $(0 + 5i) + (0 + 3i) = (0 + 8i)$

### 2. **Subtraction Tests** (6 test cases)
Tests the `-` operator for complex number subtraction using the formula:
$$z - w = (a + ib) - (c + id) = (a - c) + i(b - d)$$

**Test Cases:**
- Basic subtraction: $(5 + 7i) - (2 + 3i) = (3 + 4i)$
- Subtraction resulting in negative: $(2 + 1i) - (5 + 7i) = (-3 - 6i)$
- Subtraction with zero: $(4 + 5i) - (0 + 0i) = (4 + 5i)$
- Subtracting from zero: $(0 + 0i) - (2 + 3i) = (-2 - 3i)$
- Subtracting same number: $(3 + 4i) - (3 + 4i) = (0 + 0i)$
- With negative numbers: $(-5 + 3i) - (-2 + 1i) = (-3 + 2i)$

### 3. **Multiplication Tests** (8 test cases)
Tests the `*` operator for complex number multiplication using the formula:
$$z \times w = (a + ib) \times (c + id) = (ac - bd) + i(ad + bc)$$

**Test Cases:**
- Basic multiplication: $(2 + 3i) \times (4 + 5i) = (-7 + 22i)$
  - $(2 \times 4 - 3 \times 5) + i(2 \times 5 + 3 \times 4) = -7 + 22i$ ✓
- Multiplication by zero: $(3 + 4i) \times (0 + 0i) = (0 + 0i)$
- Multiplication by 1: $(2 + 3i) \times (1 + 0i) = (2 + 3i)$
- Multiplication by i: $(3 + 4i) \times (0 + 1i) = (-4 + 3i)$
- With negative numbers: $(-2 + 3i) \times (4 - 5i) = (7 + 22i)$
- Pure real multiplication: $(5 + 0i) \times (3 + 0i) = (15 + 0i)$
- Pure imaginary multiplication: $(0 + 2i) \times (0 + 3i) = (-6 + 0i)$
- Commutative property: $(2 + 3i) \times (4 + 5i) = (4 + 5i) \times (2 + 3i)$

### 4. **Division Tests** (8 test cases)
Tests the `/` operator for complex number division using the formula:
$$\frac{z}{w} = \frac{a + ib}{c + id} = \frac{(ac + bd)}{(c^2 + d^2)} + i\frac{(bc - ad)}{(c^2 + d^2)}$$

**Test Cases:**
- Division by real number: $\frac{10 + 5i}{-2 + 0i} = (-5 - 2.5i)$
- Division by 1: $\frac{3 + 4i}{1 + 0i} = (3 + 4i)$
- Division with complex denominator: $\frac{3 + 4i}{2 + 1i} = (2 + 1i)$
- Division resulting in imaginary: $\frac{0 + 4i}{2 + 0i} = (0 + 2i)$
- Division resulting in real: $\frac{6 + 0i}{2 + 0i} = (3 + 0i)$
- Division by pure imaginary: $\frac{4 + 0i}{0 + 2i} = (0 - 2i)$
- Multiplicative inverse: $\frac{3 + 4i}{3 + 4i} = (1 + 0i)$
- With negatives: $\frac{-10 - 5i}{2 + 1i} = (-5 + 0i)$

### 5. **Combined Operations Tests** (4 test cases)
Tests complex mathematical properties and combinations:

- Property: $(z + w) - (z - w) = 2w$
- Inverse property: $(z \times w) \div w \approx z$
- Associativity: $(z + w) + v = z + (w + v)$
- Distributivity: $z \times (w + v) = (z \times w) + (z \times v)$

## Test Statistics
- **Total Test Cases:** 32
- **Addition Cases:** 6
- **Subtraction Cases:** 6
- **Multiplication Cases:** 8
- **Division Cases:** 8
- **Combined Operations Cases:** 4

## How to Run the Tests

### Compile and Run:
```bash
cd /workspaces/cpp-code-challenges-3096958/src/07/Challenge
g++ -std=c++17 test_complex_num.cpp complex_num.cpp -o test_complex_num
./test_complex_num
```

## Expected Output
```
=== Complex Number Unit Tests ===
Testing complex_num class arithmetic operators

Testing Addition (+)...
  [6 cases] ✓ Addition tests passed

Testing Subtraction (-)...
  [6 cases] ✓ Subtraction tests passed

Testing Multiplication (*)...
  [8 cases] ✓ Multiplication tests passed

Testing Division (/)...
  [8 cases] ✓ Division tests passed

Testing Combined Operations...
  [4 cases] ✓ Combined operations tests passed

=== All Tests Passed! ===
The complex_num class successfully implements:
  • Addition:       z + w
  • Subtraction:    z - w
  • Multiplication: z * w
  • Division:       z / w
```

## Test Design Principles

1. **Edge Cases:** Tests include zero values, pure real/imaginary numbers, and negative numbers
2. **Mathematical Correctness:** Each test validates the mathematical formulas
3. **Operator Verification:** All four required operators (+, -, *, /) are tested
4. **Property Validation:** Tests verify mathematical properties like commutativity, associativity, and distributivity
5. **Comprehensive Coverage:** Tests cover basic operations, boundary conditions, and complex scenarios

## Implementation Details

- Tests are written in C++ using standard library features
- No external testing frameworks required
- Floating-point tolerance handled where necessary
- Tests output clear pass/fail status
- Return code 0 on success, 1 on failure

## Notes

- The `print()` method is used for output verification and debugging
- Tests create complex_num objects with specific real and imaginary parts
- Mathematical operations are verified by comparing expected results
- Test cases provide clear comments explaining the mathematical operations
