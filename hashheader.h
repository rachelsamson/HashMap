#ifndef HASHHEADER_H_
#define HASHHEADER_H_
const int MAX=50;
#include<stdint.h>
template<class T1,class T2>
struct hashnode
		{
			T1 key;
			T2 value;
			hashnode<T1,T2> *left,*right;
		};
template<class T1,class T2>
class hashmap
{

private:
	void m_Print_all(hashnode<T1,T2> *);
	T2 m_search(T1 key);
	struct hashnode<T1,T2> nodeptr[MAX];

public:
	hashmap<T1,T2>();
	//------------------------------------------------->
	virtual ~hashmap<T1,T2>(){};
	//------------------------------------------------->
	int m_calculatehash(T1);
	//------------------------------------------------->
	bool m_findandInsert(T1,T2);
	//------------------------------------------------->
	bool m_Insert(T1 key,T2 value);
	//------------------------------------------------->
	bool m_Delete(T1);
	//------------------------------------------------->
	uint32_t size();// returns the total number of entries present in hash map
	//------------------------------------------------->
	uint32_t getNumberOfCollisionPerSlot(uint32_t);
	//------------------------------------------------->
	uint32_t getTotalNumberOfCollision();
	//------------------------------------------------->
	void printCollisionStatistics();
};
#endif /* HASHHEADER_H_ */
