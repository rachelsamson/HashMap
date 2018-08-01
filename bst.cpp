#include<iostream>
#include<stdlib.h>
using namespace std;
template<typename T1,typename T2>
struct bstnode
{
	T1 key;
	T2 value;
	bstnode<T1,T2> *left,*right;

};
template<class T1,class T2>
class BST
{
public:
	void m_bstinsert(bstnode<T1,T2> *tree, bstnode<T1,T2> *newnode)
	{
		if (tree->key > newnode->key)
		{
			if (tree->left != NULL)
			{
				m_bstinsert(tree->left, newnode);
			}
			else
			{
				tree->left = newnode;
				(tree->left)->left = NULL;
				(tree->left)->right = NULL;
				cout<<"Node Added To Left"<<endl;
				return;
			}
		}
		else
		{
			if (tree->right != NULL)
			{
				m_bstinsert(tree->right, newnode);
			}
			else
			{
				tree->right = newnode;
				(tree->right)->left = NULL;
				(tree->right)->right = NULL;
				cout<<"Node Added To Right"<<endl;
				return;
			}
		}
	}
};
