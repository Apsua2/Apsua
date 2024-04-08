#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool isPositiveInteger(const std::string& s) {
    return !s.empty() && s.find_first_not_of("0123456789") == std::string::npos;
}

int main() {
    std::ifstream inputFile("numbers.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл" << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    std::string line;

    if (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string numberStr;

        while (iss >> numberStr) {
            if (!isPositiveInteger(numberStr)) {
                std::cerr << "Ошибка: файл должен содержать только целые положительные числа" << std::endl;
                return 1;
            }

            int number = std::stoi(numberStr);
            numbers.push_back(number);
        }

        std::string remainingLines;
        if (std::getline(inputFile, remainingLines)) {
            std::cerr << "Ошибка: числа должны быть расположены в одной строке" << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Ошибка: файл пустой" << std::endl;
        return 1;
    }

    inputFile.close();

    // Находим максимальное и минимальное число
    if (!numbers.empty()) {
        int maxNum = numbers[0];
        int minNum = numbers[0];

        for (int num : numbers) {
            if (num > maxNum) {
                maxNum = num;
            }
            if (num < minNum) {
                minNum = num;
            }
        }

        std::cout << "Максимальное число: " << maxNum << std::endl;
        std::cout << "Минимальное число: " << minNum << std::endl;
    } else {
        std::cerr << "Вектор чисел пустой" << std::endl;
        return 1;
    }

    return 0;
}
