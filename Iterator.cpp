/*
 * IteratorBST.cpp
 *
 *  Created on: Jul 23, 2018
 *      Author: samsor1
 */
#include<iostream>
#include "Iterator.h"
#include<stdlib.h>
#include<stdint.h>
//#include"hashmap.cpp"
//#include"hashheader.h"
#include "BSTIterators.h"
#include"BSTIterators.cpp"
using namespace std;
template<class T1,class T2>
Iterator<T1,T2>::Iterator() {
for(int i=0;i<MAX;i++){
nodeptr[i].key=NULL;
nodeptr[i].value=0;
nodeptr[i].right=NULL;
nodeptr[i].left=NULL;

}
/*ashmap<T1,T2> obj;
	obj.nodeptr[0];
	cout<<"this is";
cout<<obj.nodeptr[0].key;*/
current=this->nodeptr;


}


template<class T1,class T2>
Iterator<T1,T2>::Iterator(hashnodeIt<T1,T2>* currentNode)
{
	struct hashnodeIt<T1,T2> *newNode=(struct hashnodeIt<T1,T2>*)malloc(sizeof(struct hashnodeIt<T1,T2>));

	newNode=NULL;
	current=currentNode;
	int index=0;

}

template<class T1,class T2>
hashnodeIt<T1,T2>* Iterator<T1,T2>::begin()
{
	struct hashnodeIt<T1,T2> *newNode=(struct hashnodeIt<T1,T2>*)malloc(sizeof(struct hashnodeIt<T1,T2>));

	int index=0;
	newNode->key=nodeptr[index].key;
	newNode->value=nodeptr[index].value;
	newNode->right=nodeptr[index].right;
	newNode->left=nodeptr[index].left;
	while(newNode->left!=NULL)
	{
		newNode=newNode->left;
	}
	cout<<newNode->key<<"this";
	return newNode;
}



template<class T1,class T2>
hashnodeIt<T1,T2>* Iterator<T1,T2>::end()
{
	struct hashnodeIt<T1,T2> *newNode=(struct hashnodeIt<T1,T2>*)malloc(sizeof(struct hashnodeIt<T1,T2>));
	//int index=m_calculatehash();
	for(int i=MAX-1;i>=0;i--)
	{
	 if(nodeptr[i].key != NULL)
	 {
  	   newNode->key=nodeptr[i].key;
       newNode->value=nodeptr[i].value;
       newNode->right=nodeptr[i].right;
       newNode->left=nodeptr[i].left;
		while(newNode->right!=NULL)
		 {newNode=newNode->right;}
	 }
    }
	return newNode;
}


template<class T1,class T2>
hashnodeIt<T1,T2>& Iterator<T1,T2>::operator*(struct hashnodeIt<T1,T2> current)
{
 return &current;
}

template<class T1,class T2>
int Iterator<T1,T2>::size()
{int count=0;
  return count;
}


template<class T1,class T2>
T2& Iterator<T1,T2>::m_get(T1 key)
{
	int index;//=hashMap(key);
	struct hashnodeIt<T1,T2> *temp=(struct hashnodeIt<T1,T2>*)malloc(sizeof(struct hashnodeIt<T1,T2>));
	struct hashnodeIt<T1,T2> *temp1=(struct hashnodeIt<T1,T2>*)malloc(sizeof(struct hashnodeIt<T1,T2>));

	temp=&nodeptr[index];
	BSTIterators<T1,T2> bst;
	struct hashnodeIt<T1,T2> temp2;
	//temp1=
	T2 returnKey=bst.search((bstNodeIt<T1,T2>*)temp,key);

	return returnKey;
}

template<class T1,class T2>
list<T1> Iterator<T1,T2>::m_getKeys()
{
	//BSTIterators<T1,T2> obj;
	int size=10;
	list<T1> a;
	//T1 a[size];
	BSTIterators<T1,T2> bst;

	for(int i=0;i<=MAX;++i)
	{
		   struct hashnodeIt<T1,T2> *root=&nodeptr[i];
		  a=bst.inorder((bstNodeIt<T1,T2>*) root);

	}

		return a;

}


template<class T1,class T2>
T1 Iterator<T1,T2>::operator++(const T1 key)
{	BSTIterators<T1,T2> obj;
int i =0;
      struct hashnodeIt<T1,T2> *root=&nodeptr[i];
	 list<T1> a=obj.inorder((bstNodeIt<T1,T2>*) root);

	    std::list<int>::iterator findIter = std::find(a.begin(),a.end(),key);
	    T1 value=std::advance(findIter,1);
	    	T1 returnVal=*value;

	    	return returnVal;
}

template<class T1,class T2>
bool Iterator<T1,T2>::operator!=(struct hashnodeIt<T1,T2> node)
{
	T1 i;
	//temp=nodeptr[index];
	if(current->Key==node.Key && current->Value==node.Value)
	{return false;}

	return true;

}



template<class T1,class T2>
T2 Iterator<T1,T2>::operator[](int index)
{
  return nodeptr[index].Value;
}
template<class T1,class T2>
Iterator<T1,T2>::~Iterator() {
	// TODO Auto-generated destructor stub
}










