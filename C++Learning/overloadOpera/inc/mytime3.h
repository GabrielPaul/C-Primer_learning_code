#ifndef MYTIME3_H_
#define MYTIME3_H_
#include<iostream>
class TimeiType3 {
private:
	int hours_;
	int minutes_;

public:
	TimeiType3();
	TimeiType3(int h, int m);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h, int m);
	TimeiType3 operator+(const TimeiType3& t)const;
	TimeiType3 operator-(const TimeiType3& t)const;
	TimeiType3 operator* (double m)const;
	friend TimeiType3 operator* (double m, const TimeiType3& t)
	{
		return t * m;	//inline definition
	}
	friend std::ostream& operator<<(std::ostream& o, const TimeiType3& t);
};

#endif