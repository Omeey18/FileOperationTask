
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include"shm1.h"int main(){
int id;
id = shmget(48,250,IPC_CREAT|0644);//ks
if(id<0){
perror("shmget");
return 0;
}
printf("id=%d\n",id);
s.p = shmat(id,0,0);//pas---user space
printf("%s",s.p);
s.p = s.p-1;
s.p = shmat(id,0,0);
//printf("enter the data: ");
//scanf("%s",p);
return 0;
}

