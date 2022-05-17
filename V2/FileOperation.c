#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
        // check that futher 2 char are \n or not
        if (ch == 92) // asci code of '\'
        {
            ch = getc(fp1);
            if (ch == 'n')
            {
                break;
            }
            else
            {
                fseek(fp1, -2, SEEK_CUR);
                ch = getc(fp1);
            }
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