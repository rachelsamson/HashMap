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
template<class T1,class T2>
Iterator<T1,T2>::Iterator(){}

template<class T1,class T2>
Iterator<T1,T2>::Iterator(const Iterator<T1,T2>& x)
{
	this->Node.key=x.Key;
	this->Node.value=x.Value;
	this->Node.next=NULL;
}

template<class T1,class T2>
Node Iterator<T1,T2>::m_begin()
{
	 Node *data=lnode;
	return data;


}

template<class T1,class T2>
Node Iterator<T1,T2>::m_end()
{
	Node *p=this;
	 while(p->next!=NULL)
	 {
		 p=p->next;
	 }

	 return p;

}
template<class T1,class T2>
T1 Iterator<T1,T2>::operator ++(const Iterator<T1,T2> x)
{
	T1 i;
	 for ( i = m_begin().Key; i != m_end().Key; ++i)
	        {
		   return i;
	        }

	return i;

}


template<class T1,class T2>
bool Iterator<T1,T2>::operator!=()
{
	 T1 i;
	 for (i = m_begin().Key; i != m_end().Key; ++i)
	 {
		            if (i == this)
		            {
		                return true;
		            }
	 }
 return false;

}








/*Iterator<T>::~Iterator()
{
	// TODO Auto-generated destructor stub
}*/

