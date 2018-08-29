#include<iostream>
#include "Iterator.h"
#include<stdlib.h>
#include<stdint.h>
#include<thread>
#include "bst.cpp"
#include<mutex>

#include "jenkins.cpp"
/*
#include "BSTIterators.h"
#include"BSTIterators.cpp"
*/
#define FLAG 0
static std::mutex mutx;

static uint32_t count[MAX];//NO OF ENTRIES INTO HASHMAP
static uint32_t count1[MAX];//UNIQUE ENTRIES IN HASHMAP
static uint32_t count2[MAX];//COLLISION RELATED STATS

using namespace std;

//----------------------------------------------------------------------------------//
//---------------------------HASH OPERAIONS-----------------------------------------//
//----------------------------------------------------------------------------------//
//CONSTRUCTOR INITIALIZING THE DATA STRUCTURE
template<class T1,class T2>
hashmap<T1,T2>::hashmap()
{	//if(FLAG==0) cout<<"Constructor Initializing data structure to NULL\n"<<endl;
	for(int i=0;i<MAX;i++)
	{


		mutx.lock();

		nodeptr[i]=NULL;
		//for iterator
		struct hashnode<T1,T2> *nodeptr1[MAX];

		arr[i]=0;
		current=nodeptr[i];

		mutx.unlock();

	}
	//memcpy(this->nodeptr1,nodeptr, MAX*sizeof(hashnode<T1,T2>));

	}

//CALCULATES HASH BASED ON JENKINS HASH
template<class T1,class T2>
int hashmap<T1,T2>::calculatehash(T1 m_key)
{
	const uint32_t stringVal[]={uint32_t(m_key)};
	int lenght=( sizeof(stringVal)/sizeof(uint32_t));
	uint32_t ABC=JenkinsHash(stringVal,lenght, 33);
	return (ABC%MAX);
}

//---------------------------------------------INSERTION ON HASHMAP--------------------------------------------------------------//
template<class T1,class T2>
void hashmap<T1,T2>::insert(T1 m_key,T2 m_value)
{

hashmap<T1,T2> q;
	int m_index=calculatehash(m_key);
	struct hashnode<T1,T2> *newNode=new  struct hashnode<T1,T2>;
	newNode->m_key=m_key;
	newNode->m_value=m_value;
	struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
;
	if(nodeptr[m_index]==NULL )
	{
		nodeptr[m_index]=new hashnode<T1,T2>;
		nodeptr[m_index]->m_key=0;
		cout<<"\nInserting key and value into root node[nodeptr]";
		if(FLAG==0)
		{ cout<<"Key:  "<<m_key;
		//printf("Value:%c \t %d ",m_value.a,m_value.number);

		cout<<"\tIndex:"<<m_index;cout<<"\n";
		}
		nodeptr[m_index]->m_key=newNode->m_key;
		nodeptr[m_index]->m_value=newNode->m_value;
		nodeptr[m_index]->left = NULL;
		nodeptr[m_index]->right = NULL;
		temp=nodeptr[m_index];
				current=temp;
				cout<<"Inserted";
		count1[m_index]++;
		//return true;
	}
	else
	{
		hashnode<T1,T2> *root;
		root=nodeptr[m_index];
		BST<T1,T2> b_obj;
		cout<<"\nInserting into BST[nodeptr]";
		b_obj.m_bstinsert((bstnode<T1,T2>*)root,(bstnode<T1,T2>*)newNode);

		temp=nodeptr[m_index];
		current=temp;
		count2[m_index]++;
	}
	count[m_index]+=count1[m_index]+count2[m_index];


//	memcpy(hash.nodeptr1,nodeptr, MAX*sizeof(hashnode<T1,T2>));

//	currentNode(*this);

	//mutx.unlock();

	}

//----------------------------------------DELETES AN ENTRY ON HASHMAP------------------------------------------------------//
template<class T1,class T2>
bool hashmap<T1,T2>::remove(T1 m_key)
{
	std::thread::id this_id = std::this_thread::get_id();

		cout<< "Thread Id:"<<  this_id<<endl ;

	mutx.lock();

	int m_index=calculatehash(m_key);
	if(FLAG==0)cout<<"\nDeleting key "<<m_key;
	hashnode<T1,T2> *root=nodeptr[m_index];
	if(root==NULL)
	{
		cout<<"Key not found";
		mutx.unlock();

		return true;
	}
	else
	{
		BST<T1,T2> bst_obj;
		struct hashnode<T1,T2> *temp;
		root=(struct hashnode<T1,T2>*)(bst_obj.m_deleteNode((bstnode<T1,T2>*)root,m_key));

		temp=root;
		nodeptr[m_index]->m_key=temp->m_key;
		nodeptr[m_index]->m_value=temp->m_value;
		nodeptr[m_index]->left=temp->left;
		nodeptr[m_index]->right=temp->right;
		if(FLAG==0)cout<<"\tDeleted desired key";
		if(count2[m_index]!=0)
		{
			count2[m_index]--;
			--count[m_index];
		}
		mutx.unlock();
		currentNode(this);
		return true;

	}

	/*if(1)
	{

	}
	else{return false;}*/
}


