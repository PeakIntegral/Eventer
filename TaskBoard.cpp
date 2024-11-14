#include "TaskBoard.h"
const string TaskBoard::const_file_path = "Documents//Eventer.txt";
#pragma warning(push)
#pragma warning(disable: 4996) // ��������� �������������� � ������������ ������� getenv
const string TaskBoard::full_file_path = string(getenv("USERPROFILE")) + "//" + TaskBoard::const_file_path;
#pragma warning(pop)
ofstream TaskBoard::outfile;
ifstream TaskBoard::infile;
unordered_map<unsigned, string> TaskBoard::events; // ����� ������ � ������ � � ��������
bool TaskBoard::needchanges = false;
unsigned int number_event = 1;
unsigned int count_event = 0;
size_t pos;
string name_event;
string line;


TaskBoard::TaskBoard() {
    infile.open(TaskBoard::full_file_path, ios::in | ios::app);
    if (infile.is_open()) { std::cout << "���� � �������� ���������" << endl; }
    else {
        cerr << "�� ������� ������� ���� � ��������" << endl;
        return;
    }
    if (infile.peek() == EOF) {
        cout << "�� ���������� ������������ �����, ��� ������ ������ �������� ����� ������" << endl;
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
                    std::cerr << "������: �������� ������ ������ � ������� ������." << std::endl;
                }
                catch (const std::out_of_range&) {
                    std::cerr << "������: ����� ������ ������� �� ������� ����������� ���������." << std::endl;
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
        else { cerr << "�� ������� ������ ��������� � ���� � ��������\n"; }
    }
}


void TaskBoard::addEvent() {
    std::cout << "������� ������: ";
    getline(cin, name_event);
    // �������� �� ������������� ������
    for (const auto& event : events) {
        if (pos != string::npos) {
            if (event.second == name_event) {  // ��������� ������ �� ��������
                std::cout << "����� ������ ��� ����������." << endl;
                return;
            }
        }
    }
    events[++count_event] = name_event;
    if (pos == 0){
        pos = '.';
    }
    needchanges = true;
    std::cout << "������ ���������." << endl;
}

void TaskBoard::showActualEvents(){
    if (!events.empty()){
        cout << "�� ������ ������, ������ ���������: " << endl;
        for (const auto& event : events) {
            cout << event.first << '.' << ' ' << event.second << endl;
        }
    }
    else { cout << "�� ������ ������ ����� ���" << endl; }
}

void TaskBoard::removeEvent(){
    if (!events.empty()) {
        std::cout << "������� ����� ������, ������� ����� �������: ";
        cin >> number_event;
        if (events.find(number_event) == events.cend()) {
            cout << "������ ��� ����� ������� �� ����������\n";
            return;
        }
        unordered_map<unsigned, string> temp_map;
        events.erase(number_event);
        count_event = 1;
        for (const auto& event : events) {
            temp_map[count_event++] = event.second;
        }
        events = move(temp_map); //���������� �������� ����, � ������ ��������� ��-��
        needchanges = true;
        cout << "������ ������� �������" << endl;
    }
    else { cout << "�� ������ ������ ����� ���" << endl; }
}

void TaskBoard::clearEventBoard(){
    std::cout << "�� �������, ��� ������ ������� ��� ������������ ������?\n";
    std::cout << "Y - '��', N - '���'\n";
    switch (_getch()) {
    case 'y':
    case 'Y':
    case '�':
    case '�':
        events.clear();
        count_event = 0;
        needchanges = true;
        break;
    case 'n':
    case 'N':
    case '�':
    case '�':
        break;
    default:
        cerr << "�������, ����\n";
        clearEventBoard();
    }
}
    
    /*file.close();
    fstream file(full_file_path, ios::out | ios::trunc);
    std::cout << "���� ������ �� �����\n";
    return 0;*/
