#include "Customer.h"
#include<cmath>

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
