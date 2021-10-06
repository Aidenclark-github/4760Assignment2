# 4760Assignment2
Concurrent Linux Processes and shared memory
---
**Task:**
1. runsim reads a command from stdin in each iteration of its loop and forks a child.
2. The child, in turn, forks a grandchild that calls execl and executes the application
3. The child waits for the grandchild (application) to complete and then exits
4. The program uses the bakery algorithm to control the access to license manager

**The critical resource is the license object, or the number of licenses. This will be accessed by the license object’s
public functions which now constitute the critical section.**
