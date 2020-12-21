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

	//add new functions
	int length()const { return len; };
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend std::istream& operator>>(std::istream& is,String& st);
	char& operator[](int i);
	const char& operator[](int i)const;
	static int HowMany();
	String& operator =(const char* s);
};