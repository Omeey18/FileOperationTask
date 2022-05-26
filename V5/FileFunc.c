/**
 * @file FileFunc.c
 * @author Om Patel (Om.Patel@einfochips.com)
 * @brief This file has all functions which are used in FileOperation.c 
 * @version 0.4
 * @date 2022-05-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */


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
* FUNCTION BODY
****************************************/

/**
 * @brief It will take data from user and store it in file 
 * 
 * @param fp 
 */
void enterData(FILE *fp)
{
    //buffer to store user's data
    char *data = malloc(sizeof(char)*1000);
    line();
    printf("-----[NOTE]: write END in new line to complete your file-----\n");
    printf("Enter Data here:\n ");
    line();
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
    free(data);
}


/**
 * @brief It will check file is there or not. 
 * If file is not there than It will create new file 
 * 
 * @param filename 
 * @return FILE* 
 */
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
        line();
        printf("Do you want to create new or not {Y/N}: ");
        char check;
        fflush(stdout);
        scanf(" %c", &check);
        line();
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


/**
 * @brief Create a new dir if it not there 
 * 
 * @param dirname 
 */
void create_dir(char *dirname){
    mkdir(dirname,0777);
}


/**
 * @brief It will print logo 
 * 
 */
void logo(){
    printf("\n\n"
"---------------------------------------------------------------------------------\n"    
"     ___       _              ___           _       _    _                   \n"
"    (  _`\\  _ (_ )           (  _`\\        (_ )  _ ( )_ ( )_                 \n"
"    | (_(_)(_) | |    __     | (_(_) _ _    | | (_)| ,_)| ,_)   __   _ __    \n"
"    |  _)  | | | |  /'__`\\   `\\__ \\ ( '_`\\  | | | || |  | |   /'__`\\( '__)   \n"
"    | |    | | | | (  ___/   ( )_) || (_) ) | | | || |_ | |_ (  ___/| |      \n"
"    (_)    (_)(___)`\\____)   `\\____)| ,__/'(___)(_)`\\__)`\\__)`\\____)(_)      \n"
"                                    | |                                      \n"
"                                    (_)                                      \n"
"---------------------------------------------------------------------------------"
"\n\n\n");

}
/**
 * @brief print one line
 * 
 */
void line(){
    printf("---------------------------------------------------------------------------------\n");

}