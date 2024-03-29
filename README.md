
<iimg style="width: 1200px; height: 150px;" src="https://linuxreviews.org/images/7/7f/Kernel-coding-style-new-speak-rules.jpg" align="middle"  />

#  CS 4760: Project 2 - Concurrent Linux Processes and shared memory
* [Project Requirements](https://umsystem.instructure.com/courses/21098/assignments/975262)
---
## Relavent Information:
**Using the Makefile:**
1. `make`: will compile the prgram. 
2. `./runsim (number of processes) < testing data`: will run the program. 
3. `make clean`: will clean the Makefile. 

**Task:**
1. runsim reads a command from stdin in each iteration of its loop and forks a child.
2. The child, in turn, forks a grandchild that calls execl and executes the application
3. The child waits for the grandchild (application) to complete and then exits
4. The program uses the bakery algorithm to control the access to license manager

**The critical resource is the license object, or the number of licenses. This will be accessed by the license object’s
public functions which now constitute the critical section.**

## Resources Used: 
Book: 
* Unix™ Systems Programming: Communication, Concurrency, and Threads
* By Kay A. Robbins, Steven Robbins


Creating the Makefile:
* https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

Helpful Links:
* https://stackoverflow.com/questions/44435549/how-to-make-getopt-long-print-nothing-when-there-is-error-command-line-argumen
* https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm
* https://www.java-samples.com/showtutorial.php?tutorialid=597
* https://stackoverflow.com/questions/17509479/switch-case-for-parsing-options

## Submission Note: 
I found myself scambling and looking up lots of stuff on the internet. For future projects maybe more coding demonstrations from yourself. They help me out personally and I think the rest of the class would enjoy them. Additionally, I had lots of trouble trying to implement the bakery algorithm. 
