
#ifndef ITERATORBST_H_
#define ITERATORBST_H_
#define MAX 50
#include <stdint.h>
#include<stdlib.h>
#include <vector>
#include<list>
#include <iterator>


using namespace std;
template<class T1,class T2>
struct hashnode
		{
			T1 key;
			T2 value;
			hashnode<T1,T2> *left,*right;
		};

template <class T1,class T2>

class Iterator {
public:
	/*struct hashnode<T1,T2>
		{
			 T1 Key;
			 T2 Value;

			hashnode<T1,T2> *right;
			hashnode<T1,T2> *left;
		    //hashnode<T1,T2> *next;
		    int index;


		}*/
	  /* *current;
	  	int index;
	  int count=0;*/


public:
	 struct hashnode<T1,T2> nodeptr[MAX];
	// struct hashnode<T1,T2> newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));

	 struct hashnode<T1,T2> *current;
	 Iterator();
	 Iterator(T1,T2,hashnode<T1,T2>*);
	 hashnode<T1,T2>* begin();
	 hashnode<T1,T2>* end();
	 int size();
	 list<T1> m_getKeys();
	T2& m_get(T1 key);
	T1 operator++(const T1 key);
	bool operator!=(struct hashnode<T1,T2>);
	//bool operator!=(struct hashnode<T1,T2> hashnode<T1,T2>,struct hashnode<T1,T2> hashnode<T1,T2>);

	 hashnode<T1,T2>& operator*(struct hashnode<T1,T2>);
	//int* inorder(struct hashnode<T1,T2> * hashnode<T1,T2>);
	T2 operator[](int index);
	/* T2 search(struct hashnode<T1,T2> * root, int key);

		// int inorder(struct hashnode<T1,T2>*);

	*/
	virtual ~Iterator();
public:
	  static T1 KeyArray[50];
};

#endif /* ITERATORBST_H_ */
