#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Ask the user to enter a string
    char string[50] = {0};
    printf("Please enter a string: ");
    scanf("%[^\n]%*c", &string);

    // Open file for writing
    FILE *fp;
    if ((fp = fopen("outfile.txt", "w+")) == NULL)
    {
        printf("ERROR Opening Output File\n");
        exit(1);
    }

    fwrite(&string, 1, sizeof(string), fp);
    fclose(fp);
    printf("Total Written Data: %d\n", string);

    return 0;
}