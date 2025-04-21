#include <stdio.h>
#include <stdint.h>

uint32_t val = 0;

void cPrintInt(int* a) {
  printf("print here: %d", *a);
}

int main() {
  val = 32;
  cPrintInt(&val);
  return 0;
}