//----------------------SEARCHES FOR A KET AND RETURNS A VALUE IF NOT INSERTS INTO THE HASHMAP---------------------------//
template<class T1,class T2>
bool hashmap<T1,T2>::findandInsert(T1 m_key,T2 m_value)
{
	std::thread::id this_id = std::this_thread::get_id();

		cout<< "Thread Id:"<<  this_id<<endl ;

	mutx.lock();

	int m_index=calculatehash(m_key);
	cout<<"\nRunning Find and Insert function";
	struct hashnode<T1,T2> *root=nodeptr[m_index];
	if(root==NULL)
	{
		insert(m_key,m_value);
		if(FLAG==0) cout<<"\nKey Inserted";



	}
	else
	{
		BST<T1,T2> bst_obj;
		bst_obj.m_bstsearch((struct bstnode<T1,T2>*)root,m_key,m_value);
		if(FLAG==0){cout<<"\nELement found";}
	}
	mutx.unlock();

	return true;
}


//------------------------------------TOTAL ENTRIES INTO THE HASHMAP--------------------------------------------------//

template<class T1,class T2>
uint32_t hashmap<T1,T2>::size()
{
	std::thread::id this_id = std::this_thread::get_id();

		cout<< "Thread Id:"<<  this_id<<endl ;

	sum=0;
	for(int i=0;i<MAX;i++)
	{

		sum+=count[i];
	}
	return sum;
}

//-------------------------RETURNS TOTAL NUMBER OF COLLISIONS HAPPENED AT GIVEN SLOT NUMBER------------------------------//
template<class T1,class T2>
uint32_t hashmap<T1,T2>::getNumberOfCollisionPerSlot(uint32_t slotNumber)
{
	std::thread::id this_id = std::this_thread::get_id();

		cout<< "Thread Id:"<<  this_id<<endl ;

	if(count2[slotNumber]!=0)
		return --count2[slotNumber];
	else;
}

//-------------------------RETURNS TOTAL NUMBER OF COLLISIONS HAPPENED IN THE HASHMAP-----------------------------------//
template<class T1,class T2>
uint32_t hashmap<T1,T2>::getTotalNumberOfCollision()
{
	std::thread::id this_id = std::this_thread::get_id();

		cout<< "Thread Id:"<<  this_id<<endl ;

	sum=0;
	for(int i=0;i<MAX;i++)
	{
		mutx.lock();

		sum+=count2[i];
		mutx.unlock();

	}
	return sum;
}

//-------------------------PRINTS NUMBER OF COLLISIONS HAPPENED AT EVERY SLOT NUMBER----------------------------------//
template<class T1,class T2>
void hashmap<T1,T2>::printCollisionStatistics()
{
	std::thread::id this_id = std::this_thread::get_id();

		cout<< "Thread Id:"<<  this_id<<endl ;

	int i;
	for(i=0;i<MAX;i++)
	{
		cout<<"\nNumber of collision at index\t "<<i<<"\t is/are \t "<<count2[i];
	}
}





//----------------------------------------------------------------------------------//
//-----------------------------ITERATOR OPERATIONS----------------------------------//
//----------------------------------------------------------------------------------//

template<class T1,class T2>
hashmap<T1,T2>::Iterator::Iterator()
{
	//memcpy(nodeptr1,hashmap<T1,T2>::nodeptr, MAX*sizeof(hashnode<T1,T2>));
	//memcpy(nodeptr1,obj.nodeptr, MAX*sizeof(hashnode<T1,T2>));

	int i=0;//Initialization
	//Array that stores all the keys
}






//----------------------------------RETURNS FIRST ENTRY INTO THE HASHMAP-----------------------------------------------------//
template<class T1,class T2>
typename hashmap<T1,T2>::Iterator hashmap<T1,T2>::Iterator::begin()
{
	hashmap<T1,T2> obj;

	if(FLAG==0){
		cout<<"\nIterator:Begin Running";
		cout<<"\tReturns first entry into the hashmap";}
	mutx.lock();
    int index=0;
	while(nodeptr1[index]==NULL)
	{index++;}
	newNode->m_key=nodeptr1[index]->m_key;
	newNode->m_value=nodeptr1[index]->m_value;
	newNode=nodeptr1[index];
	/*newNode->m_key=obj.nodeptr[index]->m_key;
	newNode->m_value=obj.nodeptr[index]->m_value;
	*/newNode->right=nodeptr1[index]->right;
	newNode->left=nodeptr1[index]->left;
	while(newNode->left!=NULL)
	{
		newNode=newNode->left;
	}
	current=newNode;
	//memcpy(nodeptr1,itr.nodeptr, MAX*sizeof(hashnode<T1,T2>));

	mutx.unlock();
		//itr.newNode=newNode;
	return obj.itr;
}

