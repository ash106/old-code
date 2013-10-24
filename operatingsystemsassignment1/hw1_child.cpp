#include<iostream>
#include<fstream>
#include<unistd.h>

using namespace std;

int main(int argc, char* argv[])
{

int pipe;
char buffer[512];
int rc;//return code
ofstream ofs (argv[1]);
pipe = atoi(argv[2]);

while(rc != 0)
{
rc = read(pipe, buffer, sizeof(buffer));
if(rc != 0)
    ofs.write(buffer, rc);
}

}