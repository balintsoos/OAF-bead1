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

Set::Set()
{
	items = NULL;
	size = 0;
}

Set::Set(int n)
{
	Set();
	put(n);
}

Set::~Set()
{
	delete[] items;
}

Set::Set(Set& s)
{
	size = s.size;
	items = new int[size];
	for (int i = 0; i < size; ++i)
	{
		items[i] = s.items[i];
	}
}

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

void Set::put(int n)
{
	if (size == 0)
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

void Set::remove(int n)
{
	if (isContain(n))
	{
		int * temp = new int[--size];
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
	}
	else
	{
		throw INVALID_ITEM;
	}
}

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

int Set::getSize()
{
	return size;
}

int * Set::getItems()
{
	return items;
}

void Set::intersection(Set& s)
{
	if (!isEmpty() && !s.isEmpty())
	{
		int iofThis = size-1;
		int iofArg = s.getSize()-1;
		int * sitems = s.getItems();

		while (iofThis >= 0 && iofArg >= 0)
		{
			if (items[iofThis] > sitems[iofArg])
			{
				iofThis--;
			}
			if (items[iofThis] < sitems[iofArg])
			{
				iofArg--;
			}
			if (items[iofThis] == sitems[iofArg])
			{
				cout << items[iofThis] << " ";
				iofThis--;
				iofArg--;
			}
		}
		cout << endl;
	}
	else
	{
		throw EMPTY;
	}
}

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

bool Set::isEmpty()
{
	return size == 0 ? true : false;
}
