#include<iostream>
#include<unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
int pipes[2];
int rc;
char buffer[512];

rc = pipe(pipes);


rc = fork();
if(rc < 0)
{
cout << " error" << endl;
return 1;
}
if(rc == 0)
{

	sprintf(buffer, "%d", pipes[1]);
	execl("./creader.cpp", "reader", argv[1],  buffer, NULL);
	cout << " first execl(...reader...) failed" << endl;
	return 1;
}

rc = fork();
if (rc < 0)
{
	//error
}
if(rc == 0)
{
 
	sprintf(buffer, "%d", pipes[0]);
	execl("./cwriter.cpp", "writer", argv[2],  buffer, NULL);
	cout << " first execl(...writer...) failed" << endl;
	return 1;	
}
rc = wait(NULL);
rc = wait(NULL);
return 0;
}
