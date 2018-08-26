#include<iostream>
#include "Iterator.h"
#include<stdlib.h>
#include<stdint.h>
#include "bst.cpp"
#include "jenkins.cpp"


#include"BSTIterators.cpp"

#define FLAG 1
static std::mutex mutx;

static int count[MAX];//NO OF ENTRIES INTO HASHMAP
static int count1[MAX];//UNIQUE ENTRIES IN HASHMAP
static int count2[MAX];//COLLISION RELATED STATS

using namespace std;

//---------------------------------------------------------------------------------


//CONSTRUCTOR INITIALIZING THE DATA STRUCTURE
template<class T1,class T2>
hashmap<T1,T2>::hashmap()
{}


//CALCULATES HASH BASED ON JENKINS HASH
template<class T1,class T2>
int hashmap<T1,T2>::calculatehash(T1 m_key)
{
	const uint32_t stringVal[]={uint32_t(m_key)};
	int lenght=( sizeof(stringVal)/sizeof(uint32_t));

	uint32_t ABC=JenkinsHash(stringVal,lenght, 33);
	return (ABC%MAX);

}
//--------------------------------------------------------------->
//INSERTION ON HASHMAP
template<class T1,class T2>
bool hashmap<T1,T2>::insert(T1 m_key,T2 m_value)

{
	std::thread::id this_id = std::this_thread::get_id();
	 cout<<"Insert Function .Thread id"<<this_id<<endl;


		mutx.lock();


	int m_index=calculatehash(m_key);


	//if(FLAG==0){ cout<<"Key:  "<<m_key;cout<<"\tValue:  "<<m_value;cout<<"\tIndex:"<<m_index;cout<<"\n";}

	struct hashnode<T1,T2> *newNode=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	newNode->m_key=m_key;
	newNode->m_value=m_value;
	if(nodeptr[m_index]->m_key==NULL)
	{
		//nodeptr[m_index].m_key=6;
		nodeptr[m_index]->m_key=newNode->m_key;
		nodeptr[m_index]->m_value=newNode->m_value;
		nodeptr[m_index]->left = NULL;
		nodeptr[m_index]->right = NULL;
		count1[m_index]++;
		mutx.unlock();
		return true;
	}
	else
	{
		hashnode<T1,T2> *root;

		root=nodeptr[m_index];


		BST<T1,T2> b_obj;
		b_obj.m_bstinsert((bstnode<T1,T2>*)root,(bstnode<T1,T2>*)newNode);
		count2[m_index]++;
		mutx.unlock();
	}

	mutx.lock();
	count[m_index]=count1[m_index]+count2[m_index];
	mutx.unlock();
	return 0;
}
//--------------------------------------------------------------->
//DELETES AN ENTRY ON HASHMAP
template<class T1,class T2>
bool hashmap<T1,T2>::remove(T1 m_key)
{

	mutx.lock();
	std::thread::id this_id = std::this_thread::get_id();
		 cout<<"Remove Function .Thread id"<<this_id<<endl;

	int m_index=calculatehash(m_key);
	//if(FLAG==0)cout<<m_index;


	hashnode<T1,T2> *root=nodeptr[m_index];


	BST<T1,T2> bst_obj;
	if(1)
	{
		struct hashnode<T1,T2> *temp;
		root=(struct hashnode<T1,T2>*)(bst_obj.m_deleteNode((bstnode<T1,T2>*)root,m_key));
		temp=root;
		nodeptr[m_index]->m_key=temp->m_key;
		nodeptr[m_index]->m_value=temp->m_value;
		nodeptr[m_index]->left=temp->left;
		nodeptr[m_index]->right=temp->right;
		mutx.unlock();
		return true;
	}


	else{
		mutx.unlock();
		return false;}
}
//--------------------------------------------------------------->
// SEARCHES FOR A m_key AND RETURNS A m_value
// IF NOT INSERTS INTO THE HASHMAP
template<class T1,class T2>
bool hashmap<T1,T2>::findandInsert(T1 m_key,T2 m_value)
{
	mutx.lock();
	std::thread::id this_id = std::this_thread::get_id();
		 cout<<"Find and Insert Function .Thread id"<<this_id<<endl;

	int m_index=calculatehash(m_key);
	struct hashnode<T1,T2> *root=&nodeptr[m_index];
	BST<T1,T2> bst_obj;
	T2 i=bst_obj.m_bstsearch((struct bstnode<T1,T2>*)root,m_key,m_value);
	if(i==0)
	{
		insert(m_key,m_value);

	}
	mutx.unlock();
	return true;
}

