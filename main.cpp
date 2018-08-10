//============================================================================
// Name        : 0.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<string.h>
#include "hashheader.h"
#include "hashmap.cpp"
#define FLAG_ 1
int main(void)
{
	hashmap<int,int> obj;
	for(int i=2901;i>0;i-=1)
	{
		obj.insert(i,i*4);
		if(FLAG_==0) cout<<i;
	}
//	obj.remove(2);
	if(FLAG_==0)
	{
		cout<<"working fine";
		obj.findandInsert(11,22);
		cout<<"\n"<<obj.size();
		cout<<'\n'<<obj.getNumberOfCollisionPerSlot(3);
		cout<<"\n"<<obj.getTotalNumberOfCollision();
		obj.printCollisionStatistics();
	}
	return 0;
}
