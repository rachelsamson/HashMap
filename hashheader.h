/*
 * hashheader.h
 *
 *  Created on: Jul 22, 2018
 *      Author: raviiv
 */

#ifndef HASHHEADER_H_
#define HASHHEADER_H_
//template<typename T>
struct node
	{
		int key;
		node *left,*right;
	};
class hashnode
{
private:
	node *root;
	void Print_all(node *);
public:
	hashnode();
	virtual ~hashnode();
	bool IsEmpty(node *newNode);
	bool Insert(node *);
	bool Delete(int);
	struct node create_node(int);
	void insert_node(struct node*);
	void Print_one(node *);
	void PrintTree();
	void SearchTree(int);

};




#endif /* HASHHEADER_H_ */
