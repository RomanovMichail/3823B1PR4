#include "C:\Michail_Romanov\3823B1PR4\lib_parser\Parser.h"
#include "C:\Michail_Romanov\3823B1PR4\lib_stack\Stack.h"
#include<iostream>



bool IsCorrect(std::string exp) {
    TStack<char> stack = TStack<char>(exp.length());
    for (int i = 0; i < stack._size; i++) {
        if (exp[i] == '(' ||  exp[i] == '[' || exp[i] == '|') {
            stack.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '|') {
            if (stack.isEmpty()) {
                throw std::logic_error("there is no opening bracket");
            }
            else if (stack._data[stack._top] == exp[i]) {
                stack.pop();
            }
            else {
                throw std::logic_error("brackets are not equal");
            }
        }
        else if ((exp[i] < '0' || exp[i]>'9') && (exp[i] < 'A' || exp[i] != 'z' || exp[i] != '-')) {
            throw std::logic_error("unidentified object");
        }
    }
    if (stack.isEmpty() == true) {
        throw std::logic_error("The stack is not empty");
    }
    return true;
}
