//communication through b) message passing 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include<string.h>
#include<sys/msg.h>

struct msg_buffer
{
    long msg_type;
    char msg_text[1000];
}message;

int main()
{
    key_t key;
    int msgid;
    key = ftok("progfile",65);
    msgid = msgget(key,0666 | IPC_CREAT);
    message.msg_type = 1;
    if(fork() == 0)
    {
        strcpy(message.msg_text,"Message from child");
        msgsnd(msgid,&message,sizeof(message),0);
    }
    else
    {
        msgrcv(msgid,&message,sizeof(message.msg_text),1,0);
        printf("parent read: %s\n", message.msg_text);
        msgctl(msgid,IPC_RMID,NULL);
    }
    return 0;
}