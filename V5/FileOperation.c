
/**
 * @file FileOperation.c
 * @author Om Patel (Om.Patel@einfochips.com)
 * @brief This will spilt one txt file to number of txt file in respective OUTPUT directory
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
#include<string.h>
#include "header.h"


/***************************************
* MAIN FUNCTION
****************************************/

/**
 * @brief main funcation
 * 
 * @return int 
 */
int main()
{
    char ch;
    char filename[20];
    logo();
    printf("Enter File name you want to open or create: ");
    scanf("%s",filename);
    // printf("filename : %s\n",filename);
    // getting file
    FILE *fp1 = fileCheck(&filename);
    // check file is open or not
    if (!fp1)
    {
        fprintf(stderr, "[!] Failed to open the file!\n");
        return 1;
    }

//counter for creating new file
int i=1;

//Create OUTPUT folder
char dirname[] = "OUTPUT";
create_dir(dirname);
char path[20];
strcpy(path,filename);
sprintf(dirname,"%s/%s",dirname,path);
// Creating one more directory under OUTPUT dir
create_dir(dirname);

//outer loop 
do{
    //array of file pointer
    FILE *files;
    char newfilename[20];
    //it will create filename according to counter
    sprintf(newfilename,"%s/%d.txt",dirname,i);
    files = fopen(newfilename,"w");

    //inner loop
    // reading chars from file
    do
    {
        ch = getc(fp1);
        // check that ENTER button is pressed or not
        if (ch == 10) // asci code of 'ENTER'
        {
            break;
        }
        //writing char in new file
        fprintf(files,"%c",ch);
        // printf("%c", ch);
    } while (ch != EOF);
    //new file closed
    fclose(files);
    i++;
}while (ch != EOF);

    printf("\n");
    //main file closed
    fclose(fp1);

    return 0;
}