#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // To create both the parent and child pipe and open them
    mkfifo("parentP",0644);
    mkfifo("childP",0644);
    int parentP = open("parentP",O_RDONLY);
    int childP = open("childP", O_WRONLY);

    // Prompt Input
    char userIn[1000];
    // to constantly ask for input
    while (1) {
        printf("Input please 0_0:");
        fgets(userIn, 1000, stdin);
        // writes in the user input to the child pipe
        write(childP, userIn, sizeof(userIn));
        // child pipe sends response to parent pipe
        read(parentP, userIn, sizeof(userIn));
        //sleep(1);
        printf("Processed Input: %s\n", userIn); 
    }
    return 0;
}