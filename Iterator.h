/*
 * Iterator.h
 *
 *  Created on: Jul 18, 2018
 *      Author: samsor1
 */

#ifndef Iterator_H_
#define Iterator_H_
template <class T1,class T2>
class Iterator
{
 private:
	typedef struct Node
	{
		T1 key;
		T2 value;
		int hashValue;
		Node *next;
		Node *linked;

	};
	Node anode[50],lnode[50];
	struct Node *ptr = anode;
	struct Node *prtl=lnode;
 public:
	Iterator(){}
	Iterator(const T1&,const T2&);
	bool operator++(const Iterator<T1,T2>&);
	bool operator!=(const Iterator<T1, T2>&);
	// operator * ();
		//int m_access(string,node);
	void m_begin();
	void m_end();
	virtual ~Iterator(){}
};

#endif /* Iterator_H_ */// Itteratortest<int,string> it;
