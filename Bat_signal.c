//
//  Bat_signal.c
//  Systems
//
//  Created by Theodore Fahey on 11/9/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
static void sighandler(int sig){
    if (sig == SIGINT){
        int fd = open("note.txt", O_WRONLY | O_CREAT, 0777);
        write(fd, "Program Exited Due To SIGINT", 30);
        printf("Message Written to note.txt\n");
        close(fd);
        exit(0);
    }
    if (sig == SIGUSR1){
        printf("mother ppid: %d \n", getppid());
    }
}
int main(){
    signal(SIGINT,sighandler);
    signal(SIGUSR1,sighandler);
    
    while(1){
        printf("pid: %d\n",getpid());
        sleep(1);
    }
}
