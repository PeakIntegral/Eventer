#include "Utilities.h"
class TaskBoard {
private:
	static const string const_file_path;
	static const string full_file_path;
	static unordered_map<unsigned, string> events; // Номер задачи в списке и её описание
	static bool needchanges;
	bool saveFile();
	
public:
	TaskBoard();
	~TaskBoard();
	void addEvent();
	void showActualEvents();
	void removeEvent();
	void clearEventBoard();};
