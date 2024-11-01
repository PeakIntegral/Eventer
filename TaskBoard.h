#include "Utilities.h"
class TaskBoard {
private:
	static const string const_file_path;
	static map<unsigned, string> events; // ����� ������ � ������ � � ��������
	static map<unsigned, string> to_do_tasks; // 1. ���� ����� �����
	static map<unsigned, string> tasks_in_develope; // 2. � �������� ����������/������������
	static map<unsigned, string> test_tasks; // 3. �����������
	static map<unsigned, string> ready_tasks; // 4. ������
	static map<unsigned, string> droped_tasks; // 5. ���������
	static map<string, map<unsigned, string>> board; // �������� �������� ���������� ����� � ��������������� ��� ������
	static const string full_file_path;
public:
	void addEvent();
	void testEvent();
	void testShowActualEvents();
	void clearEventBoard();		
};
