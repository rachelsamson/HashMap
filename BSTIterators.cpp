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
/*template<class T1,class T2>
T1* BSTIterators<T1,T2>::Inorder(struct bstnode<T1,T2>* node)
{
	static int i;
	if (node->key== NULL)
		return NULL;

	else {
	          Inorder(node->left);

	          TotalKeys[i]=Inorder(node->key);
	          i++;
	          Inorder(node->right);

	        	}
		return TotalKeys;
}*/

template<class T1,class T2>
list<T1> BSTIterators<T1,T2>::inorder(struct bstnode<T1,T2>* node) {
    if (node->key != NULL) {
        list<T1> lhs = inorder(node->left);
        list<T1> rhs = inorder(node->right);
        copy(rhs.begin(), rhs.end(), back_insert_iterator<list<T1> >(lhs));
        return lhs;
    } else {
        return list<T1>();
    }
}


template<class T1,class T2>
T2 BSTIterators<T1,T2>::search(struct bstnode<T1,T2> * root, int key)

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

