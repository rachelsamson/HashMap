
#ifndef ITERATORBST_H_
#define ITERATORBST_H_
#define MAX 50
#include <stdint.h>
#include<stdlib.h>
#include <vector>
#include<list>
#include <iterator>
/*
#include"hashmap.cpp"
#include"hashheader.h"
*/
using namespace std;

template<class T1,class T2>

struct hashnodeIt
		{
			T1 key;
			T2 value;
			hashnodeIt<T1,T2> *left,*right;
		};


template <class T1,class T2>

class Iterator {


public:
	struct hashnodeIt<T1,T2> nodeptr[MAX];
	 struct hashnodeIt<T1,T2> *current;
	 Iterator();
	 Iterator(hashnodeIt<T1,T2>* Node);
	 hashnodeIt<T1,T2>* begin();
	 hashnodeIt<T1,T2>* end();
	 int size();
	 list<T1> m_getKeys();
	T2& m_get(T1 key);
	T1 operator++(const T1 key);
	bool operator!=(struct hashnodeIt<T1,T2>);

	 hashnodeIt<T1,T2>& operator*(struct hashnodeIt<T1,T2>);
	T2 operator[](int index);

	virtual ~Iterator();
public:
	  static T1 KeyArray[50];
};

#endif /* ITERATORBST_H_ */
