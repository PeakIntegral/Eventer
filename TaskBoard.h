#include "Utilities.h"
class TaskBoard {
private:
	static const string const_file_path;
	static map<unsigned, string> events; // ����� ������ � ������ � � ��������
	static map<string, map<unsigned, string>> board; // �������� �������� ���������� ����� � ��������������� ��� ������
	static const string full_file_path;
public:
	void addEvent();
	void testEvent();
	void showActualEvents();
	void clearEventBoard();		
};
