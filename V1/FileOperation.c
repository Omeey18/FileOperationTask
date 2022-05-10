#include <stdio.h>

int main()
{
    //file pointer declare 
    FILE *fp1;   
    char a;

    //file opening 
    fp1 = fopen("file.txt","r");

    //reading chars from file
    do{
        a = getc(fp1);
        //check that futher 2 char are /n or not
        if(a == 92){
             a = getc(fp1);
             if(a=='n'){
                 break;
             }else{
                fseek(fp1,-2,SEEK_CUR);
                a = getc(fp1);
             }
            break;
        }
        printf("%c",a);
    }while(a!=EOF);
   printf("\n");
   fclose(fp1);
  
        //    fprintf(evenfp,"%c ",num);
    return 0;
}