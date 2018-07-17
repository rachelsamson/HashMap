/*
 * Iterator.h
 *
 *  Created on: Jul 17, 2018
 *      Author: samsor1
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_
#define MAX 36;
int static collisionCount;
int static individualCount[50];
#include <iostream>
using namespace std;
class Iterator {
	public:
	struct node {

						      string key;// will store information
						      string value;
						      node *next;             // the reference to the next node
						    } newNode[50];

public:
	Iterator();
	int m_access(string,node);
	int m_accessBegin();
	int m_collisionCount(string,node);
	virtual ~Iterator();
};

#endif /* ITERATOR_H_ */
