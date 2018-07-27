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
int count;
template<typename T1,typename T2>
hashmap<T1,T2>::hashmap()
{
	//root=NULL;//for tree
	//head=NULL;//for array
	//next=NULL;
	//bool Insert(Treenode<T1,T2,T3> *);
}
/*hashnode<T1,T2>::~hashnode()
{

}*/
template<typename T1>
int m_calculatehash(T1 key)
{

	hashvalue=key();//Calculatehash on key to store hashvalue
	int index=hashvalue%599;
	return index;
	//Calculatehash will calculate the hashvalue based on key
}*/
template<typename T1,typename T2>
bool hashmap<T1,T2>::m_Insert(T1 key,T2 value)
{
	int index=m_calculatehash(key);
	hashnode<int,int> *newNode=new hashnode<int,int>;
	newNode->key=key;
	newNode->value=value;
	struct hashnode<T1,T2> nodeptr[index]=(struct node*)malloc(sizeof(struct node));
	if(nodeptr[index]==NULL)
	{
		nodeptr[index]->key=key;
		nodeptr[index]->value=value;
		nodeptr[index]->left = NULL;
		nodeptr[index]->right = NULL;
		count++;
		return true ;
	}
	else
	{
		struct hashnode<T1,T2> node=(struct node*)malloc(sizeof(struct node));
		node.key=key;
		node.value=value;
		hashnode<T1,T2> *temp;
		hashnode<T1,T2> *back;
		temp=nodeptr[index];
		back=NULL;
		while(temp!=NULL)
		{
			back=temp;
			if(temp->key>node.key)
			{
				temp->left=node;
				count++;
			}
			else
			{
				temp->right=node;
				count++;
			}

		}
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
/*
template<typename T1,typename T2,typename T3>
void hashnode<T1,T2,T3>::m_Print_one(Treenode<T1,T2,T3> *T)
{
	cout<<T->key<<endl;
}
template<typename T1,typename T2,typename T3>
void hashnode<T1,T2,T3>::m_Print_allTree(Treenode<T1,T2,T3> *T)
{
	if(T!=NULL)
	{
		m_Print_all(T->left);
		m_Print_one(T);
		m_Print_all(T->right);

	}
}
template<typename T1,typename T2,typename T3>
void hashnode<T1,T2,T3>::m_PrintTree()
{
	Print_all(root);
}
template<typename T1,typename T2,typename T3>
void hashnode<T1,T2,T3>::m_SearchTree(int key)
{
	Treenode<T1,T2,T3> *temp;
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
template<typename T1,typename T2,typename T3>
bool hashnode<T1,T2,T3>::m_Delete(int key)
{
	m_SearchTree(key);
}
//<------------------------------------------------------------->
//ARRAY OPERATIONS
//<------------------------------------------------------------->
/*template<typename T1,typename T2,typename T3>
bool hashnode<T1,T2,T3>::m_Insertarray(int index,Arraynode<T1,T2,T3> *newArrayNode)
{
	Arraynode<T1,T2,T3> node=(struct node*)malloc(sizeof(struct node));;
	Arraynode<T1,T2,T3> *temp;
	Treenode<T1,T2,T3> obj_treenode=new Treenode<T1,T2,T3>;
	//Arraynode<T1,T2,T3> *back;
	temp = head;
	//back = NULL;
	if(*arrptr[index]==NULL)
	{
		head=newArrayNode;
		next=head;
	}
	else
	{
		obj_treenode=node;
		Insert(obj_treenode);
	}

		   return true;
}*/
