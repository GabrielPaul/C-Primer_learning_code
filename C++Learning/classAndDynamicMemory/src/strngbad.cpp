//#include<iostream>
#include<cstring>
#include"../inc/strngbad.h"
using std::cout;

//intializing static class member
int StringBad::num_strings = 0;

//class methods

//construct StringBad from C string
StringBad::StringBad(const char* s) 
{
	len = std::strlen(s);		//set size
	str = new char[len + 1];	//allot storage
	std::strcpy(str, s);		//set object count
	num_strings++;
	cout << num_strings << ": \"" << str 
		<< "\" object created\n";
}

StringBad::StringBad()	//default constructor
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str
		<< "\" default object created\n";
}

StringBad::~StringBad()		//necessary destructor
{
	cout << "\"" << str << "\" object deleted,";
	--num_strings;
	cout << num_strings << " left\n";
	delete[]str;
}

StringBad::StringBad(const StringBad& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	cout << num_strings << ":\"" << str
		<< "\" object created \n";
}

StringBad& StringBad::operator =(const StringBad& st) 
{
	if (this == &st) 
	{
		return *this;
	}
	delete[] str;	//free old string
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

std::ostream& operator<<(std::ostream& os,
	const StringBad& st)
{
	os << st.str;
	return os;
}