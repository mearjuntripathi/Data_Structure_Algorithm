**Shifting operations** are another fundamental aspect of bit manipulation. There are two types of shifting operations: left shift (`<<`) and right shift (`>>`). Let's explore them:

### Left Shift (`<<`):
- The left shift operator shifts all bits in a number to the left by a specified number of positions.
- Each shift left effectively multiplies the number by 2.
- For example:
  ```
  5 << 1 = 10   // 5 (binary: 0101) shifted left by 1 becomes 10 (binary: 1010)
  5 << 2 = 20   // 5 (binary: 0101) shifted left by 2 becomes 20 (binary: 10100)
  ```

### Right Shift (`>>`):
- The right shift operator shifts all bits in a number to the right by a specified number of positions.
- Each shift right effectively divides the number by 2.
- For unsigned integers, the vacated bits from the left are filled with zeroes. For signed integers, the behavior depends on the implementation: vacated bits may be filled with the sign bit (arithmetic right shift) or with zeroes (logical right shift).
- For example:
  ```
  20 >> 1 = 10  // 20 (binary: 10100) shifted right by 1 becomes 10 (binary: 1010)
  20 >> 2 = 5   // 20 (binary: 10100) shifted right by 2 becomes 5 (binary: 101)
  ```

### Applications:
- **Multiplication and Division:** Shifting is often used as a faster alternative to multiplication and division by powers of 2.
- **Bitwise Operations:** Shifting is frequently used in conjunction with bitwise AND, OR, and XOR operations to manipulate specific bits or extract certain bit patterns.
- **Data Packing and Unpacking:** Shifting operations are used to pack multiple smaller values into a larger data type or unpack larger values into smaller ones.
- **Optimization:** Shifting can be used to optimize certain algorithms and data structures, particularly in low-level programming and embedded systems.

Understanding shifting operations is crucial for efficient bit manipulation and optimization in various programming tasks. They offer a convenient way to move bits within binary numbers and perform arithmetic operations effectively.

Here are some programming examples demonstrating left shift (`<<`) and right shift (`>>`) operations in C++:

### Left Shift Example:
```cpp
#include <iostream>

int main() {
    int num = 5; // binary: 0101
    
    // Left shift num by 1
    int result = num << 1; // binary: 1010 (decimal: 10)
    
    std::cout << "Left shift result: " << result << std::endl;
    
    return 0;
}
```
Output:
```
Left shift result: 10
```

### Right Shift Example:
```cpp
#include <iostream>

int main() {
    int num = 20; // binary: 10100
    
    // Right shift num by 2
    int result = num >> 2; // binary: 0010 (decimal: 5)
    
    std::cout << "Right shift result: " << result << std::endl;
    
    return 0;
}
```
Output:
```
Right shift result: 5
```

These examples demonstrate how left and right shift operations work in C++. You can adjust the number of shifts and the input numbers to observe different results.

---