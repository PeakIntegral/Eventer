#include "TaskBoard.h"
const string TaskBoard::const_file_path = "Documents//Eventer.txt";
#pragma warning(push)
#pragma warning(disable: 4996) // Отключаем предупреждение о небезопасной функции getenv
const string TaskBoard::full_file_path = string(getenv("USERPROFILE")) + "//" + TaskBoard::const_file_path;
#pragma warning(pop)
ofstream TaskBoard::outfile;
ifstream TaskBoard::infile;
unordered_map<unsigned, string> TaskBoard::events; // Номер задачи в списке и её описание
bool TaskBoard::needchanges = false;
unsigned int number_event = 1;
unsigned int count_event = 0;
size_t pos;
string name_event;
string line;


TaskBoard::TaskBoard() {
    infile.open(TaskBoard::full_file_path, ios::in | ios::app);
    if (infile.is_open()) { std::cout << "Файл с задачами обнаружен" << endl; }
    else {
        cerr << "Не удалось открыть файл с задачами" << endl;
        return;
    }
    if (infile.peek() == EOF) {
        cout << "Не обнаружено существующих задач, для начала работы создайте новую задачу" << endl;
        addEvent();
    }
    else {
        while (getline(infile, line)) {
            pos = line.find('.');
            if (pos != std::string::npos && pos > 0) {
                try {
                    events[stoi(line.substr(pos - 1))] = line.substr(pos + 2);
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
    }
    infile.close();
}

TaskBoard::~TaskBoard(){
    if (needchanges) {
        outfile.open(full_file_path, ios::out | ios::trunc);
        infile.seekg(0);
        if (outfile.is_open()) {
            if (!events.empty()) {
                for (const auto& event : events) {
                    cout << event.first << '.' << ' ' << event.second << endl;
                    outfile << event.first << '.' << ' ' << event.second << endl;
                }
            }
            outfile.close();
        }
        else { cerr << "Не удалось внести изменения в файл с задачами\n"; }
    }
}


void TaskBoard::addEvent() {
    std::cout << "Создать задачу: ";
    getline(cin, name_event);
    // Проверка на существование задачи
    for (const auto& event : events) {
        if (pos != string::npos) {
            if (event.second == name_event) {  // Сравнение только по описанию
                std::cout << "Такая задача уже существует." << endl;
                return;
            }
        }
    }
    events[++count_event] = name_event;
    if (pos == 0){
        pos = '.';
    }
    needchanges = true;
    std::cout << "Задача добавлена." << endl;
}

void TaskBoard::showActualEvents(){
    if (!events.empty()){
        cout << "На данный момент, задачи следующие: " << endl;
        for (const auto& event : events) {
            cout << event.first << '.' << ' ' << event.second << endl;
        }
    }
    else { cout << "На данный момент задач нет" << endl; }
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
