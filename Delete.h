#ifndef HASHHEADER_H_
#define HASHHEADER_H_
const int CAPACITY=1000;

//Class hashnode to create all member function related to Tree Insert,Update,Delete
template<typename T1,typename T2>
struct hashnode
		{
			T1 key;
			T2 value;
			hashnode<T1,T2> *left,*right;
			};

template<typename T1,typename T2>
class hashmap
{
struct hashnode<T1,T2> nodeptr[CAPACITY];


private:

	void m_Print_all(hashnode<T1,T2> *);//To print Tree


public:
hashmap<T1,T2>();
	virtual ~hashmap<T1,T2>(){std::cout<<"called";};



	bool m_Insert(T1 key,T2 value);
	bool m_Delete(int key);


};
#endif /* HASHHEADER_H_ */
