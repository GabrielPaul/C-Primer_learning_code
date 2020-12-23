#pragma once
#include"tabtenn0.h"
//simple derived class
class RatePlayer :public TableTennisPlayer {
private:
	unsigned int rating;

public:
	RatePlayer(unsigned int r = 0, const char* fn = "none",
		const char* ln = "none", bool ht = false);
	RatePlayer(unsigned int r, const TableTennisPlayer& tp);
	unsigned int Rating() { return rating; };
	void ResetRating(unsigned int r) { rating = r; };

};