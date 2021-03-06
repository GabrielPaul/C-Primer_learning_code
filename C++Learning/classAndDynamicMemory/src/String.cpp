#include "..\inc\String.h"

//intializing static class member
int String::num_strings = 0;
String::String(const char* s)
{
	len = std::strlen(s);		//set size
	str = new char[len + 1];	//allot storage
	std::strcpy(str, s);		//set object count
	num_strings++;
}

String::String()
{
	len = 0;
	str = new char[1];	//"new char[]" compatible with "delete [] str"
	str[0] = '\0';	//default string
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete[]str;
}

String& String::operator=(const String& st)
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

String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

//for use with const String objects
const char& String::operator[](int i) const
{
	return str[i];
}

char& String::operator[](int i)	//declare as char&,can be used 'String means("test");
								// means[0] = 'r'; '
{
	return str[i];
}

//The strcmp function is in alphabetical order, 
//1.the first parameter is before the second parameter, the function
//	Return a negative value; 
//2.if the two strings are the same, return 0;
//3.If the first parameter is after the second parameter, a positive value is returned
bool operator<(const String& st, const String& st2)
{
	return (std::strcmp(st.str, st2.str) < 0);
}

bool operator>(const String& st, const String& st2)
{
	return st2.str < st.str;
}

bool operator==(const String& st, const String& st2)
{
	return (std::strcmp(st.str, st2.str) == 0);
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is) //If for some reason (if the end of the file is reached, 
			//or get(char*,int) reads a blank line), the input fails, 
			//the value of the istream object will be set to false.
	{
		st = temp;
	}
	while (is && is.get() != '\n') 
	{
		continue;
	}
	return is;
}

//static method
int String::HowMany()
{
	return num_strings;
}