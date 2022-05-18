#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//It will enter user data to new file
void enterData(FILE *fp)
{
    //buffer to store user's data
    char data[100] = "";
    printf("\nEnter Data here:\n ");
    //writing data until 'END'
    while (1)
    {
        /* code */
        scanf("%s", data);
        if (strcmp(data, "END"))
        {
            fprintf(fp, "%s ", data);
        }else{
            break;
        }
    }
}

//It will check file is their or not 
FILE *fileCheck(void)
{

    char check[20];
    FILE *fp;
    //asking file name 
    printf("Enter File name you want to open or create: ");
    scanf("%s", check);

    //if file is already their then it will return file pointer
    if (fp = fopen(check, "r"))
    {
        printf("file exists\n");
        return fp;
    }
    //it will create new file and ask data
    else
    {
        if (fp = fopen(check, "w+"))
        {
            printf("\nNew File created..\n");
            enterData(fp);
            rewind(fp);
            return fp;
        }
        else
        {
            printf("File is not created\n");
        }
    }
    return NULL;
}