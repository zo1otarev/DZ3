//Copyright 2020 zo1otarev

#include "header.h"

int main() {

    setlocale(LC_ALL, "Russian");

    std::cout << "Вы можете воспользоваться выражениями:" << std::endl;
    std::cout << "cos()  sin()  tan()  ctn()  exp()  //Сохраняйте пунктуацию" << std::endl;
    std::cout << "Бинарными операторами: +  -  *  /" << std::endl;
    std::cout << "Скобками: ()" << std::endl;
    std::cout << "Вещественные числа записывайте через точку. Пример: 145.78978" << std::endl;
    std::cout << "Также вы можете использовать унарный минус (Для коректной работы используйте скобки)" << std::endl;
    std::cout << "Пример: 42*(-1)" << std::endl;
    std::cout << "Вы можете пользоваться константой pi и переменной x (вам будет предложено ввевсти её)" << std::endl;
    std::cout << "Выражение записывайте без пробелов, соблюдая пунктуацию описанную выше" << std::endl;
    std::cout << "Пример: cos((-pi)/6)*((sin(x)+1)*2+(12/1.52093+x)) " << std::endl;
    std::cout << "Введите ваше выражение: ";
    std::string a;
    getline(std::cin, a);
    std::cout << "Введите - сколько знаков после запятой вы хотите видеть (не более 10): ";
    int accuracy;
    std::cin >> accuracy;

    std::string PI;
    std::ostringstream stream;
    stream << std::setprecision(22) << M_PI;
    PI = stream.str();

    std::string x;
    if (std::count(a.begin(), a.end(), 'x') > 0) {
        std::cout << "Введите x:  ";
        std::cin >> x;
    }

    for (size_t i = 0; (i = a.find('x', i)) != std::string::npos; i += x.size())
        a.replace(i, 1, x);
    for (size_t i = 0; (i = a.find("cos", i)) != std::string::npos; i++)
        a.replace(i, 3, "c");
    for (size_t i = 0; (i = a.find("sin", i)) != std::string::npos; i++)
        a.replace(i, 3, "s");
    for (size_t i = 0; (i = a.find("tan", i)) != std::string::npos; i++)
        a.replace(i, 3, "t");
    for (size_t i = 0; (i = a.find("ctn", i)) != std::string::npos; i++)
        a.replace(i, 3, "k");
    for (size_t i = 0; (i = a.find("exp", i)) != std::string::npos; i++)
        a.replace(i, 3, "e");
    for (size_t i = 0; (i = a.find("pi", i)) != std::string::npos; i += PI.length())
        a.replace(i, 2, PI);
    for (size_t i = 0; (i = a.find('-', i)) != std::string::npos; i++)
        if (isdigit(a[i - 1]) == 0 && a[i - 1] != ')')
            a.replace(i, 1, "m");

    int amount = std::count(a.begin(), a.end(), ')');
    if (amount != std::count(a.begin(), a.end(), ')')) {
        std::cout << "Неправильно записано выражение" << std::endl;
        return 1;
    }

    for (int i = 0; i < amount; i++) {
        for (size_t m = 0; (m = a.find('-', m)) != std::string::npos; m++)
            if (isdigit(a[m - 1]) == 0 && a[m - 1] != ')')
                a.replace(m, 1, "m");
        int p2 = a.find(')');
        int p1 = a.rfind('(', p2);
        std::string sub = a.substr(p1 + 1, p2 - p1 - 1);
        sub = rpn(sub);
        sub = Count(sub);
        a.replace(p1, p2 - p1 + 1, sub);
    }

    for (size_t m = 0; (m = a.find('-', m)) != std::string::npos; m++)
        if (isdigit(a[m - 1]) == 0 && a[m - 1] != ')')
            a.replace(m, 1, "m");
    a = rpn(a);
    Count(a);
    char *end;
    double t = strtod(a.c_str(), &end);
    std::cout << std::setprecision(accuracy) << t << std::endl;

    return 0;
}
