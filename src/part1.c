#include <stdio.h>
#include <assert.h>

// Convert an int value from little endian to big endian (and vice versa).
// For example, if x is 0x12345678, then convert_endian should return 0x78563412.
// Make sure that your code does not hard-code the size of the type int.
// 3 Points
int convert_endian(int x)
{
  int res;

  for (int i = 0; i < sizeof(int); i++) {
    *((char*) &res + i) = *((char*) &x + sizeof(int) - i - 1);
  }

  return res;
}

//Extract the 8-bit exponent field of the single precision floating point number f 
//and return it as an unsigned byte
//Example: get_exponent_field(15213.0) should return 140.
// 3 Points
unsigned char get_exponent_field(float f) 
{
  unsigned int b = *((unsigned int*) &f) << 1;
  return *((unsigned char*) &b + 3);
}

/* In the remainder of this part, we will implement a set data structures that 
 * uses unsigned integer values to represent sets of bounded integers as bit 
 * vectors. For example, using a 4 byte unsigned integer value x, we can represent sets
 * of integer values in the range 0..31. A value i, 0 <= i <= 31, is in the set
 * represented by x iff the i-th bit of x is set to 1.
 * Use bit-level operations to implement the following set operations on such sets.
 */

// Return the empty set
// 1 Point
unsigned int sempty() {
  return 0;
}

// Return true iff the set represented by x contains i.
// 2 Points
int scontains(unsigned int x, int i) {
  if (i < 0 || i >= sizeof(int)*8) return 0;
  else return x & 1 << i;
}

// Return the set obtained by inserting integer i into the set represented by x.
// 2 Points
unsigned int sinsert(unsigned int x, int i) {
  assert (0 <= i && i < sizeof(int)*8);
  return x | 1 << i;
}

// Return the set obtained by removing integer i from the set represented by x.
// 2 Points
unsigned int sdelete(unsigned int x, int i) {
  assert (0 <= i && i < sizeof(int)*8);
  return x & ~(1 << i);
}

// Return the set obtained by taking the union of the sets represented by x and y.
// 2 Points
unsigned int sunion(unsigned int x, unsigned int y) {
  return x | y;
}
  
// Return the set obtained by taking the intersection of the sets represented by x and y.
// 2 Points
unsigned int sinter(unsigned int x, unsigned int y) {
  return x & y;
}
