## Part 3

1. Always true because either ux > 0 or otherwise ux == 0 in which case
   ux - 1 overflows and is greater than 0.
   
2. Always true because either y >= 2 or otherwise y < 2 in which case
   y - 2 < 2 - 2 and hence y - 2 < 0. This is only true if there is no
   signed overflow. With signed overflow, y - 2 can be positive (e.g. for
   y = INT_MIN).
   
3. Only true if the most significant bit of x and ux is 0. Otherwise,
   the result of the two sides will differ because x >> 31 performs
   arithmetic shift and ux >> 31 logical shift. Example: pick x = -1.
   
4. Always true because both x + uy and ux + y involve a mix of signed
   and unsigned int. The value of x will be implicitly converted to
   unsigned in x + uy, yielding the same result as ux + uy. Similarly
   y will be converted to unsigned in ux + y.
   
5. Always true because the square of an integer is always
   positive. However, this no longer holds true if there is signed
   overflow. If y is sufficiently large, then y * y can be negative.
   
6. Not always true. Example: pick x = 1 and y = 0.


## Part 4

1. * sign bit is 0 => x positive
  
   * exp != 0 => normalized form
   
     exp = 2 + 4 + 16 = 22 => E = 22 - 15 = 7
     
     frac = 1 + 1/4 + 1/8 = 11/8
     
   * Hence: x = 11/8 * 2^7
   
2. * sign bit is 1 => y negative

   * exp != 0 => normalized form
   
     exp = 1 + 2 + 4 = 7 => E = 7 - 15 = -8
     
     frac = 1 + 1/4 = 5/4
     
   * Hence: y = - 5/4 * 2^(-8)
   
3. * sign bis is 0 => z positive

   * exp = 0 => denormalized form
   
     E = 1 - 15 = -14
     
     frac = 1/2 + 1/4 + 1/8 = 7/8
     
   * Hence: z = 7/8 * 2^(-14)
   
4. * sign bit is 1 => u negative

   * exp != 0 => normalized form
   
     exp = 4 + 8 + 16 = 28 => E = 28 - 15 = 13
     
     frac = 1
     
   * Hence: u = - 2^13
   
5. * sign bit is 0 => v is positive

   * Exp != 0 => normalized form
   
     exp = 1 + 2 + 4 + 16 = 23 => Exp = 23 - 15 = 8
     
     frac = 1 + 1/2 = 3/2
     
   * Hence: v = 3/2 * 2^8
   

     
     
     
     