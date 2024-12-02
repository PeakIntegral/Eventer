#include "TaskBoard.h"
const string TaskBoard::const_file_path = "Documents//Eventer.txt";
#pragma warning(push)
#pragma warning(disable: 4996) // ��������� �������������� � ������������ ������� getenv
const string TaskBoard::full_file_path = string(getenv("USERPROFILE")) + "//" + TaskBoard::const_file_path;
#pragma warning(pop)

unordered_map<unsigned, string> TaskBoard::events; // ����� ������ � ������ � � ��������
bool TaskBoard::needchanges = false;
unsigned int number_event = 1;
unsigned int count_event = 0;
size_t pos = std::string::npos;
string name_event;
string line;


TaskBoard::TaskBoard() {
    ifstream infile;
    infile.open(TaskBoard::full_file_path, ios::in);
    if (infile.is_open()) { std::cout << "���� � �������� ���������" << endl; }
    else {
        cerr << "�� ������� ������� ���� � ��������" << endl;
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
                std::cerr << "������: �������� ������ ������ � ������� ������." << std::endl;
            }
            catch (const std::out_of_range&) {
                std::cerr << "������: ����� ������ ������� �� ������� ����������� ���������." << std::endl;
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
        cerr << "�� ������� ������ ��������� � ���� � ��������\n";
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
    std::cout << "������� ������: ";
    getline(cin, name_event);
    // �������� �� ������������� ������
    if (name_event.empty() || name_event.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
        cout << "������ ������ �� �����������" << endl << endl;
        return;
    }
    for (const auto& event : events) {
        if (pos != string::npos) {
            if (event.second == name_event) {  // ��������� ������ �� ��������
                std::cout << "����� ������ ��� ����������." << endl << endl;
                return;
            }
        }
    }
    events[++count_event] = name_event;
    if (pos == 0){
        pos = '.';
    }
    needchanges = true;
    std::cout << "������ ���������." << endl << endl;
}

void TaskBoard::showActualEvents(){
    if (!events.empty()){
        cout << "�� ������ ������, ������ ���������: " << endl;
        for (const auto& event : events) {
            cout << event.first << '.' << ' ' << event.second << endl;
        }
    }
    else { cout << "�� ������ ������ ����� ���" << endl; }
    cout << endl;
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
    cout << endl;
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
        cout << "��� ����c������� ������ ���� �������" << endl;
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
