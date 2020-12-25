#if 0
#include "../inc/brass.h"
#include<iostream>
#include<cstring>
using std::cout;
using std::ios_base;
using std::endl;

Brass::Brass(const char* s, long an, double bal)
{
	std::strncpy(fullname, s, MAX - 1);
	fullname[MAX - 1] = '\0';
	accNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0) 
	{
		cout << "Withdrawal amount must be positive:"
			<< "Withdrawal canceled.\n";
	}
	else
	{
		balance += amt;
	}
}

void Brass::Withdraw(double amt)
{
	if (amt < 0) 
	{
		cout << "Withdrawal amout must be positive: "
			<< "Withdraw canceled.\n";
	}
	else if (amt <= balance) 
	{
		balance -= amt;
	}
	else 
	{
		cout << "Withdrawal amout of $ " << amt
			<< "exceds your balance.\n"
			<< "Withdrawal canceled.\n";
	}
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	//set up ###.## format
	ios_base::fmtflags intialState =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	cout << "Client: " << fullname << endl;
	cout << "Account Number: " << accNum << endl;
	cout << "Balance:$ " << balance << endl;
	cout.setf(intialState);

}

Brass::~Brass()
{
}

BrassPlus::BrassPlus(const char* s, long an, double bal, double ml, double r)
	:Brass(s,an,bal)
{
	maxLoan = ml;
	oweBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r)
	:Brass(ba)
{
	maxLoan = ml;
	oweBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	//set up ###.## format
	ios_base::fmtflags intialState =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);

	Brass::ViewAcct();	//display base portion
	cout << "Maximum loadn:$ " << maxLoan << endl;
	cout << "Owed to bank: $" << oweBank << endl;
	cout << "Loan Rate: " << 100 * rate << "%\n";
	cout.setf(intialState);
}

void BrassPlus::Withdraw(double amt)
{
	//set up ###.## format
	ios_base::fmtflags initialState =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);

	double bal = Balance();
	if (amt < bal) 
	{
		Brass::Withdraw(amt);
	}
	else if (amt <= bal + maxLoan - oweBank) 
	{
		double advance = amt - bal;
		oweBank += advance * (1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else 
	{
		cout << "Credit limit exceeded.Transactin cancelled.\n";
	}
	cout.setf(initialState);
}
#endif