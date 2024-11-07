#include "Utilities.h"
#include "TaskBoard.h"

unique_ptr<TaskBoard> task;

int main() {
    system("chcp 1251 > nul");
    while (true) {
        std::cout << "Список предложенных вариантов:\n";
        std::cout << "1. Добавление задачи в текстовый файл\n2. Добавление задачи ТОЛЬКО в мапу\n3. Показать актуальные задачи\n4. Очистка файла событий\nДля выхода из программы нажмите 'X'\n";
        if (!task) { task = make_unique<TaskBoard>(); }
        std::cout << "Выберете утилиту: \n";
        switch (_getch()) {
        case '1':
            task->addEvent();
            break;
        case '2':
            task->testEvent();
            break;
        case '3':
            task->showActualEvents();
            break;
        case '4':
            task->clearEventBoard();
            break;
        case 'x':
            return 0;
        default:
            std::cout << "Полная лажа, покайся" << endl;
            break;
        }
    }
}
