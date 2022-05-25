/***************************************
* INCLUDES
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include <dirent.h>
#include <errno.h>

/***************************************
* MACROS
****************************************/

/***************************************
* GLOBAL
****************************************/

/***************************************
* INCLUDES
****************************************/

/***************************************
* FUNCTION BODY
****************************************/
//It will enter user data to new file
void enterData(FILE *fp)
{
    //buffer to store user's data
    char data[1000] = "";
    printf("\nEnter Data here:\n ");
    //writing data until 'END'
    while (1)
    {
        /* code */
        scanf(" %[^\n]%*c", data);
        if (strcmp(data, "END"))
        {
            fprintf(fp, "%s\n", data);

        }
        else{
            break;
        }
    }
}


//It will check file is their or not 
FILE *fileCheck(char *filename)
{
    FILE *fp;
    char path[50]="INPUT/";
    //asking file name 
    // printf("filename : %s\n",filename);   
    strcat(path,filename);
    // printf("file: %s\n",path);

    //if file is already their then it will return file pointer
    if (fp = fopen(path, "r"))
    {
        printf("file already exists\n");
        printf("Do you want to create new or not {Y/N}: ");
        char check;
        fflush(stdout);
        scanf(" %c", &check);
        if(check=='Y' ||check=='y'){
            if (remove(path) == 0) {
                printf("The file is deleted successfully.");
                fclose(fp);
                 if (fp = fopen(path, "w+"))
                    {
                        printf("\nNew File created..\n");
                        enterData(fp);
                        rewind(fp);
                    }
                    else
                    {
                        printf("File is not created\n");
                    }
            } else {
                printf("The file is not deleted.");
            }
        }
        return fp;
    }
    //it will create new file and ask data
    else
    {
        if (fp = fopen(path, "w+"))
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

//it will check directory is their or not 
void check_dir(char dirname){
 
    DIR* dir = opendir(dirname);
    if (dir) {
        /* Directory exists. */
        printf("Directory is exists\n");
        closedir(dir);
    } else if (ENOENT == errno) {
        /* Directory does not exist. */
        printf("calling create dir fun\n");
        create_dir(dirname);
    } else {
        /* opendir() failed for some other reason. */
        printf("-----Failed to open %d directory-----\n",dirname);
    }

}

//It will create new folder called OUTPUT
void create_dir(char *dirname){
    mkdir(dirname,0777);
}