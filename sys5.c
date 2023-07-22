#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int Pipes[2];
pid_t subprocess;

int main(int argc, char** argv) {

	char* hello_massege = "Hello child process.";

	pipe(Pipes);
	printf("you just send a %s by a first pipe\n", hello_massege);
	write(Pipes[1], hello_massege, strlen(hello_massege));

	subprocess = fork();
	if (subprocess == 0) {

		char* massege = (char*)malloc(30);
		char* answer_massege = "Hi parent process.";

		read(Pipes[0], massege, 50);
		printf("child process get: %s\n", massege);

		write(Pipes[1], answer_massege, strlen(answer_massege));
		//exit(EXIT_SUCCESS);
	}
	else {
		char answer[30];
		wait();
		read(Pipes[0], answer, 30);
		printf("you just get the massege: %s from child process\n", answer);
		return 0;
		
	}
}

