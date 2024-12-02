#include <iostream>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <unordered_map>
#include <stdbool.h>
using namespace std;

vector<string> mySplit(string letter, char div)
{
    vector<string>spliter;
    size_t start_pos, end_pos;
    start_pos = 0;
    do {
        end_pos = letter.find(div, start_pos);
        spliter.push_back(letter.substr(start_pos, end_pos - start_pos));
        start_pos = end_pos + 1;
    } while (end_pos != string::npos);
    return spliter;
}
std::string mySplit(string letter, char div, string def) {
    size_t start_pos = 0, end_pos;
    end_pos = letter.find(div, start_pos);
    if (def == "number") return letter.substr(start_pos, end_pos - start_pos);
    if (def == "definition") return letter.substr(end_pos + 1);
}