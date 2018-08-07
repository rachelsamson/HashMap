//============================================================================
// Name        : IteratorCheck.cpp
// Author      : rachel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"Iterator.h"
#include"Iterator.cpp"
using namespace std;

int main() {

	Iterator<int,int> obj1_;
	Iterator<int,int> obj2;


obj2.newNode->key=5;
obj2.newNode->value=2;
int counttemp=0;
int i;
		for(i=10;i>0;i-=2)
		{
			obj1_.m_Insert(i+1,i++);
			counttemp++;
			cout<<obj1_.nodeptr[i].value<<endl;

		}

		obj1_!=obj2;

		obj1_[6];

    	obj1_[6];
    	++obj1_;






	return 0;
}
