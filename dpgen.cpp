//------------------------------------------------------------------------------------------------
//
// Author: Rubi Ballesteros and 
// Date Created: 13 November 2013
//
// Description: General code for a binary search tree that does not handle the case of duplicate key insertions.
//				This tree is sorted based on the order of the ASCII representaion of words "varName"
//------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include "dpgen.h"
#include "Inoutput.h"

//TODO: Datapath Class & header to hold vector of all components.
//TODO: Component Class & header to hold--type,name,inputs,outputs,size of output, size string.
//TODO: Input/Output Class & header containing name string and size of input/output (includes wires).

bool ReadfromFile(Datapath &DP, char* FileName) {
	string one;
	string two;
	string three;
	string four;
	string five;
	string six;
	string seven; // longest line has seven "words"

	string command;
	string  lineString;
	ifstream input;

	int size; // in bits

	input.open(FileName);

	if (!input.is_open()) {
		cout << "Could not open file " << FileName << "\n";
		return false;
	}

	while (!input.eof()) {
		//Note: all words are separated by spaces.

		getline(input, lineString);
		istringstream inStringS(lineString);

		inStringS >> one >> two >> three >> four >> five;

		istringstream StringS1(two); // further parse a "word"
		istringstream StringS2(four);
		istringstream StringS3(five);

		//TODO: Ignore Empty Lines
		if (one == "") {
			continue;
		}
		//TODO: Ignore // (comments)
		else if (one == "//") {
			continue;
		}
		//TODO: Detect Input Output Wire Statements
		else if ((one == "input") || (one == "output") || (one == "wire")) {
			Inoutput* iow;

			//Set width length
			if (two == "Int2") {
				two = "[1:0]";
				size = 2;
			}
			else if (two == "Int8") {
				two = "[7:0]";
				size = 8;
			}
			else if (two == "Int16") {
				two = "[15:0]";
				size = 16;
			}
			else if (two == "Int32") {
				two = "[31:0]";
				size = 32;
			}
			else if (two == "Int64") {
				two = "[63:0]";
				size = 64;
			}

			//Create class object and insert to DP*****
			iow = new Inoutput(three, two, one, size);
			DP.insertPut(iow);
 		}

		//TODO: Detect Wires DONE ABOVE----
		//--------

		//TODO: Detect Components & create corresponding DP components
		else {


		}


	}


}
