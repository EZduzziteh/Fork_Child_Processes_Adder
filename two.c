
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


/*(50 pts) Write a C program that forks a number of children specified as the first parameter on the
command line. The child processes do not need to be executed concurrently. Each forked child should
execute a program that is specified as the second parameter on the command line. In fact, the executed
program will be the one that you created in the first question! If no parameters are specified, display an
appropriate usage.
Each forked child should display it's PID and the output of its execution of program “one” on a single line.
Have each child provide a random number of arguments to “one” (at least one and no more than 10).
Each argument must be a random integer from 0 through 99.
Here is sample output that your program should be able to produce (after gcc -o two two.c):
~$ ./two
Usage: ./two <num_proc> <executable>
e.g., ./two 4 ./one
~$ ./two 1 ./one
In child 32520: The sum of 25 42 92 91 is 250
~$ ./two 4 ./one
In child 32525: The sum of 21 32 55 63 59 is 230
In child 32526: The sum of 44 1 59 29 52 92 32 78 50 is 437
In child 32527: The sum of 9 27 35 91 is 162
In child 32528: The sum of 57 51 12 43 30 50 43 54 72 is 412
It may very well be that strdup, atoi, srand, rand, snprintf, fflush, and execvp are your friends.
You may safely assume that I will not try to specify invalid parameters at the command line.

*/

int main(int argc, char* argv[])
{

    //printf("amount of processes: %s\n",argv[1]);
   // printf("random number: %d\n", rand() % 100);
    for (int i = 0; i < atoi(argv[1]); i++) {
        int id = fork();
        if (id == 0) {
            //child

        //initialize the randomizer with a seed based on the current time as well as current process ID, so we get different random numbers.
            time_t currentTime;
            srand((unsigned)time(&currentTime) * getpid());

            fflush(stderr);
            printf("In child %d: \n", getpid());
            fflush(stderr);
            int argAmount = (rand() % 9) + 2; //get number from 1 - 10  
            //**Note, about the requirements I assumed no more than 10 included the "./one",
            // so we can have a maximum of 9 numeric inputs as well as 1 input for the program name.
            //if the intention was to have 10 numerical inputs as well as another one for the "./one", replace the 9 with a 10 in the random function.
            char* newargs[argAmount + 2];
            newargs[0] = "./one";
            for (int j = 1; j < argAmount; j++) {
                int randomNum = rand() % 100;//get number from 0 - 99
                if (asprintf(&newargs[j], "%d", randomNum) == -1) {
                    perror("asprintf");
                    exit(EXIT_FAILURE);
                }
            }
            newargs[argAmount] = NULL;


            fflush(stderr);
            execvp("./one", newargs);
            perror("execvp");
            exit(EXIT_FAILURE);

        }
    }

    exit(0);
}