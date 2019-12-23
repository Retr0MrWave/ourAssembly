#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>

using namespace std;

const int MEMORY_LEN = 65536;
int memory[MEMORY_LEN] = {0};

vector<int> split(string& nums_str)
{
	//split string "123 848 -55" etc for numbers
	vector<int> numbers;
	istringstream stream(nums_str);
	string s;
	while (stream >> s)
	{
		if (s[0] == '&')
			s.erase(0, 1);
		numbers.push_back(stoi(s));
	}
	return numbers;
}

int main()
{
	// initialization
	ifstream fin ("program.oa");
	string command;

	//command syntax templates
	regex set("^SET \\d+ &\\d+$|^SET -\\d+ &\\d+$");
	regex add("^ADD \\d+ &\\d+$|^ADD -\\d+ &\\d+$");
	regex mult("^MULT \\d+ &\\d+$|^ADD -\\d+ &\\d+$");	regex div("^DIV \\d+ &\\d+$|^ADD -\\d+ &\\d+$");

	// main loop
	//fetch in loop condition
	while (getline(fin, command))
	{
		//decode-execute
		if (regex_match(command, set))
        {
			//decode
			command.erase(0, 4);
			vector<int> args = split(command);
			int value = args[0];
			int adress = args[1];
			//execute
			if (adress > MEMORY_LEN-1)
			{
				cout << "IndexOutOfError: Cell in memory with this index doesn`t exist" << endl;
				break;
			}
			else memory[adress] = value;
		}
		else if (regex_match(command, add))
		{
			//decode
			command.erase(0, 4);
			vector<int> args = split(command);
			int value = args[0];
			int adress = args[1];
			//execute
			if (adress > MEMORY_LEN-1)
			{
				cout << "IndexOutOfError: Cell in memory with this index doesn`t exist" << endl;
				break;
			}
			else memory[adress] += value;
		}
		else if (regex_match(command, mult))
		{
			//decode
			command.erase(0, 4);
			vector<int> args = split(command);
			int value = args[0];
			int adress = args[1];
			//execute
			if (adress > MEMORY_LEN-1)
			{
				cout << "IndexOutOfError: Cell in memory with this index doesn`t exist" << endl;
				break;
			}
			else memory[adress] *= value;
		}
		else if (regex_match(command, div))
		{
			//decode
			command.erase(0, 4);
			vector<int> args = split(command);
			int value = args[0];
			int adress = args[1];
			//execute
			if (adress > MEMORY_LEN-1)
			{
				cout << "IndexOutOfError: Cell in memory with this index doesn`t exist" << endl;
				break;
			}
			else memory[adress] /= value;
		}
		else
		{
			cout << "CompilationError: Undefined function:\"" + command + "\"";
			break;
		}
	}

	return 0;
}