#pragma once
#include<iostream>
class String {
private:
	char* str;	//pointer to string
	int len;	//length of string
	static int num_strings;	//number if objects
	static const int CINLIM = 80;

public:
	String(const char* s);
	String();
	String(const String& st);	//copy constructor
	~String();

	int length()const { return len; };
	//overloaded operator methods
	String& operator =(const String& st);
	String& operator =(const char* s);
	char& operator[](int i);
	const char& operator[](int i)const;
	//overload operator friends
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend std::ostream& operator <<(std::ostream& os,const String& st);
	friend std::istream& operator>>(std::istream& is,String& st);
	//static function
	static int HowMany();
};