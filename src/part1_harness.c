#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <getopt.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

#include "panic_cond.h"
#include "harness.h"
#include "part1.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int convert_endian_gold(int x)
{
  int res;

  for (int i = 0; i < sizeof(int); i++) {
    *((char*) &res + i) = *((char*) &x + sizeof(int) - i - 1);
  }

  return res;
}

void test_convert_endian(int x) {
  int res = convert_endian(x);
  int res_gold = convert_endian_gold(x);
  
  panic_cond(res == res_gold,
             "test convert_endian on 0x%x:\n"
             "  expected return value: 0x%x\n"
             "               actually: 0x%x",
             x, res_gold, res);

}

unsigned char get_exponent_field_gold(float f) 
{
  //TODO: Replace the following with your code
  //assert(0);
  //return 0;
  unsigned int b = *((unsigned int*) &f) << 1;
  return *((unsigned char*) &b + 3);
}

void test_get_exponent_field(float f) {
  unsigned char res = get_exponent_field(f);
  unsigned char res_gold = get_exponent_field_gold(f);
  
  panic_cond(res == res_gold,
             "test get_exponent_field(%.20f):\n"
             "  expected return value: %d\n"
             "               actually: %d",
             f, res_gold, res);

}


unsigned int sinsert_gold(unsigned int x, int i) {
  assert (0 <= i && i < sizeof(int)*8);
  //TODO: Replace the following with your code
  //assert(0);
  //return 0;
  return x | 1 << i;
}

unsigned int scontains_gold(unsigned int x, int i) {
  //assert (0 <= i && i < sizeof(int)*8);
  if (i < 0 || i >= sizeof(int)*8) return 0;
  //TODO: Replace the following with your code
  //assert(0);
  //return 0;
  return x & 1 << i;
}


unsigned int sdelete_gold(unsigned int x, int i) {
  assert (0 <= i && i < sizeof(int)*8);
  //TODO: Replace the following with your code
  //assert(0);
  //return 0;
  return x & ~(1 << i);
}

unsigned int sunion_gold(unsigned int x, unsigned int y) {
  return x | y;
}

unsigned int sinter_gold(unsigned int x, unsigned int y) {
  return x & y;
}

void test_scontains(unsigned int x, int i) {
  unsigned int res = scontains(x, i);
  unsigned int res_gold = scontains_gold(x, i);
  
  panic_cond(!res == !res_gold,
             "test scontains(0x%x, %d):\n"
             "            x in binary: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "  expected return value: %s\n"
             "               actually: %s",
             x, i,
             BYTE_TO_BINARY(x >> 24),
             BYTE_TO_BINARY(x >> 16),
             BYTE_TO_BINARY(x >> 8),
             BYTE_TO_BINARY(x),
             res_gold ? "true" : "false", res ? "true" : "false");
}

void test_sinsert(unsigned int x, int i) {
  unsigned int res = sinsert(x, i);
  unsigned int res_gold = sinsert_gold(x, i);
  
  panic_cond(res == res_gold,
             "test sinsert(0x%x, %d):\n"
             "            x in binary: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "  expected return value: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "               actually: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN,
             x, i,
             BYTE_TO_BINARY(x >> 24),
             BYTE_TO_BINARY(x >> 16),
             BYTE_TO_BINARY(x >> 8),
             BYTE_TO_BINARY(x),
             BYTE_TO_BINARY(res_gold >> 24),
             BYTE_TO_BINARY(res_gold >> 16),
             BYTE_TO_BINARY(res_gold >> 8),
             BYTE_TO_BINARY(res_gold),
             BYTE_TO_BINARY(res >> 24),
             BYTE_TO_BINARY(res >> 16),
             BYTE_TO_BINARY(res >> 8),
             BYTE_TO_BINARY(res));
}

void test_sdelete(unsigned int x, int i) {
  unsigned int res = sdelete(x, i);
  unsigned int res_gold = sdelete_gold(x, i);
  
  panic_cond(res == res_gold,
             "test sdelete(0x%x, %d):\n"
             "            x in binary: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "  expected return value: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "               actually: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN,
             x, i,
             BYTE_TO_BINARY(x >> 24),
             BYTE_TO_BINARY(x >> 16),
             BYTE_TO_BINARY(x >> 8),
             BYTE_TO_BINARY(x),
             BYTE_TO_BINARY(res_gold >> 24),
             BYTE_TO_BINARY(res_gold >> 16),
             BYTE_TO_BINARY(res_gold >> 8),
             BYTE_TO_BINARY(res_gold),
             BYTE_TO_BINARY(res >> 24),
             BYTE_TO_BINARY(res >> 16),
             BYTE_TO_BINARY(res >> 8),
             BYTE_TO_BINARY(res));
}

