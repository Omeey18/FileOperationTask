/**
 * @file FileFunc.c
 * @author Om Patel (Om.Patel@einfochips.com)
 * @brief This file has all functions which are used in FileOperation.c 
 * @version 0.5
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
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


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
    setBlueColor();
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
    char out[20]="OUTPUT/";//path of output dir
    //asking file name 
    // printf("filename : %s\n",filename);   
    strcat(path,filename);//path=INPUT/filename.txt
    char * token = strtok(filename, ".");//token=filename {.txt removed}
    strcat(out,token);//out=OUTPUT/filename
    // printf("out: %s\n",out);

    //check dir is there or not
    DIR* dir = opendir(out);
    if (dir) {
        /* Directory exists. */
        //deleting directory
            struct dirent* entity;
            char fol_file[50];
            sprintf(fol_file,"%s/",out);//fil_file=OUTPUT/filename/
            // printf("fol_file: %s\n",fol_file);
            entity = readdir(dir);
            while(entity != NULL){
                // printf("%s\n",entity->d_name);
                char temp[50];
                strcpy(temp,fol_file);//temp=OUTPUT/filename/
                strcat(temp,entity->d_name);//temp=OUTPUT/filename/somthing.txt
                // printf("temp: %s\n",temp);
                remove(temp);//remove file {OUTPUT/filename/somthing.txt}
                entity = readdir(dir);//read new file of that dir
            }
            rmdir(out);//remove empty directory
            closedir(dir);//close dir
    } else if (ENOENT == errno) {
        /* Directory does not exist. */
    } 
    //if file is already their then it will return file pointer
    if (fp = fopen(path, "r"))
    {
        setBlueColor();
        printf("file already exists\n");
        line();
        setBlueColor();
        printf("Do you want to add new data or not {Y/N}: ");
        char check;
        fflush(stdout);
        scanf(" %c", &check);
        line();
        if(check=='Y' || check=='y'){
             
            if (remove(path) == 0) {
                setBlueColor();
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
            setBlueColor();
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
    setRedColor();
    printf("\n\n"
"---------------------------------------------------------------------------------\n"
"---------------------------------------------------------------------------------\n");
setBlueColor();
printf(    
"     ___       _              ___           _       _    _                   \n"
"    (  _`\\  _ (_ )           (  _`\\        (_ )  _ ( )_ ( )_                 \n"
"    | (_(_)(_) | |    __     | (_(_) _ _    | | (_)| ,_)| ,_)   __   _ __    \n"
"    |  _)  | | | |  /'__`\\   `\\__ \\ ( '_`\\  | | | || |  | |   /'__`\\( '__)   \n"
"    | |    | | | | (  ___/   ( )_) || (_) ) | | | || |_ | |_ (  ___/| |      \n"
"    (_)    (_)(___)`\\____)   `\\____)| ,__/'(___)(_)`\\__)`\\__)`\\____)(_)      \n"
"                                    | |                                      \n"
"                                    (_)                                      \n");
setRedColor();
printf(
"---------------------------------------------------------------------------------\n"
"---------------------------------------------------------------------------------"
"\n\n\n");
setDefaultColor();
}
/**
 * @brief print one line
 * 
 */
void line(){
    printf("\033[1;33m");//switchign color to yellow
    printf("---------------------------------------------------------------------------------\n");
    printf("\033[0m");//switchign color to default
}
/**
 * @brief Set the Blue Color object
 * 
 */
void setBlueColor(){
    printf("\033[1;34m");//switchign color to blue
}
/**
 * @brief Set the Default Color object
 * 
 */
void setDefaultColor(){
    printf("\033[0m");//switchign color to default
}
void setRedColor(){
    printf("\033[1;31m");//switchign color to red
}