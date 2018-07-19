/*
 * Iterator.cpp
 *
 *  Created on: Jul 18, 2018
 *      Author: samsor1
 */
#include<iostream>
#include "Iterator.h"
using namespace std;
template<class T1,class T2>
Iterator<T1,T2>::Iterator(const T1& a,const T2& b)
{
	//this->Node.key=a;
	//this->Node.value=b;

}
template<class T1,class T2>
bool Iterator<T1,T2>::operator ++(const Iterator<T1, T2>& x, const Iterator<T1, T2>& y)
{
	//Linked list tarversal
	//Iterator::Node current;
	//Iterator Obj_It=*this;
	//current=current.linked;
	//current.link++;
	return 0;

}

template<class T1,class T2>
void Iterator<T1,T2>::m_begin()
{
	//node traversal from beginning (array list traversal)
	Iterator::Node current;
	int *p =current[0];
	for(int i =0;i<sizeof(current)/sizeof(current[0]);i++)
	 {
		cout<<current[i];
	 }




}

template<class T1,class T2>
bool Iterator<T1,T2>::operator!=(const Iterator<T1, T2>& x,const Iterator<T1, T2>& y)
{
//	index=y.Node.hashValue%Max;
	//for(int i =index;i<sizeof(lnode)/sizeof(lnode[0]);i++)

	if( x.lnode[index].key==y.Node.key && x.lnode[index].value==y.Node.value)
	{
		for(int j=0;j<sizeof(anode)/sizeof(anode[0]);j++)
		{
		  if( x.key==y.Node.key && x.anode[j].value==y.Node.value)
		  {
			  break;
		 }
		  else
		  {
			  j++;
		  }


		}
	}
}









/*Iterator<T>::~Iterator()
{
	// TODO Auto-generated destructor stub
}*/

