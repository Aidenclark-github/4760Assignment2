/*
Main Program 

*/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/file.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include "header.h"

#define MAX_CANON 5
#define SHM_SIZE 1024
extern int nlicenses;

int shmid;
key_t key;

void deallocateSharedMemory (int sh)
{
    shmctl(sh, IPC_RMID, NULL); 
    exit(1);
}

void docommand (char* str);



/* main function */
int main ( int argc, char *argv[] ) 
{
    if ( argc != 2 ) /* argument count should be 2 for execution */
    {
        printf( "Error: %s filename", argv[0] );
        exit(1);
    }
    int licenseNUMBER = atoi(argv[1]);
    if ( initlicense() != 0)
    {
        printf( "Error: initlicense()");
        exit(1);    
    }
    nlicenses = licenseNUMBER;
    
    /* creating segment for data space */
    int * sharedMemory;
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) 
    {
        perror("shmget");
        exit(1);
    }
     /* attaching segment for data space */
    if ((sharedMemory = shmat(shmid, NULL, 0)) == (int *) -1) 
    {
        perror("shmat");
        /* send to deallocate function */
        deallocateSharedMemory(shmid);
        exit(1);
    }
    /* populate with the number of licenses */
    *sharedMemory = nlicenses;
    
    char buffer[MAX_CANON];
    printf("Request a license: \n");
    /* read lines from standard input up to the number of MAX_CANON characters
    using fges */
    while(fgets(buffer, MAX_CANON , stdin) != NULL)
    {
        //getlicense();
        
        pid_t  pid;
        pid = fork();
        if ( pid == 0)
        {
            /* child process */
            docommand(buffer);
            exit(0);
        }
        else
        {
            /* parent process */ 
            printf("Error");
        }
    }
    return 0;
}

/* docommandwill  request  a  license  
from  the  license  manager  object.
Notice thatg if the license is notg available, 
the request function will go into a wait state. */
void docommand (char* str)
{
    getlicense();
    char** argv = str;
    execl(argv[0], argv);
    
    
}


