// Copyright 2024 Marina Usova
// единичные тесты
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
void testPerformanceForDMassiveEdinichSl(int n) {
    TDMassive<T> mas;
    std::cout << "TEST FOR DMassive Edinich " << std::endl;
    std::cout << "Elements " << n << " \n";
    auto startPush = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < n; i++)
    {
        mas.push_back(i);

    }
     
    auto endPush = std::chrono::high_resolution_clock::now();
    auto durationPush = std::chrono::duration_cast<std::chrono::milliseconds>(endPush - startPush);
    std::cout << "Push time: " << durationPush.count() << " milliseconds\n";

    size_t memoryUsed = n * (sizeof(T) + sizeof(State));
    std::cout << "Memory used: " << memoryUsed << " bytes\n";

   

    auto startFind = std::chrono::high_resolution_clock::now();
    mas.find_all(5222);
    auto endFind = std::chrono::high_resolution_clock::now();
    auto durationFind = std::chrono::duration_cast<std::chrono::milliseconds>(endFind - startFind);
    std::cout << "Find time: " << durationFind.count() << " milliseconds\n";
   
    auto startPop = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < n; ++i)
    {
    mas.pop_back();
    }
    auto endPop = std::chrono::high_resolution_clock::now();
    auto durationPop = std::chrono::duration_cast<std::chrono::milliseconds>(endPop - startPop);
    std::cout << "Pop time: " << durationPop.count() << " milliseconds\n";

    std::cout << "-----------------------------------\n";

}



template <typename T>
void testPerformanceForDMassiveFront(int n) {
    TDMassive<T> mas(n);
    std::cout << "TEST FOR DMassive Front " << std::endl;
    std::cout << "Elements " << n << " \n";

    auto startPush = std::chrono::high_resolution_clock::now();

    
    
        mas.push_front(2);

    

    auto endPush = std::chrono::high_resolution_clock::now();
    auto durationPush = std::chrono::duration_cast<std::chrono::milliseconds>(endPush - startPush);
    std::cout << "Push time: " << durationPush.count() << " milliseconds\n";

    size_t memoryUsed = n * (sizeof(T) + sizeof(State));
    std::cout << "Memory used: " << memoryUsed << " bytes\n";

    auto startPop = std::chrono::high_resolution_clock::now();
   
        mas.pop_front();

    
    auto endPop = std::chrono::high_resolution_clock::now();
    auto durationPop = std::chrono::duration_cast<std::chrono::milliseconds>(endPop - startPop);
    std::cout << "Pop time: " << durationPop.count() << " milliseconds\n";

    std::cout << "-----------------------------------\n";

}
template <typename T>
void testPerformanceForListFront(int n) {
    TList<T> l(n);
    std::cout << "TEST FOR LIST Front" << std::endl;
    std::cout << "Elements " << n << " \n";

    auto startPush = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < n; i++)
    {
        l.push_front(i);

    }

    auto endPush = std::chrono::high_resolution_clock::now();
    auto durationPush = std::chrono::duration_cast<std::chrono::milliseconds>(endPush - startPush);
    std::cout << "Push time: " << durationPush.count() << " milliseconds\n";

    size_t memoryUsed = n * (sizeof(T) + sizeof(TNode<T>));
    std::cout << "Memory used: " << memoryUsed << " bytes\n";

    auto startFind = std::chrono::high_resolution_clock::now();
    l.find(999);
    auto endFind = std::chrono::high_resolution_clock::now();
    auto durationFind = std::chrono::duration_cast<std::chrono::milliseconds>(endFind - startFind);
    std::cout << "Find time: " << durationFind.count() << " milliseconds\n";

    auto startPop = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < n; ++i)
    {
        l.pop_front();

    }
    auto endPop = std::chrono::high_resolution_clock::now();
    auto durationPop = std::chrono::duration_cast<std::chrono::milliseconds>(endPop - startPop);
    std::cout << "Pop time: " << durationPop.count() << " milliseconds\n";


    std::cout << "-----------------------------------\n";

}

