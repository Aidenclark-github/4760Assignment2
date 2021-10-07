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

/* Blocks until license is available */
int getlicense() 
{
    printf("Blocking license until it is available. \n");
    while (nlicenses <= 0);
    removelicenses(1);
    return(0);
}

/* Increments number of licenses available  */
int returnlicense() 
{   
    addtolicenses(1);
    return(0);
}

/* Adds "L" licenses to number available */
void addtolicenses (int L)
{
    /* Increment */
    nlicenses += L;
    printf("Licenses available:", nlicenses);
    
}

void removelicenses (int L)
{
    /* Increment */
    nlicenses -= L;
    printf("Licenses available:", nlicenses);
}

void logmsg(const char * msg)
{
    char* filename = "data.log";
    
    FILE *fp;
    fp = fopen (filename, "w");
    fprintf(fp, "Logged Messages: ");
}
