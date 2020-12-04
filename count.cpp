//Copyright 2020 zo1otarev

#include "header.h"

std::string Count(std::string &str) {

    std::map<char, std::function<double(const double &, const double &)>> operations;
    operations['+'] = [](const double &a, const double &b) { return a + b; };
    operations['-'] = [](const double &a, const double &b) { return a - b; };
    operations['*'] = [](const double &a, const double &b) { return a * b; };
    operations['/'] = [](const double &a, const double &b) { return a / b; };

    std::map<char, std::function<double(const double &)>> unary;
    unary['c'] = [](const double &a) { return cos(a); };
    unary['s'] = [](const double &a) { return sin(a); };
    unary['t'] = [](const double &a) { return round(tan(a)*pow(10,12))/pow(10,12); };
    unary['k'] = [](const double &a) { return round(cos(a)/sin(a)*pow(10,12))/pow(10,12); };
    unary['e'] = [](const double &a) { return exp(a); };

    std::string expression = str, n;
    std::stack<double> stack_;
    double number;
    bool flag = true;
    char flag1 = 'a';
    char *end;

    for (auto i = expression.begin(); i < expression.end(); i++) {
        if (isdigit(*i) || *i == '.' || *i == 'm') {
            if (*i == 'm') n += '-';
            else n += *i;
            flag = true;
        } else {
            if (*i != ' ') {
                if (*i == 'c' || *i == 's' || *i == 't' || *i == 'k' || *i == 'e') {
                    flag1 = *i;
                    continue;
                }
                double num2 = stack_.top();
                stack_.pop();
                double num1 = stack_.top();
                stack_.pop();
                stack_.push(operations[*i](num1, num2));
                flag = false;
            } else if (*i == ' ' && flag) {
                number = strtod(n.c_str(), &end);
                if (flag1 != 'a') {
                    number = unary[flag1](number);
                    flag1 = 'a';
                }
                if (number == 0)
                    number = 0;
                stack_.push(number);
                n.clear();
            }
        }
    }

    std::ostringstream stream1;
    stream1 << std::setprecision(15) << stack_.top();
    str = stream1.str();

    return str;
}
