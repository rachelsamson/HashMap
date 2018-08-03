#include<stdint.h>
#include<iostream>
#include "hashheader.h"
#include<stdlib.h>
#include "bst.cpp"
#include "jenkins.cpp"
using namespace std;
static int count[MAX];
template<class T1,class T2>
hashmap<T1,T2>::hashmap()
{
	for(int i=0;i<50;i++){
		nodeptr[i].key=NULL;
		nodeptr[i].value=0;
		nodeptr[i].right=NULL;
		nodeptr[i].left=NULL;
	}
}
template<class T1,class T2>
int hashmap<T1,T2>::m_calculatehash(T1 key)
{
	const uint32_t stringVal[]={key};
	int lenght=( sizeof(stringVal)/sizeof(uint32_t));
	uint32_t ABC=JenkinsHash(stringVal,lenght, 33);
	int index=(ABC/100000000)/2;
	return index%MAX;

}
template<class T1,class T2>
bool hashmap<T1,T2>::m_Insert(T1 key,T2 value)
{
	int index=m_calculatehash(key);
	cout<<index<<endl;
	struct hashnode<T1,T2> *newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	newNode->key=key;
	newNode->value=value;
	hashnode<T1,T2> *to_newNode;
	to_newNode=newNode;//newNode=node;
	if(nodeptr[index].key==NULL)
	{
		nodeptr[index].key=newNode->key;
		nodeptr[index].value=newNode->value;
		nodeptr[index].left = NULL;
		nodeptr[index].right = NULL;
		count[index]++;
		cout<<nodeptr[index].key<<endl;
		return true;
	}
	else
	{
		hashnode<T1,T2> *root;
		root=&nodeptr[index];
		BST b_obj;
		b_obj.m_bstinsert((bstnode<T1,T2>*)root,(bstnode<T1,T2>*)newNode);
	}
	return 0;
}
//--------------------------------------------------------------->
template<class T1,class T2>
bool hashmap<T1,T2>::m_Delete(T1 key)
{
	int index=m_calculatehash(key);
	hashmap<int,int> obj;
	hashnode<T1,T2> *root=&nodeptr[index];
	if (root == NULL)
	{ return false;}
	BST b_obj;

	if(1)
	{
		struct hashnode<T1,T2> *root=b_obj.m_deleteNode((struct bstnode<T1,T2>*)root,key);
	 return true;
	}
	 else{return false;}
	}
/*
template<class T1,class T2>
bool hashmap<T1,T2>::m_findandInsert(T1 key,T2 value)
{
		struct hashnode<T1,T2> newNode;
		newNode.key=key;
		newNode.value=value;
		//struct hashnode<T1,T2> *temp;
		//temp=&nodeptr[0];
		T2 i=m_search(key);
		//cout<<i;
		if
		//for(int index=0;index<MAX;index++)
		//{

		//}
}*/
template<class T1,class T2>
T2 hashmap<T1,T2>::m_search(T1 key)
{
	int index=m_calculatehash(key);
	struct hashnode<T1,T2> *temp=&nodeptr[index];
	temp->left=nodeptr[index].left;
	temp->right=nodeptr[index].right;
	while((temp!=NULL) && (temp->key!=key))
	{
		if(key < temp->key)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(temp==NULL)
		return false;
	else
		return temp->value;

}


template<class T1,class T2>
uint32_t hashmap<T1,T2>::size()
{
	int sum=0,i;
	for(i=0;i<MAX;i++)
	{
		sum+=count[i];
	}
	cout<<"Total entries on hashmap"<<sum;
}
//--------------------------------------------------------------->
template<class T1,class T2>
uint32_t hashmap<T1,T2>::getNumberOfCollisionPerSlot(uint32_t slotNumber)
{
	return --count[slotNumber];
}
//------------------------------------------------->
template<class T1,class T2>
uint32_t hashmap<T1,T2>::getTotalNumberOfCollision()
{
	int i;
	uint32_t sum=0;
	for(i=0;i<MAX;i++)
	{
		sum+=count[i];
	}
	return sum-MAX;
}
//------------------------------------------------->
template<class T1,class T2>
void hashmap<T1,T2>::printCollisionStatistics()
{
	int i;
	for(i=0;i<MAX;i++)
	{
		cout<<"number of collision at index at %u"<<i<<"are"<<--count[i]<<"\n";
	}
}
