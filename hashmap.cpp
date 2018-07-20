/*
 * hashmap.cpp
 *
 *  Created on: Jul 18, 2018
 *      Author: raviiv
 */
//stringstream concept

#include "hashmap.h"
using namespace std;
//#include<vector>
template<typename K,typename V>
hashnode<K,V>::hashnode(K key,V value)
{
	head=NULL;
	tail=NULL;
	int size=0;
	hashnode<K,V> obj_arr=new hashnode<K,V>*[CAPACITY];//initializing
	for(int i;i < CAPACITY; i++)
		{
			obj_arr[i]=NULL;
		}
	//this->Value=value;
	//this->Key=Key;
}
/*template<typename K,typename V>
//hashmap<K,V>::hashmap()
{
	//CAPACITY=26;

}*/
template<typename K,typename V>
void hashnode<K,V>::insertNode(K Key ,V Value)

{
	this->node.Key=Key;
	this->node.Value=Value;
	hashnode<K,V> *tmp=new hashnode<K,V>(Key,Value);
	int hashIndex=hashCode(Key);
	while(tmp->lnode[hashIndex]!=NULL || tmp->lnode[hashIndex].Key!=Key || tmp->lnode[hashIndex].Value!=Value)
	{
		if(tmp->lnode[hashIndex].HEAD == NULL && hashIndex == tmp->lnode[hashIndex])//i==a[i]
		{
			//creating new node
			tmp->lnode[hashIndex].next= tmp->hashnode.lnode[hashIndex];
			tmp[hashIndex].lnode.Key =tmp->hashnode.Key;
			tmp[hashIndex].lnode.Value =tmp->hashnode.Value;
		}
	}
			hashIndex++;
			hashIndex%=CAPACITY;
	for(int i=0;i<CAPACITY;i++)
	{
		//obj_arr[hashIndex]==tmp->hashnode(Key)
		if(tmp[i]!=NULL);
		{

			//tmp->lnode[];
		}
	}
}





