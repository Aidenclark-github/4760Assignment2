extern int nlicenses;

/* Blocks until license is available */
int getlicense(void);

/* Increments number of licenses available  */
int returnlicense(void);

/* Performs needed initialization of license object */
int initlicense(void);

/* Adds "n: licenses to number available */
void addtolicenses(int n);

/* Decrements  number of licenses by "n" */
void removelicenses(int n); 

/* Write specified message to log file  */
void logmsg(const char * msg); 

