/*
 * Iterator.cpp
 *
 *  Created on: Jul 18, 2018
 *      Author: samsor1
 */

//checking for errors
#include<iostream>
#include "Iterator.h"
using namespace std;
template<class T1,class T2, class T3>
Iterator<T1,T2,T3>::Iterator(){
	cout<<"Empty constr.";
}

template<class T1,class T2, class T3>
Iterator<T1,T2,T3>::Iterator(T1 Key,T2 Value)
{
	this->Node.Key=Key;
	this->Node.Value=Value;
	this->Node.next=NULL;
	this->Node.head=lnode;
	this->Node.tail=lnode;
	this->prtl=NULL;
}

template<class T1,class T2, class T3>
T3 Iterator<T1,T2,T3>::m_begin()
{
	 Node *data=lnode;
	return data;
}



template<class T1,class T2, class T3>
T3 Iterator<T1,T2,T3>::m_end()
{
//	this->Node.head;
	Node *p=this;
	 while(p->next!=NULL)
	 {
		 p=p->next;
	 }

	 return p;

}
template<class T1,class T2, class T3>
struct Node Iterator<T1,T2,T3>::operator*()
{
	return this;
}



template<class T1,class T2, class T3>
T2 Iterator<T1,T2,T3>::m_get(T1 key)
{
	// int index=hashmap(key)
	int index;
	T2 it;
	for(int i=0;i<=MAX;i++)
	{
		if(index==lnode[i].hashvalue)
		{
			for(it=m_begin();it<=m_end();++it)
			{
				if(it.Key==key)
				{
					return it.Value;
				}

			}

	   }


	}
}

template<class T1,class T2, class T3>
T1 Iterator<T1,T2,T3>::m_getKeys()
{
	T1 i;
	T2 j;
	for(i=lnode[0];i<=lnode[MAX];++i)
	{
	   for(j=m_begin();j<=m_end();i++)
		return this->Node.Value;

	}
}



template<class T1,class T2, class T3>
T1 Iterator<T1,T2,T3>::operator ++(const T1 x)
{
	T1 i;
	 for ( i = m_begin().Key; i != m_end().Key; ++i)
	        {
		   return i;
	        }

	return i;

}




template<class T1,class T2, class T3>
bool Iterator<T1,T2,T3>::operator!=(const T1 x)
{
	 T1 i;
	 for (i = m_begin().Key; i != m_end().Key; ++i)
	 {
		            if (x.Key==i)
		            {
		                return true;
		            }
	 }
 return false;

}


