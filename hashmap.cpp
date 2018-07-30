/*
 * main.cpp
 *
 *  Created on: Jul 22, 2018
 *      Author: raviiv
 */
#include<stdint.h>
#include<iostream>
#include "hashheader.h"
#include<stdlib.h>
#include "jenkins.cpp"
using namespace std;
static int count[CAPACITY];
template<typename T1,typename T2>
hashmap<T1,T2>::hashmap()
{

}
template<typename T1,typename T2>
bool hashmap<T1,T2>::m_Insert(T1 key,T2 value)
{
	const uint32_t stringVal[]={key};
	int lenght=( sizeof(stringVal)/sizeof(uint32_t));
    uint32_t ABC=JenkinsHash(stringVal,lenght, 33);
    int index=(ABC/100000000)/2;
    cout<<index;
    struct hashnode<T1,T2> *newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
    /*struct hashnode<T1,T2> node=(struct node*)malloc(sizeof(struct node));
	struct hashnode<T1,T2> newNode=new hashnode<T1,T2>;
	//node->key=key; //node->value=value;
	//struct hashnode<T1,T2> newNode;//=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	//struct hashnode<T1,T2> newNode;//=new hashnode<T1,T2>;
	//node->key=key;
	//node->value=value;*/
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
		return true;
	}
	else
	{
		//struct hashnode<T1,T2> node=(struct node*)malloc(sizeof(struct node));
		//node=newNode;
		hashnode<T1,T2> *temp;
		hashnode<T1,T2> *back;
		temp=&nodeptr[index];
		back=NULL;
		while(temp != NULL) // Loop till temp falls out of the tree
		{
		        back = temp;
		        if(newNode->key < temp->key)
		        {
		            //temp->left=&newNode;
		        	temp=temp->left;
		        }
		        else
		        {
		            temp=temp->right;
		        }
		 }
		if(newNode->key < back->key )
		{
			struct hashnode<T1,T2> newNode_1;
			newNode_1.key=newNode->key;
			newNode_1.value=newNode->value;
			back->left=&newNode_1;
			count[index]++;
		}
		else
		{
			struct hashnode<T1,T2> newNode_1;
			newNode_1.key=newNode->key;
			newNode_1.value=newNode->value;
			back->right=&newNode_1;
			count[index]++;
		}
		return true ;
	}
	return 0;
}
template<typename T1,typename T2>
bool hashmap<T1,T2>::m_findandInsert(T1 key,T2 value)
{
	struct hashnode<T1,T2> newNode;
	newNode.key=key;
	newNode.value=value;
	//struct hashnode<T1,T2> *temp;
	//temp=&nodeptr[0];
	int i=m_search(key);
	//cout<<i;
	//for(int index=0;index<CAPACITY;index++)
	//{

	//}
}
template<typename T1,typename T2>
T2 hashmap<T1,T2>::m_search(T1 Key)
{
	const uint32_t stringVal[]={Key};
	int lenght=( sizeof(stringVal)/sizeof(uint32_t));
	uint32_t ABC=JenkinsHash(stringVal,lenght, 33);
	int index=(ABC/100000000)/2;
	struct hashnode<T1,T2> *temp=&nodeptr[index];
	temp->left=nodeptr[index].left;
	temp->right=nodeptr[index].right;
	while((temp!=NULL) && (temp->key!=Key))
	{
		if(Key < temp->key)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(temp==NULL)
		return false;
	else
		return temp->value;

}
//--------------------------------------------------------------->
template<typename T1,typename T2>
uint32_t hashmap<T1,T2>::size()
{
	int sum=0,i;
	for(i=0;i<CAPACITY;i++)
	{
		sum+=count[i];
	}
	cout<<"Total entries on hashmap"<<sum;
}
//--------------------------------------------------------------->
template<typename T1,typename T2>
uint32_t hashmap<T1,T2>::getNumberOfCollisionPerSlot(uint32_t slotNumber)
{
	return --count[slotNumber];
}
//------------------------------------------------->
template<typename T1,typename T2>
uint32_t hashmap<T1,T2>::getTotalNumberOfCollision()
{
	int i;
	uint32_t sum=0;
	for(i=0;i<CAPACITY;i++)
	{
		sum+=count[i];
	}
	return sum-CAPACITY;
}
//------------------------------------------------->
template<typename T1,typename T2>
void hashmap<T1,T2>::printCollisionStatistics()
{
	int i;
	for(i=0;i<CAPACITY;i++)
	{
		cout<<"number of collision at index at %u"<<i<<"are"<<--count[i]<<"\n";
	}
}
