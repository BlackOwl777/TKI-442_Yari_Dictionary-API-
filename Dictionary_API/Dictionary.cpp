#include "pch.h"
#include "Dictionary.h"
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>

namespace dictionary {

    class Dictionary {
    private:
        std::map<std::string, std::string> data; // Хранение ключей и значений

    public:
        // Конструктор по умолчанию
        Dictionary() {}

        // Добавление ключа и значения
        void insert(const std::string& key, const std::string& value) {
            if (data.find(key) != data.end()) {
                throw std::invalid_argument("Ключ уже существует!");
            }
            data[key] = value;
        }

        // Получение значения по ключу
        std::string get(const std::string& key) const {
            auto it = data.find(key);
            if (it == data.end()) {
                throw std::out_of_range("Ключ не найден!");
            }
            return it->second;
        }

        // Удаление ключа
        void remove(const std::string& key) {
            auto it = data.find(key);
            if (it == data.end()) {
                throw std::out_of_range("Ключ не найден!");
            }
            data.erase(it);
        }

        // Проверка наличия ключа
        bool contains(const std::string& key) const {
            return data.find(key) != data.end();
        }

        // Печать всех ключей и значений
        void print() const {
            for (const auto& pair : data) {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }
        }

        // Очистка словаря
        void clear() {
            data.clear();
        }

        // Проверка, пуст ли словарь
        bool isEmpty() const {
            return data.empty();
        }
    };

} // namespace dictionary

