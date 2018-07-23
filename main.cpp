//============================================================================
// Name        : 0.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "hashheader.h"
int main(void) {
	hashnode *obj;
	node *newNode;
	//Inserting one node
	obj=new hashnode();
	newNode=new node();
	newNode->key=8;
	obj->Insert(newNode);
	//Inserting one node
	newNode=new node();
	newNode->key=10;
	obj->Insert(newNode);
	//Inserting one node
	newNode=new node();
	newNode->key=7;
	obj->Insert(newNode);
	cout<<"\n";
	//Printing the tree
	obj->PrintTree();
	//newNode=obj->SearchTree(7);
	//if(newNode!=NULL)
	//{
		//obj->Print_one(newNode);
//	}

	return 0;
}