void test_sunion(unsigned int x, unsigned int y) {
  unsigned int res = sunion(x, y);
  unsigned int res_gold = sunion_gold(x, y);
  
  panic_cond(res == res_gold,
             "test sunion(0x%x, 0x%x):\n"
             "            x in binary: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "            y in binary: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "  expected return value: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "               actually: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN,
             x, y,
             BYTE_TO_BINARY(x >> 24),
             BYTE_TO_BINARY(x >> 16),
             BYTE_TO_BINARY(x >> 8),
             BYTE_TO_BINARY(x),
             BYTE_TO_BINARY(y >> 24),
             BYTE_TO_BINARY(y >> 16),
             BYTE_TO_BINARY(y >> 8),
             BYTE_TO_BINARY(y),
             BYTE_TO_BINARY(res_gold >> 24),
             BYTE_TO_BINARY(res_gold >> 16),
             BYTE_TO_BINARY(res_gold >> 8),
             BYTE_TO_BINARY(res_gold),
             BYTE_TO_BINARY(res >> 24),
             BYTE_TO_BINARY(res >> 16),
             BYTE_TO_BINARY(res >> 8),
             BYTE_TO_BINARY(res));
}


void test_sinter(unsigned int x, unsigned int y) {
  unsigned int res = sinter(x, y);
  unsigned int res_gold = sinter_gold(x, y);
  
  panic_cond(res == res_gold,
             "test sinter(0x%x, 0x%x):\n"
             "            x in binary: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "            y in binary: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "  expected return value: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "               actually: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN,
             x, y,
             BYTE_TO_BINARY(x >> 24),
             BYTE_TO_BINARY(x >> 16),
             BYTE_TO_BINARY(x >> 8),
             BYTE_TO_BINARY(x),
             BYTE_TO_BINARY(y >> 24),
             BYTE_TO_BINARY(y >> 16),
             BYTE_TO_BINARY(y >> 8),
             BYTE_TO_BINARY(y),
             BYTE_TO_BINARY(res_gold >> 24),
             BYTE_TO_BINARY(res_gold >> 16),
             BYTE_TO_BINARY(res_gold >> 8),
             BYTE_TO_BINARY(res_gold),
             BYTE_TO_BINARY(res >> 24),
             BYTE_TO_BINARY(res >> 16),
             BYTE_TO_BINARY(res >> 8),
             BYTE_TO_BINARY(res));
}


void test_sempty() {
  unsigned int res = sempty();
  unsigned int res_gold = 0;
  
  panic_cond(res == res_gold,
             "test sempty:\n"
             "  expected return value: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN"\n"
             "               actually: "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN" "
             BYTE_TO_BINARY_PATTERN,
             BYTE_TO_BINARY(res >> 24),
             BYTE_TO_BINARY(res >> 16),
             BYTE_TO_BINARY(res >> 8),
             BYTE_TO_BINARY(res),
             BYTE_TO_BINARY(res_gold >> 24),
             BYTE_TO_BINARY(res_gold >> 16),
             BYTE_TO_BINARY(res_gold >> 8),
             BYTE_TO_BINARY(res_gold));

}


int main(int argc, char** argv)
{
  printf("part1: testing convert_endian...\n");
  for (int i = 0; i < 100; i++) {
    int x = random();
    test_convert_endian(x);
  }
  printf("part1: convert_endian OK\n");

  printf("part1: testing get_exponent_field...\n");
  test_get_exponent_field(15213.0);
  for (int i = 0; i < 100; i++) {
    int x = rand() - RAND_MAX / 2;
    test_get_exponent_field(*((float*) &x));
  }
  printf("part1: get_exponent_field OK\n");

  printf("part1: testing sempty...\n");
  test_sempty();
  printf("part1: sempty OK\n");

  printf("part1: testing scontains...\n");
  for (int i = 0; i < 100; i++) {
    unsigned int x = random();
    int i = random() % (sizeof(int) * 8);
    test_scontains(x, i);
  }
  printf("part1: scontains OK\n");

  printf("part1: testing sinsert...\n");
  for (int i = 0; i < 100; i++) {
    unsigned int x = random();
    int i = random() % (sizeof(int) * 8);
    test_sinsert(x, i);
  }
  printf("part1: sinsert OK\n");

  printf("part1: testing sdelete...\n");
  for (int i = 0; i < 100; i++) {
    unsigned int x = random();
    int i = random() % (sizeof(int) * 8);
    test_sdelete(x, i);
  }
  printf("part1: sdelete OK\n");

  printf("part1: testing sunion...\n");
  for (int i = 0; i < 100; i++) {
    unsigned int x = random();
    unsigned int y = random();
    test_sunion(x, y);
  }
  printf("part1: sunion OK\n");

  printf("part1: testing sinter...\n");
  for (int i = 0; i < 100; i++) {
    unsigned int x = random();
    unsigned int y = random();
    test_sinter(x, y);
  }
  printf("part1: sinter OK\n");

  return 0;
}
