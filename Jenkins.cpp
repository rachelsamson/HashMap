//============================================================================
// Name        : Jenkins.cpp
// Author      : rachel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include<iostream>
//#include "mongoose.h"
//#include "main.h"
#include <stdint.h>
using namespace std;

#define JHASH_GOLDEN_RATIO  0x9e3779b9
                #define __jhash_mix(a, b, c) \
                { \
                  a -= b; a -= c; a ^= (c>>13); \
                  b -= c; b -= a; b ^= (a<<8); \
                  c -= a; c -= b; c ^= (b>>13); \
                  a -= b; a -= c; a ^= (c>>12);  \
                  b -= c; b -= a; b ^= (a<<16); \
                  c -= a; c -= b; c ^= (b>>5); \
                  a -= b; a -= c; a ^= (c>>3);  \
                  b -= c; b -= a; b ^= (a<<10); \
                  c -= a; c -= b; c ^= (b>>15); \
                }


                //JenkinsHash is standard opensource code for calculatin hash function
                static inline uint32_t JenkinsHash(const uint32_t * k,uint32_t length,uint32_t initval)
                {
                  uint32_t a, b, c, len;


                  a = b = JHASH_GOLDEN_RATIO;
                  c = initval;
                  len = length;


                  while (len >= 3)
                  {
                    a += k[0];
                    b += k[1];
                    c += k[2];
                    __jhash_mix(a, b, c);
                    k += 3;
                    len -= 3;
                  }


                  c += length * 4;


                  switch (len)
                  {
                    case 2:
                      b += k[1];
                    case 1:
                      a += k[0];
                  };


                  __jhash_mix(a, b, c);


                  return c;
                }


               int main()
                {
                 const uint32_t stringVal[]={0,9,55,29283};
                 int lenght=( sizeof(stringVal)/sizeof(uint32_t));

                 uint32_t ABC=JenkinsHash(stringVal,lenght, 33);
                 int index=(ABC/100000000)/2;


                                printf("%u\n",ABC);
                                printf("%d",index);


		        return 0;

                }
