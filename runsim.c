/*
Main Program 
runsim.c
To run: runsim (number of processes (L) < testing.data)

*/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/file.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include <sys/wait.h>

#include "header.h"

#define MAX_CANON 5
#define SHM_SIZE 1024
extern int nlicenses;

int shmid;
key_t key;

void deallocateSharedMemory (int sh)
{
    shmctl(sh, IPC_RMID, NULL); 
    perror("runsim Eoror: shmctl (shared memory error)");
    exit(1);
}

void docommand (char* str);



/* main function */
int main ( int argc, char *argv[] ) 
{
    if ( argc != 2 ) /* argument count should be 2 for execution */
    {
        printf( "Error: %s filename", argv[0] );
        perror("runsim Error: argc (argument count error)");
        exit(1);
    }
    int licenseNUMBER = atoi(argv[1]);
    if ( initlicense() != 0)
    {
        perror("runsim Error: initlicense (initialize license error)");

        exit(1);    
    }
    nlicenses = licenseNUMBER;
    
    /* creating segment for data space */
    int * sharedMemory;
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) 
    {
        perror("runsim Error: shmget (shared memory error)");
        exit(1);
    }
     /* attaching segment for data space */
    if ((sharedMemory = shmat(shmid, NULL, 0)) == (int *) -1) 
    {
        perror("runsim Error: shmget (shared memory error)");
        /* send to deallocate function */
        deallocateSharedMemory(shmid);
        exit(1);
    }
    /* populate with the number of licenses */
    *sharedMemory = nlicenses;
    
    char buffer[MAX_CANON];
    int status;
    printf("Request a license: \n");
    /* read lines from standard input up to the number of MAX_CANON characters
    using fges */
    while(fgets(buffer, MAX_CANON , stdin) != NULL)
    {
        getlicense();
        
        pid_t  pid, return_pid;
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
            return_pid = waitpid(pid, &status, WNOHANG);
            if (return_pid == -1)
            {
                perror("runsim Error: fork  and waitpid");    
            } 
            else  
            {
                returnlicense();    
            }    
        }
        /* father code that waits for child code to finsih */
        while ((return_pid = wait(&status)) > 0);
        {
            deallocateSharedMemory(shmid);
        }
        return 0;
    }
}

/* docommand will  request  license  
from  license  manager  object.
Notice if  license is not available, 
the request function will go into wait state. */
void docommand (char* str)
{
    getlicense();
    char* argv = str;
    execl(argv[0], argv);   
}


