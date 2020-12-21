//mytime1.cpp --implementing Time methods
#include<iostream>
#include"../inc/mytime1.h"
TimeType1::TimeType1()
{
	hours_ = minutes_ = 0;
}

TimeType1::TimeType1(int h, int m)
{
	hours_ = h;
	minutes_ = m;
}

void TimeType1::AddMin(int m)
{
	minutes_ += m;
	hours_ += minutes_ / 60;
	minutes_ %= 60;
}

void TimeType1::AddHr(int h)
{
	hours_ += h;
}

void TimeType1::Reset(int h, int m)
{
	hours_ = h;
	minutes_ = m;
}

/*
overload operator +
*/
TimeType1 TimeType1::operator+(const TimeType1& t) const
{
	TimeType1 sum;
	sum.minutes_ = minutes_ + t.minutes_;
	sum.hours_ = hours_ + t.hours_ + sum.minutes_ / 60;
	sum.minutes_ %= 60;
	return sum;
}

void TimeType1::Show()
{
	std::cout << hours_ << " hours," << minutes_ << " minutes";
}