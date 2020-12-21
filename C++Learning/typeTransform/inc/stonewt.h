//example code for showing type transform.
//stonewt.h --definetion for Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_

#define IMPLICT_CONVERSION 1

class Stonewt {
private:
	enum {Lbs_per_stn = 14}; //define special const variable for class
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt();
#if IMPLICT_CONVERSION
	Stonewt(double lbs);
#else
	explicit Stonewt(double lbs);	//no implict conversion allowed
#endif
	Stonewt(int stn,double lbs);
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;
};

#endif