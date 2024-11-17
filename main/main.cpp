// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE
#include <iostream>
#include <iomanip>
#include <chrono>
#include "../lib_easy_example/easy_example.h"
#include "../lib_dmassive/dmassive.h"
#include"..\lib_list\List.h"
#include "..\lib_stack_tl\StackTL.h"
#include "..\lib_stack_dm\StackDM.h"

template <typename T>
void testPerformanceForTL(int n) {
    TStackTL<T> stack;
    std::cout << "TEST FOR STACK TL "<< std::endl;
    std::cout << "Elements " << n << " \n";

    auto startPush = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        stack.push(i);
    }
    auto endPush = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationPush = endPush - startPush;
    std::cout << "Push time: " << durationPush.count() << " seconds\n";

    size_t memoryUsed = n * (sizeof(T) + sizeof(TNode<T>));
    std::cout << "Memory used: " << memoryUsed << " bytes\n";

    auto startPop = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        stack.pop();
    }
    auto endPop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationPop = endPop - startPop;
    std::cout << "Pop time: " << durationPop.count() << " seconds\n";

    std::cout << "-----------------------------------\n";

}



template <typename T>
void testPerformanceForDM(int n) {
    TStackDM<T> stack;
    std::cout << "TEST FOR STACK DM " << std::endl;
    std::cout << "Elements " << n << " \n";

    auto startPush = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        stack.push(i);
    }
    auto endPush = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationPush = endPush - startPush;
    std::cout << "Push time: " << durationPush.count() << " seconds\n";

    size_t memoryUsed = n * (sizeof(T) + sizeof(State));
    std::cout << "Memory used: " << memoryUsed << " bytes\n";

    auto startPop = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        stack.pop();
    }
    auto endPop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationPop = endPop - startPop;
    std::cout << "Pop time: " << durationPop.count() << " seconds\n";

    std::cout << "-----------------------------------\n";
}

int main() {
  int a, b;
  float result;
  testPerformanceForTL<int>(100);
  testPerformanceForTL<int>(1000);
  testPerformanceForTL<int>(10000);
  testPerformanceForTL<int>(100000);

  testPerformanceForDM<int>(100);
  testPerformanceForDM<int>(1000);
  testPerformanceForDM<int>(10000);
  testPerformanceForDM<int>(100000);

  a = 1; b = 4;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  a = 1; b = 0;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  return 0;
}

#endif  // EASY_EXAMPLE
