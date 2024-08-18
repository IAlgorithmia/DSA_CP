#include <bits/stdc++.h>
using namespace std;

void rschecker(int number, int k)
{
    if (((number >> (k - 1)) & 1) == 1)
    {
        cout << "7 Karoooooode by ls" << endl;
    }
    else
    {
        cout << "Na ji by ls" << endl;
    }
}
void lschecker(int number, int k)
{
    if ((number & (1 << (k - 1))) == 1)
    {
        cout << "7 Karoooooode by rs" << endl;
    }
    else
    {
        cout << "Na ji by rs" << endl;
    }
}

int main()
{
    cout << "Enter the number and the bit which you want to check for on/off : ";
    int number, k;
    cin >> number >> k;
    lschecker(number, k);
    rschecker(number, k);
}

// In C++, a `bitset` is a standardized class provided by the C++ Standard Library to manage and manipulate a fixed-size sequence of bits. It offers a variety of functionalities to work with bits efficiently and is part of the `<bitset>` header.

// Here are some key features and functionalities of `bitset`:

// 1. **Initialization**:
//    - You can initialize a `bitset` using an integer, string, or by default, which initializes all bits to zero.

//      ```cpp
//      #include <bitset>
//      #include <string>

//      std::bitset<8> b1;            // 00000000
//      std::bitset<8> b2(42);        // 00101010
//      std::bitset<8> b3("1100");    // 00001100
//      ```

// 2. **Size**:
//    - The size of a `bitset` is fixed at compile time and specified as a template parameter.

//      ```cpp
//      std::bitset<8> b; // A bitset with 8 bits
//      ```

// 3. **Access and Manipulation**:
//    - Individual bits can be accessed and modified using the subscript operator `[]`.

//      ```cpp
//      b[0] = 1;  // Set the first bit
//      b[1] = 0;  // Clear the second bit
//      ```

//    - Functions like `set()`, `reset()`, and `flip()` allow for setting, clearing, and toggling bits, respectively.

//      ```cpp
//      b.set(3);   // Set the fourth bit
//      b.reset(3); // Clear the fourth bit
//      b.flip(3);  // Toggle the fourth bit
//      ```

// 4. **Querying**:
//    - Functions like `any()`, `none()`, and `count()` provide information about the state of the bits.

//      ```cpp
//      if (b.any()) { /* At least one bit is set */ }
//      if (b.none()) { /* No bits are set */ }
//      size_t setBits = b.count(); // Number of bits set to 1
//      ```

// 5. **String Conversion**:
//    - `bitset` can be converted to a string for easy representation.

//      ```cpp
//      std::string bitString = b.to_string();
//      ```

// 6. **Logical Operations**:
//    - `bitset` supports bitwise operations like AND, OR, XOR, and NOT.

//      ```cpp
//      std::bitset<8> b1("1010");
//      std::bitset<8> b2("1100");
//      std::bitset<8> result = b1 & b2; // Bitwise AND
//      ```

// 7. **Range of Operations**:
//    - You can perform operations on ranges of bits, such as shifting left or right.

//      ```cpp
//      std::bitset<8> b("1010");
//      b <<= 2; // Left shift by 2 positions, resulting in "1000"
//      b >>= 1; // Right shift by 1 position, resulting in "0100"
//      ```

// ### Example

// Here is a complete example demonstrating the usage of `bitset`:

// ```cpp
// #include <iostream>
// #include <bitset>

// int main() {
//     std::bitset<8> b("00101101"); // Initialize bitset with string

//     std::cout << "Initial bitset: " << b << std::endl;

//     b.set(4);  // Set the 5th bit
//     std::cout << "After setting 5th bit: " << b << std::endl;

//     b.reset(2); // Clear the 3rd bit
//     std::cout << "After resetting 3rd bit: " << b << std::endl;

//     b.flip(1); // Toggle the 2nd bit
//     std::cout << "After flipping 2nd bit: " << b << std::endl;

//     std::cout << "Number of bits set: " << b.count() << std::endl;
//     std::cout << "Bitset to string: " << b.to_string() << std::endl;

//     return 0;
// }
// ```

// Output:

// ```
// Initial bitset: 00101101
// After setting 5th bit: 00111101
// After resetting 3rd bit: 00111001
// After flipping 2nd bit: 00111011
// Number of bits set: 5
// Bitset to string: 00111011
// ```

// The `bitset` class provides a powerful way to handle binary data efficiently and perform various bit-level operations conveniently.