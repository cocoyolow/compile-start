#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//simple script to automatically compile ( if not compiled ) and run c programs with gcc
char * concatenate(const char *start,const char *end); 
char * strip_end(const char *s); 

int main(int argc, char *argv[]) {
    for (int i=1; i<argc; i++) {

        char *c = strip_end(argv[i]);
        char *d = concatenate(c,argv[i]);
        system(d);
        free(d);
    }
}

char * strip_end(const char *s)  {
    
    int len = strlen(s);
    char *new_c = malloc(len + 1); // len + 1 for the '\0'
    if (!new_c) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == '.') { // check if there is a dot (start of the 'c' extension)
            new_c[i] = '\0'; // Null-terminate at dot
            return new_c;
        }
        new_c[i] = s[i];
    }
    new_c[len] = '\0'; // If no dot found
    return new_c;
}

char * concatenate(const char *end,const char *start) {
    int needed_size = strlen(start) + strlen(end) + 25;
    char *command = malloc(needed_size); // allocate memory for the command
    if (!command) {
        fprintf(stderr, "Error : memory allocation failed \n"); // error message
        exit(1); //leave the program
    }
    snprintf(command, needed_size, "gcc %s -o %s && ./%s", start, end, end);// remove the ./ if your using windows
    return command;
}
    

