
#ifndef ITERATORBST_H_
#define ITERATORBST_H_
#define MAX 50





template <class T1,class T2>

class Iterator {
private:
	struct Node
		{
			typedef T1 Key;
			typedef T2 Value;

			Node *right;
			Node *left;
		    Node *next;
		    int index;


		};
	  Node *current;
	  Node *temp;
	  Node lnode[MAX];	int index;
	  int count=0;


public:

	 Iterator();
	 Iterator(T1,T2,Node*);
	 typename Iterator<T1,T2>::Node m_begin();
	 typename Iterator<T1,T2>::Node m_end();
	 int size();
		typename Iterator<T1,T2>::Node* search(struct node * root, int key);

	// int inorder(struct Node*);

	T1* m_getKeys();
	T2& m_get(T1 key);
	T1 operator++(const T1 key);
	bool operator!=(struct Node node);
	//bool operator!=(struct Node node,struct Node node);

	typename Iterator<T1,T2>::Node* operator*(struct Node * node);
	int* inorder(struct Node * node);
	T2 operator[](int index);
	virtual ~Iterator();
public:
	  static T1 KeyArray[50];
};

#endif /* ITERATORBST_H_ */
