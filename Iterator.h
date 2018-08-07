
#ifndef ITERATORBST_H_
#define ITERATORBST_H_
#define MAX 50
#include <stdint.h>
#include<stdlib.h>
#include <vector>
#include<list>
#include <iterator>
//int returnKey;
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
	//T1 returnKey;
	struct hashnodeIt<T1,T2> nodeptr[MAX];
	 struct hashnodeIt<T1,T2> *current;
	 struct hashnodeIt<T1,T2> *_try;

	 Iterator();
	 Iterator(hashnodeIt<T1,T2>* Node);
	 hashnodeIt<T1,T2>* begin();
	 hashnodeIt<T1,T2>* end();
	 int size();
	 T1* m_getKeys();
	T2& m_get(T1 key);
	T1 operator++() ;
	bool operator!=( Iterator<T1,T2>) const;

	 hashnodeIt<T1,T2>* operator*(Iterator<T1,T2> node) const;
	T2 operator[](int index) ;
	//----------------------------------------------------------------------------------------
	    int m_calculatehash(T1 key);
		bool m_findandInsert(T1,T2);

		bool m_Insert(T1,T2);

	//--------------------------------------------------------------------------------------------
	virtual ~Iterator();
public:
	  T1 arr[50]={NULL};
	  T1 returnKey;
	  list<T1> a;

	  struct hashnodeIt<T1,T2> *newNode=(struct hashnodeIt<T1,T2>*)malloc(sizeof(struct hashnodeIt<T1,T2>));

};

#endif /* ITERATORBST_H_ */
