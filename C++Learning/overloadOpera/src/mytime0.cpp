#include<iostream>
#include"../inc/mytime0.h"

TimeType0::TimeType0()
{
	hours_ = minutes_ = 0;
}

TimeType0::TimeType0(int h, int m)
{
	hours_ = h;
	minutes_ = m;
}

void TimeType0::AddMin(int m)
{
	minutes_ += m;
	hours_ += minutes_ / 60;
	minutes_ %= 60;
}

void TimeType0::AddHr(int h)
{
	hours_ += h;
}

void TimeType0::Reset(int h, int m)
{
	hours_ = h;
	minutes_ = m;
}

TimeType0 TimeType0::Sum(const TimeType0& t) const
{
	TimeType0 sum;
	sum.minutes_ = minutes_ + t.minutes_;
	sum.hours_ = hours_ + t.hours_ + sum.minutes_/60;
	sum.minutes_ %= 60;
	return sum;
}

void TimeType0::Show() const
{
	std::cout << hours_ << " hours," << minutes_ << " minutes";
}
