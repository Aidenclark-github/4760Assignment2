extern int nlicenses;

/* Blocks until license is available */
int getlicense(void);

/* Increments number of licenses available  */
int returnlicense(void);

/* Performs needed initialization of license object */
int initlicense(void);

/* Adds "L" licenses to number available */
void addtolicenses(int L);

/* Decrements  number of licenses by "L" */
void removelicenses(int L); 

/* Write specified message to log file  */
void logmsg(const char * msg); 

