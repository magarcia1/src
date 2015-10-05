// Author: Rubi Ballesteros and Miguel Garcia
// Date Created: 26 September 2015
//
// Description: Main controlling a program that translates circuit pseudo code into
//				a syntatically correct verilog implementation.
//------------------------------------------------------------------------------------------------

#include <iostream>
#include <sstream>
#include "dpgen.h"
#include "Datapath.h"

//------------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	Datapath DPComponents;
	//TODO: Check for correct input. DONE !
	if (argc != 2) {
		cout << "\nUsage:" << argv[0] << " inputFile inputFile \n";
		return -1;
	}
	//TODO: Create a file
	if (!ReadfromFile(DPComponents, argv[1])) {
		cout << "Could not finish reading the file due to the errors listed above." << endl;
		return -2;
	}

	return 0;
}
