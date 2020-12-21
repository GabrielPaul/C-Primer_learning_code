#pragma once
class StonewtType1 {
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;

public:
	StonewtType1(double lbs);
	StonewtType1(int stn,double lbs);
	StonewtType1();
	~StonewtType1();
	void show_lbs()const;
	void show_stn()const;
	//conversion functions
	operator int()const;
	operator double()const;
};