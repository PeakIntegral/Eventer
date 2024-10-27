//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <stdbool.h>
using namespace std;

int count_event = 0;
string location = ";C:/Users/Mikul/Documents/Eventer/Eventer.txt";
unsigned number_utility;

unordered_map<unsigned, string> events;

void testEvent() {
    string name_event;
    cout << "Создать задачу: ";
    cin >> name_event;
    events[++count_event] = name_event;
    return;
}


void addEvent() {
    string name_event;
    cout << "Создать задачу: ";
    cin >> name_event;

    // Проверка на существование задачи в файле
    fstream file(location);
    events[++count_event] = name_event;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find(name_event) != string::npos) {
                cout << "Такая задача уже существует." << endl;
                file.close();
                events[count_event].erase();
                count_event--;
                return;
            }
        }
    }
    else {
        events[count_event].erase();
        count_event--;
        cerr << "Не удалось открыть файл для записи." << endl;
        return;
    }

    // Запись задачи в файл
    file << count_event << ": " << name_event << ";\n";
    file.close();
    cout << "Задача добавлена." << endl;
}   
void showActualEvents() {
    for (const auto& event : events) {
        cout << event.first << ' ' << event.second << endl;
    }
    return;
}

int main() {
    system("chcp 1251 > nul");
    do {
        cout << "Выберете утилиту: " << endl;
        cout << "1. Добавление задачи в текстовый файл\n2. Добавление задачи ТОЛЬКО в мапу\n3. Показать актуальные задачи\n4. Ебучий выход\n";
        scanf_s("%hd", &number_utility);
        switch (number_utility) {
        case 1:
            addEvent();
            break;
        case 2:
            testEvent();
            break;
        case 3:
            showActualEvents();
            break;
        case 4:
            return 0;
        default:
            cout << "Полная лажа" << endl;
            break;
        }

    } while (number_utility != 4);
}