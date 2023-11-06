# Numerical Utility (numberUtil) for C++

wayne::numberUtil is a bunch of tools related to number operation. 

Access these functions by adding namespace:

<code>wayne::numberUtil::</code>

## Usage

- <code>numberToBytes(int/long number, numberByteOrder numByteOrder</code>   
  
  - Convert **a number type**(e.g., <code>int, long, long long,...</code>) to a byte array <code>std::vector\<char\></code>
  
  - <code>numByteOrder</code> is an optional flag to determine the output byte array's order, the default value is: <code>ORDER_DATA_DEFAULT</code>
    
    - <code>ORDER_DATA_DEFAULT:</code> The byte order of the array is according to the endianess of the current processor.
    
    - <code>ORDER_DATA_SMALL_ENDIAN:</code> Force the output byte order to small endian.
    
    - <code>ORDER_DATA_BIG_ENDIAN:</code> Force the output byte order to big endian.
  
  - Returns <code>std::vector\<char\></code>

- <code>numberToBytesStatic(int/long number, numberByteOrder numByteOrder</code>
  
  - It acts the same as <code>numberToBytes</code>, but it returns <code>char*</code> array.
  
  - Returns <code>char*</code>

- <code>bytesToNumber(std::vector\<char\> rawBytes, <integerType> reference, numberByteOrder rawByteOrder</code>
  
  - It converts a <code>std::vector\<char\></code> back to a number type, according to the <code>reference</code>'s number type.
  
  - <code>rawByteOrder</code> is an optional flag to determine the endianess of <code>rawBytes</code>. The default value is <code>ORDER_DATA_DEFAULT</code>
    
    - <code>ORDER_DATA_DEFAULT:</code> The function assumed the byte order of <code>rawBytes</code> respects to the current processor.
    
    - <code>ORDER_DATA_SMALL_ENDIAN</code>: It tells the function that the byte order of <code>rawBytes</code> is small endian.
    
    - <code>ORDER_DATA_BIG_ENDIAN</code>: It tells the function that the byte order of <code>rawBytes</code> is big endian.
  
  - Returns **Data Type according to the reference**

- <code>bytesStaticToNumber(char* rawBytes, <integerType> reference, numberByteOrder rawByteOrder</code>
  
  - It acts the same as <code>bytesToNumber</code>, but this time, a <code>char* rawBytes</code> is provided. 
  
  - Returns **Data Type according to the reference**

- isBigEndian()
  
  - A function determines current processor's endianess.
  
  - Returns <code>bool</code>

## Example

```cpp
long long x = 9223372036854775807;
std::vector<char> bytesOfX = numberToBytes(x, numberByteOrder::ORDER_DATA_BIG_ENDIAN);
for (unsigned char elementOfX : bytesOfX)
{
    std::cout << (int)elementOfX << " ";
}
std::cout << std::endl;
long long y = bytesToNumber(bytesOfX, y, numberByteOrder::ORDER_DATA_BIG_ENDIAN);
std::cout << y << std::endl;

Output:
127 255 255 255 255 255 255 255
9223372036854775807
```
