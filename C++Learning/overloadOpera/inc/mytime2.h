#ifndef MYTIME2_H_
#define MYTIME2_H_

#include <ostream>
class TimeType2{
private:
	int hours_;
	int minutes_;

public:
	TimeType2();
	TimeType2(int h, int m);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h, int m);
	TimeType2 operator+(const TimeType2& t)const;
	TimeType2 operator-(const TimeType2& t)const;
	TimeType2 operator*(double n)const;
	friend TimeType2 operator*(double m, const TimeType2& t);
	friend std::ostream& operator<<(std::ostream& os, const TimeType2& t);
	void Show()const;
};
#endif