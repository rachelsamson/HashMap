#ifndef HASHHEADER_H_
#define HASHHEADER_H_
const int MAX=5000;
#include<stdint.h>
template<class T1,class T2>
struct hashnode
{
	T1 m_key;
	T2 m_value;
	hashnode<T1,T2> *left,*right;
};
template<class T1,class T2>
class hashmap
{

private:

	T2 m_search(T1 key);
	struct hashnode<T1,T2> nodeptr[MAX];

public:
	hashmap<T1,T2>();
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
	 T1* m_getKeys();//for iterator
	void print_all();
	T1 arr[MAX];
	struct hashnode<T1,T2> *current;
};
#endif /* HASHHEADER_H_ */
