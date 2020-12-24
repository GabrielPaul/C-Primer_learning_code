#pragma once
class Brass {
private:
	enum { MAX = 35 };
	char fullname[MAX];
	long accNum;
	double balance;

public:
	Brass(const char* s = "Nullbody", long an = -1,
		double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance()const;
	virtual void ViewAcct()const;
	virtual ~Brass();
};

//Brass Plus Account Class
class BrassPlus :public Brass{
private:
	double maxLoan;
	double rate;
	double oweBank;

public:
	BrassPlus(const char* s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500,
		double r = 0.10);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; };
	void ResetRate(double r) { rate = r; };
	void ResetOwes() { oweBank = 0; };
};