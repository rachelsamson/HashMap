//============================================================================
// Name        : 0.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<conio.h>
using namespace std;
#include<string.h>
//#include "Iterator.cpp"
//#include "Iterator.h"
#include "hashheader.h"
#include "hashmap.cpp"
#define FLAG_ 0
int main(void)
{
	int counter=0;
	hashmap<int,int> obj;
	for(int i=0;i<2850;i+=1)
	{

		obj.insert(i,i*4);
		if(i==2800){cout<<"\t\t"<<i;}
		//cout<<i;
		//break;
}
//	obj.remove(2);

//		cout<<"working fine";
	//	obj.findandInsert(11,22);
		//cout<<"\n"<<obj.size();
		//cout<<'\n'<<obj.getNumberOfCollisionPerSlot(3);
		//cout<<"\n"<<obj.getTotalNumberOfCollision();
		//obj.printCollisionStatistics();
		//obj.print_all();
		//obj.m_getKeys();
		//for(int j=0;j<MAX;j++)
		//{
			//cout<<obj.arr[j];
		//}


	return 0;
}
