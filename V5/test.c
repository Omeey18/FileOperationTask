/**
 * @file removeDir.c
 * @author Om Patel (ompatel1861@gmail.com)
 * @brief This program will remove non empty directory.  
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<string.h>
#include<dirent.h>

int main()
{
    DIR* dir = opendir("OUTPUT/Aakash");
     
    struct dirent* entity;
    entity = readdir(dir);
    while(entity != NULL){
        char path[30] ="OUTPUT/Aakash/";
        printf("%s\n",entity->d_name);
        strcat(path,entity->d_name);
        printf("PAth: %s\n",path);
        remove(path);
        entity = readdir(dir);
    }
    char path1[30] ="OUTPUT/Aakash";
    rmdir(path1);
    closedir(dir);
    char out[20]="OUTPUT/";
                char fol_file[30];
            sprintf(fol_file,"%s\\",out);
            printf("%s",fol_file);
    return 0;
}