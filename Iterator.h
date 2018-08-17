
#ifndef ITERATORBST_H_
#define ITERATORBST_H_
#define ARRAYMAX 21
#define MAX 21

#include <stdint.h>
#include<stdlib.h>



template<class T1,class T2>
struct hashnode
{
	T1 m_key;
	T2 m_value;
	hashnode<T1,T2> *left,*right;
};




//---------------------------------------------------------------------------Class HASHMAP---------------------------------------------------------
template<class T1,class T2>
class hashmap:public hashnode<T1,T2>
{
public:
	T2 m_search(T1 key);
	struct hashnode<T1,T2> nodeptr[MAX];


public:
	hashmap<T1,T2>();
	hashmap<T1,T2>(int a);

	//------------------------------------------------->
	virtual ~hashmap<T1,T2>(){};
	//------------------------------------------------->
	int calculatehash(T1);
	//------------------------------------------------->
	bool findandInsert(T1,T2);
	//------------------------------------------------->
	bool insert(T1 key,T2 value);
	//------------------------------------------------->
	bool remove(T1);
	//------------------------------------------------->
	uint32_t size();
	//------------------------------------------------->
	uint32_t getNumberOfCollisionPerSlot(uint32_t);
	//------------------------------------------------->
	uint32_t getTotalNumberOfCollision();
	//------------------------------------------------->
	void printCollisionStatistics();
	// T1* m_getKeys();//for iterator
	void print_all();
	T1 arr[MAX];

	struct hashnode<T1,T2> *current;
	//****************************************************************************************
	//hashnode<T1,T2>* getHashNode(){return nodeptr;}
};

//-------------------------------------------------------------------------------------------------------------------------------------------------
template <class T1,class T2>

class Iterator:public hashmap<T1,T2> {


public:
	 struct hashnode<T1,T2> *newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	 struct hashnode<T1,T2> *current;
	 //uint32_t a=size();
	 //nodeptr;
	 Iterator();
	 Iterator(hashnode<T1,T2>* Node);
	 hashnode<T1,T2>* begin();
	 hashnode<T1,T2>* end();
	 T1* getKeys();
	T2& get(T1 key);
	T1 operator++() ;
	bool operator!=( Iterator<T1,T2>) ;

	 hashnode<T1,T2>* operator*() ;

	T2 operator[](int index) ;
	//----------------------------------------------------------------------------------------


	//--------------------------------------------------------------------------------------------
	virtual ~Iterator();
public:

	  T1 arr[ARRAYMAX];
	  T1 returnKey;
	//  hashmap<T1,T2> t1;
	// hashmap<T1,T2> it;
	//getHashNode();
	 };


#endif /* ITERATORBST_H_ */
