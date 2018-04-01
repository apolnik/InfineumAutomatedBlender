#include "Logger.h"
#include "CurrentSen.h"
#include "weightMeasurement.h"
#include "tempMeasurement.h"
#include "sys/time.h"
// typedef struct logs{
// 		double weight1_logs;
// 		double mix1_logs;
// 		double hot1_logs;

// 		double weight1_logs;
// 		double mix1_logs;
// 		double hot1_logs;
	
// 		double weight1_logs;
// 		double mix1_logs;
// 		double hot1_logs;

// 		double weight1_logs;
// 		double mix1_logs;
// 		double hot1_logs;

// 		int time;

// }logs_t;
Logger::Logger(){

	tail = head = NULL;
	graph_start=NULL;

}

int Logger::displayLogs(){


}
int Logger::saveLogs(){


}
void Logger::updateLogs(){
	logs_t* l = new logs_t();
	l->weight1_logs = weightMeasurement::beaker1_weight;
	l->weight2_logs = weightMeasurement::beaker2_weight;
	l->weight3_logs = weightMeasurement::beaker3_weight;
	l->weight4_logs = weightMeasurement::beaker4_weight;

	CurrentSen* cur_sen = CurrentSen::stirrer_sen;
	double temp_b1 = tempMeasurement::tmp1->measureHeat();
	double temp_b2 = tempMeasurement::tmp2->measureHeat();
	double temp_b3 = tempMeasurement::tmp3->measureHeat();
	double temp_b4 = tempMeasurement::tmp4->measureHeat();
	double current = cur_sen->measureCurrent();
	l->mix1_logs = current;
	l->mix2_logs = current;
	l->mix3_logs = current;
	l->mix4_logs = current;
	l->hot1_logs = temp_b1;
	l->hot2_logs = temp_b2;
	l->hot3_logs = temp_b3;
	l->hot4_logs = temp_b4;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	l->time = tv.tv_sec;
	insertLog(l);

}
void Logger::insertLog(logs_t* l){
	if(size==100){
		graph_start=tail;
	}
	if(size>100){
		graph_start=graph_start->prev;
	}
	if(size<10000){
		LogNode* new_node = new LogNode(l,NULL,head);
		head = new_node;
		size++;
		if(head->next == NULL)
			tail = head;
	}
	else{
		remove1000xLogs();
		LogNode* new_node = new LogNode(l,NULL,head);
		head = new_node;
		size++;
	}


}

void Logger::removeNode(LogNode* n){

	if(n == NULL){
		return;

	}
	if(n->prev != NULL){
		n->prev->next = n->next;

	}
	if(n->next != NULL){
		n->next->prev = n->prev;

	}
	if(tail == n){
		tail = n->prev;

	}
	if(head == n){
		head = n->next;

	}
	delete n;//->t;

}

void Logger::remove1000xLogs(){
	LogNode* temp = graph_start->next;
	int count =0;
	while(temp!=tail){
		//delete 9/10 nodes after the most recent 100 samples
		if(count%10!=0){
			LogNode* deltemp = temp;
			temp = temp->next;
			removeNode(deltemp);

		}
		else{
			temp=temp->next;
		}
		count++;
	}

}
