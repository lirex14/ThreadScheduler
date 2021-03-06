

#pragma once
//myschedule.h
//Aiyu Cui, Rex Li, Weiming Shan


/* Students need to define their own data structure to contain
   and access objects from 'thread class'. The 'CreateThread()' 
   function should insert the threads into the student defined
   data structure after creating them.
   They are allowed to add any additional functionality (only 
   declaration in this file, define in 'myschedule.cpp')
   which they might find helpful.*/

#include "scheduler.h"
#include <queue> 
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
using namespace std;

struct compareAT {
public:
	 bool operator()( const ThreadDescriptorBlock& a, const ThreadDescriptorBlock& b) { return a.arriving_time > b.arriving_time; }
	
};
struct compareRT {
public:
	bool operator()(const ThreadDescriptorBlock& a, const ThreadDescriptorBlock& b) { return a.remaining_time > b.remaining_time; }

};
struct comparePR {
public:
	bool operator()(const ThreadDescriptorBlock& a, const ThreadDescriptorBlock& b) { return a.priority > b.priority; }

};
static priority_queue<ThreadDescriptorBlock, vector<ThreadDescriptorBlock>, compareAT> buffer;
static priority_queue<ThreadDescriptorBlock, vector<ThreadDescriptorBlock>, compareRT> bufferRT;
static priority_queue<ThreadDescriptorBlock, vector<ThreadDescriptorBlock>, compareRT> bufferPR;

static bool threadControl = false; //

class MyScheduler: public Scheduler {
public:
	MyScheduler(Policy p, unsigned int n) : Scheduler(p, n) {}
	bool Dispatch() override; //Function to implement scheduling policy and to keep a check on processed threads
	void CreateThread(int arriving_time, int remaining_time, int priority, int tid) override; //Function to create threads and insert them in student defined data structure
private: 
	int findNextAvailableCPU();
	ThreadDescriptorBlock *getHighestPriorityThread();
	int MyScheduler::getCPUThreadLowestPriority();
	bool MyScheduler::isFreeAllCPU();
	int MyScheduler::getCPUThreadLRT();
	ThreadDescriptorBlock *MyScheduler::getThreadSRT();

};