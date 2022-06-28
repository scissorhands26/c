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

        // Loop over content of file until all of it is read and printed (as hex)
        do
        {
            fread(content, 1, 100, fp);
            printf("%02X", content);
        } while (ftell(fp) < filesize);

        // Close file
        printf("\n");
        fclose(fp);
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