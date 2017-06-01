#include "FactorialTest.h"

#include <string>
#include <utility>
#include <iostream>
#include <vector>

using std::string;
using std::pair;
using std::cerr;
using std::endl;

//test function to wskaźnik na funkcję zwracającą bool
using TestFunction = bool (*)();

std::vector<pair<string,TestFunction>> all_tests {{"FactorialOf0ShouldBe1", FactorialOf0ShouldBe1}, {"FactorialOf1ShouldBe1", FactorialOf1ShouldBe1}, {"FactorialOf10ShouldBe3628800", FactorialOf10ShouldBe3628800}, {"FactorialOfNegativeShouldBe0", FactorialOfNegativeShouldBe0}};

void ReportTest(const string &failed_test_name) {
  cerr << "Test " << failed_test_name << " FAILED" << endl;
}

int RunTests(const std::vector<TestFunction> tests) {
  int failed_tests = 0;
  for (auto test : tests) {
    bool result = test.first();
    if (result) {
      continue;
    } else {
      ReportTest(test.second);
      failed_tests++;
    }
  }
  return failed_tests;
}

int main() {
  int result = RunTests(all_tests);
  return result;
}