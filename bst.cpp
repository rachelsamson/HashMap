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
//template<class T1,class T2>
class BST
{
public:
	template<class T1,class T2>
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
				//cout<<"Node Added To Left"<<endl;
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
				//cout<<"Node Added To Right"<<endl;
				return;
			}
		}
	}
	template<typename T1,typename T2>
	struct bstnode<T1,T2> * minValueNode( bstnode<T1,T2>* node)
	{
		struct bstnode<T1,T2>* current = node;

		/* loop down to find the leftmost leaf*/
		while (current->left != NULL)
			current = current->left;

		return current;
	}
	template<class T1,class T2>
	struct bstnode<T1,T2>* m_deleteNode(struct bstnode<T1,T2> *root, T1 key)
	{
		// base case


		// If the key to be deleted is smaller than the root's key,
		// then it lies in left subtree
		if (key < root->key)
			root->left = m_deleteNode(root->left, key);

		// If the key to be deleted is greater than the root's key,
		// then it lies in right subtree
		else if (key > root->key)
			root->right = m_deleteNode(root->right, key);

		// if key is same as root's key, then This is the node
		// to be deleted
		else
		{
			// node with only one child or no child
			if (root->left == NULL)
			{
				struct bstnode<T1,T2> *temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == NULL)
			{
				struct bstnode<T1,T2> *temp = root->left;
				free(root);
				return temp;
			}

			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			struct bstnode<T1,T2>* temp = minValueNode(root->right);

			// Copy the inorder successor's content to this node
			root->key = temp->key;

			// Delete the inorder successor
			root->right = m_deleteNode(root->right, temp->key);
		}
		return root;
	}

};
