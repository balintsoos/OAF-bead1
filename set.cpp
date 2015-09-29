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
		cout << n << " added to set" << endl;
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
			cout << n << " added to set" << endl;
		}
		else
		{
			cout << "Set already contains " << n << endl;
		}
	}
}

void Set::remove(int n)
{
	if(isContain(n))
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
		cout << n << " removed from set" << endl;
	}
	else
	{
		cout << "Set doesn't contain " << n << endl;
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

int Set::setSize()
{
	return size;
}

void Set::intersection(Set& s)
{
	print();
	s.print();
	if(!isEmpty() && !s.isEmpty())
	{
		cout << "\nIntersection: " << endl;
		//int length = (size <= s.setSize()) ? size : s.setSize();
		int i = 0;
		int is = 0;
		while(i < size || is < s.setSize())
		{
			if(s.isContain(items[i]))
			{
				cout << items[i] << " ";
			}
		}
	}
	else
	{
		cout << "\nIntersection is an empty set" << endl;
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
