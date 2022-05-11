#include <stdio.h>
#include<stdlib.h>
#include<string.h>


FILE* fileCheck(void){
    char check[20],data[1000];
    FILE *fp;
    printf("Enter File name you want to open or create: ");
    scanf("%s",check);
    
    
    if(fp = fopen(check,"r")){
        printf("file exists\n");
        return fp;
    }else{
        fp = fopen(check,"w+");
        if(fp){
            printf("\nNew File created..\n");
            printf("\nEnter Data here:\n ");
            scanf("%[^\n]",data);
            // fflush(stdin);
            // gets();
            
            fprintf(fp, "%s\n", data);
            return fp;
        }else{
            printf("File is not created\n");
        }
        
    }
    return NULL;
}


int main()
{
      
    char ch;

    //getting file
    FILE *fp1 = fileCheck();
    //check file is open or not 
    if (!fp1)
    {
        fprintf(stderr, "[!] Failed to open the file!\n");
        return 1;
    } 


    //reading chars from file
    do{
        ch = getc(fp1);
        //check that futher 2 char are \n or not
        if(ch == 92)//asci code of '\'
        {
             ch = getc(fp1);
             if(ch=='n'){
                 break;
             }else{
                fseek(fp1,-2,SEEK_CUR);
                ch = getc(fp1);
             }
        }
        printf("%c",ch);
    }while(ch!=EOF);
   printf("\n");
   fclose(fp1);

    return 0;
}