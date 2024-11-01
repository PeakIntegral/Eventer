
#include "TaskBoard.h"
const string TaskBoard::const_file_path = "Documents//Eventer.txt";
const string TaskBoard::full_file_path = string(getenv("USERPROFILE")) + "//" + TaskBoard::full_file_path;
unsigned int count_event = 0;
map<unsigned, string> TaskBoard::events;
map<string, map<unsigned, string>> TaskBoard::board;

void TaskBoard::addEvent(){
    string name_event;
    cout << "������� ������: ";
    cin >> name_event;

    // �������� �� ������������� ������ � �����
    fstream file(TaskBoard::full_file_path, ios::in | ios::out | ios::app); 
    events[++count_event] = name_event;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find(name_event) != string::npos) {
                cout << "����� ������ ��� ����������" << endl;
                file.close();
                events[count_event].erase();
                count_event--;
                return;
            }
        }
        // ������ ������ � ����
        file.clear();  // ������� ��������� ����� ��� �������� � ������
        file << count_event << ": " << name_event << ";\n";
        cout << "������ ���������." << endl;
    }
    else {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
        events[count_event].erase();
        count_event--;
    }

    file.close();
}

void TaskBoard::testEvent() {
    string name_event;
    cout << "������� ������: ";
    cin.ignore();
    getline(std::cin, name_event);
    events[++count_event] = name_event; 
    cout << "������ ������� �������\n";
}

void TaskBoard::showActualEvents() {
    for (const auto& event : events) {
        cout << event.first << ' ' << event.second << endl;
    }
}

void TaskBoard::clearEventBoard(){
    fstream file(full_file_path, ios::out | ios::trunc);
    cout << "���� ������ �� �����\n";
    file.close();
}
