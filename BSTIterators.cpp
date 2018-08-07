/*
 * BSTIterators.cpp
 *
 *  Created on: Jul 31, 2018
 *      Author: samsor1
 */

#include "BSTIterators.h"
#include<stdint.h>

template<class T1,class T2>
BSTIterators<T1,T2>::BSTIterators() {
	// TODO Auto-generated constructor stub

}


template<class T1,class T2>
T1* BSTIterators<T1,T2>::inorder(struct bstNodeIt<T1,T2> *root)
{



	while(root!=NULL)
	{
	if (root->key !='\0'&&root!=NULL)
	{
		tempTree.key=root->key;
		tempTree.value=root->value;
		tempTree.left=root->left;
		tempTree.right=root->right;
        inorder(root->left);
        KeyArray[i++]=root->key;
        inorder(root->right);
          return KeyArray;

    }
   }
 return KeyArray;
}


template<class T1,class T2>
T2 BSTIterators<T1,T2>::search(struct bstNodeIt<T1,T2> * root, int key)

{
	//struct bstnode<T1,T2>* root=rootnode;
    // Base Cases: root is null or key is present at root
    if ( root!=NULL||root->key== key)
       return root->value;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

template<class T1,class T2>
BSTIterators<T1,T2>::~BSTIterators() {
	// TODO Auto-generated destructor stub
}

