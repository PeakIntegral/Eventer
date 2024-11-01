
#include "TaskBoard.h"
const string TaskBoard::const_file_path = "Documents//Eventer.txt";
const string TaskBoard::full_file_path = string(getenv("USERPROFILE")) + "//" + TaskBoard::full_file_path;
unsigned int count_event = 0;
map<unsigned, string> TaskBoard::events;
map<string, map<unsigned, string>> TaskBoard::board;

void TaskBoard::addEvent(){
    string name_event;
    cout << "Создать задачу: ";
    cin >> name_event;

    // Проверка на существование задачи в файле
    fstream file(TaskBoard::full_file_path, ios::in | ios::out | ios::app); 
    events[++count_event] = name_event;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find(name_event) != string::npos) {
                cout << "Такая задача уже существует" << endl;
                file.close();
                events[count_event].erase();
                count_event--;
                return;
            }
        }
        // Запись задачи в файл
        file.clear();  // Очистка состояния файла для перехода к записи
        file << count_event << ": " << name_event << ";\n";
        cout << "Задача добавлена." << endl;
    }
    else {
        cerr << "Не удалось открыть файл для записи." << endl;
        events[count_event].erase();
        count_event--;
    }

    file.close();
}

void TaskBoard::testEvent() {
    string name_event;
    cout << "Создать задачу: ";
    cin.ignore();
    getline(std::cin, name_event);
    events[++count_event] = name_event; 
    cout << "Задача успешно создана\n";
}

void TaskBoard::showActualEvents() {
    for (const auto& event : events) {
        cout << event.first << ' ' << event.second << endl;
    }
}

void TaskBoard::clearEventBoard(){
    fstream file(full_file_path, ios::out | ios::trunc);
    cout << "Файл очищен от задач\n";
    file.close();
}
