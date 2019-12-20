#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// initialization
	ifstream fin ("program.oa");
	string command;

	// main loop
	while (!fin.eof())
	{
		//fetch
		fin >> command;
		//execute
		
	}

	return 0;
}