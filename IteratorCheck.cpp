/*
//============================================================================
// Name        : IteratorCheck.cpp
// Author      : rachel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include<thread>
using namespace std;

void thread_function()
{
	for(int i = 0; i < 10000; i++);
	std::cout<<"thread function Executing"<<std::endl;
}

int main()
{

	std::thread threadObj(thread_function);
	for(int i = 0; i < 10000; i++);
	std::cout<<"Display From MainThread"<<std::endl;
	threadObj.join();
	std::cout<<"Exit of Main function"<<std::endl;
	return 0;
}
/*
#include"Iterator.h"
#include"Iterator.cpp"
using namespace std;

int main() {

	Iterator<int,int> obj1_;
	Iterator<int,int> obj2;
struct hashnodeIt<int,int>* temp;

obj2.newNode->key=12;
obj2.newNode->value=10;
int counttemp=0;
		for(int i=10;i>0;i-=2)
		{
			obj1_.m_Insert(i+1,i++);
			counttemp++;
			cout<<obj1_.nodeptr[i].value<<endl;

		}
		 temp=obj1_.begin();

		obj1_!=obj2;

		obj1_[6];

    	obj1_[6];
    	++obj1_;
    	//obj1.m_getKeys();
    	obj1_.m_getKeys();






	return 0;
}

*/
