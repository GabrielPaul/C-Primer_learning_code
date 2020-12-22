#pragma once
class Customer {
private:
	long arrive;	//arrival time for customer
	int processtime;	//processing time for customer

public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when()const { return arrive; }
	int ptime()const { return processtime; }
};