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
int main(void) {
	hashmap<int,int> obj;
	for(int i=20;i>0;i-=2)
	{
		obj.m_Insert(i,i*4);
	}
	obj.m_Delete(20);
	//obj.m_findandInsert(11,22);
	//obj.size();
	//obj.getNumberOfCollisionPerSlot(10);
	//obj.getTotalNumberOfCollision();
	//obj.printCollisionStatistics();
	return 0;
}
