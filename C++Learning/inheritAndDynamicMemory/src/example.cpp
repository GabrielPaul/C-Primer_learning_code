#include "..\inc\example.h"
#include"../inc/dma.h"
#include<iostream>
void usedma()
{
	using std::cout;
	using std::endl;

	baseDMA shirt("Portabeelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << shirt << endl;
	cout << balloon << endl;
	cout << map << endl;
	lacksDMA balloon2(balloon);
	hasDMA map2(map);
	cout << balloon2 << endl;
	cout << map2 << endl;
}
