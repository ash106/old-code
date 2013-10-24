#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
//#include <time.h>
//#include <signal.h>
#include <stdlib.h>


using namespace std;

int stdout_pipe[2];
int stdin_pipe[2];
int stderr_pipe[2];

void * outMonitor(void* pParam);
void * errMonitor(void* pParam);

sem_t semCounter;
sem_t semtime;
int main(int argc, char **argv)
{
	int num = 2;
	pthread_t *tids = new pthread_t[num];
	
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	
	void **pRetvals = new void* [num];

	pid_t secondrc;
	pid_t firstrc;
	int outReturnCode = pipe(stdout_pipe);
	int inReturnCode = pipe(stdin_pipe);
	int errReturnCode = pipe(stderr_pipe);
	int frcStatus;
	int srcStatus;
	int writeStatus;
	
	sem_init(&semtime, 0, 0);
	sem_init(&semCounter, 0, 1);

	firstrc = fork();
	if (firstrc == 0)
	{
		execl("/usr/bin/g++", "g++", argv[1], NULL);
		//execl("./g++", "g++", argv[1], NULL);
	}

	else if (firstrc > 0)
	{
		
		waitpid(firstrc, &frcStatus, 0);
	}

	else if (firstrc == -1)
	{
		std::cout << "Error on first fork" << std::endl;
	}

	pthread_create(&tids[0], &attr, outMonitor, (void*)(stdout_pipe[0]));
	pthread_create(&tids[1], &attr, errMonitor, (void*)(stderr_pipe[0]));
	
	secondrc = fork();
	if (secondrc == 0) 
	{
		dup2(stdout_pipe[1],STDOUT_FILENO);
		dup2(stdin_pipe[0],STDIN_FILENO);
		dup2(stderr_pipe[1],STDERR_FILENO);
		execl("./a.out", "a.out", NULL);
	}

	else if (secondrc == -1)
	{
		std::cout << "There was an error forking" << std::endl;
	}
	writeStatus = write(stdin_pipe[1], "5\r\n", sizeof("5\r\n"));
	struct timespec ts;
	int sem;		
	clock_gettime(CLOCK_REALTIME, &ts);
	ts.tv_sec += 10;
	sem = sem_timedwait(&semtime, &ts);
	if (sem == -1)
	{
		cout << "The program has timed out!" << endl;
		kill(0, SIGINT);
		return 0;
	}
	return 0;
}
void * outMonitor(void* pParam)
{
	const int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE];
	int totalBytes = 0;
	int kiloByte = 1024;
	int maxBytes = 100 * kiloByte;
	int outFD = (int) pParam;
	int currentBytes = 0;
	
	while (true)
	{
		//totalBytes += read(outFD, &buffer, 512);
		//cout << "OutMonitor: " << buffer << endl;
		currentBytes = read(outFD, &buffer, 512);
		sem_wait(&semCounter);
		totalBytes += currentBytes;
		cout << buffer << endl;
		sem_post(&semCounter);
		if (totalBytes >= maxBytes)
			sem_post(&semtime);//kill(-1,SIGINT);//Signal(&semtime);
	}
	
	cout << "OutMonitor went over 100 KB" << endl;
	kill(0, SIGINT);
	
	return 0;
}

void * errMonitor(void* pParam)
{
	int errFD = (int) pParam;
	int kiloByte = 1024;
	int maxBytes = 100 * kiloByte;
	int currentBytes = 0;
	const int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE];
	int totalBytes = 0;

	
	while (true)
	{
		//totalBytes += read(errFD, &buffer, 512);
		//cout << "ErrMonitor: "  << buffer << endl;
		currentBytes = read(errFD, &buffer, 512);
		sem_wait(&semCounter);
		totalBytes += currentBytes;
		cout << buffer << endl;
		sem_post(&semCounter);
		if (totalBytes >= maxBytes)
			sem_post(&semtime);//kill(-1,SIGINT);//Signal(&semtime);
			
	}
	
	cout << "ErrMonitor went over 100 KB" << endl;
	kill(0, SIGINT);
	
	return 0;
}
