#include <stdio.h>
#include<string.h>
#include "header.h"


int main()
{
    char ch;
    char filename[20];
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
// printf("PAth: %s\n",path);
sprintf(dirname,"%s/%s",dirname,path);
// printf("Dirname: %s",dirname);
create_dir(dirname);

//outer loop 
do{
    //array of file pointer
    FILE *files;
    char newfilename[20];
    //it will create filename according to counter
    sprintf(newfilename,"%s/%d.txt",dirname,i);
    // strcat(newfilename,dirname);
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