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
		typedef T1 Key;
		typedef T2 Value;
		int hashValue;
		int *next;
		//Node *end;

	};
	Node anode[50],lnode[50];
	struct Node *ptr = anode;
	struct Node *prtl=lnode;
	//typedef std::pair<const T1, T2> value_type;

 public:
	Iterator();
	Iterator(const Iterator<T1,T2>&);
	bool operator++(const Iterator<T1,T2>&);
	bool operator!=(const Iterator<T1,T2>&);
	// operator * ();
		//int m_access(string,node);
	Node m_begin();
	Node m_end();
	virtual ~Iterator(){}
};

#endif /* Iterator_H_ */// Itteratortest<int,string> it;
