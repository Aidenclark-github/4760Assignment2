/*
Main Program 

*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

/* main function */
int main ( int argc, char *argv[] )
{

    if ( argc != 2 ) /* argument count should be 2 for execution */
    {
        /* print argv[0] */
        printf( "Error: %s filename", argv[0] );
        exit(1);
    }




