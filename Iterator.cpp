#include<iostream>
#include "Iterator.h"
#include<stdlib.h>
#include<stdint.h>
#include "bst.cpp"
#include "jenkins.cpp"
#include "BSTIterators.h"
#include"BSTIterators.cpp"
#define FLAG 0
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
{
	//if(FLAG==0) cout<<"Constructor Initializing data structure to NULL\n"<<endl;
	for(int i=0;i<MAX;i++)
	{
		nodeptr[i]=NULL;
		arr[i]=0;//for iterator
		current=nodeptr[i];

	}
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
bool hashmap<T1,T2>::insert(T1 m_key,T2 m_value)
{

	int m_index=calculatehash(m_key);
	struct hashnode<T1,T2> *newNode=new  struct hashnode<T1,T2>;
	newNode->m_key=m_key;
	newNode->m_value=m_value;
	if(nodeptr[m_index]==NULL || nodeptr[m_index]->m_key==NULL)
	{
		nodeptr[m_index]=new hashnode<T1,T2>;
		nodeptr[m_index]->m_key=0;
		cout<<"\nInserting key and value into root node[nodeptr]";
		if(FLAG==0)
		{ cout<<"Key:  "<<m_key;
		printf("Value:%c \t %d ",m_value.a,m_value.number);
		cout<<"\tIndex:"<<m_index;cout<<"\n";
		}
		nodeptr[m_index]->m_key=newNode->m_key;
		nodeptr[m_index]->m_value=newNode->m_value;
		nodeptr[m_index]->left = NULL;
		nodeptr[m_index]->right = NULL;
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
		count2[m_index]++;
	}
	count[m_index]+=count1[m_index]+count2[m_index];
	return 0;
}

//----------------------------------------DELETES AN ENTRY ON HASHMAP------------------------------------------------------//
template<class T1,class T2>
bool hashmap<T1,T2>::remove(T1 m_key)
{
	int m_index=calculatehash(m_key);
	if(FLAG==0)cout<<"\nDeleting key "<<m_key;
	hashnode<T1,T2> *root=nodeptr[m_index];
	if(root==NULL)
	{
		cout<<"Key not found";
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
	return true;
}


//------------------------------------TOTAL ENTRIES INTO THE HASHMAP--------------------------------------------------//

template<class T1,class T2>
uint32_t hashmap<T1,T2>::size()
{
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
	if(count2[slotNumber]!=0)
		return --count2[slotNumber];
	else;
}

//-------------------------RETURNS TOTAL NUMBER OF COLLISIONS HAPPENED IN THE HASHMAP-----------------------------------//
template<class T1,class T2>
uint32_t hashmap<T1,T2>::getTotalNumberOfCollision()
{
	sum=0;
	for(int i=0;i<MAX;i++)
	{
		sum+=count2[i];
	}
	return sum;
}

//-------------------------PRINTS NUMBER OF COLLISIONS HAPPENED AT EVERY SLOT NUMBER----------------------------------//
template<class T1,class T2>
void hashmap<T1,T2>::printCollisionStatistics()
{
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
Iterator<T1,T2>::Iterator()
{
	//cout<<"Constuctor initilializing the iterator";
	int i=0;//Initialization
	arr[i]=0;//Array that stores all the keys
}


template<class T1,class T2>
Iterator<T1,T2>::Iterator(hashnode<T1,T2>* currentNode)
{
	//if(FLAG==0)cout<<"Overloading constructor";
	newNode=NULL;//Temporary to hold values
	current=currentNode;
	int index=0;
}

//----------------------------------RETURNS FIRST ENTRY INTO THE HASHMAP-----------------------------------------------------//
template<class T1,class T2>
hashnode<T1,T2>* Iterator<T1,T2>::begin()
{	int index=0;
	if(FLAG==0){
	cout<<"\nIterator:Begin Running";
	cout<<"\tReturns first entry into the hashmap";}
	while(hashmap<T1,T2>::nodeptr[index]->m_key==NULL){index++;}
	newNode->m_key=hashmap<T1,T2>::nodeptr[index]->m_key;
	newNode->m_value=hashmap<T1,T2>::nodeptr[index]->m_value;
	newNode->right=hashmap<T1,T2>::nodeptr[index]->right;
	newNode->left=hashmap<T1,T2>::nodeptr[index]->left;
	while(newNode->left!=NULL)
	{
		newNode=newNode->left;
	}
	current=newNode;
	return newNode;
}

//---------------------------------RETURNS LAST ENTRY INTO THE HASHMAP-------------------------------------------------------//
template<class T1,class T2>
hashnode<T1,T2>* Iterator<T1,T2>::end()
{
	if(FLAG==0){
	cout<<"\nIterator:End Running";
	cout<<"\tReturns last entry into the hashmap";}
	for(int i=MAX-1;i>=0;i--)
	{
		if(hashmap<T1,T2>::nodeptr[i]->m_key != NULL)
		{
			newNode->m_key=hashmap<T1,T2>::nodeptr[i]->m_key;
			newNode->m_value=hashmap<T1,T2>::nodeptr[i]->m_value;
			newNode->right=hashmap<T1,T2>::nodeptr[i]->right;
			newNode->left=hashmap<T1,T2>::nodeptr[i]->left;
			while(newNode->right!=NULL)
			{newNode=newNode->right;}
		}
		break;
	}
	current=newNode;
	return newNode;
}

//----------------------------------------------RETURNS CURRENT NODE INFO---------------------------------------------//
template<class T1,class T2>
hashnode<T1,T2>* Iterator<T1,T2>::operator*()
{

	return current;
}

//--------------------------------------------RETURNS VALUE BASED ON KEY----------------------------------------------//
template<class T1,class T2>
T2& Iterator<T1,T2>::get(T1 m_key)
{
	Iterator<T1,T2> it_obj;
	int index=it_obj.calculatehash(m_key);
	struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	temp=&(hashmap<T1,T2>::nodeptr[index]);
	if(FLAG==0)	cout<<"\nIterator:Get Running";
	BSTIterators<T1,T2> bst;
	struct hashnode<T1,T2> temp2;
	returnKey=bst.search((bstNodeIt<T1,T2>*)temp,m_key);
	current=temp;
	return returnKey;
}

//---------------------------------------RETURNS ALL THE KEYS IN THE HASHMAP-----------------------------------------//
template<class T1,class T2>
T1* Iterator<T1,T2>::getKeys()
{
	struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	BST<T1,T2> bst;
	if(FLAG==0){
	cout<<"\nIterator:Getkeys Running";
	cout<<"\nReturns all the keys in the hashmap";}
	for(int i=0;i<=MAX;i++)
	{
		temp=(hashmap<T1,T2>::nodeptr[i]);
		if(temp->m_key!=NULL)
			bst.inorder((bstnode<T1,T2>*)temp);
	}
	current=temp;
	for(int i=0;i<MAX;i++)
	{arr[i]=bst.KeyArray[i];}
	return arr;
}

//------------------------------------INCREMENTS THE CURRENT AND RETURNS THE NEXT NODE------------------------------//
template<class T1,class T2>
T1 Iterator<T1,T2>::operator++()
{
	BSTIterators<T1,T2> obj;
	struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	int i =0;
	T1 m_key=current->m_key;
	Iterator<T1,T2> it_obj;
	if(FLAG==0){
	cout<<"\nIterator:Operator++ Running";
	cout<<"\nIncrements the current node and returns the next node";}
	int index=it_obj.calculatehash(m_key);
	if(arr[i]!='\0'){
		while(m_key!=arr[i]){i++;}
		returnKey=arr[i+1];}
	else if(hashmap<T1,T2>::nodeptr[index]->right!=NULL)
	{
		returnKey=hashmap<T1,T2>::nodeptr[index]->right->m_key;
	}
	else
	{
		index=index+1;
		while(hashmap<T1,T2>::nodeptr[index]->m_key==NULL){index++;}
		temp=(hashmap<T1,T2>::nodeptr[index]);
		if(temp->m_key!=NULL)obj.inorder((bstNodeIt<T1,T2>*)temp);
		returnKey= obj.KeyArray[0];
	}
	current=temp;
	return returnKey;
}

//-------------------------------------------Returns true if value and key matches----------------------------------//
template<class T1,class T2>
bool Iterator<T1,T2>::operator!=(Iterator<T1,T2> node)
{
	if(FLAG==0){
	cout<<"\nIterator:Operator!= running";
	cout<<"\n Returns 0 if two objects' key and value matches";}
	if(current->m_key==node.m_key && current->m_value.a==node.m_value.a && current->m_value.number==node.m_value.number)
	{return true;}
	return false;
}

//-------------------------------------------RETURNS INPUT SUBSCRIPT'S VALUE---------------------------------------//

template<class T1,class T2>
T2 Iterator<T1,T2>::operator[](int index)
{
	if(FLAG==0){
	cout<<"\nIterator:Operator[] running";
	cout<<"\n Returns desired subscript's value";}
	current=(hashmap<T1,T2>::nodeptr[index]);
	if(hashmap<T1,T2>::nodeptr[index]!=NULL){
	cout<<hashmap<T1,T2>::nodeptr[index]->m_value.a;}
	//cout<<nodeptr[index]->m_value.number;
	//return hashmap<T1,T2>::nodeptr[index]->m_value;
	//return eg;
}

template<class T1,class T2>
Iterator<T1,T2>::~Iterator() {
}
