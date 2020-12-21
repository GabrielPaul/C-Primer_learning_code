#include<iostream>
#include"../inc/mytime2.h"
TimeType2::TimeType2() 
{
	hours_ = minutes_ = 0;
}

TimeType2::TimeType2(int h, int m) 
{
	hours_ = h;
	minutes_ = m;
}

void TimeType2::AddMin(int m)
{
	minutes_ += m;
	hours_ += minutes_ / 60;
	minutes_ %= minutes_;
}

void TimeType2::AddHr(int h)
{
	hours_ += hours_;
}

void TimeType2::Reset(int h, int m)
{
	hours_ = h;
	minutes_ = m;
}

TimeType2 TimeType2::operator+(const TimeType2& t) const
{
	TimeType2 sum;
	sum.minutes_ = minutes_ + t.minutes_;
	sum.hours_ = hours_ + t.hours_ + sum.minutes_ / 60;
	sum.minutes_ = sum.minutes_ % 60;
	return sum;
}

TimeType2 TimeType2::operator-(const TimeType2& t) const
{
	TimeType2 diff;
	int tot1, tot2;
	tot1 = t.minutes_ + 60 * t.hours_;
	tot2 = minutes_ + 60 * hours_;
	diff.minutes_ = (tot2 - tot1) % 60;
	diff.hours_ = (tot2 - tot1) / 60;
	return diff;
}

TimeType2 TimeType2::operator*(double mult) const
{
	TimeType2 result;
	long totalminutes = hours_ * mult * 60 + minutes_ * mult;
	result.hours_ = totalminutes / 60;
	result.minutes_ = totalminutes % 60;
	return result;
}

void TimeType2::Show() const
{
	std::cout << hours_ << " hours," << minutes_ << " minutes";
}

TimeType2 operator*(double mult, const TimeType2& t)
{
	TimeType2 result;
	long totalminutes = t.hours_ * mult * 60 + t.minutes_ * mult;
	result.hours_ = totalminutes / 60;
	result.minutes_ = totalminutes % 60;
	return result;
}

std::ostream& operator<<(std::ostream& os, const TimeType2& t)
{
	os << t.hours_ << " hours," << t.minutes_ << " minutes";
	return os;
}
