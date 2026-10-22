#pragma once

// RAII-класс для управления сырым режимом терминала в Unix-системах
// При создании включает raw mode, при уничтожении - восстанавливает настройки
class TerminalGuide
{
    public:
        TerminalGuide();
        ~TerminalGuide();

        // Запрещаем копирование - ресурс должен быть только один
        TerminalGuide(const TerminalGuide&) = delete;
        TerminalGuide& operator = (const TerminalGuide&) = delete;
};

// Считывает один символ без буферизации (без ожидания enter)
char getch();