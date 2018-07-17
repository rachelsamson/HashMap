/*
 * Iterator.cpp
 *
 *  Created on: Jul 17, 2018
 *      Author: samsor1
 */


//Checking with errors
#include<iostream>
#include "Iterator.h"
using namespace std;

Iterator::Iterator() {


}


int Iterator::m_access(string inputKey,struct node *traverse)
{
	 Iterator::node current;


	int index;
	//index=hashmapfunction
	int value =index%MAX;
	while(current.next!=NULL)
	{
			if(current.value==inputKey)
			{
				//element present
				cout<<current.key<<endl;
				cout<<current.value<<endl;

			}
			else
			{
				current->current.next;
			}



	}
	return 0;

}

int Iterator::m_collisionCount(string inputKey,struct node *traverse)
{
	Iterator::node current;
	//current =traverse;
	int index;
	int a[50];
	//index=hashmapfunction
	int value =index % MAX;
	if (a[value]!= NULL)

	{
		collisionCount+1;
		   while(current != NULL) {
			   individualCount[value]++;
			  current = current.next;
		   }

		   }

	return 0;

}




Iterator::~Iterator() {
	// TODO Auto-generated destructor stub
}

