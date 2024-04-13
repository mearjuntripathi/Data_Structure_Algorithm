Let's delve into the theory behind some common **bitwise tricks and optimizations**:

### 1. Power of Two Check:
- The expression `(n & (n - 1))` efficiently clears the least significant set bit of `n`.
- If `n` is a power of two, it has only one bit set (e.g., `1000`, `0100`, `0010`, `0001`). Clearing the least significant set bit results in `0`.
- Therefore, if `n & (n - 1)` evaluates to `0`, it means `n` has only one bit set, indicating it's a power of two.

### 2. Counting Set Bits (Hamming Weight):
- The expression `n & (n - 1)` efficiently clears the least significant set bit of `n`.
- By repeatedly performing this operation until `n` becomes zero, we effectively count the number of set bits in `n`.
- The number of times we perform this operation corresponds to the number of set bits in `n`.

### 3. Swap Values:
- Bitwise XOR (`^`) has the property that `x ^ x = 0` and `x ^ 0 = x`.
- By performing `a ^= b`, `b ^= a`, and `a ^= b`, we effectively swap the values of `a` and `b` without using an additional variable.

### 4. Absolute Value:
- The expression `n >> (sizeof(int) * CHAR_BIT - 1)` extracts the sign bit of `n`.
- If `n` is negative, its sign bit is 1, and the mask becomes `-1`. If `n` is non-negative, its sign bit is 0, and the mask becomes `0`.
- Adding the mask to `n` effectively sets all bits to 1 for negative `n` and leaves them unchanged for non-negative `n`.
- Performing XOR with the mask toggles the bits for negative `n` and leaves them unchanged for non-negative `n`, resulting in the absolute value of `n`.

### 5. Fast Multiplication and Division:
- Left shift (`<<`) effectively multiplies an integer by 2 raised to the power of the shift amount.
- Right shift (`>>`) effectively divides an integer by 2 raised to the power of the shift amount.
- Multiplying or dividing by powers of two can be optimized using these bitwise operations, which are more efficient than multiplication and division operations.

### 6. Extracting the Least Significant Bit (LSB):
- Performing `n & 1` extracts the least significant bit of `n`.
- If the least significant bit of `n` is 1, the result is 1; otherwise, it's 0.

These techniques leverage the properties of bitwise operations to achieve specific goals efficiently. Understanding these properties and how to use them creatively can lead to more concise and efficient code.

Bitwise tricks and optimizations involve using bitwise operations creatively to achieve specific goals efficiently. These techniques are often employed in performance-critical scenarios or when working with low-level programming tasks. Here are some common bitwise tricks and optimizations:

### 1. Power of Two Check:
- Testing whether a number is a power of two can be done efficiently using bitwise operations.
```cpp
bool isPowerOfTwo(int n) {
    return n && !(n & (n - 1));
}
```
This function returns `true` if `n` is a power of two and `false` otherwise. It works by checking if there is only one bit set in the binary representation of `n`.

### 2. Counting Set Bits (Hamming Weight):
- Counting the number of set bits (bits with value 1) in an integer can be optimized using bitwise operations.
```cpp
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
```
This function efficiently counts the number of set bits in `n` by repeatedly clearing the least significant set bit until `n` becomes zero.

### 3. Swap Values:
- Swapping the values of two variables without using a temporary variable can be achieved using bitwise XOR.
```cpp
void swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
```
This `swap` function exchanges the values of `a` and `b` without using an additional variable by leveraging the properties of bitwise XOR.

### 4. Absolute Value:
- Calculating the absolute value of an integer without branching can be done using bitwise operations.
```cpp
int abs(int n) {
    int mask = n >> (sizeof(int) * CHAR_BIT - 1);
    return (n + mask) ^ mask;
}
```
This `abs` function computes the absolute value of `n` without using branching by masking the sign bit and performing an XOR operation.

### 5. Fast Multiplication and Division:
- Multiplying or dividing integers by powers of two can be optimized using left and right shifts, respectively.
```cpp
int multiplyByPowerOfTwo(int num, int pow) {
    return num << pow; // equivalent to num * 2^pow
}

int divideByPowerOfTwo(int num, int pow) {
    return num >> pow; // equivalent to num / 2^pow
}
```
These functions perform multiplication and division by powers of two efficiently by utilizing left and right shifts, respectively.

### 6. Extracting the Least Significant Bit (LSB):
- Extracting the least significant bit of an integer can be done using bitwise AND with 1.
```cpp
int getLSB(int n) {
    return n & 1;
}
```
This function returns the least significant bit of `n`.

These are just a few examples of bitwise tricks and optimizations. By leveraging bitwise operations effectively, you can often achieve significant performance improvements and write more concise and efficient code.