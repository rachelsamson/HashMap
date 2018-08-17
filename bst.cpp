#include<iostream>
#include<stdlib.h>
#define BSTARRAYMAX 21

//static int count;
using namespace std;
template<class T1,class T2>
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
	int i;
		int KeyArray[BSTARRAYMAX];
		bstnode<T1,T2> tempTree;

		BST(){
		for(i=0;i<BSTARRAYMAX;i++)
			KeyArray[i]=0;
			i=0;
		}
	//template<class T1,class T2>
	void m_bstinsert(bstnode<T1,T2> *tree, bstnode<T1,T2> *newnode)
	{
		if (tree->key > newnode->key)
		{
			if (tree->left != NULL)
			{
				//count++;
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
	//template<typename T1,typename T2>
	struct bstnode<T1,T2> * minValueNode( bstnode<T1,T2>* node)
	{
		struct bstnode<T1,T2>* current = node;

		/* loop down to find the leftmost leaf*/
		while (current->left != NULL)
			current = current->left;

		return current;
	}
	//template<class T1,class T2>
	struct bstnode<T1,T2>* m_deleteNode( bstnode<T1,T2> *root, T1 key)
	{
		// base case
		if (root == NULL) return root;

		// If the key to be deleted is smaller than the root's key,
		// then it lies in left subtree
		if (key < root->key)

			root->left = m_deleteNode(root->left, key);
		//printf("%x updated",temp);

		// If the key to be deleted is greater than the root's key,
		// then it lies in right subtree
		else if (key > root->key)
			root->right = m_deleteNode(root->right, key);

		// if key is same as root's key, then This is the node
		// to be deleted
		else
		{
			struct bstnode<T1,T2> *temp =new struct bstnode<T1,T2>;
			// node with no child
			if(root->left==NULL && root->right==NULL)
			{
				root=NULL;
				//return root;
			}
			// node with only one child
			else if (root->left == NULL)
			{

				temp=root;
				root=root->right;
				temp=NULL;
			}
			else if (root->right == NULL)
			{
				temp=root;
				root=root->left;
				temp=NULL;
			}
			else
			{

				// node with two children: Get the inorder successor (smallest
						// in the right subtree)
				temp=minValueNode(root->right);
				//struct bstnode<T1,T2>* temp = minValueNode(root->right);

				// Copy the inorder successor's content to this node
				root->key = temp->key;

				// Delete the inorder successor
				root->right = m_deleteNode(root->right, temp->key);
			}
		}
		return root;
	}
	//template<class T1,class T2>
	T2 m_bstsearch(struct bstnode<T1,T2> *root,T1 key,T2 value)
	{
		// Base Cases: root is null or key is present at root
		if (root == NULL)
			return 0;
		else if(root->key==key)
			return root->value;

		// Key is greater than root's key
		if (root->key < key)
			return m_bstsearch(root->right, key,value);

		// Key is smaller than root's key
		return m_bstsearch(root->left, key,value);


	}

	//template<class T1,class T2>
	T1* inorder(struct bstnode<T1,T2> *root)
	{



		while(root!=NULL)
		{
		if (root->key !='\0'&&root!=NULL)
		{

			tempTree.key=root->key;
			tempTree.value=root->value;
			tempTree.left=root->left;
			tempTree.right=root->right;
	        inorder(root->left);
	        KeyArray[i++]=root->key;
	       // if(i>21700)
	       // cout<<i<<" index"<<"   root->key --"<<root->key<<"root->value---------" <<root->value<<endl;
	        inorder(root->right);
	          return KeyArray;

	    }
	   }
	 return KeyArray;
	}


//	template<class T1,class T2>
	T2 m_bstsearch(struct bstnode<T1,T2> * root, int key)

	{
		//struct bstnode<T1,T2>* root=rootnode;
	    // Base Cases: root is null or key is present at root
	    if ( root!=NULL||root->key== key)
	       return root->value;

	    // Key is greater than root's key
	    if (root->key < key)
	       return search(root->right, key);

	    // Key is smaller than root's key
	    return search(root->left, key);
	}

};
