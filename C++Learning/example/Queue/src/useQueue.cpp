#include<iostream>
#include<cstdlib>
#include<ctime>
#include"../inc/Queue.h"
#include "..\inc\useQueue.h"

const int MIN_PER_HR = 60;
bool newcustomer(double x);	//is there a new customer

void useQueue()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	//setting things up
	std::srand(std::time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximun size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	//simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours;

	cout << "Enter the average number of customer per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;		//new customer data
	long customers = 0;		//turn away by full queue
	long served = 0;		//joined the queue
	long sum_line = 0;		//cumulative line length
	int wait_time = 0;		//time until autoleller is free
	long line_waite = 0;	//cumulative tie in line

	//running the simulation
	for (int cycle=0; cycle < cyclelimit; cycle++) 
	{
		if (newcustomer(min_per_cust))	//have new comer
		{
			if (line.isFull()) 
			{
				turnaways++;
			}
			else 
			{
				customers++;
				temp.set(cycle);	//cycle = time of arrival
				line.enQueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isEmpty()) 
		{
			line.deQueue(temp);
			wait_time = temp.ptime();
			line_waite += cycle - temp.when();
			served++;
		}
		if (wait_time > 0) 
		{
			wait_time--;
		}
		sum_line += line.queueCount();
	}

	//reporting results
	if (customers > 0)
	{
		cout << "Customers accepted: " << customers << endl;
		cout << " customers served: " << served << endl;
		cout << "	turn aways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_waite / served << " minutes\n" << endl;
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
}

bool newcustomer(double x) 
{
	return (std::rand() * x / RAND_MAX < 1);
}