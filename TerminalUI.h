#pragma once
#include <string>

using namespace std;

// ANSI цвета
namespace Color
{
    extern const string RESET;
    extern const string RED;
    extern const string GREEN;
    extern const string YELLOW;
    extern const string CYAN;
    extern const string BOLD;
}

class TerminalUI
{
    public:
        // Очищает экран с помощью ANSI escape code
        static void clearScreen();
        // Печатает текст по центру
        static void printCentered(const string& text, const string& color = "");
        // Печатает заголовок + содержимое в рамке
        static void printBox(const string& title, const string& content);
};