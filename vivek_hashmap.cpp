/*
 * hashmap.cpp
 *
 *  Created on: Jul 17, 2018
 *      Author: raviiv
 */
//Checking for errors
#include "vivek_hashmap.h"

#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

hashmapfunction::hashmapfunction()
{
	string K;

		MD5 md5;
	char *x,*inputh;
	char *fixedh;
			char hex[] = "A0";
			char last[] = "AD";
			char input[] = "AB";
			char fixed[] = "00";

			const char* ch;
			char* arr;

			char arr2[17];

			// md5.Update();
		//	cout<<("%s is hashofinput\n", inputh);

		arr = md5.digestString(K);
		int ascii=(int)arr[0];
ch = arr;
		cout<<arr<< "is hashof arr old hash\n";
				cout<<"\n this is ascii value of the digest \n"<<ascii;

		memcpy(arr, arr2, 16);
			inputh = md5.digestString(input);
			cout<<" is hashof arr new hash\n"<<arr2;
				cout<<" is hashof new hash\n"<<ch;

			cout<<" is hashofinput\n"<< inputh;


			char buffer[2];

			int num = (int)strtol(arr, NULL,16);
		 	cout<<" is converted of number\n"<< num;
			num = num + 1;
			cout<<" is incremented of number\n"<< num;
			itoa(num, arr, 8);
			cout<<" is converted from int to hex\n"<< hex;

			if (strcmp(hex, last)!=0)
			{
				cout<<"not equal ";
			}
			else
			{
				cout<< "equal \n";
			}

			//int i;
}


