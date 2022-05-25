#include <stdio.h>
#include "header.h"


int main()
{
    char ch;

    // getting file
    FILE *fp1 = fileCheck();
    // check file is open or not
    if (!fp1)
    {
        fprintf(stderr, "[!] Failed to open the file!\n");
        return 1;
    }

//counter for creating new file
int i=1;

//Create OUTPUT folder
// char *dirname = "OUTPUT";
// // printf("Dirname: %s",dirname);
// // check_dir(dirname);
// create_dir(dirname);

//outer loop 
do{
    //array of file pointer
    FILE *files;
    char filename[20];
    //it will create filename according to counter
    sprintf(filename,"%d.txt",i);
    files = fopen(filename,"w");

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