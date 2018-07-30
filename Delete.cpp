/*
 * main.cpp
 *
 *  Created on: Jul 22, 2018
 *      Author: raviiv
 */
#include<iostream>
#include "IteratorBST.h"
#include<stdlib.h>
using namespace std;
//int count;
template<typename T1,typename T2>
hashmap<T1,T2>::hashmap()
{

}

template<typename T1,typename T2>
bool hashmap<T1,T2>::m_Insert(T1 key,T2 value)
{
	cout<<"this is done";
	int index=1;//m_calculatehash(key);

	struct hashnode<T1,T2> *newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));

	newNode->key=key;
	newNode->value=value;
hashnode<T1,T2> *to_newNode;
	to_newNode=newNode;

cout<<"this is new node"<<&newNode;
	if(nodeptr[index].key==NULL)
	{

		nodeptr[index].key=newNode->key;
		nodeptr[index].value=newNode->value;

		nodeptr[index].left = NULL;
		nodeptr[index].right = NULL;
		//count++;
		cout<<nodeptr[index].key;
		return true ;
	}

	else
	{

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
		        //	back=temp;
		        }

		        else{
		            temp=temp->right;
		          //  back=temp;
		    }


		        		}
		if(newNode->key < back->key ){
			struct hashnode<T1,T2> newNode_1;
			newNode_1.key=newNode->key;
			newNode_1.value=newNode->value;
			back->left=&newNode_1;
		cout<<nodeptr[index].left<<endl;}
		else{
			struct hashnode<T1,T2> newNode_1;
						newNode_1.key=newNode->key;
						newNode_1.value=newNode->value;
			back->right=&newNode_1;
			cout<<nodeptr[index].right;}

		   return true ;
	}
	return 0;
}

template<typename T1,typename T2>
struct hashnode<T1,T2> * minValueNode( hashnode<T1,T2>* node)
{
    struct hashnode<T1,T2>* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

template<typename T1,typename T2>
struct hashnode<T1,T2>* deleteNode(struct hashnode<T1,T2> * root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
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
            struct hashnode<T1,T2> *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct hashnode<T1,T2> *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct hashnode<T1,T2>* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

template<typename T1,typename T2>
bool hashmap<T1,T2>::m_Delete(int key)
{
	//index=HAshMap();
	int index;
	hashmap<int,int> obj;
	hashnode<T1,T2> *temp=&nodeptr[index];

	if(1)
	{
		struct hashnode<T1,T2> *tempNode=deleteNode(temp,key);
	 return true;
	}
	 else{return false;}
	}




