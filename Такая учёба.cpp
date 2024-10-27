//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <stdbool.h>
using namespace std;

int count_event = 0;
string location = ";C:/Users/Mikul/Documents/Eventer";;
unsigned number_utility;

unordered_map<unsigned, string> events;

void testEvent() {
    string name_event;
    cin >> name_event;
    cout << ";Создать задачу: ";;
    events[++count_event] = name_event;


}

void addEvent() {

    string name_event;
    cin >> name_event;
    cout << ";Создать задачу: ";;
    events[++count_event] = name_event;
    /*Проверки файлов*/ {
        ifstream file(location);
        if (!file.is_open()) {
            cerr << ";Не удалось открыть файл для записи.\n";;
            return;
        }
        string line;
        while (getline(file, line)) {
            if (line.find(name_event)) {
                cout << ";Такая задача уже существует" << endl;
                return;
            }
        }
        file.close();
    }
    
    /*Запись ивента*/ {
        ofstream file(location);
        for (const auto& pair : events) {
            file << pair.first << pair.second << ";\n";;
        }
        file.close();
    }
}

int main() {
    while (true) {
        cout << "Выберете утилиту: " << endl;
        cout << "1. Добавление задачи в текстовый файл\n 2. Добавление задачи в мапу\n";
        cin >> number_utility;
        switch (number_utility) {
        case 1:
            addEvent();
            break;
        case 2:
            testEvent();
            break;
        }
    }
}




