#ifndef HASHHEADER_H_
#define HASHHEADER_H_
const int CAPACITY=1000;
//<---------------------------------------------------------------------------->
//Template declaration for Array and Tree
/*template<typename T1,typename T2>
struct Arraynode
{
	T1 key;
	T2 value;
	T3 hashvalue;
	Arraynode *next;
};//*arrptr[CAPACITY];*/

//<---------------------------------------------------------------------------->

//<---------------------------------------------------------------------------->
//Class Calculatehash to create hashvalue and return index by mod function

//<--------------------------------------------------------------------------------->
/*template<typename T1,typename T3>
class calculatehash
{
	int calculate_hash(T1,T3);
};*/
//<--------------------------------------------------------------------------------->
//Class hashnode to create all member function related to Tree Insert,Update,Delete
template<typename T1,typename T2>
struct hashnode
		{
			T1 key;
			T2 value;
			//T3 hashvalue;
			hashnode<T1,T2> *left,*right;
			//hashnode<T1,T2> *root;
			//Treenode(){std::cout<<"print this ";}
			//Treenode(T1 Key,T2 Value,T3 Hash){this->key=Key; this->value=Value; this->hashvalue=Hash;std::cout<<this->key;}
		};

template<typename T1,typename T2>
class hashmap
{
struct hashnode<T1,T2> nodeptr[CAPACITY];

//template<typename T1,typename T2>
private:
	//hashnode<T1,T2> *root;
	//Arraynode<T1,T2,T3> *head;
	//Arraynode<T1,T2,T3> *next;
	//Arraynode<T1,T2,T3> arrptr[CAPACITY];
	void m_Print_all(hashnode<T1,T2> *);//To print Tree
	//void m_Print_all(Arraynode<T1,T2,T3> *);//To print Array


public:
	//struct hashnode<T1,T2> obj_Tree;
	//------------------------------------------------->
	hashmap<T1,T2>();
	virtual ~hashmap<T1,T2>(){};
	//bool IsEmpty(node *newNode);//yet to implement
	int m_calculatehash(T1);
	//------------------------------------------------->
	//bool m_Delete(int);//yet to implement
	//struct Treenode<T1,T2,T3> create_node(int);
	//void insert_node(struct Treenode<T1,T2,T3>*);
	//------------------------------------------------->
	//void m_Print_one(Treenode<T1,T2,T3> *);
	//------------------------------------------------->
	//void m_PrintT();
	//------------------------------------------------->
	//void m_SearchTree(int);
//------------------------------------------------->
	//bool m_Insertarray(int,Arraynode<T1,T2,T3> *);
	//------------------------------------------------->
	bool m_findandInsert(T1,T2);
	//------------------------------------------------->
	bool m_Insert(T1 key,T2 value);
	bool m_Delete(T1);
	//------------------------------------------------->
	bool m_updatearray();
	//------------------------------------------------->
	//bool m_Insert(Treenode<T1,T2,T3> *newNode);
	//------------------------------------------------->

};
#endif /* HASHHEADER_H_ */
