#include "../inc/typTranExp.h"
#include"../inc/stonewt.h"
#include<iostream>
void assignmentTest() 
{
	Stonewt myCat;
#if IMPLICT_CONVERSION
	myCat = 19.6;	//use construct with doule to construct object.
					//then copy it to myCat.called "Implicit conversion"
					//only accept one parameter.
#else
	myCat = Stonewt(19.6);
	myCat = (Stonewt)19.6;
#endif

}

using std::cout;
void display(const Stonewt st, int n);
void useStonewt() 
{
	Stonewt pavarotti = 260; //uses construct to initialize
	Stonewt wolfe(285.7);	//same as Stonewt wolfe = 285.7
	Stonewt taft(21,8);

	cout << "the tenor weighed ";
	pavarotti.show_stn();
	cout << "the detective weighed ";
	wolfe.show_stn();
	cout << "The President weighed ";
	taft.show_lbs();
	pavarotti = 265.8;
	taft = 325;	//int to double , then double to class type
	cout << "After dinner,the tenor weighed ";
	pavarotti.show_stn();
	cout << "After dinner, the President weighed ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";

}

void display(const Stonewt st, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		cout << "Wow! ";
		st.show_stn();
	}
}

//stone1.cpp --user-defined conersion  functions
//compile with stonewt1.cpp
#include<iostream>
#include"../inc/stonewt1.h"
void useStonewt1()
{
	using std::cout;
	StonewtType1 poppins(9, 2.8);
	double p_wt = poppins;	//implict conversion
	cout << "convert to double";
	cout << "Poppins: " << p_wt << " pounds.\n";
	cout << "Convert to int => ";
	cout << "Poppins: " << int(poppins) << " pounds\n";

}