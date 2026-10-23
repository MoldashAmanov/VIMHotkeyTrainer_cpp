#include "TerminalGuard.h"
#include <termios.h>
#include <unistd.h>

namespace {
    // Глобальные переменные для хранения старых настроек терминала
    struct termios g_old_tty;
    bool g_terminal_saved = false;
}

// Конструктов: включаем "сырой" режим терминала
TerminalGuard::TerminalGuard()
{
    // Получаем текущие настройки терминала
    // STDIN_FILENO = 0 (стандартный ввод)
    if (tcgetattr(STDIN_FILENO, &g_old_tty) == 0)
    {
        struct termios tty = g_old_tty; // Копируем настройки
        // Выключаем канонический режим (ICANON)
        // Без него ввод буферизуется до нажатия enter
        // Выключаем эхо (ECHO)
        // Без него нажатые клавиши не отображаются на экране
        // Применяем изменения немедленно (TCSANOW)
        tty.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &tty);

        g_terminal_saved = true;
    }
}
// Деструктор: восстанавливаем настройки терминала
// Это гарантирует, что даже при сбросе программы терминал вернется в нормальное состояние
TerminalGuard::~TerminalGuard()
{
    if (g_terminal_saved)
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &g_old_tty);
    }
}
// Функция для чтения одного символа без буферизации
char getch()
{
    char buf = 0;
    // read() возвращает количество прочитанных байт
    // Если < 0, значит ошибка
    if (read(STDIN_FILENO, &buf, 1) < 0)
        return -1;
    return buf;
}