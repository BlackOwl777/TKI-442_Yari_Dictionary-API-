#include "Dictionary.h"
#include <iostream>

int main() {
    dictionary::Dictionary dict;

    std::cout << "Добавление элементов в словарь:" << std::endl;
    dict.insert("apple", "яблоко");
    dict.insert("banana", "банан");
    dict.insert("cherry", "вишня");
    dict.insert("date", "финик");

    dict.print();

    std::cout << "Проверка наличия ключа 'banana': ";
    if (dict.contains("banana")) {
        std::cout << "Ключ существует. Значение: " << dict.get("banana") << std::endl;
    }
    else {
        std::cout << "Ключ отсутствует." << std::endl;
    }

    std::cout << "Удаление ключа 'banana'." << std::endl;
    dict.remove("banana");
    dict.print();

    std::cout << "Попытка получить удалённый ключ 'banana':" << std::endl;
    try {
        std::cout << dict.get("banana") << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}

