// firstly create a.txt with cmd => 'cat > a.txt' on terminal , write some content in it
#include <stdio.h>      // printf, fgets
#include <string.h>     // strcmp, strcpy, sscanf
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // waitpid
#include <fcntl.h>      // open
#include <stdlib.h>     // exit
#include <unistd.h>     // fork, read, close


// Global buffers for command and tokens
char ss[40], tok1[10], tok2[10], tok3[10], tok4[10];
pid_t pid;
char ch[1], ch1[100];

// Function to separate command string into tokens
// Example: "count c a.txt" → tok1="count", tok2="c", tok3="a.txt"
void sep() {
    strcpy(tok1, "\0");
    strcpy(tok2, "\0");
    strcpy(tok3, "\0");
    strcpy(tok4, "\0");
    
    sscanf(ss, "%s%s%s%s", tok1, tok2, tok3, tok4);
}

// Function to implement the 'count' command
// count c filename → count characters
// count w filename → count words
// count l filename → count lines
void count() {
    int cc = 0, wc = 0, lc = 0;   // counters for characters, words, lines
    int fp;
    fp = open(tok3, O_RDONLY);   // open file passed in tok3

    if(fp == -1) {
        printf("Error opening file\n");
    } else {
        while(read(fp, ch, 1) != 0) {   // read file one character at a time
            printf("%c", ch[0]);        // print the file content (echo)

            // Count words: here you count wc on space/newline/tab
            // (⚠️ not fully accurate, but works roughly)
            if(ch[0] == ' ' || ch[0] == '\n' || ch[0] == '\t')
                wc++;
            else
                cc++;

            // Count lines
            if(ch[0] == '\n')
                lc++;
        }
        close(fp);

        // Check which option user passed (tok2) and display result
        if (strcmp(tok2, "c") == 0)
            printf("Total no of characters = %d\n", cc);
        else if (strcmp(tok2, "w") == 0)
            printf("Total no of words = %d\n", wc);
        else if (strcmp(tok2, "l") == 0)
            printf("Total no of lines = %d\n", lc);
        else if (strcmp(tok2, "cw") == 0)
            printf("Total no of characters = %d & words = %d\n", cc, wc);
        else if (strcmp(tok2, "cl") == 0)
            printf("Total no of characters = %d & lines = %d\n", cc, lc);
        else if (strcmp(tok2, "wl") == 0)
            printf("Total no of words = %d & lines = %d\n", wc, lc);
        else if (strcmp(tok2, "cwl") == 0)
            printf("Total no of characters = %d, words = %d & lines = %d\n", cc, wc, lc);
    }
}

int main() {
    while(1) {
        // Display prompt
        printf("myshell$");

        // Take user input (⚠️ gets() is unsafe, use fgets() ideally)
        gets(ss);

        // Split input into tokens
        sep();

        // Create child process
        pid = fork();

        if(pid == 0) {   // child process
            if(strcmp(tok1, "count") == 0)
                count();   // call count function

            else if(strcmp(tok1, "exit") == 0)
                exit(0);   // terminate child if 'exit'

            else
                printf("Bad command\n");   // invalid command

            exit(0);   // child exits after executing
        }
        else if(pid != 0) {   // parent process
            waitpid(pid, NULL, 0);  // wait for child to finish
            printf("\n parent process completed\n");

            // ⚠️ Your bug: exit(0) here kills the parent → shell ends after 1 command
            // Remove the exit(0) so shell runs continuously
            // exit(0);
        }
    }
}
