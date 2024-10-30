#include "Utilities.h"
class TaskBoard {
protected:
	static unordered_map<unsigned, string> events;
	static const string location;
public:
	void addEvent();
	void testEvent();
	void showActualEvents();
	void clearEventBoard();
};
