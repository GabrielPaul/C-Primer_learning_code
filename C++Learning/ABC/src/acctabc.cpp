#include "..\inc\acctabc.h"
#include<iostream>
#include<cstring>
using std::cout;
using std::ios_base;
using std::endl;

//Abstrat Base Class
AcctABC::AcctABC(const char* s, long an, double bal)
{
	std::strncpy(fullName, s, MAX - 1);
	fullName[MAX - 1] = '\0';
	acctNum = an;
	balance = bal;
}

void AcctABC::Deposit(double amt)
{
	if (amt < 0)
	{
		cout << "Negative deposti not allowed: "
			<< "deposti is cancelled.\n";
	}
	else
		balance += amt;
}

void AcctABC::WithDraw(double amt)
{
	balance -= amt;
}

//protected method
ios_base ::fmtflags AcctABC::SetFormat()const
{
	//set up ###.## format
	ios_base::fmtflags intialState =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	return intialState;
}

//Brass methods
void Brass::WithDraw(double amt)
{
	if (amt < 0) 
	{
		cout << "Withdrawal amout must be positive;"
			<< "withdrawal canceled.\n";
	}
	else if (amt <= Balance()) 
	{
		AcctABC::WithDraw(amt);
	}
	else 
	{
		cout << "Withdrawal amout of $" << amt
			<< " exceeds your balance.\n"
			<< "Withdrawal canceled.\n";
	}

}

void Brass::ViewAcct() const
{
	ios_base::fmtflags initialState = SetFormat();
	cout << "Brass Client: " << FullName() << endl;
	cout << "Account Number: " << AcctNum() << endl;
	cout << "Balance:$" << Balance() << endl;
	cout.setf(initialState);
}

//BrassPlus Methods
BrassPlus::BrassPlus(const char* s, long an,
	double bal, double ml,
	double r):AcctABC(s,an,bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct()const 
{
	ios_base::fmtflags initialState = SetFormat();

	cout << "BrassPlus Client: " << FullName() << endl;
	cout << "Acctount Number: " << AcctNum() << endl;
	cout << "Balance:$ " << Balance() << endl;
	cout << "Maximum loan:$ " << maxLoan << endl;
	cout << "Owed to bank:$" << owesBank << endl;
	cout << "Loan Rate: " << 100 * rate << "%\n";
	cout.setf(initialState);
}

void BrassPlus::WithDraw(double amt) 
{
	ios_base::fmtflags initialState = SetFormat();

	double bal = Balance();
	if(amt<=bal)
	{
		AcctABC::WithDraw(amt);
	}
	else if (amt <= bal + maxLoan - owesBank) 
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance:$" << advance << endl;
		Deposit(advance);
		AcctABC::WithDraw(amt);
	}
	else
	{
		cout << "Credit limit exceeded.Transaction cancelled.\n";
	}
	cout.setf(initialState);
}