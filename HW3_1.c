#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        // Read cmdline args from user for file location
        FILE *fp = fopen(argv[1], "r");

        // Check if there is a file
        if (fp == NULL)
        {
            printf("ERROR Opening File!\n");
            exit(1);
        }

        // Move to EOF
        fseek(fp, 0, SEEK_END);

        // Store value for EOF location (How many bytes until EOF)
        int eof = ftell(fp);

        fclose(fp);

        // Print info to user
        printf("The file ‘%s’ is %d bytes in size.\n", argv[1], eof);
    }

    // Error handling for incorrect number of args
    else if (argc > 2)
    {
        printf("Too many arguments supplied.\n");
    }
    else
    {
        printf("Please supply an argument. (ie. 'filename')\n");
    }

    return 0;
}