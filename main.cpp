#include "Application.h"
#include <iostream>
#include <exception>

using namespace std;

int main()
{
    try
    {
        Application app;
        app.run();
    }
    catch (const exception& e)
    {
        cerr << "Критическая ошибка: " << e.what() << "\n";
        return 1;
    }
    return 0;
}