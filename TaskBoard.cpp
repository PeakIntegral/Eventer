#include "TaskBoard.h"
const string TaskBoard::const_file_path = "Documents//Eventer.txt";
#pragma warning(push)
#pragma warning(disable: 4996) // ��������� �������������� � ������������ ������� getenv
const string TaskBoard::full_file_path = string(getenv("USERPROFILE")) + "//" + TaskBoard::const_file_path;
#pragma warning(pop)
fstream TaskBoard::file;
unordered_map<unsigned, string> TaskBoard::events; // ����� ������ � ������ � � ��������
/*unordered_map<unsigned, string> TaskBoard::to_do_tasks; // 1. ���� ����� �����
unordered_map<unsigned, string> TaskBoard::tasks_in_develope; // 2. � �������� ����������/������������
unordered_map<unsigned, string> TaskBoard::test_tasks; // 3. �����������
unordered_map<unsigned, string> TaskBoard::ready_tasks; // 4. ������
unordered_map<unsigned, string> TaskBoard::droped_tasks; // 5. ���������
unordered_map<string, unordered_map<unsigned, string>> TaskBoard::board; // �������� �������� ���������� ����� � ��������������� ��� ������*/

unsigned int number_event = 0;
unsigned int count_event = 0;
size_t pos;
string name_event;
string line;


TaskBoard::TaskBoard() {
    file.open(TaskBoard::full_file_path, ios::in | ios::out | ios::app);
    if (file.is_open()) { std::cout << "���� � �������� ���������" << endl; }
    else { cerr << "�� ������� ������� ���� � ��������" << endl; }
}

TaskBoard::~TaskBoard(){
    file.close();
}


void TaskBoard::addEvent() {
    std::cout << "������� ������: ";
    getline(cin, name_event);
    // �������� �� ������������� ������
    file.clear();              
    file.seekg(0);             // ���������� ��������� �� ������ �����
    
    while (!file.eof()) {
        getline(file, line);
        pos = line.find(". ");
        if (pos != string::npos) {
            string description = line.substr(pos + 2);
            if (description == name_event) {  // ��������� ������ �� ��������
                std::cout << "����� ������ ��� ����������." << endl;
                return;
            }
            if (stoi(line.substr(pos - 1)) > 0) { number_event = stoi(line.substr(pos - 1)); }
        }
    }
    file.clear();
    file.seekp(0, ios::end);   
    file << ++number_event << ". " << name_event << "\n";
    file.flush(); //���������� ������ � ����������� ����� � ���� ��������� � ����� ���������
    events[number_event] = name_event;
    count_event++;
    std::cout << "������ ���������." << endl;
}

void TaskBoard::testEvent() {
    string name_event;
    std::cout << "������� ������: ";
    cin.ignore();
    getline(std::cin, name_event);
    events[++number_event] = name_event; 
    std::cout << "������ ������� �������\n";
}

void TaskBoard::testShowActualEvents() {
    for (const auto& event : events) {
        std::cout << event.first << ' ' << event.second << endl;
    }
}

void TaskBoard::showActualEvents(){
    file.seekg(0);
    cout << "�� ������ ������, ������ ���������: " << endl;
    while (!file.eof()) {
        getline(file, line);
        std::cout << line << endl;
    }
    file.seekp(0, ios::end);
    file.clear();
}

//!!!!��������
void TaskBoard::removeEvent(){
    std::cout << "������� ����� ������, ������� ����� �������: ";
    number_event = _getch();
    // �������� �� ������������� ������
    file.clear();
    file.seekg(0);             // ���������� ��������� �� ������ �����
    string deleted_line;
    
    while (!file.eof()) {
        getline(file, line);
        if (!pos) {
            cerr << "� ����� ����� ����� ����� �� ����������";
            return;
        }
        if (pos != string::npos) {
            if (number_event == stoi(line.substr(pos - 1))) {
            }
        }
    }
    file.clear();
    file.seekp(0, ios::end);
    file.flush(); //���������� ������ � ����������� ����� � ���� ��������� � ����� ���������
}

bool TaskBoard::clearEventBoard(){
    file.close();
    fstream file(full_file_path, ios::out | ios::trunc);
    std::cout << "���� ������ �� �����\n";
    return 0;
}
