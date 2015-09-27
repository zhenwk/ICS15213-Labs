/* 
 * CS:APP Data Lab 
 * 
 * <Weikun Zhen: weikunz>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int a = x & y;
  int b = (~x) & (~y);
  return (~a) & (~b);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  return !((x+!(!(~x))) ^ (~x));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int a = 0xAA;
  int b = 0xAA << 8;
  int c = a | b;
  int d = (c << 16) | c;
  return !(d^(d&x));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int l = x + (~0x30+1);
  int h = 0x39 + (~x+1);
  int r = ((l >> 31) & ~0) | ((h >> 31) & ~0);
  return !r;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int m = (((!(!x))<<31)>>31); 
  return (y&m) + (z&(~m));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int m = ~((x>>31) ^ (y>>31)); 
  int d = x + (~y + 1);
  int r = !(!((d>>31) | (!d)));
  return (r & m) + ((!(!(x>>31))) & (~m));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int m = ~(((~x+1)>>31)|(x>>31));
  return 1&m;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {

  int a, b, c, d, e; 

  x = (x & (~(x >> 31))) + ((~x) & (x>>31));

  x = x | (x >> 1);
  x = x | (x >> 2);
  x = x | (x >> 4);
  x = x | (x >> 8);
  x = x | (x >> 16);

  // Design bit-level masks
  a = 0x55 | (0x55 << 8); 
  a = a | (a << 16);

  b = 0x33 | (0x33 << 8);
  b = b | (b << 16);

  c = 0x0f | (0x0f << 8);
  c = c | (c << 16);

  d = 0xff | (0xff << 16);

  e = 0xff | (0xff << 8);

  x = (x & a) + ((x >>  1) & a);
  x = (x & b) + ((x >>  2) & b);
  x = (x & c) + ((x >>  4) & c);
  x = (x & d) + ((x >>  8) & d);
  x = (x & e) + ((x >> 16) & e);
 
  x = x + 1;

  return x; 
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  unsigned exp_m = 0xff << 23;
  unsigned frc_m = (1 << 24) + (~1 + 1);
  unsigned sig_m = 1 << 31;
  
  // if nomalized fp
  if((uf & exp_m) != 0 && 
     (uf & exp_m) != exp_m) {
    uf = uf + (1 << 23);

	if((uf & exp_m) == exp_m) {
	  uf = uf & (sig_m | exp_m);
	}
  }
  else {
    if((uf & exp_m) == 0) {
      uf = (uf & (sig_m | exp_m)) + ((uf << 1) & frc_m);
    }
	else {
	  uf = uf;
	}
  }

  return uf;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  unsigned sig_m, exp_m, frc_m;
  unsigned sig_v, exp_v, frc_v;
  unsigned rod, rod_m;
  int e;

  sig_m = 1 << 31;
  exp_m = 0xff << 23;
  frc_m = (1<<23)-1;


  if(x != 0x0) {
    frc_v = x;
    sig_v = x & sig_m;
    if(sig_v) frc_v = ~x + 1;

    e = 0;
    exp_v = 0;
    while((frc_v & sig_m) == 0) {
      frc_v <<= 1;
      e++;
    }

    // round if necessary
	rod = 0;
	if((31-e) > 23) {
	  rod_m = frc_v & 0xff;
	  if(rod_m > 0x80) rod = 1;
      else if(rod_m == 0x80) rod = (frc_v & (1<<8))>>8;
    }
	
	frc_v = (frc_v << 1) >> 9;
	exp_v = (158-e) << 23;
	
	x = (sig_v & sig_m) + (exp_v & exp_m) + (frc_v & frc_m) + rod;
  }
  return x;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  unsigned sig_m = 1 << 31;
  unsigned exp_m = 0xff << 23;
  unsigned frc_m = (1<<23)-1;
  
  unsigned sig_v = uf & sig_m;
  unsigned temp = uf & exp_m;
  unsigned exp_v = temp >> 23;
  unsigned frc_v = uf & frc_m;
  
  if( temp == exp_m) {
    uf = sig_m;
  }
  else if(temp == 0x00) {
	uf = 0;
  }
  else {
	if(exp_v >= 158) {
	  uf = sig_m;
	}
	else if(exp_v < 127) {
	  uf = 0;
	}
	else {
	  unsigned e = exp_v - 127;
	  if(e < 23) {
		frc_v >>= (23-e);
      }
	  else {
	    frc_v <<= (e-23);
	  }

	  uf = (1<<e) + frc_v;
	  	
	  if(sig_v != 0) uf = ~uf + 1;
	}
  }

  return uf;
}
