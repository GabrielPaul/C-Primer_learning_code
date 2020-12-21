//strngbad.h --flawed string class definition
#include<iostream>
#pragma once
class StringBad {
private:
	char* str;	//pointer to string
	int len;	//length of string
	static int num_strings;	//number if objects

public:
	StringBad(const char* s);
	StringBad();
	~StringBad();

	//friend function
	friend std::ostream& operator <<(std::ostream& os,
		const StringBad& st);
};