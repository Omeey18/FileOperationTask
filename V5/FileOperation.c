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
#include <time.h> 
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
    char filenameWithExatension[20]=" ";
    // to store the execution time of code
    double time_spent = 0.0;
    // print logo
    logo();
    line();
    printf("Enter File name you want to open or create: ");
    scanf("%s",filename);
    sprintf(filenameWithExatension,"%s.txt",filename);
    line();
    // getting file
    FILE *fp1 = fileCheck(&filenameWithExatension);
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
sprintf(dirname,"%s/%s",dirname,path);//OUTPUT/filename
// Creating one more directory under OUTPUT dir
create_dir(dirname);

//taken time calculated start
clock_t begin = clock();

//outer loop 
do{

    //array of file pointer
    FILE *files;
    char newfilename[20];
    //it will create filename according to counter
    sprintf(newfilename,"%s/%d.txt",dirname,i);
    files = fopen(newfilename,"w");

    int blankLine = 0; 
    //inner loop
    // reading chars from file
    do
    {
        
        ch = getc(fp1);
        // check that ENTER button is pressed or not
        if (ch == 10) // asci code of 'ENTER'
        {
            if(blankLine==0){
                remove(newfilename);
                i--;
            }
            break;
        }
        //writing char in new file
        fprintf(files,"%c",ch);
        blankLine++;
        // printf("%c", ch);
    } while (ch != EOF);
    //new file closed
    fclose(files);
    i++;
}while (ch != EOF);

    //deleting last blank file
    char blankFile[20];
    i--;
    sprintf(blankFile,"%s/%d.txt",dirname,i);
    remove(blankFile);
    printf("\n");
    line();
    printf("successfully file splited\n");
    line();
    //taken time calculated start
    clock_t end = clock();

    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n");
    line();
    printf("Total taken time is %f seconds\n", time_spent);
    line();
    //main file closed
    fclose(fp1);

    return 0;
}