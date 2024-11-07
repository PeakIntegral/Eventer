#include "Utilities.h"
class TaskBoard {
private:
	static fstream file;
	static const string const_file_path;
	static unordered_map<unsigned, string> events; // Номер задачи в списке и её описание
	/*static unordered_map<unsigned, string> to_do_tasks; // 1. Банк новых задач
	static unordered_map<unsigned, string> tasks_in_develope; // 2. В процессе разработки/исследования
	static unordered_map<unsigned, string> test_tasks; // 3. Тестируется
	static unordered_map<unsigned, string> ready_tasks; // 4. Готово
	static unordered_map<unsigned, string> droped_tasks; // 5. Заброшено
	static unordered_map<string, unordered_map<unsigned, string>> board; // Название разделов прогрессий задач и непосредственно сам список*/
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
