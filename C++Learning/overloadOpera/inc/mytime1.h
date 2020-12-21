#ifndef MYTIME1_H_
#define MYTIME1_H_

class TimeType1 {
private:
	int hours_;
	int minutes_;

public:
	TimeType1();
	TimeType1(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h, int m);
	TimeType1 operator+(const TimeType1& t) const;  //overload operator +
	void Show();
};

#endif // !MYTIME1_H_
