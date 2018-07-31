/*
 * BSTIterators.h
 *
 *  Created on: Jul 31, 2018
 *      Author: samsor1
 */

#ifndef BSTITERATORS_H_
#define BSTITERATORS_H_
#include <list>
#include <iterator>
using namespace std;
template<class T1,class T2>

struct bstnode
		{
			T1 key;
			T2 value;
			bstnode<T1,T2> *left,*right;
		};
template<class T1,class T2>
class BSTIterators {
public:
	T1 TotalKeys[];
	struct bstnode<T1,T2> Treenode;
	BSTIterators();
	//T1* Inorder(struct bstnode<T1,T2>* node);
	list<T1> inorder(struct bstnode<T1,T2>* node);
	T2 search(struct bstnode<T1,T2> * root, int key);
	virtual ~BSTIterators();
};

#endif /* BSTITERATORS_H_ */
