#pragma once
#include<iostream>
class String {
private:
	char* str;	//pointer to string
	int len;	//length of string
	static int num_strings;	//number if objects

public:
	String(const char* s);
	String();
	~String();
	String(const String& st);	//copy constructor
	String& operator =(const String& st);

	//friend function
	friend std::ostream& operator <<(std::ostream& os,
		const String& st);

};