#pragma once
#include "Lesson.h"
#include <vector>
#include <csdtdef>

// Состояния конечного автомата (State Machine)
// Каждый экран тренажера - это отдельное состояние
enum class AppState
{
    MENU,               // Главное меню
    PLAYING,            // Активный режим прохождения
    LESSON_COMPLETE,    // Экран завершения
    EXIT                // Выход
};

// Главный движок
// Реализует паттерн State Machine для управления состояниями
class TrainerEngine
{
    public:
        TrainerEngine();
        // Обработать ввод пользователя
        void update(char input);
        // Отрисовать текущее состояние
        void render() const;
        // Проверить, работает ли главный цикл
        bool isRunning() const 
        {
            return state_ != AppState::EXIT;
        }
        // Получить статистику
        int getCompletedLessons() const
        {
            return completed_lessons_;
        }
        int getTotalKeystrokes() const
        {
            return total_keystrokes_;
        }
    private:
        AppState state_ = AppState::MENU;
        vector<Lesson> lessons_;
        size_t current_lesson_idx_ = 0;
        size_t current_key_idx_ = 0;

        // Статистика
        int completed_lessons_ = 0;
        int total_keystrokes_ = 0;

        // Обработчики ввода для каждого состояния
        void renderMenu() const;
        void renderPlaying() const;
        void renderComplete() const;

        // Инициализация всех уроков
        void initializeLessons();
};