//============================================================================
// Name        : IteratorCheck.cpp
// Author      : rachel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <thread>

#include"Iterator.h"
#include"Iterator.cpp"
#define LAST 30

using namespace std;

int main() {

	thread threads[LAST];

	Iterator<int, int> iter1;
	Iterator<int, int> iter2;

	iter2.newNode->m_key = 12;
	iter2.newNode->m_value = 10;

	int value = 12;
	for (int i = 0; i <30; i++) {
		int key = i;
		if(i%5==1)
		threads[i] = std::thread(&Iterator<int, int>::insert, &iter1, key,value);

		if(i%5==2)
		threads[i] = std::thread(&Iterator<int, int>::get, &iter1,3);

		if(i%5==3)
		threads[i] = std::thread(&Iterator<int, int>::getKeys, &iter1);

		if(i%5==4)
		threads[i] = std::thread(&Iterator<int, int>::remove, &iter1,key);

		if(i%5==0)
			cout<<"this";
		//threads[i] = std::thread(&Iterator<int, int>::g, &iter1, key);

	}

	//thread1();
	 	 for (int i = 0; i < LAST; i++) {
	 		threads[i].join();
	 	}

	 iter1[6];
	++iter1;



	return 0;
}

/*




 #include<iostream>

 void thread_function()
 {
 std::cout<<"Inside Thread :: ID  = "<<std::this_thread::get_id()<<std::endl;
 }
 int main()
 {
 std::thread threadObj1(thread_function
 std::thread threadObj2(thread_function);

 if(threadObj1.get_id() != threadObj2.get_id())
 std::cout<<"Both Threads have different IDs"<<std::endl;

 std::cout<<"From Main Thread :: ID of Thread 1 = "<<threadObj1.get_id()<<std::endl;
 std::cout<<"From Main Thread :: ID of Thread 2 = "<<threadObj2.get_id()<<std::endl;

 threadObj1.join();
 threadObj2.join();
 return 0;
 }


 */
