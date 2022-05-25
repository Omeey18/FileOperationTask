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

    char filename[20];
    FILE *fp;
    char path[50]="INPUT/";
    //asking file name 
    printf("Enter File name you want to open or create: ");
    scanf("%s", filename);
    strcat(path,filename);
    // printf("file: %s\n",path);

    //if file is already their then it will return file pointer
    if (fp = fopen(path, "r"))
    {
        printf("file exists\n");
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
void create_dir(const char* dirname){
    // int dir;
    // // char* dirname = DIRNAME;
    // dir = mkdir(dirname,0777);
    // // check if directory is created or not
    // if (!dir)
    //     printf("Directory created\n");
    // else {
    //     printf("Unable to create directory\n");
    //     exit(1);

    // }
    #ifdef __linux__
       mkdir(dirname, 777); 
    #else
       _mkdir(dirname);
   #endif
}

