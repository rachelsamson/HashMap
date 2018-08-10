#include<stdint.h>
#include<iostream>
#include "hashheader.h"
#include<stdlib.h>
#include "bst.cpp"
#include "jenkins.cpp"
#define FLAG 0
using namespace std;
static int count[MAX];//NO OF ENTRIES INTO HASHMAP
static int count1[MAX];//UNIQUE ENTRIES IN HASHMAP
static int count2[MAX];//COLLISION RELATED STATS
template<class T1,class T2>
//--------------------------------------------------------------->
//CONSTRUCTOR INITIALIZING THE DATA STRUCTURE
hashmap<T1,T2>::hashmap()
{
	if(FLAG==0) cout<<"Constructor Initializing data structure to NULL\n";
	for(int i=0;i<MAX;i++)
	{
		nodeptr[i].m_key='\0';
		nodeptr[i].m_value=0;
		nodeptr[i].right=NULL;
		nodeptr[i].left=NULL;
	}
}
//--------------------------------------------------------------->
//CALCULATES HASH BASED ON JENKINS HASH
template<class T1,class T2>
int hashmap<T1,T2>::calculatehash(T1 m_key)
{
	const uint32_t stringVal[]={uint32_t(m_key)};
	int lenght=( sizeof(stringVal)/sizeof(uint32_t));
	uint32_t ABC=JenkinsHash(stringVal,lenght, 33);
	return (ABC%MAX);
/*
	int index=(ABC/100000000)/2;
	return index%MAX;*/
}
//--------------------------------------------------------------->
//INSERTION ON HASHMAP
template<class T1,class T2>
bool hashmap<T1,T2>::insert(T1 m_key,T2 m_value)
{

	int m_index=calculatehash(m_key);
	if(FLAG==0){ cout<<"Key:  "<<m_key;cout<<"\tValue:  "<<m_value;cout<<"\tIndex:"<<m_index;cout<<"\n";}
	struct hashnode<T1,T2> *newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	newNode->m_key=m_key;
	newNode->m_value=m_value;
	if(nodeptr[m_index].m_key=='\0')
	{
		nodeptr[m_index].m_key=newNode->m_key;
		nodeptr[m_index].m_value=newNode->m_value;
		nodeptr[m_index].left = NULL;
		nodeptr[m_index].right = NULL;
		count1[m_index]++;
		return true;
	}
	else
	{
		hashnode<T1,T2> *root;
		root=&nodeptr[m_index];
		BST b_obj;
		b_obj.m_bstinsert((bstnode<T1,T2>*)root,(bstnode<T1,T2>*)newNode);
		count2[m_index]++;
	}
	count[m_index]=count1[m_index]+count2[m_index];
	if(FLAG==0){cout<<"\n"<<m_key;}
	return 0;
}
//--------------------------------------------------------------->
//DELETES AN ENTRY ON HASHMAP
template<class T1,class T2>
bool hashmap<T1,T2>::remove(T1 m_key)
{
	int m_index=calculatehash(m_key);
	//if(FLAG==0)cout<<m_index;
	hashnode<T1,T2> *root=&nodeptr[m_index];
	BST bst_obj;
	if(1)
	{
		struct hashnode<T1,T2> *temp;
		root=(struct hashnode<T1,T2>*)(bst_obj.m_deleteNode((bstnode<T1,T2>*)root,m_key));
		temp=root;
		nodeptr[m_index].m_key=temp->m_key;
		nodeptr[m_index].m_value=temp->m_value;
		nodeptr[m_index].left=temp->left;
		nodeptr[m_index].right=temp->right;
		return true;
	}
	else{return false;}
}
//--------------------------------------------------------------->
// SEARCHES FOR A m_key AND RETURNS A m_value
// IF NOT INSERTS INTO THE HASHMAP
template<class T1,class T2>
bool hashmap<T1,T2>::findandInsert(T1 m_key,T2 m_value)
{
	int m_index=calculatehash(m_key);
	struct hashnode<T1,T2> *root=&nodeptr[m_index];
	BST bst_obj;
	T2 i=bst_obj.m_bstsearch((struct bstnode<T1,T2>*)root,m_key,m_value);
	if(i==0)
	{
		insert(m_key,m_value);

	}
	return true;
}

template<class T1,class T2>
uint32_t hashmap<T1,T2>::size()
{
	uint32_t sum=0;
	for(int i=0;i<MAX;i++)
	{
		sum+=uint32_t(count[i]);
	}
	cout<<"Total entries on hashmap";
	return sum;
}
//--------------------------------------------------------------->
//RETURNS TOTAL NUMBER OF COLLISIONS HAPPENED AT GIVEN SLOT NUMBER
template<class T1,class T2>
uint32_t hashmap<T1,T2>::getNumberOfCollisionPerSlot(uint32_t slotNumber)
{
	return --count2[slotNumber];
}
//--------------------------------------------------------------->
//RETURNS TOTAL NUMBER OF COLLISIONS HAPPENED IN THE HASHMAP
template<class T1,class T2>
uint32_t hashmap<T1,T2>::getTotalNumberOfCollision()
{
	uint32_t sum=0;
	for(int i=0;i<MAX;i++)
	{
		sum+=count2[i];
	}
	return sum;
}
//--------------------------------------------------------------->
//PRINTS NUMBER OF COLLISIONS HAPPENED AT EVERY SLOT NUMBER
template<class T1,class T2>
void hashmap<T1,T2>::printCollisionStatistics()
{
	int i;
	for(i=0;i<MAX;i++)
	{
		cout<<"\nnumber of collision at index\t"<<i<<"\tare\t"<<count2[i];
	}
}
