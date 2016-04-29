//
//  Calculator.hpp
//  Simple Calculator
//
//  Created by Nicholas.L.Y on 2016/4/29.
//  Copyright © 2016年 廖颖泓. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
bool isNumber(char a) {
    return (a >= '0' && a <= '9');
}
bool isOperator(char a) {
    return (a == '+' || a == '-');
}
class calculator {
    public:
        calculator() {}
        ~calculator() {}
        int calculate(string a) throw(ExpressionException,
            IllegalSymbolException,
            MissingOperatorException,
            MissingOperandException,
            EmptyExpressionException) {
            if (a.empty()) throw EmptyExpressionException();
            int len = a.length();
            int amount = 0;
            char _operator;
            for (int i = 0; i < len; i++) {
                if (!isNumber(a[i]) && !isOperator(a[i])) {
                    throw IllegalSymbolException(i);
                }
                else if (isOperator(a[i]) && i % 2 == 0) {
                    throw MissingOperandException(i);
                }
                else if (isNumber(a[i]) && i % 2 == 0) {
                    if (i == 0) {
                        amount = a[i] - '0';
                    } else {
                        if (_operator == '+') amount += a[i] - '0';
                        else if (_operator == '-') amount -= a[i] - '0';
                    }
                }
                else if (isOperator(a[i]) && i % 2 == 1) {
                    _operator = a[i];
                }
                else if (isNumber(a[i]) && i % 2 == 1) {
                    throw MissingOperatorException(i);
                }
            }
            if (len % 2 == 0 && isOperator(a[len - 1])) {
                throw MissingOperandException(len);
            }
            return amount;
        }
};
