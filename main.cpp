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
	//Treenode<string,string,int> *newTreeNode;
	//Treenode<string,string,int> newTreeNode2("t","q",6);
	//Treenode<string,string,int> newTreeNode3;
	//Arraynode<string,string,int> *newArrayNode;

	hashmap<int,int> obj;

	//Inserting one node
	//newTreeNode=new Treenode<string,string,int>();
	//newTreeNode->key="vivek";
	//newTreeNode->value="a2b";
	//newTreeNode->hashvalue=20;
	obj.m_Insert(9,12);
	obj.m_Insert(2,12);
	obj.m_Insert(11,22);
	obj.m_findandInsert(11,22);
	//obj.m_Insert(2,30);
	//obj.m_Insert(13,35);
	//obj.m_Insert(16,50);
	//Inserting one node
	/*Treenode<string,string,int> *newTreeNode;
	newTreeNode->key=10;
	obj->Insert(newNode);
	//Inserting one node
	Treenode<string,string,int> newNode=new Treenode<string,string,int>();
	newTreeNode->key=7;
	obj->Insert(newNode);
	cout<<"\n";
	//Printing the tree
	obj->PrintTree();
	//newNode=obj->SearchTree(7);
	//if(newNode!=NULL)
	//{
		//obj->Print_one(newNode);
//	}
*/
	return 0;
}
