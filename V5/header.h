#ifndef HEADER_H
#define HEADER_H
/*function declaration.*/
void line();
void logo();
void setBlueColor();
void setDefaultColor();
void enterData(FILE *fp);
FILE *fileCheck(char *filename);
void create_dir(char *dirname);
void check_dir(char dirname);

#endif //HEADER_H