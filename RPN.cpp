//Copyright 2020 zo1otarev

#include "header.h"

std::string rpn(std::string &a) {
    std::stack<char> sign;
    std::string b;
    int flag = 1;
    for (auto i = a.begin(); i < a.end(); i++) {
        if (isdigit(*i) || *i == 'c' || *i == 's' || *i == 't' || *i == 'k' || *i == 'e' || *i == 'm' || *i == '.')
            b.push_back(*i);
        else if (*i == '+' || *i == '-' || *i == '/' || *i == '*') {
            b.push_back(' ');
            if (*i == '+' || *i == '-') {
                if (flag == 1) sign.push(*i);
                if (flag == 2) {
                    for (int n = 0; n < sign.size();) {
                        b += sign.top();
                        b += ' ';
                        sign.pop();
                    }
                    sign.push(*i);
                    flag = 1;
                }
            }
            if (*i == '*' || *i == '/') {
                sign.push(*i);
                flag = 2;
            }
        }

    }
    b.push_back(' ');
    for (int n = 0; n < sign.size();) {
        b += sign.top();
        b += ' ';
        sign.pop();
    }
    return b;
}
