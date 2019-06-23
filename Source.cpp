#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		system("pause");
		return 1;
	}
	else {
		ifstream inputFile;
		ofstream outputFile;
		inputFile.open(argv[1]);
		outputFile.open(argv[2]);
		if (inputFile.is_open() && outputFile.is_open()) {
			cout << "Files opened successfuly \n";
		}
		else {
			cout << "Unexpected error occured while opening files, please try again. \n";
			return 1;
		}
		List lst;
		lst.In(inputFile);
		outputFile << "Filled container. " << endl;
		lst.Out(outputFile);
		lst.Clear();
		outputFile << "Empty container: " << endl;
		lst.Out(outputFile);
		cout << "Stop" << endl;
		system("pause");
	}
	return 0;
}