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
    // create_dir(dirname); 

printf(
"     ___       _              ___           _       _    _                   \n"
"    (  _`\\  _ (_ )           (  _`\\        (_ )  _ ( )_ ( )_                 \n"
"    | (_(_)(_) | |    __     | (_(_) _ _    | | (_)| ,_)| ,_)   __   _ __    \n"
"    |  _)  | | | |  /'__`\\   `\\__ \\ ( '_`\\  | | | || |  | |   /'__`\\( '__)   \n"
"    | |    | | | | (  ___/   ( )_) || (_) ) | | | || |_ | |_ (  ___/| |      \n"
"    (_)    (_)(___)`\\____)   `\\____)| ,__/'(___)(_)`\\__)`\\__)`\\____)(_)      \n"
"                                    | |                                      \n"
"                                    (_)                                      \n"
"\n");


    return 0;
}