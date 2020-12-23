#include "..\inc\useClassExample.h"
#include"../inc/tabtenn0.h"
#include<iostream>
void useBaseClass()
{
	using std::cout;
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable()) 
	{
		cout << ":has a table.\n";
	}
	else 
	{
		cout << ": hasn't a table.\n";
	}

	player2.Name();
	if (player2.HasTable())
	{
		cout << ":has a table.\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}
}

//usett1.cpp -- using base class and derived class
#include<iostream>
#include"../inc/tabtenn1.h"
void usett1()
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatePlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();	//base class method
	if (rplayer1.HasTable()) 
	{
		cout << ": has a table.\n";
	}
	else 
	{
		cout << ": hasn't a table.\n";
	}
	player1.Name();
	if (player1.HasTable())
	{
		cout << ": has a table.\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}
	cout << "Name: ";
	rplayer1.Name();
	//derive class method
	cout << ": Rating:" << rplayer1.Rating() << endl;	
	RatePlayer rplayer2(1212, player1);
	cout << "Name: ";
	rplayer2.Name();
	cout << ": Rating:" << rplayer2.Rating() << endl;
}
