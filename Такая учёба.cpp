#include "Utilities.h"
#include "TaskBoard.h"
#include "Game.h"

unique_ptr<TaskBoard> task;
unique_ptr<Game> game;
int action = 0;

int main() {
    system("chcp 1251 > nul");
    while (true) {
        std::cout << "Список предложенных вариантов:\n";
        std::cout << "1. Добавление задачи в текстовый файл\n2. Показать актуальные задачи\n3. Удаление конкретной задачи из списка\n4. Очистка файла событий\n5. Запустить игру\nДля выхода из программы нажмите 'X'\n";
        if (!task) { task = make_unique<TaskBoard>(); }
        std::cout << "Выберете утилиту: \n";
        switch (_getch()) {
        case '1':
            task->addEvent();
            break;
        case '2':
            task->showActualEvents();
            break;
        case '3':
            task->removeEvent();
            break;
        case '4':
            task->clearEventBoard();
            break;
        case '5': {
            cout << "Выбирете игру:\n1. Пак-Ман\n2. Змейка" << endl;
            char game_choise = _getch();
            if (game_choise == '1') {
                game = make_unique<Game>(1);
            }
            else if (game_choise == '2') {
                game = make_unique<Game>(2);
            }
            else { cout << "Неправильный ввод\n"; }
            break;
        }
        case 'x':
        case 'X':
            return 0;
        default:
            std::cout << "Полная лажа, покайся" << endl;
            break;
        }
    }
}