template<class T1,class T2>
uint32_t hashmap<T1,T2>::size()

{
	std::thread::id this_id = std::this_thread::get_id();
		 cout<<"Size Function .Thread id"<<this_id<<endl;

	mutx.lock();
	size=0;

	for(int i=0;i<MAX;i++)
	{
		sum+=uint32_t(count[i]);
	}
	cout<<"Total entries on hashmap";
	mutx.unlock();
	return sum;
}
//--------------------------------------------------------------->
//RETURNS TOTAL NUMBER OF COLLISIONS HAPPENED AT GIVEN SLOT NUMBER
template<class T1,class T2>
uint32_t hashmap<T1,T2>::getNumberOfCollisionPerSlot(uint32_t slotNumber)
{
	return --count2[slotNumber];
}
//--------------------------------------------------------------->
//RETURNS TOTAL NUMBER OF COLLISIONS HAPPENED IN THE HASHMAP
template<class T1,class T2>
uint32_t hashmap<T1,T2>::getTotalNumberOfCollision()
{

	mutx.lock();
	sum=0;
	for(int i=0;i<MAX;i++)
	{
		sum+=count2[i];
	}
	mutx.unlock();
	return sum;
}
//--------------------------------------------------------------->
//PRINTS NUMBER OF COLLISIONS HAPPENED AT EVERY SLOT NUMBER
template<class T1,class T2>
void hashmap<T1,T2>::printCollisionStatistics()
{
	mutx.lock();
	int i;
	mutx.unlock();
	for(i=0;i<MAX;i++)
	{
		cout<<"\nnumber of collision at index\t"<<i<<"\tare\t"<<count2[i];
	}
}

//----------------------------------------------------------------------------------
//ITERATOR FUNCTIONS



template<class T1,class T2>
Iterator<T1,T2>::Iterator()
{
	mutx.lock();
	int i=0;
	arr[i]=0;

   	hashmap<T1,T2>::nodeptr[i]=NULL;
	/*	hashmap<T1,T2>::nodeptr[i]->m_value=0;
		hashmap<T1,T2>::nodeptr[i]->right=NULL;
		hashmap<T1,T2>::nodeptr[i]->left=NULL;
*/
     current=this->nodeptr[i];
     mutx.unlock();
}


template<class T1,class T2>
hashnode<T1,T2>* Iterator<T1,T2>::begin()
{
	std::thread::id this_id = std::this_thread::get_id();
		 cout<<"Begin Function .Thread id"<<this_id<<endl;


	mutx.lock();
	int index=0;
	mutx.unlock();
	while(hashmap<T1,T2>::nodeptr[index]->m_key==NULL){index++;}
	newNode->m_key=hashmap<T1,T2>::nodeptr[index]->m_key;
	newNode->m_value=hashmap<T1,T2>::nodeptr[index]->m_value;
	newNode->right=hashmap<T1,T2>::nodeptr[index]->right;
	newNode->left=hashmap<T1,T2>::nodeptr[index]->left;
	while(newNode->left!=NULL)
	{
		newNode=newNode->left;
	}

	mutx.lock();

	current=newNode;
	mutx.unlock();

	return newNode;
}