template <typename T>
void testPerformanceForList(int n) {
    TList<T> l(n);
    std::cout << "TEST FOR LIST " << std::endl;
    std::cout << "Elements " << n << " \n";

    auto startPush = std::chrono::high_resolution_clock::now();
   
    for (size_t i = 0; i < n; i++)
    {
        l.push_back(i);

    }
  
    auto endPush = std::chrono::high_resolution_clock::now();
    auto durationPush = std::chrono::duration_cast<std::chrono::milliseconds>(endPush - startPush);
    std::cout << "Push time: " << durationPush.count() << " milliseconds\n";

    size_t memoryUsed = n * (sizeof(T) + sizeof(TNode<T>));
    std::cout << "Memory used: " << memoryUsed << " bytes\n";
    
   /* auto startPop = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < n; ++i)
    {
        l.pop_back();

    }
    auto endPop = std::chrono::high_resolution_clock::now();
    auto durationPop = std::chrono::duration_cast<std::chrono::milliseconds>(endPop - startPop);
    std::cout << "Pop time: " << durationPop.count() << " milliseconds\n";
    */
    auto startFind = std::chrono::high_resolution_clock::now();
    l.find(999);
    auto endFind = std::chrono::high_resolution_clock::now();
    auto durationFind = std::chrono::duration_cast<std::chrono::milliseconds>(endFind - startFind);
    std::cout << "Find time: " << durationFind.count() << " milliseconds\n";


    std::cout << "-----------------------------------\n";

}

template <typename T>
void testPerformanceForTL(int n) {
    TStackTL<T> stack(n);
    std::cout << "TEST FOR STACK TL " << std::endl;
    std::cout << "Elements " << n << " \n";

    auto startPush = std::chrono::high_resolution_clock::now();
    
        stack.push(52);
    
    auto endPush = std::chrono::high_resolution_clock::now();
    auto durationPush = std::chrono::duration_cast<std::chrono::milliseconds>(endPush - startPush);
    std::cout << "Push time: " << durationPush.count() << " milliseconds\n";

    size_t memoryUsed = n * (sizeof(T) + sizeof(TNode<T>));
    std::cout << "Memory used: " << memoryUsed << " bytes\n";

    auto startPop = std::chrono::high_resolution_clock::now();
 
        stack.pop();
  
    auto endPop = std::chrono::high_resolution_clock::now();
    auto durationPop = std::chrono::duration_cast<std::chrono::milliseconds>(endPop - startPop);
    std::cout << "Pop time: " << durationPop.count() << " milliseconds\n";

    std::cout << "-----------------------------------\n";

}



template <typename T>
void testPerformanceForDM(int n) {
    TStackDM<T> stack(n);
    std::cout << "TEST FOR STACK DM " << std::endl;
    std::cout << "Elements " << n << " \n";

    auto startPush = std::chrono::high_resolution_clock::now();
    
        stack.push(52);
 
    auto endPush = std::chrono::high_resolution_clock::now();
    auto durationPush = std::chrono::duration_cast<std::chrono::milliseconds>(endPush - startPush);
    std::cout << "Push time: " << durationPush.count() << " milliseconds\n";

    size_t memoryUsed = n * (sizeof(T) + sizeof(State));
    std::cout << "Memory used: " << memoryUsed << " bytes\n";

    auto startPop = std::chrono::high_resolution_clock::now();
   
        stack.pop();

    auto endPop = std::chrono::high_resolution_clock::now();
    auto durationPop = std::chrono::duration_cast<std::chrono::milliseconds>(endPop - startPop);
    std::cout << "Pop time: " << durationPop.count() << " milliseconds\n";

    std::cout << "-----------------------------------\n";
}

int main() {
//testPerformanceForDMassiveEdinichSl<int>(1000000);
//testPerformanceForDMassiveEdinichSl<int>(10000000);
//testPerformanceForDMassiveEdinichSl<int>(100000000);

//testPerformanceForDMassiveFRONTPOP<int>(10000);
//testPerformanceForDMassiveFRONTPOP<int>(100000);
//testPerformanceForDMassiveFRONTPOP<int>(1000000);

testPerformanceForDMassiveFront<int>(100);
testPerformanceForDMassiveFront<int>(1000);
testPerformanceForDMassiveFront<int>(10000);
testPerformanceForDMassiveFront<int>(100000);


//testPerformanceForListFront<int>(100000);
//testPerformanceForListFront<int>(1000000);
//testPerformanceForListFront<int>(10000000);
//
//testPerformanceForList<int>(100);
//testPerformanceForList<int>(1000);
//testPerformanceForList<int>(10000);
//testPerformanceForList<int>(100000);
//testPerformanceForList<int>(1000000);
//testPerformanceForList<int>(10000000);
//      
testPerformanceForTL<int>(100000);
testPerformanceForTL<int>(1000000);
testPerformanceForTL<int>(10000000);

testPerformanceForDM<int>(100000);
testPerformanceForDM<int>(1000000);
testPerformanceForDM<int>(10000000);
testPerformanceForDM<int>(100000000);

   
 
    return 0;
}
#endif