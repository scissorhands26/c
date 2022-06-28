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

        // Go to EOF to see how long it is
        fseek(fp, 0, SEEK_END);
        int filesize = ftell(fp);

        // Go back to the beginning of the file to read it
        fseek(fp, 0, SEEK_SET);

        // Set up content buffer with NULL char
        char content[filesize];
        content[filesize] = '\0';

        // Read file and close it
        fread(content, filesize, 1, fp);
        fclose(fp);

        // Print the file contents to the user
        printf("%s", content);
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