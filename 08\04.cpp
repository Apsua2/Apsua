#include <iostream>
#include <string>

double divide(int a, int b) 
{
    if (b) {
        double result = double(a) / b;
        return result;
    }
    throw std::string{"На нуль делить нельзя\n"};
}

int main()
{
    int a;
    int b;
    std::string input;
    
    std::cout << "Введите первое число: ";
    std::cin >> input;
    
    try {
        a = std::stoi(input);
    } catch (const std::invalid_argument& e) {
        std::cout << "Не заходи сюда больше." << std::endl;
        return 1;
    }
    
    std::cout << "Введите второе число: ";
    std::cin >> input;

    try {
        b = std::stoi(input);
    } catch (const std::invalid_argument& e) {
        std::cout << "Не заходи сюда больше." << std::endl;
        return 1;
    }
    
    try {
        double result = divide(a, b);
        std::cout << result << std::endl;
    } catch (std::string error_message) {
        std::cout << error_message << std::endl;
    }
    
    std::cout << "The End..." << std::endl;
    
    return 0;
}

