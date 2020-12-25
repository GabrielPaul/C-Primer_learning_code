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

#if 0
//usebrass1.cpp --testing bank accout classes
//compile with brass.cpp
#include<iostream>
#include"../inc/brass.h"
void usebrass1()
{
	using std::cout;
	using std::endl;

	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Depositing $1000 into the Hogg Account: \n";
	Hoggy.Deposit(1000.00);
	cout << "New balance :$" << Hoggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Hogg Account: \n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
}
#endif

//usebrass2.cpp --polyorphic example
//compile with brass.cpp
#include<iostream>
//#include"../inc/brass.h"
#include"../../ABC/inc/acctabc.h"
void usebrass2()
{
	const int CLINETS = 4;
	const int LEN = 40;
	using std::cin;
	using std::cout;
	using std::endl;
	//Brass* p_clients[CLINETS];
	AcctABC* p_clients[CLINETS];

	int i;
	for (i = 0; i < CLINETS; i++) 
	{
		char temp[LEN];
		long tempnum;
		double tempbal;
		char kind;
		cout << "Enter client's name: ";
		cin.getline(temp, LEN);
		cout << "Enter client's account number: ";
		cin >> tempnum;
		cout << "Enter opening balance:$ ";
		cin >> tempbal;
		cout << "Enter 1 for Brass Accout or "
			<< "2 for BrassPlus Accout: ";
		while (cin >> kind && (kind != '1' && kind != '2')) 
		{
			cout << "Enter either 1 or 2";
		}
		if (kind == '1') 
		{
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		}
		else 
		{
			double tmax, trate;
			cout << "Enter the overdraft limit:$";
			cin >> tmax;
			cout << "Enter the interest rate "
				<< "as a decimal fraction: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp,tempnum,tempbal,tmax,trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (i = 0; i < CLINETS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (i = 0; i < CLINETS; i++)
	{
		delete p_clients[i];
	}
	cout << "Done.\n" << endl;
}
