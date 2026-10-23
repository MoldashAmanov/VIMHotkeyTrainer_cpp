#include "Application.h"
#include "TerminalUI.h"
#include "TerminalGuard.h"
#include "TrainerEngine.h"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

void Application::run()
{
    TerminalGuard guard; // Включаем raw mode
    TrainerEngine engine;

    while (engine.isRunning())
    {
        engine.render();

        // Задержка, чтобы не грузить CPU
        this_thread::sleep_for(chrono::milliseconds(50));

        char c = getch();
        engine.update(c);
    }
    TerminalUI::clearScreen();
    cout << "Спасибо за игру!";
}