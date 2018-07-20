/*
 * Iterator.h
 *
 *  Created on: Jul 18, 2018
 *      Author: samsor1
 */

#ifndef Iterator_H_
#define Iterator_H_
#define MAX 50
template <class T1,class T2, class T3>
class Iterator
{
 public:
	 struct Node
	{
		typedef T1 Key;
		typedef T2 Value;
		int hashValue;
		int *next;
		int *head;
		int *tail;


	};
	Node lnode[MAX];
	struct Node *prtl;

 public:
	Iterator();
	Iterator(T1,T2);
	T3 m_begin();
    T3  m_end();
	unsigned int size();

	T1 m_getKeys();
	T2 m_get(T1 key);
	T1 operator++(const T1);
	bool operator!=(const T1);
	struct Node operator*();

	virtual ~Iterator(){}
};

#endif /* Iterator_H_ */// Itteratortest<int,string> it;
