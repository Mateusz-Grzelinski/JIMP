#include <Factorial.h>
#include <gtest/gtest.h>

using namespace std;


TEST(FactorialTest, FactorialOf0ShouldBe1) {
  EXPECT_EQ(1, Factorial(1));
}
