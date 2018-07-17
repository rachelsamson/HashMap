/*
 * hashmap.h
 *
 *  Created on: Jul 16, 2018
 *      Author: raviiv
 */
//Checking for errors
#include<iostream>
using namespace std;
#ifndef HASHMAP_H_
#define HASHMAP_H_
#define Key as K
#define Value as V
#include<string>

class storagefunction
{
private:
	int hashcode;//data part of linkedlist
public:
	int hashmap[36];//Defining Array of 36 slots
	//cout<<"Defining Array of 36 slots"<<endl;
	struct storage
	{
		string K;
		int V;
		struct storage *next;
	};

	void arraydefine(string K);
	void linkedlistdefine(int hashcode,struct storage*);
	//void f1();

};
/*class accessfunctions
	{
public:
	bool insert(char K,int v);  //inserting the hash code
	bool findandInsert(char K,int V);// linear search on the key
	void getKeys(char K);//returns a vector of keys in the table
	bool remove();//remove function should remove the entry from the hash map
	};
class collisionstats
{
public:
	//int countoncollision;//total no
void getTotalNumberOfCollision();//will return total number of collisions happened in the hash map
void getNumberOfCollisionPerSlot(int bucketNo);};//will return number of collisions happened for the input slot number
void printCollisionStatistics();//will print all the collision for all the slots sequentially in format like (number of collision at index %u are %u\n)
*/

#endif /* HASHMAP_H_ */
