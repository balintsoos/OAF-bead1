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
	put(n);
}

Set::Set(int (&n)[])
{
	for (int i = 0; i < sizeOf(n); ++i)
	{
		put(n[i]);
	}
}

Set::~Set()
{
	delete[] items;
}

Set::Set(const Set &s)
{
	size = s.size;
	items = new int[size];
	for (int i = 0; i < size; ++i)
	{
		items[i] = s.items[i];
	}
}

Set& Set::operator= (const Set &s)
{
	if (this == &s) return *this;
	delete[] items;
	size = s.size;
	items = new int[size];
	for (int i = 0; i < size; ++i)
	{
		items[i] = s.items[i];
	}
}

void Set::put(int n)
{
	if (size == 0)
	{
		items = new int[++size];
		items[0] = n;
	}
	else
	{
		if (!isContain(n))
		{
			int * temp = new int[++size];
			int i = 0;
			int tempI = 0;
			bool Nfound = false;
			for (; (i < size) && (!Nfound); ++i)
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
		}
	}
}

void Set::remove(int n)
{
	//TODO
}

void Set::print()
{
	for (int i = 0; i < size; ++i)
	{
		cout << items[i] << endl;
	}
}

bool Set::isContain(int n)
{
	for (int i = 0, bool found = false; (i <= size) && (!found); ++i)
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
