#pragma once

// RAII-класс для управления сырым режимом терминала в Unix-системах
// При создании включает raw mode, при уничтожении - восстанавливает настройки
class TerminalGuard
{
    public:
        TerminalGuard();
        ~TerminalGuard();

        // Запрещаем копирование - ресурс должен быть только один
        TerminalGuard(const TerminalGuard&) = delete;
        TerminalGuard& operator = (const TerminalGuard&) = delete;
};

// Считывает один символ без буферизации (без ожидания enter)
char getch();