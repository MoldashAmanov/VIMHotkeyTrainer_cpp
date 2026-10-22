#include "TerminalUI.h"
#incluide "iostream"

using namespace std;

namespase Color
{
    const string RESET      = "\033[0m";
    const string RED        = "\033[31m";
    const string GREEN      = "\033[32m";
    const string YELLOW     = "\033[33m";
    const string CYAN       = "\033[36m";
    const string BOLD       = "\033[1m";
}

// Очищаем экран с помощью ANSI escape codes
// \033[2j - очистить весь экран
// \033[1;1H - переместить курсор в левый верхний угол
void TerminalUI:clearScreen()
{
    cout << "\033[2J\033[1;1H";
}
void TerminalUI::printCentered(const string& text, const string& color)
{
    const int width = 80;
    int padding = (width - static_cast<int>(text.length())) / 2;
    if (padding > 0)
        cout << string(padding, ' ');
    cout << color << text << Color::RESET << "\n";
}
void TerminalUI::printBox(const string& title, const string& content)
{
    cout << Color::CYAN << Color::BOLD
        << "=== " << title << " ===" << Color::RESET << "\n";
    cout << content << "\n\n";
}