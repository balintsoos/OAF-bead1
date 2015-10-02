//
// set.cpp
// OAF - 1. beadando - 7. feladat
//
// Soos Balint
// HDX9MU
// 2015.09.27.
//

#include <iostream>
#include "set.h"

using namespace std;

// constructor
// inicializalasnal a halmaz elemeit tartalmazo tomb egy nullpointer, merete 0
Set::Set()
{
	items = NULL;
	size = 0;
}

// constructor w/ argumentum
// az argumentumkent atadott erteket berakja a halmazba
Set::Set(int n)
{
	Set();
	put(n);
}

// destructor
// torli a halmaz elemeit reprezentalo tombot
Set::~Set()
{
	delete[] items;
}

// sajat masolo konstructor
Set::Set(Set& s)
{
	size = s.size;
	items = new int[size];
	for (int i = 0; i < size; ++i)
	{
		items[i] = s.items[i];
	}
}

// sajat ertekadas operator
Set& Set::operator= (Set& s)
{
	if (this == &s) return *this;
	delete[] items;
	size = s.size;
	items = new int[size];
	for (int i = 0; i < size; ++i)
	{
		items[i] = s.items[i];
	}
	return *this;
}

// elem berakasa a halmazba
// ha a dinamikus tombunk ures, 0. indexre berakjuk ay elemet
// ha merete nagyobb mint 0 es az adott elem nincs benne a halmazba
// akkor letrehozunk egy eggyel hosszabb ideiglenes tombot, majd
// a beszurasos rendezes algoritmusat alkalmazva atmasoljuk az elemeket
// majd az ideiglenesbol atmasoljuk az eredeti tombbe
// bemeneti adat: egesz szam, berakni kivant ertek
// kimeneti adat: nincs (void)
void Set::put(int n)
{
	if (isEmpty())
	{
		delete[] items;
		items = new int[++size];
		items[0] = n;
	}
	else
	{
		if (!isContain(n))
		{
			int * temp = new int[size+1];
			int i = 0;
			int tempI = 0;
			bool Nfound = false;
			for (; (i < size) && (!Nfound); i++)
			{
				if (items[i] > n)
				{
					Nfound = true;
					temp[tempI++] = n;
					temp[tempI++] = items[i];
				}
				else
				{
					temp[tempI++] = items[i];
				}
			}
			for (; i < size; ++i)
			{
				temp[tempI++] = items[i];
			}
			if (!Nfound)
			{
				temp[tempI] = n;
			}
			delete[] items;
			items = temp;
			size++;
		}
		else
		{
			throw CONTAIN;
		}
	}
}

// elem kivetele a halmazbol
// ha az adott elem benne van a tombben, akkor letrehozunk
// egy eggyel rovidebb ideiglenes tombot es az adott elem
// kivetelevel minden elemet atmasolunk, majd az ideiglenes
// tombot atmasoljuk az eredetibe
// bemeneti adat: egesz szam, amit ki szeretnenk venni a halmazbol
// kimeneti adat: nincs (void)
void Set::remove(int n)
{
	if (isContain(n))
	{
		int * temp = new int[size-1];
		int tempI = 0;
		for (int i = 0; i < size; ++i)
		{
			if(items[i] != n)
			{
				temp[tempI++] = items[i];
			}
		}
		delete[] items;
		items = temp;
		size--;
	}
	else
	{
		throw INVALID_ITEM;
	}
}

// halmaz megjelenitese
// tombon vegighaladva kiirjuk a konzolra az elemeket
// es a tomb meretet
// bemeneti ertek: nincs, kimeneti ertek: nincs
void Set::print()
{
	cout << "\nSize: " << size << endl;
	cout << "Items: ";
	for (int i = 0; i < size; ++i)
	{
		cout << items[i] << " ";
	}
	cout << endl;
}

// segedfuggveny: atadja a halmaz hosszusagat
int Set::getSize()
{
	return size;
}

// segedfuggveny: atadja a halmaz elemeit
int * Set::getItems()
{
	return items;
}

// ket halmaz metszete
// ha egyik halmaz sem ures,
// a halmazokon vegigiteralva a mindkettoben 
// elofordulo elemeket kiirjuk
// kihasznaljuk hogy a tomb rendezett:
// hatulrol haladva parhuzamosan a tomb elemein, ha
// a ket ertek megegyezik akkor metszetelemet talatunk
// ha az ertek kulonbozik, akkor a relacio alapjan
// az egyik tombon tovabbiteralunk
// a folyamat addig folytatodik amig el nem erjuk 
// valamelyik tomb veget
// bemeneti adat: egy halmaz
// kimeneti adat: nincs (void)
void Set::intersection(Set& s)
{
	if (!isEmpty() && !s.isEmpty())
	{
		int iOfThis = size-1;
		int iOfArg = s.getSize()-1;
		int * itemsOfArg = s.getItems();

		while (iOfThis >= 0 && iOfArg >= 0)
		{
			if (items[iOfThis] > itemsOfArg[iOfArg])
			{
				iOfThis--;
			}
			else if (items[iOfThis] < itemsOfArg[iOfArg])
			{
				iOfArg--;
			}
			else if (items[iOfThis] == itemsOfArg[iOfArg])
			{
				cout << items[iOfThis] << " ";
				iOfThis--;
				iOfArg--;
			}
		}
		cout << endl;
	}
	else
	{
		throw EMPTY;
	}
}

// tartalmaz-e a halmaz egz adott elemet
// lineraris keresest alkalmazva keressuk az elemet a tombben
// bemeneti adat: egesz szam
// kimeneti adat: logikai (bool)
bool Set::isContain(int n)
{
	bool found = false;
	for (int i = 0; (i < size) && (!found); ++i)
	{
		if (items[i] == n)
		{
			found = true;
		}
	}
	return found;
}

// ures-e a halmaz
// tomb hosszusaga nulla-e
// bemeneti adat: nincs
// kimeneti adat: logikai (bool)
bool Set::isEmpty()
{
	return size == 0;
}
