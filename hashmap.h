/*
 * hashmap.h
 *
 *  Created on: Jul 18, 2018
 *      Author: raviiv
 */
#define CAPACITY 26

#ifndef HASHMAP_H_
#define HASHMAP_H_
#include<iostream>
//#include<vector>
using namespace std;
//template for generic type
template <typename K,typename V>
class hashnode
{
struct node
{
	K Key;
	V Value;
	struct node *next;
}lnode[];//anode is ambiguous

private:
		node *head;
		node *tail;
public:
	hashnode(K,V);
	//constructor of class hashnode
	//hashnode(K Key,V Value);
	virtual ~hashnode(){}
	void hashmap();
	void insertNode(K,V);
};
template<typename K,typename V>
class hashmap
{
//	int capacity;
//	int size;
public:
	//vector<K,V> obj_v;
	//hashnode<K,V> **obj_arr;
	hashmap();
	virtual ~hashmap(){}


};
template <typename K,typename V>
int hashcode(K key);


#endif /* HASHMAP_H_ */
