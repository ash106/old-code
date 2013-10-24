#include<string>
#ifndef PASSWORD_H
#define PASSWORD_H
using namespace std;

class Password
{
		private:
				string password;		

		public:
				//Constructor
				Password();
				
				int check(string password);

				int compare(string password, string filePassword);
		

		

};

#endif
