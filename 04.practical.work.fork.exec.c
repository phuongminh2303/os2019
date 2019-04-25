#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
	printf("Main before fork()\n");
	// ps -ef
	int pid = fork();
	if(pid == 0){
		printf("I am child after fork(), launching ps -ef\n");
		char *args[] = { "/bin/ps", "-ef", NULL};
		execvp("/bin/ps", args);
		printf("Finished launching ps -ef\n");
	}
	else {
	waitpid(pid, NULL, 0);
		// free -h
		int pid2 = fork();
		if(pid2 == 0){
			printf("I am child after fork(), lanching free -h\n");
			char *args2[] = { "/usr/bin/free", "-h", NULL};
			execvp("/usr/bin/free", args2);
			printf("Finsish launching free -h\n");
		} else{
			printf("I am parent after fork(), child is %d\n", pid2);
			waitpid(pid2, NULL, 0);
		}
	}
	return 0;
}