//---------------------------------RETURNS LAST ENTRY INTO THE HASHMAP-------------------------------------------------------//
template<class T1,class T2>
typename hashmap<T1,T2>::Iterator hashmap<T1,T2>::Iterator::end()
{
	if(FLAG==0){
	cout<<"\nIterator:End Running";
	cout<<"\tReturns last entry into the hashmap";}
	mutx.lock();

	for(int i=MAX-1;i>=0;i--)
	{
		if(nodeptr1[i] != NULL)
		{
			newNode->m_key=nodeptr1[i]->m_key;
			newNode->m_value=nodeptr1[i]->m_value;
			newNode->right=nodeptr1[i]->right;
			newNode->left=nodeptr1[i]->left;
			while(newNode->right!=NULL)
			{newNode=newNode->right;}
		}
		break;
	}
	current=newNode;
	mutx.unlock();
//	newNode=newNode;
	return itr;
}

//----------------------------------------------RETURNS CURRENT NODE INFO---------------------------------------------//
template<class T1,class T2>
hashnode<T1,T2>* hashmap<T1,T2>::Iterator::operator*(class hashmap<T1,T2> &obj)
{
	/*std::thread::id this_id = std::this_thread::get_id();

		cout<< "Thread Id:"<<  this_id<<endl ;
*/
	return this;
}

//--------------------------------------------RETURNS VALUE BASED ON KEY----------------------------------------------//
template<class T1,class T2>
T2 hashmap<T1,T2>::get(T1 m_key)
{

	if(FLAG==0)	cout<<"\nIterator:Get Running";


	BST<T1,T2> bst;
	//hashmap<T1,T2> hashObj;
	struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));

	mutx.lock();

	int index=calculatehash(m_key);
	if(nodeptr[index]==NULL)
	{
		mutx.unlock();
		return returnKey;}
	else{

		        struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
				temp=nodeptr[index];
				if(FLAG==0)	cout<<"\nIterator:Get Running";
				BST<T1,T2> bst;

				returnKey=bst.m_bstsearch((bstnode<T1,T2>*)temp,m_key);
				current=temp;
				mutx.unlock();
				return returnKey;

	}



}

//---------------------------------------RETURNS ALL THE KEYS IN THE HASHMAP-----------------------------------------//
template<class T1,class T2>
T1* hashmap<T1,T2>::getKeys()
{



	struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
		BST<T1,T2> bst;
		if(FLAG==0){
		cout<<"\nIterator:Getkeys Running";
		cout<<"\nReturns all the keys in the hashmap";}
		for(int i=0;i<=MAX;i++)
		{
			if(itr.nodeptr1[i]!=NULL)
			{
			temp=(itr.nodeptr1[i]);
			if(temp->m_key!=NULL)
				bst.inorder((bstnode<T1,T2>*)temp);}
		}
		current=temp;
		//mutx.lock();
		for(int i=0;i<MAX;i++)
		{while(bst.KeyArray[i]!=NULL)
			cout<<bst.KeyArray[i];
			arr[i]=bst.KeyArray[i];}
		//mutx.unlock();
		return arr;

}

//------------------------------------INCREMENTS THE CURRENT AND RETURNS THE NEXT NODE------------------------------//
template<class T1,class T2>
T1 hashmap<T1,T2>::Iterator::operator++()
{
	if(FLAG==0){
				cout<<"\nIterator:Operator++ Running";
				cout<<"\nIncrements the current node and returns the next node";}


			struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
			int i =0;
			T1 m_key=current->m_key;
			getKeys();
			while(arr[i]!='\0')
			{
				if(m_key==arr[i]){

					returnKey2=arr[i+1];
					break;
				}
				else
				{
					i++;
				}

			}
			current=temp;

			return returnKey2;


}

//-------------------------------------------Returns true if value and key matches----------------------------------//
template<typename T1,typename T2>
bool hashmap<T1,T2>::Iterator::operator!=(class hashmap<T1,T2> &obj)
{

	if(FLAG==0){
	cout<<"\nIterator:Operator!= running";
	cout<<"\n Returns 0 if two objects' key and value matches";}

	return(!(*this == obj));

}

//-------------------------------------------RETURNS INPUT SUBSCRIPT'S VALUE---------------------------------------//

template<typename T1,typename T2>
T2 hashmap<T1,T2>::Iterator::operator[](int index)
{

	if(FLAG==0){
	cout<<"\nIterator:Operator[] running";
	cout<<"\n Returns desired subscript's value";}

	current=(hashmap<T1,T2>::nodeptr1[index]);
	if(hashmap<T1,T2>::nodeptr1[index]!=NULL){
	cout<<hashmap<T1,T2>::nodeptr1[index]->m_value;

	}

}

template<typename T1,typename T2>
hashmap<T1,T2>::Iterator::~Iterator() {
}































