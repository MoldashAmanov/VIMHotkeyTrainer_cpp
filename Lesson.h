#pragma once
#include <string>
#include <vector>

using namespace std;

// Модель данных урока
// Инкапсулирует всю информацию об одном уроке тренажера
class Lesson
{
    public:
        // Конструктор с move - для эффективности
        Lesson(string name, string description, string target_keys, int difficulty = 1)
            : name_(move(name)), description_(move(description)),
            target_keys_(move(target_keys)), difficulty_(difficulty) {}

        // Геттеры (const, чтобы нельзя было изменить извне)
        const string& getName() const
        {
            return name_;
        }
        const string& getDescription() const
        {
            return description_;
        }
        const string& getTargetKeys() const
        {
            return target_keys_;
        }
        int getDifficulty() const
        {
            return difficulty_;
        }
    private:
        string name_;           // Название урока
        string description_;    // Описание и подсказки
        string target_keys_;    // Целевая последовательность клавиш
        int difficulty_;        // Уровень сложности (1-10)         
};