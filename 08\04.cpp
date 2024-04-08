#include <iostream>

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
    std::cout << "Введите первое число: " << std::endl;
    std::cin >> a;
    std::cout << "Введите второе число: " << std::endl;
    std::cin >> b;
    
    try{
        double result = divide(a, b);
        std::cout << result << std::endl;
    } 
    catch (std::string error_message) {
        std::cout << error_message << std::endl;
    }
    std::cout << "The End..." << std::endl;
    
    return 0;
}
