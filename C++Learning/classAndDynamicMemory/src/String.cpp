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
	str = new char[1];
	str[0] = '\0';	//default string
	num_strings++;
}

String::~String()
{
	--num_strings;
	delete[]str;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
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

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}
