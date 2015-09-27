//
// app.h
// OAF - 1. beadando - 7. feladat
//
// Soos Balint
// HDX9MU
// 2015.09.27.
//

#ifndef APP_H
#define APP_H
#include "set.h"

class App
{
	public:
		App();
		//~App();

		void run();
	
	private:
		int size;
		Set* sets;
		int currentSet;

		void displayNav();
		void newSet();
		void changeCurrentSet();
		void put();
		void remove();
		void print();
		void isContain();
		void isEmpty();
};

#endif