#include <stdio.h>
#include<errno.h>


void create_dir(char *dirname){
    if(mkdir(dirname,0777)==-1){
        perror("error");
        printf("Error creating dir...!\n");
    }
}

int main()
{
    char dirname[] = "OUTPUT/file";
    create_dir(dirname); 
    return 0;
}