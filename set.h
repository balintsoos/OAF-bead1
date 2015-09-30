//
// set.h
// OAF - 1. beadando - 7. feladat
//
// Soos Balint
// HDX9MU
// 2015.09.27.
//

#ifndef SET_H
#define SET_H

class Set 
{
	public:
		Set();
		Set(int n);
		~Set();

		Set(Set& s);
		Set& operator= (Set& s);

		void put(int n);
		void remove(int n);
		void print();
		void intersection(Set& s);
		bool isContain(int n);
		bool isEmpty();
		int getSize();
		int * getItems();
	
	private:
		int * items;
		int size;
};

#endif