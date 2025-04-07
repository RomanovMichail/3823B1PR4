// Copyright 2024 Marina Usova
// единичные тесты
#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE
#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include "../lib_easy_example/easy_example.h"
#include "../lib_dmassive/dmassive.h"
#include"..\lib_list\List.h"
#include "..\lib_stack_tl\StackTL.h"
#include "..\lib_stack_dm\StackDM.h"
#include "../lib_tbinsearchtree/tbinsearchtree.h"
#include"../lib_minheap/MinHeap.h"
#include"../lib_dsu/dsu.h"


template <typename T>
void testPerformanceForDMassiveEdinichSl(int n) {
    TDMassive<T> mas;
    std::cout << "TEST FOR DMassive Edinich " << std::endl;
    std::cout << "Elements " << n << " \n";
    auto startPush = std::chrono::high_resolution_clock::now();
   
        mas.push_back(522);

    
     
    auto endPush = std::chrono::high_resolution_clock::now();
    auto durationPush = std::chrono::duration_cast<std::chrono::milliseconds>(endPush - startPush);
    std::cout << "Push time: " << durationPush.count() << " milliseconds\n";

    size_t memoryUsed = n * (sizeof(T) + sizeof(State));
    std::cout << "Memory used: " << memoryUsed << " bytes\n";

   

   /* auto startFind = std::chrono::high_resolution_clock::now();
    mas.find_all(5222);
    auto endFind = std::chrono::high_resolution_clock::now();
    auto durationFind = std::chrono::duration_cast<std::chrono::milliseconds>(endFind - startFind);
    std::cout << "Find time: " << durationFind.count() << " milliseconds\n*//*";*/
   
    auto startPop = std::chrono::high_resolution_clock::now();
  
    mas.pop_back();
    
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
    for (size_t i = 0; i < n; i++)
    {
        mas.push_back(i);

    }

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

   
        l.push_front(999);

    

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
    
    
        l.pop_front();

    
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
    for (size_t i = 0; i < n; i++)
    {
        l.push_back(i);

    }
    auto startPush = std::chrono::high_resolution_clock::now();
   
    
        l.push_back(999);

    
  
    auto endPush = std::chrono::high_resolution_clock::now();
    auto durationPush = std::chrono::duration_cast<std::chrono::milliseconds>(endPush - startPush);
    std::cout << "Push time: " << durationPush.count() << " milliseconds\n";

    size_t memoryUsed = n * (sizeof(T) + sizeof(TNode<T>));
    std::cout << "Memory used: " << memoryUsed << " bytes\n";
    
    auto startPop = std::chrono::high_resolution_clock::now();
    
        l.pop_back();

    
    auto endPop = std::chrono::high_resolution_clock::now();
    auto durationPop = std::chrono::duration_cast<std::chrono::milliseconds>(endPop - startPop);
    std::cout << "Pop time: " << durationPop.count() << " milliseconds\n";
    
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


int get_random(int min, int max) {
    return min + rand() % (max - min + 1);
}

void print_maze(const TDMassive<int>& maze, size_t height, size_t width) {
    int max_num = *std::max_element(maze.data(), maze.data() + maze.size());
    int cell_width = std::to_string(max_num).length() + 1;

    std::cout << std::string(width * (cell_width + 1) + 1, '-') << std::endl;

    for (size_t i = 0; i < height; ++i) {
        std::cout << "|";
        for (size_t j = 0; j < width; ++j) {
            size_t index = i * width + j;
            std::cout << std::string(cell_width - std::to_string(maze.data()[index]).length(), ' ');
            std::cout << maze.data()[index] << "|";
        }
        std::cout << std::endl;
        std::cout << std::string(width * (cell_width + 1) + 1, '-') << std::endl;
    }
}


void generate_maze(size_t height, size_t width) {
    size_t size = height * width;
    TDMassive<int> maze(size);
    DSU dsu(size);

    for (size_t i = 0; i < size; ++i) {
        maze.replace(i, i + 1); 
    }
    srand(time(nullptr));
    size_t walls_to_remove = size - 1; 

    while (walls_to_remove > 0) {
        size_t cell = get_random(0, size - 1);
        int direction = get_random(0, 3); 

        size_t neighbor = cell;

        switch (direction) {
        case 0:
            if (cell >= width) neighbor = cell - width;
            break;
        case 1: 
            if ((cell + 1) % width != 0) neighbor = cell + 1;
            break;
        case 2: 
            if (cell < size - width) neighbor = cell + width;
            break;
        case 3: 
            if (cell % width != 0) neighbor = cell - 1;
            break;
        }

        if (neighbor != cell && dsu.find(cell) != dsu.find(neighbor)) {
            dsu.union_sets(cell, neighbor);
            walls_to_remove--;

            int root = dsu.find(cell);
            maze.replace(cell, root + 1);
            maze.replace(neighbor, root + 1);
        }
    }

    std::cout << "\nGenerated maze:" << std::endl;
    print_maze(maze, height, width);

}   
int main() {

    size_t height = 5;
    size_t width = 5;

    generate_maze(height, width);

    return 0;
  

}
#endif