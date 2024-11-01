#include "Utilities.h"
class TaskBoard {
private:
	static const string const_file_path;
	static map<unsigned, string> events; // Номер задачи в списке и её описание
	static map<string, map<unsigned, string>> board; // Название разделов прогрессий задач и непосредственно сам список
	static const string full_file_path;
public:
	void addEvent();
	void testEvent();
	void showActualEvents();
	void clearEventBoard();		
};
