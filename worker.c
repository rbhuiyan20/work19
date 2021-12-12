#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>


int main() {
    // opens up the parent and child pipe
    int parentP = open("parentP",O_WRONLY);
    int childP = open("childP", O_RDONLY);
    
    // input is 1k characters max 
    char userIn[1000];
    // loop to read from parent pipe, iterates through input, and send the response back to the parent pipe
    while (1) {
        read(childP, userIn, sizeof(userIn)); 

        // simple for loop to iterate through the character ray containing the input and turns the characters into uppercase
        int i;
        for(i=0; i<strlen(userIn); i++) {
            userIn[i] = tolower(userIn[i]);
        }
        //gives processed input to parent pipe
        write(parentP, userIn, sizeof(userIn)); 
    }
    return 0;
}