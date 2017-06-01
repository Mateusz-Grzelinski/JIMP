#include "FactorialTest.h"

bool FactorialOf0ShouldBe1() {
  int expected = 1;
  int result = Factorial(0);
  return expected == result;
}

bool FactorialOf1ShouldBe1() {
  int expected = 1;
  int result = Factorial(1);
  return expected == result;
}

bool FactorialOf10ShouldBe3628800() {
  int expected = 3628800;
  int result = Factorial(10);
  return expected == result;
}

bool FactorialOfNegativeShouldBe0() {
  int expected = 0;
  int result = Factorial(-7);
  return expected == result;
}