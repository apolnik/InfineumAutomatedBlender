#ifndef Logger_H
#define Logger_H
typedef struct logs{
		double weight1_logs;
		double mix1_logs;
		double hot1_logs;

		double weight2_logs;
		double mix2_logs;
		double hot2_logs;
	
		double weight3_logs;
		double mix3_logs;
		double hot3_logs;

		double weight4_logs;
		double mix4_logs;
		double hot4_logs;

		int time;

}logs_t;

class Logger{
	public:
	class LogNode{
	public:
		LogNode* next;
		LogNode* prev;
		logs_t* logs_n;
		LogNode(logs_t* logs_n, LogNode* prev, LogNode* next) 
				: logs_n(logs_n), prev(prev), next(next)
		{


		}
		
	};
	LogNode* head;
	LogNode* tail;
	LogNode* graph_start;
	int size;
	Logger();
	void insertLog(logs_t* l);
	void removeNode(LogNode* n);
	int displayLogs();
	int saveLogs();
	void remove1000xLogs();
	void updateLogs();
};
 
#endif /* Logger_H */
