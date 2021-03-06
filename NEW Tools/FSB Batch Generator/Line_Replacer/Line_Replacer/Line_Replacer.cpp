

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>


// Ver    Date        Name
// v1.0   20.07.2019  Bartlomiej Duda


#pragma warning(disable : 4996)
using namespace std;


int replace_lines(string input_filename, string line_identifier, string replace_string)
{

	string line;
	ifstream in_file;
	ofstream out_file;
	in_file.open(input_filename);
	out_file.open(input_filename + "_NEW");
	if (in_file.is_open())
	{
		while (getline(in_file, line))
		{
			if (line.find(line_identifier) != std::string::npos)
			{
				out_file << replace_string << '\n'; //found
			}
			else
			{
				out_file << line << '\n'; //not found
			}

			
		}
		in_file.close();
		out_file.close();

		if (remove(input_filename.c_str()) != 0) //removing original file
		{
			cout << "Error: Remove operation failed" << endl;
		}
			

		if (rename((input_filename + string("_NEW")).c_str(), input_filename.c_str()) == -1) //renaming file
		{
			std::cout << "Error: " << strerror(errno) << std::endl;
		}

	}
	else 
	{ 
		cout << "Unable to open file" << input_filename << "." << endl;
	}


	return 0;
}


int main(int argc, char * argv[] )
{
	if (argc != 4)
	{
		cout << "Line Replacer by Bartlomiej Duda" << endl;
		cout << "Usage: line_replacer.exe <input_filename> <line_identifier> <replace_string>" << endl;
		cout << "Example: line_replacer.exe \"C:\\file.txt\" \"aaa\" \"bbb\"" << endl << endl;
	}
	else
	{
		replace_lines(argv[1], argv[2], argv[3]);
	}



	return 0;
}

