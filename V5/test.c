/**
 * @file test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<string.h>
#include<dirent.h>

int main()
{
    int a[10];
    for(int i=0;i<10;i++){
        // integers:
        char str_i[20];
        fgets(str_i, 20, stdin);
        a[i] = strtol(str_i, NULL, 0);
    }
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    // printf("%d",i);
    return 0;
}