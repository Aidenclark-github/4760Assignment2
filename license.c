#include<sys/file.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>

#include"header.h"

int nlicenses = 0;


struct License {
    int x;
};
  
int initlicense()
{
    struct License initialize = { 0 };

    initialize.x = 0;
  
    printf("Initialized license object %d", initialize.x);
    return 0;
}
