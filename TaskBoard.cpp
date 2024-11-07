#include "TaskBoard.h"
const string TaskBoard::const_file_path = "Documents//Eventer.txt";
#pragma warning(push)
#pragma warning(disable: 4996) // Отключаем предупреждение о небезопасной функции getenv
const string TaskBoard::full_file_path = string(getenv("USERPROFILE")) + "//" + TaskBoard::const_file_path;
#pragma warning(pop)
fstream TaskBoard::file;
unordered_map<unsigned, string> TaskBoard::events; // Номер задачи в списке и её описание
/*unordered_map<unsigned, string> TaskBoard::to_do_tasks; // 1. Банк новых задач
unordered_map<unsigned, string> TaskBoard::tasks_in_develope; // 2. В процессе разработки/исследования
unordered_map<unsigned, string> TaskBoard::test_tasks; // 3. Тестируется
unordered_map<unsigned, string> TaskBoard::ready_tasks; // 4. Готово
unordered_map<unsigned, string> TaskBoard::droped_tasks; // 5. Заброшено
unordered_map<string, unordered_map<unsigned, string>> TaskBoard::board; // Название разделов прогрессий задач и непосредственно сам список*/

unsigned int number_event = 0;
unsigned int count_event = 0;
size_t pos;
string name_event;
string line;


TaskBoard::TaskBoard() {
    file.open(TaskBoard::full_file_path, ios::in | ios::out | ios::app);
    if (file.is_open()) { std::cout << "Файл с задачами обнаружен" << endl; }
    else { cerr << "Не удалось открыть файл с задачами" << endl; }
}

TaskBoard::~TaskBoard(){
    file.close();
}


void TaskBoard::addEvent() {
    std::cout << "Создать задачу: ";
    getline(cin, name_event);
    // Проверка на существование задачи
    file.clear();              
    file.seekg(0);             // Перемещаем указатель на начало файла
    
    while (!file.eof()) {
        getline(file, line);
        pos = line.find(". ");
        if (pos != string::npos) {
            string description = line.substr(pos + 2);
            if (description == name_event) {  // Сравнение только по описанию
                std::cout << "Такая задача уже существует." << endl;
                return;
            }
            if (stoi(line.substr(pos - 1)) > 0) { number_event = stoi(line.substr(pos - 1)); }
        }
    }
    file.clear();
    file.seekp(0, ios::end);   
    file << ++number_event << ". " << name_event << "\n";
    file.flush(); //Прерывание буфера и запихивание задач в файл синхронно с ходом программы
    events[number_event] = name_event;
    count_event++;
    std::cout << "Задача добавлена." << endl;
}

void TaskBoard::testEvent() {
    string name_event;
    std::cout << "Создать задачу: ";
    cin.ignore();
    getline(std::cin, name_event);
    events[++number_event] = name_event; 
    std::cout << "Задача успешно создана\n";
}

void TaskBoard::testShowActualEvents() {
    for (const auto& event : events) {
        std::cout << event.first << ' ' << event.second << endl;
    }
}

void TaskBoard::showActualEvents(){
    file.seekg(0);
    cout << "На данный момент, задачи следующие: " << endl;
    while (!file.eof()) {
        getline(file, line);
        std::cout << line << endl;
    }
    file.seekp(0, ios::end);
    file.clear();
}

//!!!!ДОДЕЛАТЬ
void TaskBoard::removeEvent(){
    std::cout << "Введите номер задачи, которую нужно удалить: ";
    number_event = _getch();
    // Проверка на существование задачи
    file.clear();
    file.seekg(0);             // Перемещаем указатель на начало файла
    string deleted_line;
    
    while (!file.eof()) {
        getline(file, line);
        if (!pos) {
            cerr << "В файле задач самих задач не обнаружено";
            return;
        }
        if (pos != string::npos) {
            if (number_event == stoi(line.substr(pos - 1))) {
            }
        }
    }
    file.clear();
    file.seekp(0, ios::end);
    file.flush(); //Прерывание буфера и запихивание задач в файл синхронно с ходом программы
}

bool TaskBoard::clearEventBoard(){
    file.close();
    fstream file(full_file_path, ios::out | ios::trunc);
    std::cout << "Файл очищен от задач\n";
    return 0;
}
