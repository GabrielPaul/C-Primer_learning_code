//usetime0.cpp -using the first draft of Time class
//compile usetime0.cpp and mytime0.cpp together
#include<iostream>
#include"../inc/useMytimeX.h"
#include"../inc/mytime0.h"

int UseMytime0() //main
{
	using std::cout;
	using std::endl;
	TimeType0 planning;
	TimeType0 coding(2, 40);
	TimeType0 fixing(5, 55);
	TimeType0 total;

	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "fixing time = ";
	fixing.Show();
	cout << endl;

	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) = ";
	total.Show();
	cout << endl;

	return 0;
}

/*
	usetime1.cpp --using the secend draft of the Time class
	compile usertime1.cpp and mytime1.cpp together
*/
#include<iostream>
#include"../inc/mytime1.h"
int UseMyTime1()
{
	using std::cout;
	using std::endl;
	TimeType1 planning;
	TimeType1 coding(2, 40);
	TimeType1 fixing(5, 55);
	TimeType1 total;

	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "coding time = ";
	coding.Show();
	cout << endl;

	cout << "fixing time = ";
	fixing.Show();
	cout << endl;

	total = coding + fixing;
	cout << "coding + fixing = ";
	total.Show();
	cout << endl;

	TimeType1 morefixing(3.28);
	cout << "more fixing time = ";
	morefixing.Show();
	cout << endl;

	total = morefixing.operator+(total);
	cout << "morefixing.operator+(total) = ";
	total.Show();
	cout << endl;
	return 0;
}

//usetime2.cpp --using the third draft of the Time class
//compile usetime2.cpp and mytime2.cpp together
#include<iostream>
#include"../inc/mytime2.h"
int UseMyTime2() 
{
	using std::cout;
	using std::endl;
	TimeType2 weeding(4, 35);
	TimeType2 waxing(2, 47);
	TimeType2 total;
	TimeType2 diff;
	TimeType2 adjusted;
	TimeType2 adjusted2;

	cout << "weeding time = ";
	weeding.Show();
	cout << endl;

	cout << "waxing time = ";
	waxing.Show();
	cout << endl;

	cout << "total work time = ";
	total = weeding + waxing;
	total.Show();
	cout << endl;

	diff = weeding - waxing;
	cout << "weeding time - waxing time = ";
	diff.Show();
	cout << endl;

	adjusted = total * 1.5;
	cout << "adjusted work time = ";
	adjusted.Show();
	cout << endl;

	adjusted2 = 2.75 * total;
	cout << "2.75 * adjusted work time = ";
	//adjusted2.Show();
	//cout << adjusted;
	cout << adjusted << endl;
	cout << endl;
	return 0;
}

//compile usetime3.cpp and mytime3.cpp together
#include<iostream>
#include"../inc/mytime3.h"
int UseMyTime3()
{
	using std::cout;
	using std::endl;
	TimeiType3 aida(3, 35);
	TimeiType3 tosca(2, 48);
	TimeiType3 temp;

	cout << "Aida and Tosca:\n";
	cout << aida << ";"<<tosca << endl;
	temp = aida * 1.17;
	cout << "Aida* 1.17:" << temp << endl;
	cout << "10 * Tosca:" << 10 * tosca << endl;

	return 0;
}

//randwalk.cpp --using the Vector class
//compile with the vect.cpp file
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"../inc/vector.h"
int UseVector() 
{
	using namespace std;
	using VECTOR::Vector;

	srand(time(0)); //seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance(q to quit)";
	while (cin >> target) 
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
		{
			break;
		}
		while (result.magval() < target) 
		{
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			steps++;
		}
		cout << "After " << steps << "steps,the subject "
			"has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or \n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		cout << "Enter target distance(q to quit): ";
	}
	cout << "Bye!\n";
	return 0;
}