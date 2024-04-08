#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

// Функция для проверки, является ли строка положительным целым числом
bool isPositiveInteger(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    // Открываем файл numbers.txt для чтения
    std::ifstream inputFile("numbers.txt");
    
    // Проверяем, успешно ли открыт файл
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return 1;
    }
    
    // Вектор для хранения чисел из файла
    std::vector<int> numbers;
    std::string line;
    
    // Считываем файл построчно
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string numberStr;
        
        // Читаем каждое слово из строки
        while (iss >> numberStr) {
            // Проверяем, является ли слово положительным целым числом
            if (!isPositiveInteger(numberStr)) {
                std::cerr << "Ошибка: файл должен содержать только целые положительные числа" << std::endl;
                return 1;
            }
            
            // Преобразуем строку в число и добавляем его в вектор
            int number = std::stoi(numberStr);
            numbers.push_back(number);
        }
    }
    
    // Проверяем, что файл не пустой
    if (numbers.empty()) {
        std::cerr << "Ошибка: файл пустой" << std::endl;
        return 1;
    }
    
    // Находим минимальное и максимальное числа в векторе
    int min = numbers[0];
    int max = numbers[0];
    
    for (int num : numbers) {
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }
    
    // Выводим минимальное и максимальное числа
    std::cout << "Наименьшее число: " << min << std::endl;
    std::cout << "Наибольшее число: " << max << std::endl;
    
    // Закрываем файл
    inputFile.close();
    
    return 0;
}
