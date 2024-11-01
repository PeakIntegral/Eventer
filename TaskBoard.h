#include "Utilities.h"
class TaskBoard {
private:
	static const string const_file_path;
	static map<unsigned, string> events; // Номер задачи в списке и её описание
	static map<unsigned, string> to_do_tasks; // 1. Банк новых задач
	static map<unsigned, string> tasks_in_develope; // 2. В процессе разработки/исследования
	static map<unsigned, string> test_tasks; // 3. Тестируется
	static map<unsigned, string> ready_tasks; // 4. Готово
	static map<unsigned, string> droped_tasks; // 5. Заброшено
	static map<string, map<unsigned, string>> board; // Название разделов прогрессий задач и непосредственно сам список
	static const string full_file_path;
public:
	void addEvent();
	void testEvent();
	void testShowActualEvents();
	void clearEventBoard();		
};
