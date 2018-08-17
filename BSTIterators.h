/*
 * BSTIterators.h
 *
 *  Created on: Jul 31, 2018
 *      Author: samsor1
 */

#ifndef BSTITERATORS_H_
#define BSTITERATORS_H_

#include<iostream>
#define BSTARRAYMAX 21
using namespace std;
template<class T1,class T2>
struct bstNodeIt
		{
			T1 key;
			T2 value;
			bstNodeIt<T1,T2> *left,*right;
		};
template<class T1,class T2>
class BSTIterators {
public:
	//T1 TotalKeys[];
	int i;
	T1 KeyArray[BSTARRAYMAX];
	struct bstNodeIt<T1,T2> tempTree;
	BSTIterators();
	T1* inorder(bstNodeIt<T1,T2> *root);
	T2 search(struct bstNodeIt<T1,T2> * root, int key);
	virtual ~BSTIterators();
};

#endif /* BSTITERATORS_H_ */
