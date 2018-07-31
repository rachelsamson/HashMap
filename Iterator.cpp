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
#include "BSTIterators.h"
#include"BSTIterators.cpp"
using namespace std;
template<class T1,class T2>
Iterator<T1,T2>::Iterator() {
for(int i=0;i<50;i++){
	nodeptr[i].key=NULL;
nodeptr[i].value=0;
nodeptr[i].right=NULL;
nodeptr[i].left=NULL;
}
current=this->nodeptr;


}


template<class T1,class T2>
Iterator<T1,T2>::Iterator(T1 Key,T2 Value,hashnode<T1,T2>* currentNode)
{
	struct hashnode<T1,T2> *newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));

	newNode=NULL;
	current=currentNode;
	int index=0;

}

template<class T1,class T2>
hashnode<T1,T2>* Iterator<T1,T2>::begin()
{
	struct hashnode<T1,T2> *newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));

	int index=1;
	newNode->key=nodeptr[index].key;
	newNode->value=nodeptr[index].value;
	newNode->right=nodeptr[index].right;
	newNode->left=nodeptr[index].left;
	while(newNode->left!=NULL)
	{
		newNode=newNode->left;
	}
	return newNode;
}


template<class T1,class T2>
hashnode<T1,T2>* Iterator<T1,T2>::end()
{
	struct hashnode<T1,T2> *newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	int index=1;
	for(int i=MAX;i>=0;i--)
	{
	 if(nodeptr[i].key != NULL)
	 {
  	   newNode->key=nodeptr[i-1].key;
       newNode->value=nodeptr[i-1].value;
       newNode->right=nodeptr[i-1].right;
       newNode->left=nodeptr[i-1].left;
		while(newNode->right!=NULL)
		 {newNode=newNode->right;}
	 }
    }
	return newNode;
}


template<class T1,class T2>
hashnode<T1,T2>& Iterator<T1,T2>::operator*(struct hashnode<T1,T2> current)
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
	struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	struct hashnode<T1,T2> *temp1=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));

	temp=&nodeptr[index];
	BSTIterators<T1,T2> bst;
	struct hashnode<T1,T2> temp2;
	//temp1=
	T2 returnKey=bst.search((bstnode<T1,T2>*)temp,key);

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
		   struct hashnode<T1,T2> *root=&nodeptr[i];
		  a=bst.inorder((bstnode<T1,T2>*) root);

	}

		return a;

}
/*
template<class T1,class T2>
int* Iterator<T1,T2>::inorder(struct hashnode<T1,T2>* node)
{
	int i;
    if (node == NULL)
		return 0;

	  first recur on left child
	inorder(node->left);

	  then print the data of node
	KeyArray[i]= node->Key ;
	i++;

    now recur on right child
 //  printInorder(node->right);
	return KeyArray;
}
*/

template<class T1,class T2>
T1 Iterator<T1,T2>::operator++(const T1 key)
{	BSTIterators<T1,T2> obj;
int i =0;
      struct hashnode<T1,T2> *root=&nodeptr[i];
	 list<T1> a=obj.inorder((bstnode<T1,T2>*) root);

	    std::list<int>::iterator findIter = std::find(a.begin(),a.end(),key);
	    T1 value=std::advance(findIter,1);
	    	T1 returnVal=*value;

	    	return returnVal;
}

template<class T1,class T2>
bool Iterator<T1,T2>::operator!=(struct hashnode<T1,T2> node)
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










/*

struct Node* deleteNode(struct Node* root, int key)
{
    // base case
    if (root == NULL)
    	return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->Key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            //free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
           // free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}*/
