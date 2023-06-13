#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    pid=vfork();
    if(pid==-1)
    {
        return 1;
    
    }else if(pid==0){
        printf("Child process:hello,i'm child!\n");
        printf("Child process:my PID is %d\n",getpid());
        printf("child process:My parent's PID is%d\n",getppid());
        _exit(0);
    }else {
        printf("Parent process:hello,i'm parent!\n");
        printf("parent process:my PID is %d\n",getpid());
        printf("parent process:My child's PID is%d\n",pid);
        int status;
        waitpid(pid,&status,0);
        if(WIFEXITED(status)){
            printf("parent process:Child process terminated normally.\n");
        }else{
            printf("Parent process:Child process terminated abnormally.\n");
        }
    }
}