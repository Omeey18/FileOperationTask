#include <stdio.h>
#include <stdlib.h>
#include <string.h>



FILE *enterData(FILE *fp)
{
    char data[1000] = "";
    printf("\nEnter Data here:\n ");
    while (strcmp(data, "END"))
    {
        /* code */
        scanf("%s", data);
        if (strcmp(data, "END"))
        {
            fprintf(fp, "%s ", data);
        }
    }
    // fgets(data, 1000, stdin);
    return fp;
}

FILE *fileCheck(void)
{
    char check[20];
    FILE *fp;
    printf("Enter File name you want to open or create: ");
    scanf("%s", check);
    fflush(stdin);

    if (fp = fopen(check, "r"))
    {
        printf("file exists\n");
        return fp;
    }
    else
    {

        if (fp = fopen(check, "w+"))
        {
            printf("\nNew File created..\n");
            // printf("\nEnter Data here:\n ");
            // scanf("%[^\n]s",data);
            // gets();
            fp = enterData(fp);
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
int i=1;
//outer loop 
do{
    FILE *files[100];
    char filename[20];
    sprintf(filename,"%d.txt",i);
    files[i] = fopen(filename,"w");

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
        fprintf(files[i],"%c",ch);
        printf("%c", ch);
    } while (ch != EOF);
    fclose(files[i]);
    i++;
}while (ch != EOF);

    printf("\n");
    fclose(fp1);

    return 0;
}