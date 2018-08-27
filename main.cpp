#include"Iterator.h"
#include"Iterator.cpp"
#define LAST 20
using namespace std;
struct structvalue
{
	char a;
	int number;
}ex;
int main() {
	Iterator<int,structvalue> iter1;
	Iterator<int,structvalue> iter2;
	Iterator<int,structvalue> iter3;
	Iterator<int,int> iter4;

	iter2.newNode->m_key=5;
	iter2.newNode->m_value.a='b';
	iter2.newNode->m_value.number=4;

	int count=0;

	for(char j='A';j<'E';j++)
	{
		ex.a=j;
		ex.number=int(j);
		count++;
		iter1.insert(count,ex);
	}

	iter1.remove(4);//Deletes an entry on hashmap

	ex.a='1';
	ex.number=100;
	iter1.findandInsert(5,ex);

	cout<<"\nTotal entries into hashmap\n "<<iter1.size();

	iter1.getNumberOfCollisionPerSlot(3);

	cout<<"\nTotal collisions "<<iter1.getTotalNumberOfCollision()<<endl;

	int opoverload=iter1!=iter2;cout<<opoverload;
	cout<<"Operator!= Result "<<opoverload;
	iter1.newNode->m_value=iter1[22];//Returns value on the specified index


			iter1.newNode->m_key=++iter1;
			cout<<iter1.newNode->m_key;
			//Increments the pointer to where the current points

	iter1.begin();//Returns first entry into hashmap


	iter1.end();//Returns last entry into hashmap

	iter1.get(4);
	iter1.get(3);


	iter1.getKeys();//Returns all the keys in the hashmap
	//cout<<"\nListing all keys\n "<<endl;

	for(int i=0;i<26;i++)
	{

		cout<<iter1.arr[i]<<endl;
	}
	return 0;
}


