#include "Factorial.h"

int Factorial(int value) {
  if (value <= 0) {
    return 1;
  }
  return value*Factorial(value-1);
}
