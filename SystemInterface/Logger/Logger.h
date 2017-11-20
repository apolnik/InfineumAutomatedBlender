#ifndef Logger_H
#define Logger_H


class Logger{
	public:
	int* logs;
	int size;
	int capacity;
	Logger();

	int displayLogs();
	int saveLogs();

};
 
#endif /* Logger_H */
