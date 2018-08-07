#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
#include "Iterator.h"
#include<stdlib.h>
#include"bst.cpp"
#include<stdint.h>
#include "jenkins.cpp"
#include "BSTIterators.h"
#include"BSTIterators.cpp"
using namespace std;
template<class T1,class T2>
Iterator<T1,T2>::Iterator() {
for(int i=0;i<MAX;i++){
nodeptr[i].key=NULL;
nodeptr[i].value=0;
nodeptr[i].right=NULL;
nodeptr[i].left=NULL;

}
/*ashmap<T1,T2> obj;
	obj.nodeptr[0];
	cout<<"this is";
cout<<obj.nodeptr[0].key;*/
current=this->nodeptr;


}


template<class T1,class T2>
Iterator<T1,T2>::Iterator(hashnodeIt<T1,T2>* currentNode)
{
	newNode=NULL;
	current=currentNode;
	int index=0;

}

template<class T1,class T2>
hashnodeIt<T1,T2>* Iterator<T1,T2>::begin()
{
	int index=0;
	newNode->key=nodeptr[index].key;
	newNode->value=nodeptr[index].value;
	newNode->right=nodeptr[index].right;
	newNode->left=nodeptr[index].left;
	while(newNode->left!=NULL)
	{
		newNode=newNode->left;
	}
	cout<<newNode->key<<"this";
	current=newNode;
	return newNode;
}



template<class T1,class T2>
hashnodeIt<T1,T2>* Iterator<T1,T2>::end()
{
	//int index=m_calculatehash();
	for(int i=MAX-1;i>=0;i--)
	{
	 if(nodeptr[i].key != NULL)
	 {
  	   newNode->key=nodeptr[i].key;
       newNode->value=nodeptr[i].value;
       newNode->right=nodeptr[i].right;
       newNode->left=nodeptr[i].left;
		while(newNode->right!=NULL)
		 {newNode=newNode->right;}
	 }
    }
	current=newNode;
	return newNode;
}


template<class T1,class T2>
hashnodeIt<T1,T2>* Iterator<T1,T2>::operator*(Iterator<T1,T2> node) const
{
 return current;
}

template<class T1,class T2>
int Iterator<T1,T2>::size()
{int count=0;
  return count;
}


template<class T1,class T2>
T2& Iterator<T1,T2>::m_get(T1 key)
{
	int index=m_calculatehash(key);
	struct hashnodeIt<T1,T2> *temp=new hashnodeIt<int,int>;

	temp=&nodeptr[index];
	BSTIterators<T1,T2> bst;
	struct hashnodeIt<T1,T2> temp2;
	//temp1=
	 returnKey=bst.search((bstNodeIt<T1,T2>*)temp,key);
current=temp;
	return returnKey;
}

template<class T1,class T2>
T1* Iterator<T1,T2>::m_getKeys()
{
	struct hashnodeIt<T1,T2> *temp=(struct hashnodeIt<T1,T2>*)malloc(sizeof(struct hashnodeIt<T1,T2>));


	BSTIterators<T1,T2> bst;

	for(int i=0;i<=MAX-1;++i)
	{

		temp=&nodeptr[i];
		 if(temp->key!=NULL)
		 bst.inorder((bstNodeIt<T1,T2>*)temp);

	}
	current=temp;
	for(int i=0;i<MAX;i++)
	{arr[i]=bst.KeyArray[i];}
	free(temp);
		return arr;

}


template<class T1,class T2>
T1 Iterator<T1,T2>::operator++()
{	BSTIterators<T1,T2> obj;
struct hashnodeIt<T1,T2> *temp=(struct hashnodeIt<T1,T2>*)malloc(sizeof(struct hashnodeIt<T1,T2>));

int i =0;

	T1 Key=current->key;
	int index=m_calculatehash(Key);
	if(arr[i]!='\0'){
		while(Key!=arr[i]){i++;}
		 returnKey=arr[i+1];}
	else if(nodeptr[index].right!=NULL)
	{
		returnKey=(nodeptr[index].right)->key;
	}
	else {
		index=index+1;
		while(nodeptr[index].key=='\0'){index++;}
		temp=&nodeptr[index];
				 if(temp->key!='\0')
				 obj.inorder((bstNodeIt<T1,T2>*)temp);
				returnKey= obj.KeyArray[0];
	}

	//free(temp);
	return returnKey;

}

template<class T1,class T2>
bool Iterator<T1,T2>::operator!=(Iterator<T1,T2> node) const
{


	if(current->key==node.newNode->key && current->value==node.newNode->value)
	{return true;}

	return false;

}



template<class T1,class T2>
T2 Iterator<T1,T2>::operator[](int index)
{
	current=&nodeptr[index];
  return nodeptr[index].value;
}




//--------------------------------------------------------------------------------------


template<class T1,class T2>
int Iterator<T1,T2>::m_calculatehash(T1 key)
{
	const uint32_t stringVal[]={key};
	int lenght=( sizeof(stringVal)/sizeof(uint32_t));
	uint32_t ABC=JenkinsHash(stringVal,lenght, 33);
	int index=(ABC/100000000)/2;
	return index%MAX;

}
template<class T1,class T2>
bool Iterator<T1,T2>::m_Insert(T1 key,T2 value)
{
	int index=m_calculatehash(key);
	//cout<<index<<endl;
	struct hashnodeIt<T1,T2> *newNode=new hashnodeIt<int,int>;
	newNode->key=key;
	newNode->value=value;
	if(nodeptr[index].key=='\0')
	{
		nodeptr[index].key=newNode->key;
		nodeptr[index].value=newNode->value;
		nodeptr[index].left = NULL;
		nodeptr[index].right = NULL;
		//count[index]++;
		//cout<<nodeptr[index].key<<endl;
		return true;
	}
	else
	{
		hashnodeIt<T1,T2> *root;
		root=&nodeptr[index];
		BST<T1,T2> b_obj;
		//b_obj.m_bstinsert()
		b_obj.m_bstinsert((bstnode<T1,T2>*)root,(bstnode<T1,T2>*)newNode);
	}
current=nodeptr;
	return 0;
}

//----------------------------------------------------------------------------------

template<class T1,class T2>
Iterator<T1,T2>::~Iterator() {
	free(newNode);
}










