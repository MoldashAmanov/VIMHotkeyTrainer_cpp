#include "TrainerEngine.h"
#include "TrainerUI.h"
#include <iostream>

using namespace std;

TrainerEngine::TrainerEngine()
{
    initializeLessons();
}
void TrainerEngine::initializeLessons()
{
    // Уровень 1. Базовое движение
    lessons_.emplace_back("Базовое движение",
        "h - влево, j - вниз, k - вверх, l - вправо\n"
        "Это основа навигации в Vim.",
        "hjklhjklhjkl", 1);
    
    lessons_.emplace_back("Движение с числами",
        "Число перед командой = повторить N раз\n"
        "Пример: 5j = вниз 5 раз, 3l = вправо 3 раза",
        "5j3l2k4h", 2);

    // Уровень 2. Навигация по словам
    lessons_.emplace_back("Слова (w, b, e)",
        "w - начало следующего слова\n"
        "b - начало предыдущего слова\n"
        "e - конец текущего/следущего слова",
        "wbe", 2);

    lessons_.emplace_back("Слова (W, B, E)",
        "W, B, E - то же самое, но для WORD (игнорирует пунктуацию)\n"
        "Полезно для работы с путями файлов, URL",
        "WBE", 3);
    
    lessons_.emplace_back("Комбинация слов",
        "2w - перескочить через 2 слова\n"
        "3b - назад на 3 слова\n"
        "5e - в конец 5-го слова",
        "2w3b5e", 3);

    // Уровень 3. Навигация по строкам
    lessons_.emplace_back("Начало и конец строки",
        "0 - начало строки\n"
        "$ - конец строки\n"
        "^ - первый непустой символ строки",
        "0$^", 3);

    lessons_.emplace_back("Движение между строками",
        "+ - первый непустой символ следующей строки\n"
        "- - первый непустой символ предыдущей строки\n"
        "Enter - то же самое, что и +",
        "+-", 3);

    lessons_.emplace_back("Переход к символу в строке",
        "f{char} - найти символ вперед\n"
        "F{char} - найти символ назад\n"
        "t{char} - до символа вперед\n"
        "T{char} - до символа назад\n"
        "; - повторить последнее f/t\n"
        ", - повторить последнее f/t в обратном направлении",
        "faFbTc;,", 4);

    // Уровень 4. Навигация по экрану
    lessons_.emplace_back("Верх, середина, низ экрана",
        "H - High\n"
        "M - Middle\n"
        "L - Low",
        "HML", 4);

    lessons_.emplace_back("Прокрутка экрана",
        "Ctrl+u - up (вверх на пол-экрана)\n"
        "Ctrl+d - down (вниз на пол-экрана)\n"
        "Ctrl+f - forward (вперед на весь экран)\n"
        "Ctrl+b - backward (назад на весь экран)",
        "udfb", 5);

    lessons_.emplace_back("Центрирование курсора",
        "zz - центрировать курсор вертикали\n"
        "zt - курсор вверху экрана\n"
        "zb - курсор внизу экрана",
        "zzztzb", 4);

    // Уровень 5. Поиск
    lessons_.emplace_back("Базовый поиск",
        "/{pattern} - поиск вперед\n"
        "?{pattern} - поиск назад\n"
        "n - следующий результат\n"
        "N - предыдущий результат",
        "/?nN", 5);
    
    lessons_.emplace_back("Поиск слова под курсором",
        "* - искать слово под курсором вперед\n"
        "# - искать слово под курсором назад\n"
        "g* - то же, но без границ слова\n"
        "G# - то же, но назад",
        "*#g*G#", 6);
    
    lessons_.emplace_back("Повтор поиска",
        "n - следущий результат\n"
        "N - предыдущий результат\n"
        "; - повторить последнее\n"
        ", - повторить в обратном направлении",
        "nN;,", 5);

    // Уровень 6. Режимы и отмена
    lessons_.emplace_back("Вход в режим вставки",
        "i - вставка перед курсором\n"
        "I - вставка в начало строки\n"
        "a - вставка после курсора\n"
        "A - вставка в конец строки\n"
        "o - новая строка ниже\n"
        "O - новая строка выше",
        "iIaAoO", 4);

    lessons_.emplace_back("Выход из режима вставки",
        "ESC - выход в Normal Mode\n"
        "Ctrl+[ - альтернатива ESC\n"
        "Ctrl+c - то же самое",
        "ESC", 3);

    lessons_.emplace_back("Визуальные режимы",
        "v - визуальный режим (выделение символов)\n"
        "V - визуальный режим строк\n"
        "Ctrl+v - визуальный режим блоков\n"
        "gv - восстановить последнее выделение",
        "vVgv", 6);

    lessons_.emplace_back("Отмена и повтор",
        "u - отменить последнее действие\n"
        "U - отменить все изменения в строке\n"
        "Ctrl+r - повторить отмененное действие\n"
        ". - повторить последнюю команду",
        "uUr.", 5);

    // Уровень 7. Операции с текстом
    lessons_.emplace_back("Удаление",
        "x - удалить символ под курсором\n"
        "X - удалить символ перед курсором\n"
        "dd - удалить строку\n"
        "D - удалить до конца строки\n"
        "dw - удалить слово\n"
        "db - удалить слово назад\n"
        "de - удалить до конца слова",
        "xXddDdwdbde", 6);
    
    lessons_.emplace_back("Изменение",
        "c - изменить (удалить + режим вставки)\n"
        "cc - изменить строку\n"
        "C - изменить до конца строки\n"
        "cw - изменить слово\n"
        "cb - изменить слово назад\n"
        "ce - изменить до конца слова\n",
        "cccCcwcbce", 7);

    lessons_.emplace_back("Копирование",
        "y - копирование (yank)\n"
        "yy - копировать строку\n"
        "yw - копировать слово\n"
        "yb - копировать слово назад\n"
        "ye - копировать до конца слова",
        "yyyywybye", 6);

    lessons_.emplace_back("Вставка",
        "p - вставить после курсора/строки\n"
        "P - вставить перед курсором/строкой\n"
        "]p - вставить с правильным отступом\n"
        "pP]p", 5);

    lessons_.emplace_back("Замена",
        "r - заменить один символ\n"
        "R - войти в режим замены (как печатная машинка)\n"
        "s - заменить символ и войти в режим вставки\n"
        "S - заменить строку и войти в режим вставки",
        "rRsS", 6);

    lessons_.emplace_back("Text Objects (iw, aw)",
        "iw - внутреннее слово (inner word)\n"
        "aw - слово с пробелом (a word)\n"
        "i\' - внутри кавычек\n"
        "i( - внутри скобок\n"
        "diw - удалить слово\n"
        "ci\' - изменить текст в кавычках",
        "iwawdiwdci\'", 8);

    // Уровень 8. Продвинутые функции
    lessons_.emplace_back("Marks (закладки)",
        "ma - установить метку 'a'\n"
        "`a - перейти к метке 'a' (точная позиция)\n"
        "'a - перейти к метке 'a' (начало строки)\n"
        "`` - вернуться к последней позиции\n"
        "'' - вернуться к последней строке",
        "ma`a'a``''", 8);
    
    lessons_.emplace_back("Registers (регистры)",
        "\"ay - скопировать в регистр 'a'\n"
        "\"ap - вставить из регистра 'a'\n"
        "\"+y - скопировать в системный буфер обмена\n"
        "\"+p - вставить из системного буфера\n"
        "\"*y - скопировать в primary selection (X11)",
        "\"ay\"ap\"+y\"+p", 9);

    lessons_.emplace_back("Macros (макросы)",
        "qa - начать запись макроса в регистр 'a'\n"
        "q - остановить запись\n"
        "@a - воспроизвести макрос 'a'\n"
        "@@ - повторить последний макрос\n"
        "5@a - выполнить макрос 'a' 5 раз",
        "qaq@a@@5@a", 10);

    lessons_.emplace_back("Окна (windows)",
        "Ctrl+w s - разделить окно горизонтально\n"
        "Ctrl+w v - разделить окно вертикально\n"
        "Ctrl+w q - закрыть окно\n"
        "Ctrl+w h/j/k/l - переместиться между окнами\n"
        "Ctrl+w H/J/K/L - переместить окно",
        "svqhjkl", 9);

    lessons_.emplace_back("Buffers (буферы)",
        ":bn - следующий буфер\n"
        ":bp - предыдущий буфер\n"
        ":bd - закрыть буфер\n"
        ":ls - список всех буферов\n"
        ":b {num} - перейти к буферу N",
        "bnpbdls", 8);

    lessons_.emplace_back("Folding (сворачивание)",
        "za - переключить складку\n"
        "zo - открыть складку\n"
        "zc - закрыть складку\n"
        "zR - открыть все складки\n"
        "zM - закрыть все складки\n"
        "zf - создать складку",
        "zaocRMf", 9);

    lessons_.emplace_back("Tags (теги)",
        "Ctrl+] - перейти к определению тега\n"
        "Ctrl+t - вернуться назад\n"
        ":tag {name} - перейти к тегу\n"
        ":pop - вернуться по стеку тегов",
        "]ttagpop", 8);

    lessons_.emplace_back("Командная строка",
        ":w - сохранить файл\n"
        ":q - выйти\n"
        ":wq - сохранить и выйти\n"
        ":e {file} - открыть файл\n"
        ":sp - горизонтальное разделение\n"
        ":vsp - вертикальное разделение",
        "wqeqesvsp", 7);

    lessons_.emplace_back("Подстановка (substitution)",
        ":s/old/new/ - заменить в строке\n"
        ":s/old/new/g - заменить все в строке\n"
        ":%s/old/new/g - заменить во всём файле\n"
        ":%s/old/new/gc - с подтверждением",
        "s/old/new/g:%s/old/new/gc", 9);
}
void TrainerEngine::update(char input)
{
    switch (state_)
    {
        case AppState::MENU:
        {
            handleMenuInput(input);
            break;
        }
        case AppState::Playing:
        {
            handlePlayingInput(input);
            break;
        }
        case AppState::LESSON_COMPLETE:
        {
            handleCompleteInput(input);
            break;
        }
        case AppState::EXIT:
        {
            break;
        }
    }
}
voidTrainerEngine::render() const
{
    TerminalUI::clearScreen();
    switch (state_)
    {
        case AppState::MENU:
        {
            renderMenu();
            break;
        }
        case AppState::PLAYING:
        {
            renderPlaying();
            break;
        }
        case AppState::LESSON_COMPLETE:
        {
            renderComplete();
            break;
        }
        case AppState::EXIT:
        {
            break;
        }
    }
}
void TrainerEnging::handleMenuInput(char c)
{
    if (c >= '1' && c == '9')
    {
        size_t idx = static_cast<size_t>(c - '1');
        if (idx < lessons_.size())
        {
            current_lessons_idx_ = idx;
            current_key_idx_ = 0;
            state_ = AppState::PLAYING;
        }
        else if (c == 'q' || c == 'Q')
        {
            state_ = AppState::EXIT;
        }
    }
}
void TrainerEngine::handlePlayingInput(char c)
{
    const Lesson& lesson = lessons_[current_lesson_idx_];
    // ESC или q для выхода в меню
    if (c == '\x1B' || c == 'q')
    {
        state_ = AppState::MENU;
        return;
    }

    total_keystrokes_++;

    // Проверяем правильность нажатия
    if (c == lesson.getTargetKeys()[current_key_idx_])
    {
        current_key_idx_++;
        if (current_key_idx_ >= lesson.getTargetKeys().length())
        {
            completed_lessons_++;
            state_ = AppState::LESSON_COMPLETE;
        }
        else
        {
            // Строгость Vim: ошибка = сброс прогресса
            current_key_idx_ = 0;
        }
    }
}
void TrainerEngine::handleCompleteInput(char c)
{
    if (c == 'n' || c == ' ')
    {
        // Следущий урок
        current_lesson_idx_ = (current_lesson_idx_ + 1) % lessons_.size();
        current_key_idx_ = 0;
        state_ = AppState::PLAYING;
    }
    else if (c == 'm' || c == 'q')
    {
        state_ = AppState::MENU;
    }
}
void TrainerEngine::renderMenu() const
{
    TerminalUI::printCentered(Color::GREEN + Color::BOLD + "VIM HOTKEY TRAINER" + Color::RESET);
    cout << "\n";
    
    // Показываем статистику
    cout << Color::CYAN << "Статистика: " << Color::RESET
        << "Пройдено уроков: " << Color::YELLOW << completed_lessons_ << Color::RESET
        << "  |  Нажатий клавиш: " << Color::YELLOW << total_keystrokes_ << Color::RESET
        << "\n\n";

    TerminalUI::printBox("Выберите урок",
        "1. Базовое движение (h, j, k, l)\n"
        "2. Движение с числами (5j, 3l)\n"
        "3. Слова (w, b, e)\n"
        "4. Слова (W, B, E)\n"
        "5. Комбинации слов (2w, 3b)\n"
        "6. Начало и конец строки (0, $, ^)\n"
        "7. Движение между строками (+, -)\n"
        "8. Переход к символу (f, F, t, T)\n"
        "9. Верх, середина, низ экрана (H, L, M)\n"
        "0. Прокрутка экрана (Ctrl+u, Ctrl+d)\n"
        "\n"
        "Введите номер урока или 'q' для выхода");
}
void TrainerEngine::renderPlaying() const
{
    const Lesson& lesson = lessons_[current_lesson_idx_];

    // Заголовок урока
    TerminalUI::printBox("Урок " + to_string(current_lesson_idx_ + 1) + ": " + lesson.getName(), lesson.getDescription());
    // Сложность
    cout << Color::CYAN << "Сложность: " << Color::RESET;
    for (int i = 0; i < lesson.getDifficulty(); ++i)
    {
        cout << Color::YELLOW << "★" << Color::RESET;
    }
    cout << "\n\n";
    // Целевая последовательность с подсветкой прогресса
    cout << "Цель: " << Color::YELLOW;
    for (size_t i = 0; i < lesson.getTargetKeys().length(); ++i)
    {
        if (i < current_key_idx_)
        {
            cout << Color::GREEN; // Уже введено
        }
        else if (i == current_key_idx_)
        {
            cout << Color::BOLD << Color::CYAN; // Текущая клавиша
        }
        else
        {
            cout << Color::YELLOW; // Еще не выведено
        }
        // Красивое отображение специальных символов
        char key = lesson.getTargetKeys()[i];
        if (key == '\x1B')
        {
            cout << "ESC ";
        }
        else
        {
            cout << key << " ";
        }
    }
    cout << Color::RESET << "\n\n";
    // Введенная последовательность
    cout << Color::CYAN << "Ваш ввод: " << Color::RESET;
    for (size_t i = 0; i < current_key_idx_; ++i)
    {
        cout << Color::GREEN << lesson.getTargetKeys()[i] << " " Color::RESET;
    }
    cout << "\n\n";
    // Прогресс бар
    int progress = static_cast<int>((current_key_idx_ * 100) / lesson.getTargetKeys().length());
    cout << Color::CYAN < "Прогресс: [" << Color::RESET;
    for (int i = 0; i < 50; ++i)
    {
        if (i < progress / 2)
        {
            cout << Color::GREEN << "█" << Color::RESET;
        }
        else
        {
            cout << Color::YELLOW << "░" << Color::RESET;
        }
    }
    cout << Color::CYAN << "] " << progress << "%" << Color::RESET << "\n\n";
    cout << Color::YELLOW << "(Нажмите 'q' или ESC для возврата в меню)" << Color::RESET << "\n";
}
void TrainerEngine::renderComplete() const
{
    TerminaUI::printCentered(Color::GREEN + Color::BOLD + "Урок пройден!" + Color::RESET);
    cout << "\n";

    TerminalUI::printBox("Поздравляем!",
        "Вы успешно завершили урок!\n\n"
        "Общая статистика:\n"
        "   * Пройдено уроков: " + to_string(completed_lessons_) + "\n"
        "   * Всего нажатий: " + to_string(total_keystrokes_) + "\n\n"
        "n / [Пробел] - Следущий урок\n"
        "m / q - Вернуться в меню");
}