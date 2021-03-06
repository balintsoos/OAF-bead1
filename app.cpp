//
// app.cpp
// OAF - 1. beadando - 7. feladat
//
// Soos Balint
// HDX9MU
// 2015.09.27.
//

#include <iostream>
#include "app.h"
#include "set.h"

using namespace std;

// constructor
// a programban egy futas soran csak 10 db halmazt tudunk letrehozni
App::App()
{
	size = 1;
	sets = new Set[10]; // ez a szam barmikor megvaltoztathato
	sets[0] = *(new Set());
	currentSet = 0;
}

/*
App::~App()
{
	for (int i = 0; i < size; ++i)
	{
		delete[] sets[i];
	}
	delete[] sets;
}
*/

void App::run()
{
	int v = -1;
	do
	{
		displayNav();
		cout << endl << "Choose a method: ";
		cin >> v;
		switch(v)
		{
			case 1: newSet(); break;
			case 2: changeCurrentSet(); break;
			case 3: put(); break;
			case 4: remove(); break;
			case 5: print(); break;
			case 6: isContain(); break;
			case 7: isEmpty(); break;
			case 8: intersection(); break;
		}
	} while (v != 0);
}

void App::displayNav()
{
	cout << "-------------------------------" << endl;
	cout << "Current set: Set " << currentSet << endl;
	cout << "Methods:" << endl;
	cout << "0 - EXIT" << endl;
	cout << "1 - Create a new set" << endl;
	cout << "2 - Change current set" << endl;
	cout << "3 - Put a new item to current set" << endl;
	cout << "4 - Remove an item from current set" << endl;
	cout << "5 - Print current set" << endl;
	cout << "6 - Check current set contains an item" << endl;
	cout << "7 - Check current set is empty" << endl;
	cout << "8 - Intersection of two sets" << endl;
}

void App::newSet()
{
	if(size < 10)
	{
		sets[size] = *(new Set());
		cout << "\nSet " << size << " created" << endl;
		size++;
	}
	else
	{
		cout << "\nYou can't create more than 10 sets" << endl;
	}
}

void App::changeCurrentSet()
{
	cout << "\nChange current set" << endl;
	int setNumber = -1;
	cout << "Set number: ";
	cin >> setNumber;
	if(setNumber < size && setNumber >= 0) {
		currentSet = setNumber;
	}
	else
	{
		cout << "Set " << setNumber << " doesn't exist" << endl;
	}
}

void App::put()
{
	cout << "\nPut a new item to current set" << endl;
	int item = -1;
	cout << "Item: ";
	cin >> item;
	try {
		sets[currentSet].put(item);
	} catch (Set::Exceptions ex) {
		switch (ex)
		{
			case Set::CONTAIN : cout << "Set already contains " << item << endl; break;
		}
	}
}

void App::remove()
{
	cout << "\nRemove an item from current set" << endl;
	int item = -1;
	cout << "Item: ";
	cin >> item;
	try {
		sets[currentSet].remove(item);
	} catch (Set::Exceptions ex) {
		switch (ex)
		{
			case Set::INVALID_ITEM : cout << "Set doesn't contain " << item << endl; break;
		}
	}
}

void App::print()
{
	cout << "\nSet " << currentSet << ":";
	sets[currentSet].print();
}

void App::isContain()
{
	cout << "\nCheck current set contains an item" << endl;
	int item = -1;
	cout << "Item: ";
	cin >> item;
	if(sets[currentSet].isContain(item))
	{
		cout << "Set " << currentSet << " contains " << item << endl;
	}
	else
	{
		cout << "Set " << currentSet << " doesn't contain " << item << endl;
	}
}

void App::isEmpty()
{
	if(sets[currentSet].isEmpty())
	{
		cout << "\nSet " << currentSet << " is empty"<< endl;
	}
	else
	{
		cout << "\nSet " << currentSet << " isn't empty"<< endl;
	}
}

void App::intersection()
{
	int setNumber = -1;
	cout << "Set number: ";
	cin >> setNumber;
	if(setNumber < size && setNumber >= 0)
	{
		cout << "Intersection of Set " << currentSet << " and Set " << setNumber << endl;
		sets[currentSet].print();
		sets[setNumber].print();
		cout << "\nIntersection: " << endl;
		try {
			sets[currentSet].intersection(sets[setNumber]);
		} catch (Set::Exceptions ex) {
			switch (ex)
			{
				case Set::EMPTY : cout << "empty set" << endl; break;
			}
		}
	}
	else
	{
		cout << "Set " << setNumber << " doesn't exist" << endl;
	}
}

