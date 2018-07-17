//============================================================================
// Name        : HashMap.cpp
// Author      : rachel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include"Iterator.h"
using namespace std;





int main() {

	string inputKey;
	Iterator obj_It;


	Iterator::node traverse;
	traverse.key="this is node 1";
    traverse.value="this is value 1";
	traverse.next=NULL;
	cout <<"ENTER KEY TO SEARCH"  <<endl;
	cin>>inputKey;
	obj_It.m_access(inputKey,traverse);
	return 0;
}



