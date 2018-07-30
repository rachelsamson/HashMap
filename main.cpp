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
	obj.m_Insert(9,12);
	obj.m_Insert(2,12);
	obj.m_Insert(11,22);
	obj.m_findandInsert(11,22);
	obj.size();
	obj.getNumberOfCollisionPerSlot(10);
	obj.getTotalNumberOfCollision();
	obj.printCollisionStatistics();
	return 0;
}
