#include <iostream>
#include "set.h"

using namespace std;

int main ()
{
	cout << "Hello World\n";
	Set **a = new Set*();
	(*a)->put(3);

	return 0;
}