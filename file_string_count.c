#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS   1000



int main()
{
    FILE *fptr;
    char path[100];
    int i, len, index, isUnique;
    char words[MAX_WORDS][50];
    char word[50];
    /* Count of distinct words */
    /* int  count[MAX_WORDS]; */
    int *count = calloc(MAX_WORDS, sizeof(int));
    /* Input file path */
    printf("Enter file path: ");
    scanf("%s", path);


    /* Try to open file */
    fptr = fopen(path, "r");

    /* Exit if file not opened successfully */
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read previleges.\n");

        exit(EXIT_FAILURE);
    }
/*    for (i=0; i<MAX_WORDS; i++)
        count[i] = 0;*/




    index = 0;

    while (fscanf(fptr, "%s", word) != EOF)
    {
        
        for(int i = 0; word[i]; i++){
          word[i] = tolower(word[i]);
        }
        len = strlen(word);
        if (ispunct(word[len - 1]))
            word[len - 1] = '\0';

        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(words[i], word) == 0)
                isUnique = 0;
        }
        if (isUnique) 
        {
            strcpy(words[index], word);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }
    fclose(fptr);
    printf("\nOccurrences of all distinct words in file: \n");
    for (i=0; i<index; i++)
    {  /*
        * %-15s prints string in 15 character width.
        *          * - is used to print string left align inside
        *                   * 15 character width space.
        *                            */
        printf("%-15s => %d\n", words[i], count[i]);
    }    


    return 0;
}
