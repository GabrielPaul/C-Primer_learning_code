#include "../inc/tabtenn1.h"
#include<iostream>
#include<cstring>
RatePlayer::RatePlayer(unsigned int r, const char* fn, const char* ln, bool ht)
	:TableTennisPlayer(fn,ln,ht)
{
	rating = r;
}

RatePlayer::RatePlayer(unsigned int r, const TableTennisPlayer& tp)
	:TableTennisPlayer(tp),rating(r)
{
}
