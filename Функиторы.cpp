// -----1-----

// #include <iostream>
// #include <string>

// class SimpleFunctor {
//     std::string name_;
// public:
//     SimpleFunctor(const char *name) : name_(name) {}
//     void operator()() { std::cout << "Oh, hello, " << name_ << std::endl; }
// };

// int main() {
//     SimpleFunctor sf("catonmat");
//     sf();  // выводит "Oh, hello, catonmat"
// }

// -----2-----

// #include <algorithm>
// #include <iostream>
// #include <list>

// class EvenOddFunctor {
//     int even_;
//     int odd_;
// public:
//     EvenOddFunctor() : even_(0), odd_(0) {}
//     void operator()(int x) {
//         if (x%2 == 0) even_ += x;
//         else odd_ += x;
//     }
//     int even_sum() const { return even_; }
//     int odd_sum() const { return odd_; }
// };

// int main() {
//     EvenOddFunctor evenodd;
    
//     int my_list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//     evenodd = std::for_each(my_list,
//                   my_list+sizeof(my_list)/sizeof(my_list[0]),
//                   evenodd);

//     std::cout << "Сумма чётных: " << evenodd.even_sum() << "\n";
//     std::cout << "Сумма нечётных: " << evenodd.odd_sum() << std::endl;

    // вывод:
    // Сумма чётных: 30
    // Сумма нечётных: 25
// }

// -----3-----

// Пример функтора, который умножает число на определенное значение:

#include <algorithm>
#include <iostream>
#include <list>

class Multiplier {
public:
    Multiplier(int factor) : factor_(factor) {}

    int operator()(int value) {
        return value * factor_;
    }

private:
    int factor_;
};

int main() {
    Multiplier multiplyBy2(2);
    int result = multiplyBy2(5); // результат: 10
    std::cout << "Результат умножения: " << result << std::endl;
    return 0;
}

// -----4-----

// Пример функтора, который проверяет, является ли число четным:


// #include <algorithm>
// #include <iostream>
// #include <list>

// class IsEven {
// public:
//     bool operator()(int number) {
//         return number % 2 == 0;
//     }
// };

// int main() {
//     IsEven isEven;
//     bool result = isEven(6); // результат: true
//     std::cout << "Результат: " << result << std::endl;
//     return 0;
// }

// -----5-----

// Пример функтора, который сравнивает строки по длине:

// #include <algorithm>
// #include <iostream>
// #include <list>

// class CompareLength {
// public:
//     bool operator()(const std::string& str1, const std::string& str2) {
//         return str1.length() < str2.length();
//     }
// };

// int main() {
//     CompareLength compare;
//     bool result = compare("apple", "banana"); // результат: true
//     std::cout << "Результат: " << result << std::endl;
//     return 0;
// }

// -----6-----

// Пример функтора, который выводит сообщение на экран:

// #include <algorithm>
// #include <iostream>
// #include <list>

// class MessagePrinter {
// public:
//     void operator()(const std::string& message) {
//         std::cout << message << std::endl;
//     }
// };

// int main() {
//     MessagePrinter printer;
//     printer("Hello, world!"); // выводит: Hello, world!
//     return 0;
// }

// -----7-----

// Пример функтора, который вычисляет сумму квадратов двух чисел:


#include <algorithm>
#include <iostream>
#include <list>

class SumOfSquares {
public:
    int operator()(int num1, int num2) {
        return num1 * num1 + num2 * num2;
    }
};

int main() {
    SumOfSquares sum;
    int result = sum(3, 4); // результат: 25 (3^2 + 4^2)
    std::cout << "Результат: " << result << std::endl;
    return 0;
}
