#include "../inc/stonewt1.h"
#include<iostream>
using std::cout;
StonewtType1::StonewtType1(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;//integer division
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

StonewtType1::StonewtType1(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

StonewtType1::StonewtType1()
{
	stone = pounds = pds_left = 0;
}

StonewtType1::~StonewtType1()
{
}

void StonewtType1::show_lbs() const
{
	cout << pounds << " pounds\n";
}

void StonewtType1::show_stn() const
{
	cout << stone << " stone," << pds_left << " pounds\n";
}

StonewtType1::operator int() const
{
	return int(pounds + 0.5);
}

StonewtType1::operator double() const
{
	return pounds;
}
