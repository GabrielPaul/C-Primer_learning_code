#include "..\inc\mytime3.h"

TimeiType3::TimeiType3()
{
    hours_ = minutes_ = 0;
}

TimeiType3::TimeiType3(int h, int m)
{
    hours_ = h;
    minutes_ = m;
}

void TimeiType3::AddMin(int m)
{
    minutes_ += m;
    hours_ += minutes_ / 60;
    minutes_ = minutes_ % 60;
}

void TimeiType3::AddHr(int h)
{
    hours_ += h;
}

void TimeiType3::Reset(int h, int m)
{
    hours_ = h;
    minutes_ = m;
}

TimeiType3 TimeiType3::operator+(const TimeiType3& t) const
{
    TimeiType3 sum;
    sum.minutes_ =minutes_+ t.minutes_;
    sum.hours_ = hours_ + t.hours_ + sum.minutes_/60;
    sum.minutes_ %= 60;
    return sum;
}

TimeiType3 TimeiType3::operator-(const TimeiType3& t) const
{
    TimeiType3 diff;
    int tot1, tot2;
    tot1 = hours_ * 60 + minutes_;
    tot2 = t.hours_ * 60 + t.minutes_;
    diff.minutes_ = (tot1 - tot2) % 60;
    diff.hours_ = (tot1 - tot2) / 60;
    return diff;
}

TimeiType3 TimeiType3::operator*(double m) const
{
    TimeiType3 result;
    long totalminutes = hours_ * m * 60 + minutes_ * m;
    result.minutes_ = totalminutes % 60;
    result.hours_ = totalminutes / 60;

    //error code
    //result.minutes_ = minutes_ * m;
    //result.hours_ = hours_*m+result.minutes_/60;
    //result.minutes_ %= 60;
    return result;
}

std::ostream& operator<<(std::ostream& os, const TimeiType3& t)
{
    os << t.hours_ << " hours, " << t.minutes_ << " minutes.";
    return os;
}
