/*
 * hashmap.h
 *
 *  Created on: Jul 18, 2018
 *      Author: raviiv
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_
#include<iostream>
#include<vector>
using namespace std;
//template for generic type
template <typename K,typename V>
class hashnode
{
public:
	struct node
	{
		K Key;
		V Value;
		int *HEAD;
		int *TAIl;
		struct node *next;


	}lnode;
public:
	hashnode(K Key,V Value);
	//constructor of class hashnode
	//hashnode(K Key,V Value);
	virtual ~hashnode(){}
	void hashmap();

};
template<typename K,typename V>
class hashmap
{
	int capacity;
	int size;
public:
	//vector<K,V> obj_v;
	hashnode<K,V> **obj_arr;
	hashmap();
	virtual ~hashmap(){}
	void insertNode(K Key ,V Value);

};
template <typename K,typename V>
int hashcode(K key);


#endif /* HASHMAP_H_ */
