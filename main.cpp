#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
using namespace std;

const int MEMORY_LEN = 65536;
int memory[MEMORY_LEN];

int main()
{
	// initialization
	ifstream fin ("program.oa");
	string command;

	//command syntax templates
	regex set("^SET \\d+ &\\d+$|^SET -\\d+ &\\d+$");

	// main loop
	//fetch in loop condition
	while (getline(fin, command))
	{
		//execute
		if (regex_match(command, set))
        {
			command.erase(0, 4);
			stringstream value_str, adress_str;
			int value, adress;
			//slpit command to value and address
			istringstream c_stream(command);
			string s;
			c_stream >> s;
			value = stoi(s);
			c_stream >> s;
			//remove "&"
			s.erase(0, 1);
			adress = stoi(s);

			if (adress > MEMORY_LEN-1)
				cout << "Error: Cell in memory with this index doesn`t exist" << endl;
			else memory[adress] = value;			
		}
	}

	return 0;
}