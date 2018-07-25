/*
 * IteratorBST.cpp
 *
 *  Created on: Jul 23, 2018
 *      Author: samsor1
 */
#include<iostream>
#include "Iterator.h"

template<class T1,class T2>
Iterator<T1,T2>::Iterator() {

}


template<class T1,class T2>
Iterator<T1,T2>::Iterator(T1 Key,T2 Value,Node* currentNode)
{
	temp=NULL;
	current=currentNode;
	index=0;

}

template<class T1,class T2>
typename Iterator<T1,T2>::Node Iterator<T1,T2>::m_begin()
{
  for(int i=0;i<=MAX;i++)
  {
	if(lnode[i]!=NULL)
	 {
		 temp=lnode;
		 while(temp->left!=NULL)
		 {
			 temp=temp->left;

		 }
		return temp;

	 }

  }
  return temp;
}


template<class T1,class T2>
typename Iterator<T1,T2>::Node Iterator<T1,T2>::m_end()
{
	for(int i=MAX;i>=0;i--)
	  {
		if(lnode[i]!=NULL)
		 {
			 temp=lnode[i];
			 while(temp->right!=NULL)
			 {
				 temp=temp->right;

			 }
			return temp;

		 }

      }
	return temp;
}


template<class T1,class T2>
typename Iterator<T1,T2>::Node* Iterator<T1,T2>::operator*(struct Node * node)
{
 return current;
}

template<class T1,class T2>
int Iterator<T1,T2>::size()
{
  return count;
}


template<class T1,class T2>
T2& Iterator<T1,T2>::m_get(T1 key)
{
	//index=hashMap(T1 key);

	temp=lnode[index];
	Node temp2=NULL;
	while((temp!=NULL) && (temp->Key!=key))
		{
		    temp2=temp;
			while(temp->left!=NULL)
			{
				temp2=temp;
				temp=temp->left;//Search key before root node
			}
/*
			{
				temp=temp->right;//Search key after root node
			}
*/

		}

			T2 returnKey=temp->Key;
			return returnKey;
}

template<class T1,class T2>
T1* Iterator<T1,T2>::m_getKeys()
{
	Node* temp;
	int a=0;
	for(int i=0;i<=size();++i)
	{
		   Node root=lnode[i];

	 inorder(root);

	}

		return KeyArray;

}
template<class T1,class T2>
int* Iterator<T1,T2>::inorder(struct Node* node)
	   {
	      int i;

		     if (node == NULL)
		         return 0;

		     /* first recur on left child */
		     inorder(node->left);

		     /* then print the data of node */
		     KeyArray[i]= node->Key ;
		     	 i++;
		     /* now recur on right child */
		     printInorder(node->right);
		     return KeyArray;
	       }


template<class T1,class T2>
T1 Iterator<T1,T2>::operator++(const T1 key)
{
	Iterator<T1,T2> it;

		Node temp=current;
		if(current->right!=NULL)
	     {
			current = current->right;
		    while(current->left!=NULL)
		    {
		    	current=current->left;
		    }

          }

	return current->Key;

}

template<class T1,class T2>
bool Iterator<T1,T2>::operator!=(Node node)
{
	T1 i;
	temp=lnode[index];
	if(current->Key==node.Key && current->Value==node.Value)
	{return true;}

	return false;

}

template<class T1,class T2>
bool Iterator<T1,T2>::operator!=(Node node1 ,Node node2)
{
	T1 i;
	temp=lnode[index];
	if(node1.Key==node2.Key && node1.Value==node2.Value)
	{return true;}

	return false;

}
template<class T1,class T2>
T2 Iterator<T1,T2>::operator[](int index)
{
  return lnode[index].Value;
}
template<class T1,class T2>
Iterator<T1,T2>::~Iterator() {
	// TODO Auto-generated destructor stub
}

