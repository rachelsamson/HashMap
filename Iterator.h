
#ifndef ITERATORBST_H_
#define ITERATORBST_H_
#define ARRAYMAX 21
#define MAX 21

#include <mutex>
#include<thread>
#include <stdint.h>
#include<stdlib.h>


template<class T1,class T2>
struct hashnode
{
	T1 m_key;
	T2 m_value;
	hashnode<T1,T2> *left,*right;
};

template<class T3,class T4>
class Iterator;

//---------------------------------------------------------------------------Class HASHMAP---------------------------------------------------------


template<class T1,class T2>
class hashmap:public hashnode<T1,T2>
{
public:
class Iterator;
	T2 m_search(T1 key);
	uint32_t sum;
	   struct hashnode<T1,T2> *nodeptr[MAX];//pointer
//	struct hashnode<T1,T2> *node;


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
	void insert(T1 key,T2 value);
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
	T2 get(T1 key);

	 T1* getKeys();
	 T1 arr[ARRAYMAX];
	//T1 arr[MAX];
	 T2 returnKey;
	friend class Iterator;

	struct hashnode<T1,T2> *current;


	class Iterator{


			public:

			struct hashnode<T1,T2> *newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
				 struct hashnode<T1,T2> *current;
				 Iterator();
				Iterator(hashmap<T1,T2> &obj){memcpy(nodeptr1,obj.nodeptr, MAX*sizeof(hashnode<T1,T2>));
}
				Iterator begin();
				Iterator end();


				T1 operator++() ;
				bool operator!=( hashmap<T1,T2> &obj) ;
				 hashnode<T1,T2>* operator*(hashmap<T1,T2> &obj) ;

				T2 operator[](int index) ;
				//----------------------------------------------------------------------------------------

				//--------------------------------------------------------------------------------------------
				virtual ~Iterator();
			public:
						struct hashnode<T1,T2> *nodeptr1[MAX];


				  T1 returnKey2;
				 };


hashmap<T1,T2>::Iterator itr;


};


//-------------------------------------------------------------------------------------------------------------------------------------------------
#endif /* ITERATORBST_H_ */
