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
		bool isContain(int n);
		bool isEmpty();
	
	private:
		int * items;
		int size;
};

#endif