#include "Utilities.h"
class TaskBoard {
private:
	static fstream file;
	static const string const_file_path;
	static unordered_map<unsigned, string> events; // ����� ������ � ������ � � ��������
	/*static unordered_map<unsigned, string> to_do_tasks; // 1. ���� ����� �����
	static unordered_map<unsigned, string> tasks_in_develope; // 2. � �������� ����������/������������
	static unordered_map<unsigned, string> test_tasks; // 3. �����������
	static unordered_map<unsigned, string> ready_tasks; // 4. ������
	static unordered_map<unsigned, string> droped_tasks; // 5. ���������
	static unordered_map<string, unordered_map<unsigned, string>> board; // �������� �������� ���������� ����� � ��������������� ��� ������*/
	static const string full_file_path;
public:
	TaskBoard();
	~TaskBoard();
	void addEvent();
	void testEvent();
	void testShowActualEvents();
	void showActualEvents();
	void removeEvent();
	bool clearEventBoard();		
};
