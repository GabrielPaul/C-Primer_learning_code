//stonewt.cpp --Stonewt methods
#include<iostream>
#include "../inc/stonewt.h"

using std::cout;
Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;//integer division
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::~Stonewt()
{
}

void Stonewt::show_lbs() const
{
	cout << pounds << " pounds\n";
}

void Stonewt::show_stn() const
{
	cout << stone << " stone," << pds_left << " pounds\n";
}
