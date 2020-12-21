//mytime0.h --Time class befor operator overloading
#ifndef MYTIME0_H_
#define MYTIME0_H_
class TimeType0{
private:
	int hours_;
	int minutes_;

public:
	TimeType0();
	TimeType0(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h, int m = 0);
	TimeType0 Sum(const TimeType0& t)const;
	void Show()const;
};

int UseMytime0();
#endif
