
#include <stdio.h>
#include <stdlib.h>


/*(30 pts) Write a C program (one.c) that displays the sum of the arguments specified at the command line. If
no parameters are specified, display an appropriate usage.
Here is sample output that your program should be able to produce (after gcc -o one one.c):
~$ ./one
Usage: ./one val [val [ ... ] ] e.g., ./one 17 49 3 466
~$ ./one 123
The sum of 123 is 123
~$ ./one 1 2 3
 The sum of 1 2 3 is 6

 ~$ ./one 10 32 2 1 45
 The sum of 10 32 2 1 45 is 90*/



int main(int argc, char* argv[])
{
    fflush(stderr);
    if (argc <= 1) {
        printf("No arguments were specified in the command line!\n");
        exit(0);
    }

    int sum = 0;
    printf("The sum of ");
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
        sum = sum + atoi(argv[i]);
    }
    printf("is %d\n", sum);
    fflush(stderr);

    exit(0);
}