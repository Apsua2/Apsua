#include <iostream>

class AgeException {
private:
    std::string message;    

public: 
    AgeException(std::string _message): message{_message} {} // Конструктор инициализации сообщения об ошибке
    virtual std::string getMessage() const { // Виртуальная функция для получения сообщения об ошибке
        return message;
    }
};

class MaxAgeException: public AgeException {
public: 
    MaxAgeException(std::string _message, int _maxAge): AgeException{_message}, maxAge{_maxAge} {} // Конструктор инициализации сообщения и максимального возраста
    std::string getMessage() const override { // Переопределение виртуальной функции для вывода сообщения с максимальным возрастом
        return AgeException::getMessage() + " Max age should be " + std::to_string(maxAge);
    }
private:
    int maxAge;
};

class Person {
public:
    Person(std::string name, int age) {
        if (age < 1) { // Проверка на нулевой возраст
            throw AgeException{"So small age"};
        }
        if (age > 110) { // Проверка на максимальный возраст
            throw MaxAgeException{"Invalid age.", 110};
        }
        this->name = name;
        this->age = age;
    }
    void print() const {
        std::cout << "Name: " << name << "\tAge: " << age << std::endl;
    }
private:
    std::string name;
    int age;
};

int main() {
    try {
        Person bob{"Bob", 15}; // Создание объекта bob
        bob.print(); // Вывод информации о bob
        
        Person tom{"Tom", -15}; // Попытка создать объект tom с отрицательным возрастом
        bob.print(); // Вывод информации о bob (ошибка в коде, должно быть tom.print())
    }
    catch (const AgeException& ex) {
        std::cout << ex.getMessage() << std::endl; // Обработка и вывод сообщения об ошибке
    }
}
