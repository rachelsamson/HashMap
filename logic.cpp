/*
 * main.cpp
 *
 *  Created on: Jul 22, 2018
 *      Author: raviiv
 */
#include<iostream>
#include "hashheader.h"
#include<stdlib.h>
using namespace std;
hashnode::hashnode()
{
	root=NULL;
}
hashnode::~hashnode()
{

}
bool hashnode::Insert(node *newNode)
{
	 node *temp;
	 node *back;

	    temp = root;
	    back = NULL;

	    while(temp != NULL) // Loop till temp falls out of the tree
	    {
	        back = temp;
	        if(newNode->key < temp->key)
	            temp = temp->left;
	        else
	            temp = temp->right;
	    }

	    // Now attach the new node to the node that back points to
	    if(back == NULL) // Attach as root node in a new tree
	        root = newNode;
	    else
	    {
	        if(newNode->key < back->key)
	            back->left = newNode;
	        else
	            back->right = newNode;
	    }
	   return true ;
}
/*struct node create_node(int val)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->key=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}*/
void hashnode::Print_one(node *T)
{
	cout<<T->key<<endl;
}
void hashnode::Print_all(node *T)
{
	if(T!=NULL)
	{
		Print_all(T->left);
		Print_one(T);
		Print_all(T->right);

	}
}
void hashnode::PrintTree()
{
	Print_all(root);
}
void hashnode::SearchTree(int key)
{
	node *temp;
	temp=root;
	while((temp!=NULL) && (temp->key!=key))
	{
		if(key<temp->key)
		{
			temp=temp->left;//Search key before root node
		}
		else
		{
			temp=temp->right;//Search key after root node
		}

	}
}
