#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "..\lib_list\List.h"
#include "..\lib_list\Node.h"
#include "..\lib_stack_dm\StackDM.h"

enum ParsingErrorType {
    EXTRA_BRACKET = 1,
    MISSING_BRACKET = 2,
    MISMATCHED_BRACKET = 3,
    UNVALID_BRACKET = 4,
    NON_ERROR = 0
};

enum LexemType {
    BRACKET,
    VARIABLE,
    OPERATION,
    FUNCTION,
    INT_CONST,
    FLOAT_CONST,
    NONE
};


bool is_number(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

bool is_string(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z');
}

bool is_operation(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^';
}

bool is_function(const std::string& exp) {
    static const std::string functions[] = { "sin", "cos", "tg", "ctg" };
    for (const auto& func : functions) {
        if (exp == func)
            return true;
    }
    return false;
}


class Lexem {
public:
    std::string _name;
    LexemType _type;

    Lexem(std::string name, LexemType type) : _name(name), _type(type) {}
    Lexem() : _name(""), _type(NONE) {}

    void set_name(std::string name) { _name = name; }
    void set_type(LexemType type) { _type = type; }

    std::string name() const { return _name; }
    LexemType type() const { return _type; }

    friend std::ostream& operator<<(std::ostream& out, const Lexem& lexem);
};

std::ostream& operator<<(std::ostream& out, const Lexem& lexem) {
    out << lexem._name;
    return out;
}


class FloatConst : public Lexem {
    float _value;
public:
    FloatConst(std::string exp) : Lexem(exp, FLOAT_CONST), _value(0.0f) {
        size_t curr_pos = 0;
        float result = 0.0f;

        while (curr_pos < exp.size() && is_number(exp[curr_pos])) {
            result = result * 10 + (exp[curr_pos] - '0');
            curr_pos++;
        }

        if (curr_pos < exp.size() && exp[curr_pos] == '.') {
            curr_pos++;
            float fraction = 0.0f;
            float divisor = 10.0f;

            while (curr_pos < exp.size() && is_number(exp[curr_pos])) {
                fraction += (exp[curr_pos] - '0') / divisor;
                divisor *= 10;
                curr_pos++;
            }
            result += fraction;
        }

        _value = result;
    }

    float value() const { return _value; }
};

class IntConst : public Lexem {
    int _value;
public:
    IntConst(std::string exp) : Lexem(exp, INT_CONST), _value(0) {
        for (char c : exp) {
            if (is_number(c)) {
                _value = _value * 10 + (c - '0');
            }
            else {
                throw std::logic_error("Invalid integer constant");
            }
        }
    }

    int value() const { return _value; }
};



class Expression {
    TList<Lexem> _expression;

public:
    Expression(std::string exp) {
        delete_spaces(exp);
        parse(exp);
        check();
    }

    void print() const {
        for (const auto& lexem : _expression) {
            std::cout << lexem << " ";
        }
        std::cout << std::endl;
    }

private:
    void delete_spaces(std::string& exp) {
        exp.erase(std::remove(exp.begin(), exp.end(), ' '), exp.end());
    }

    void parse(const std::string& exp) {
        size_t curr_pos = 0;
        while (curr_pos < exp.size()) {
            if (is_number(exp[curr_pos])) {
                size_t start_pos = curr_pos;
                while (curr_pos < exp.size() && is_number(exp[curr_pos])) { curr_pos++; }
                if (curr_pos < exp.size() && exp[curr_pos] == '.') {
                    curr_pos++;
                    while (curr_pos < exp.size() && is_number(exp[curr_pos])) { curr_pos++; }
                    _expression.push_back(FloatConst(exp.substr(start_pos, curr_pos - start_pos)));
                }
                else {
                    _expression.push_back(IntConst(exp.substr(start_pos, curr_pos - start_pos)));
                }
            }
            else if (is_operation(exp[curr_pos])) {
                _expression.push_back(Operation(std::string(1, exp[curr_pos])));
                curr_pos++;
            }
            else if (is_string(exp[curr_pos])) {
                size_t start_pos = curr_pos;
                while (curr_pos < exp.size() && is_string(exp[curr_pos])) { curr_pos++; }
                std::string token = exp.substr(start_pos, curr_pos - start_pos);
                if (is_function(token)) {
                    _expression.push_back(Function(token));
                }
                else {
                    _expression.push_back(Variable(token));
                }
            }
            else if (exp[curr_pos] == '(' || exp[curr_pos] == ')') {
                _expression.push_back(Bracket(std::string(1, exp[curr_pos])));
                curr_pos++;
            }
            else {
                throw std::logic_error("Incorrect symbol in expression");
            }
        }
    }

    void check() {
        TStackDM<char> stack;
        for (const auto& lexem : _expression) {
            if (lexem.type() == BRACKET) {
                if (lexem.name() == "(") {
                    stack.push('(');
                }
                else if (lexem.name() == ")") {
                    if (stack.empty() || stack.top() != '(') {
                        throw std::logic_error("Mismatched brackets");
                    }
                    stack.pop();
                }
            }
        }
        if (!stack.empty()) {
            throw std::logic_error("Extra opening bracket");
        }
    }
}