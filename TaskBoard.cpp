#include "TaskBoard.h"
const string TaskBoard::const_file_path = "Documents//Eventer.txt";
#pragma warning(push)
#pragma warning(disable: 4996) // Отключаем предупреждение о небезопасной функции getenv
const string TaskBoard::full_file_path = string(getenv("USERPROFILE")) + "//" + TaskBoard::const_file_path;
#pragma warning(pop)

unordered_map<unsigned, string> TaskBoard::events; // Номер задачи в списке и её описание
bool TaskBoard::needchanges = false;
unsigned int number_event = 1;
unsigned int count_event = 0;
size_t pos = std::string::npos;
string name_event;
string line;


TaskBoard::TaskBoard() {
    ifstream infile;
    infile.open(TaskBoard::full_file_path, ios::in);
    if (infile.is_open()) { std::cout << "Файл с задачами обнаружен" << endl; }
    else {
        cerr << "Не удалось открыть файл с задачами" << endl;
        return;
    }
    while (getline(infile, line)) {
        pos = line.find('.');
        if (pos != std::string::npos) {
            try {
                events[stoi(mySplit(line, '.', "number"))] = mySplit(line, '.', "definition");
                count_event++;
            }
            catch (const std::invalid_argument&) {
                std::cerr << "Ошибка: неверный формат строки — пропуск строки." << std::endl;
            }
            catch (const std::out_of_range&) {
                std::cerr << "Ошибка: номер задачи выходит за пределы допустимого диапазона." << std::endl;
            }
        }
    }
    infile.close();
}

bool TaskBoard::saveFile() {
    if (!needchanges) return false;
    ofstream outfile;
    outfile.open(full_file_path, ios::out | ios::trunc);
    if (!outfile.is_open()) {
        cerr << "Не удалось внести изменения в файл с задачами\n";
        return false;
    }
    
    if (events.empty()) {
        return false;
    }
    
    for (const auto& event : events) {
//        cout << event.first << '.' << ' ' << event.second << endl;
        outfile << event.first << '.' << ' ' << event.second << endl;
    }

    outfile.close();
    return true;    
}

TaskBoard::~TaskBoard(){
    saveFile();
}


void TaskBoard::addEvent() {
    std::cout << "Создать задачу: ";
    getline(cin, name_event);
    // Проверка на существование задачи
    if (name_event.empty() || name_event.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
        cout << "Пустая задача не принимается" << endl << endl;
        return;
    }
    for (const auto& event : events) {
        if (pos != string::npos) {
            if (event.second == name_event) {  // Сравнение только по описанию
                std::cout << "Такая задача уже существует." << endl << endl;
                return;
            }
        }
    }
    events[++count_event] = name_event;
    if (pos == 0){
        pos = '.';
    }
    needchanges = true;
    std::cout << "Задача добавлена." << endl << endl;
}

void TaskBoard::showActualEvents(){
    if (!events.empty()){
        cout << "На данный момент, задачи следующие: " << endl;
        for (const auto& event : events) {
            cout << event.first << '.' << ' ' << event.second << endl;
        }
    }
    else { cout << "На данный момент задач нет" << endl; }
    cout << endl;
}

void TaskBoard::removeEvent(){
    if (!events.empty()) {
        std::cout << "Введите номер задачи, которую нужно удалить: ";
        cin >> number_event;
        if (events.find(number_event) == events.cend()) {
            cout << "Задачи под таким номером не обнаружено\n";
            return;
        }
        unordered_map<unsigned, string> temp_map;
        events.erase(number_event);
        count_event = 1;
        for (const auto& event : events) {
            temp_map[count_event++] = event.second;
        }
        events = move(temp_map); //Перезапись исходной мапы, с учётом удалённого эл-та
        needchanges = true;
        cout << "Задача успешно удалена" << endl;
    }
    else { cout << "На данный момент задач нет" << endl; }
    cout << endl;
}

void TaskBoard::clearEventBoard(){
    std::cout << "Вы уверены, что хотите удалить уже существующие записи?\n";
    std::cout << "Y - 'да', N - 'нет'\n";
    switch (_getch()) {
    case 'y':
    case 'Y':
    case 'д':
    case 'Д':
        events.clear();
        count_event = 0;
        needchanges = true;
        cout << "Все сущеcтвующие задачи были удалены" << endl;
        break;
    case 'n':
    case 'N':
    case 'т':
    case 'Т':
        break;
    default:
        cerr << "Выбирай, блэт\n";
        clearEventBoard();
    }
}
    
    /*file.close();
    fstream file(full_file_path, ios::out | ios::trunc);
    std::cout << "Файл очищен от задач\n";
    return 0;*/
