#include<iostream>
#include<unistd.h>
#include<fstream>

using namespace std;

int main(int argc, char* argv[])
{

int pipe;
int rc;
char buffer[512];
ifstream its(argv[1]);
pipe = atoi(argv[2]);
while(rc != 0){
its.read(buffer, sizeof(buffer));
if(rc != 0)
write(pipe, buffer, its.gcount());
}
close(pipe);
return 0;
}