#pragma once
#include <unordered_map>
#include <string>
#include <iostream>

/**
 * @brief Пространство имён для словаря.
 *
 * Содержит реализацию класса Dictionary.
 */
namespace dictionary {

    /**
     * @brief Класс Словарь.
     *
     * Реализует базовые операции со словарём, такие как добавление пары ключ-значение,
     * удаление, получение значения по ключу и проверка наличия ключа.
     */
    class Dictionary {
    private:
        /**
         * @brief Внутреннее хранилище данных словаря.
         *
         * Использует `std::unordered_map` для быстрого доступа по ключу.
         */
        std::unordered_map<std::string, std::string> data;

    public:
        /**
         * @brief Конструктор словаря.
         *
         * Создаёт пустой словарь.
         */
        Dictionary();

        /**
         * @brief Добавляет пару ключ-значение в словарь.
         *
         * @param key Ключ для добавления.
         * @param value Значение для добавления.
         */
        void insert(const std::string& key, const std::string& value);

        /**
         * @brief Удаляет пару ключ-значение по заданному ключу.
         *
         * @param key Ключ для удаления.
         * @throws std::runtime_error Если ключ отсутствует.
         */
        void remove(const std::string& key);

        /**
         * @brief Возвращает значение по заданному ключу.
         *
         * @param key Ключ для поиска.
         * @return Значение, соответствующее ключу.
         * @throws std::runtime_error Если ключ отсутствует.
         */
        std::string get(const std::string& key) const;

        /**
         * @brief Проверяет, существует ли ключ в словаре.
         *
         * @param key Ключ для проверки.
         * @return true, если ключ существует, иначе false.
         */
        bool contains(const std::string& key) const;

        /**
         * @brief Выводит содержимое словаря на экран.
         *
         * Выводит все пары ключ-значение.
         */
        void print() const;
    };

} // namespace dictionary
