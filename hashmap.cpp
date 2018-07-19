/*
 * hashmap.cpp
 *
 *  Created on: Jul 18, 2018
 *      Author: raviiv
 */
//Checking for errors In Progress
#include "hashmap.h"
using namespace std;
//#include<vector>
template<typename K,typename V>
hashnode<K,V>::hashnode(K Key,V Value)
{
	//this->Value=value;
	//this->Key=Key;

}
template<typename K,typename V>
hashmap<K,V>::hashmap()
{
	capacity=26;
	size=0;
	obj_arr=new hashnode<K,V>*[capacity];
	for(int i;i < capacity; i++)
	{
		obj_arr[i]=NULL;
	}
}
template<typename K,typename V>
void hashmap<K,V>::insertNode(K Key ,V Value)
{
	hashnode<K,V> *tmp=new hashnode<K,V>(Key,Value);
	int hashIndex=hashCode(Key);
	while(obj_arr[hashIndex]!=NULL || obj_arr[hashIndex].Key!=Key || obj_arr[hashIndex].Value!=Value)
	{
		if(obj_arr[hashIndex].HEAD == NULL)
		{
			//creating new node
			obj_arr[hashIndex]->lnode *next= new obj_arr[hashnode].lnode;
			obj_arr[hashIndex].lnode.Key =tmp->hashnode.Key;

			obj_arr[hashIndex].lnode.Value =tmp->hashnode.Value;
		}
	}
			hashIndex++;
			hashIndex%=capacity;
	for(int i=0;i<capacity;i++)
	{
		//obj_arr[hashIndex]==tmp->hashnode(Key)
		if(obj_arr[i]!=NULL);
		{

			//tmp->lnode[];
		}
	}
}