template<class T1,class T2>
hashnode<T1,T2>* Iterator<T1,T2>::end()
{
	std::thread::id this_id = std::this_thread::get_id();
		 cout<<"End Function .Thread id"<<this_id<<endl;


	mutx.lock();
	int i;
	mutx.unlock();
	for( i=MAX-1;i>=0;i--)
	{
	 if(hashmap<T1,T2>::nodeptr[i].m_key != NULL)
	 {
  	   newNode->m_key=hashmap<T1,T2>::nodeptr[i].m_key;
       newNode->m_value=hashmap<T1,T2>::nodeptr[i].m_value;
       newNode->right=hashmap<T1,T2>::nodeptr[i].right;
       newNode->left=hashmap<T1,T2>::nodeptr[i].left;
		while(newNode->right!=NULL)
		 {newNode=newNode->right;}
	 }
    }
	mutx.lock();

	current=newNode;
	mutx.unlock();

	return newNode;
}


template<class T1,class T2>
hashnode<T1,T2>* Iterator<T1,T2>::operator*()
{
 return current;
}



template<class T1,class T2>
T2& Iterator<T1,T2>::get(T1 m_key)
{
	std::thread::id this_id = std::this_thread::get_id();
		 cout<<"Get Function .Thread id"<<this_id<<endl;


	Iterator<T1,T2> it_obj;
    mutx.lock();
	int index=it_obj.calculatehash(m_key);
	struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
	temp=(hashmap<T1,T2>::nodeptr[index]);
	BSTIterators<T1,T2> bst;
	returnKey=bst.search((bstNodeIt<T1,T2>*)temp,m_key);
	current=temp;
	 mutx.unlock();
	return returnKey;
}

template<class T1,class T2>
T1* Iterator<T1,T2>::getKeys()
{
	std::thread::id this_id = std::this_thread::get_id();
		 cout<<"GetKeys Function .Thread id"<<this_id<<endl;


	struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));


	BSTIterators<T1,T2> bst;
	mutx.lock();
	for(int i=0;i<=MAX-1;++i)
	{
		temp=(hashmap<T1,T2>::nodeptr[i]);
		mutx.unlock();//2 thread change tempn values
		if(temp->m_key!='\0')
		 bst.inorder((bstNodeIt<T1,T2>*)temp);

	}
	mutx.lock();
	current=temp;
	  for(int i=0;i<MAX;i++)
	{
	arr[i]=bst.KeyArray[i];}
	 mutx.unlock();

		return arr;

}


template<class T1,class T2>
T1 Iterator<T1,T2>::operator++()
{
	BSTIterators<T1,T2> obj;
	 Iterator<T1,T2> it_obj;
     struct hashnode<T1,T2> *temp=(struct hashnode<T1,T2>*)malloc(sizeof(struct hashnode<T1,T2>));
     mutx.lock();
	 int i =0;
	 T1 m_key=current->m_key;
	 int index=it_obj.calculatehash(m_key);
	if(arr[i]!='\0'){
		while(m_key!=arr[i]){i++;}
		 returnKey=arr[i+1];}
	else if(hashmap<T1,T2>::nodeptr[index]->right!=NULL)
	{
		returnKey=hashmap<T1,T2>::nodeptr[index]->right->m_key;
	}
	else {
		index=index+1;
		while(hashmap<T1,T2>::nodeptr[index]->m_key==NULL){index++;}
		temp=(hashmap<T1,T2>::nodeptr[index]);
		mutx.unlock();

		if(temp->m_key!='\0')
				 obj.inorder((bstNodeIt<T1,T2>*)temp);
				 mutx.lock();

				returnKey= obj.KeyArray[0];
				mutx.unlock();

	}
    mutx.lock();
	current=temp;
	mutx.unlock();
	return returnKey;

}

template<class T1,class T2>
bool Iterator<T1,T2>::operator!=(Iterator<T1,T2> node)
{


	if(current->m_key==node.m_key && current->m_value==node.m_value)
	{return true;}

	return false;

}



template<class T1,class T2>
T2 Iterator<T1,T2>::operator[](int index)
{
	mutx.lock();
    current=(hashmap<T1,T2>::nodeptr[index]);
    mutx.unlock();
    return hashmap<T1,T2>::nodeptr[index]->m_value;
}




template<class T1,class T2>
Iterator<T1,T2>::~Iterator() {
	}








