﻿#pragma once

#ifndef STACK_H
#define STACK_H
#include <vector>
#include <string>
#include <stdexcept>

/**
 * @brief Класс, реализующий структуру данных "Стек" для целых чисел.
 *
 * Стек реализован на основе динамического массива `std::vector<int>`.
 * Поддерживает стандартные операции добавления, удаления элементов,
 * проверки состояния и поиска элементов.
 */
class Stack {
public:
    /**
     * @brief Конструктор по умолчанию.
     *
     * Инициализирует пустой стек.
     */
    Stack();


    /**
     * @brief Добавляет элемент на вершину стека.
     *
     * @param value Значение типа `int`, которое будет добавлено в стек.
     */
    void push(int value);

    /**
     * @brief Удаляет элемент с вершины стека и возвращает его.
     *
     * @return Значение типа `int`, которое было удалено с вершины стека.
     * @throws std::out_of_range Если стек пустой.
     */
    int pop();

    /**
     * @brief Возвращает значение элемента на вершине стека без его удаления.
     *
     * @return Значение типа `int`, находящееся на вершине стека.
     * @throws std::out_of_range Если стек пустой.
     */
    int top() const;

    /**
     * @brief Проверяет, пуст ли стек.
     *
     * @return `true`, если стек пустой, иначе `false`.
     */
    bool empty() const;

    /**
     * @brief Возвращает количество элементов в стеке.
     *
     * @return Размер стека типа `size_t`.
     */
    size_t size() const;

    /**
     * @brief Проверяет, содержится ли заданное значение в стеке.
     *
     * @param value Значение типа `int`, которое необходимо найти в стеке.
     * @return `true`, если значение найдено, иначе `false`.
     */
    bool contains(int value) const;

    /**
     * @brief Возвращает строковое представление стека.
     *
     * Формат строки: [элемент1, элемент2, ..., элементN]
     *
     * @return Строка, представляющая содержимое стека.
     */
    std::string toString() const;

private:
    std::vector<int> data_; ///< Внутреннее хранилище элементов стека.
};

#endif