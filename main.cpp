#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector <int> memory;

int main()
{
	// initialization
	ifstream fin ("program.oa");
	string command;

	// main loop
	while (!fin.eof())
	{
		//fetch
		getline(fin, command);
		//execute
		if (command.substr(0, 3) == "SET")
        {
        	//remove "SET"
		    command.erase(0, 4);
		}
	}

	return 0;
}