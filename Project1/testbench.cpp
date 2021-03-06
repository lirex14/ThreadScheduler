// Project1.cpp : Defines the entry point for the console application.
//Aiyu Cui, Rex Li, Weiming Shan


#include "myscheduler.h"

int main(int argc, char* argv[])
{
	int flag = 0;
	int arrivingTime[5] = { 1, 3, 4, 2, 5 };
	int remainingTime[5] = { 4, 8, 3, 5, 7 };
	int priority[5] = { 1, 8, 4, 5, 1 };
	MyScheduler Scheduler1(FCFS, 2);
	MyScheduler Scheduler2(STRFwoP, 2);
	MyScheduler Scheduler3(PBS, 2);
	MyScheduler Scheduler4(STRFwP, 2);

	for (int i = 0; i < 5; i++) //5 threads
	{
	//Scheduler1.CreateThread(arrivingTime[i], remainingTime[i], priority[i], i);
	//Scheduler2.CreateThread(arrivingTime[i], remainingTime[i], priority[i], i);

	//Scheduler3.CreateThread(arrivingTime[i], remainingTime[i], priority[i], i);
	Scheduler4.CreateThread(arrivingTime[i], remainingTime[i], priority[i], i);
	}

	//Scheduler1.Go();
	//Scheduler2.Go();
	//Scheduler3.Go();
	Scheduler4.Go();
	return 0;
	
}