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
	hashmap<int,structvalue>::Iterator<int,structvalue> iter1;
	hashmap<int,structvalue>::Iterator<int,structvalue> iter2;
	hasmap<int,structvalue> hash1;

	//To check for != operator giving static values
	hashmap<T1,T2>::iter2.newNode->m_key=5;
	hashmap<T1,T2>::iter2.newNode->m_value.a='b';
	hashmap<T1,T2>::iter2.newNode->m_value.number=4;
	//--------------------------------------
	int count=0;
	for(char j='A';j<'Z';j++)
	{
		ex.a=j;
		ex.number=int(j);
		count++;
		hash1.insert(count,ex);//Insers an entry on hashmap
	}

	hash1.remove(4);//Deletes an entry on hashmap

	ex.a='1';
	ex.number=100;
	hash1.findandInsert(5,ex);//Finds and if not then inserts the key and value

	cout<<"\nTotal entries into hashmap "<<iter1.size();//Total entries into hasmap

	hash1.getNumberOfCollisionPerSlot(3);//collisions at input slot

	cout<<"\nTotal collisions "<<hash1.getTotalNumberOfCollision()<<endl;//total no of collisions in the hashmap

	//!= operator---------------------------------
	int opoverload=hashmap<T1,T2>::iter1!=hashmap<T1,T2>::iter2;cout<<opoverload;
	cout<<"Operator!= Result "<<opoverload;
	//----------------------------------------
	hashmap<T1,T2>::iter1.newNode->m_value=hashmap<T1,T2>::iter1[22];//Returns value on the specified index


	hashmap<T1,T2>::iter1.newNode->m_key=++iter1;
	cout<<hashmap<T1,T2>::iter1.newNode->m_key;
	//Increments the pointer to where the current points

	hashmap<T1,T2>::iter1.begin();//Returns first entry into hashmap


	hashmap<T1,T2>::iter1.end();//Returns last entry into hashmap

	hashmap<T1,T2>::iter1.get(4);//Returns value for the specified


	hashmap<T1,T2>::iter1.getKeys();//Returns all the keys in the hashmap
	cout<<"\nListing all keys\n "<<endl;
	for(int i=0;i<26;i++)
	{
		cout<<hashmap<T1,T2>::iter1.arr[i]<<endl;
	}
	return 0;
}


