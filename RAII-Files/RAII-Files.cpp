#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

class OpenFile {
public:
	OpenFile(char const * filename) {
		file_.open(filename);
	}

	~OpenFile() {
		file_.close();
		//std::cout << "The file is closed\n";
	}

	void write(std::string const & s) {
		file_ << s;
		//throw("Just to make a test");
	}

private:
	std::ofstream file_;
};

int main() {
	// Option 1 - the classic way
	std::ofstream myfile1;
	myfile1.open("example1.txt");
	myfile1 << "Writing into a txt file.\n";
	myfile1.close();
	
	// Option 2 - with RAII
	OpenFile myfile2("example2.txt");
	myfile2.write("Writing in a safe txt file.\n");
	myfile2.write("Writing again in a safe txt file.\n");
	return 0;
}