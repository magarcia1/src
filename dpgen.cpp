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

//TODO: Datapath Class & header to hold vector of all components. DONE
//TODO: Component Class & header to hold--type,name,inputs,outputs,size of output, size string. DONE
//TODO: Input/Output/wire Class & header containing name string and size of input/output (includes wires). DONE

bool ReadfromFile(Datapath &DP, char* FileName) {

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
		string words[18];

		getline(input, lineString);
		istringstream inStringS(lineString);

		//parse line
		inStringS >> words[0] >> words[1] >> words[2] >> words[3] >> words[4] >> words[5] >> words[6]
			>> words[7] >> words[8] >> words[9] >> words[10] >> words[11] >> words[12] >> words[13]
			>> words [14] >> words[15] >> words[16] >> words [17];


		//TODO: Ignore Empty Lines DONE----------------------------------------------------------------------
		if (words[0] == "") {
			continue;
		}
		//TODO: Ignore // (comments) DONE---------------------------------------------------------------------
		else if (words[0] == "//") {
			continue;
		}

		//TODO: Detect Input Output Wire Statements DONE-----------------------------------------------------
		else if ((words[0] == "input") || (words[0] == "output") || (words[0] == "wire") || (words[0] == "register")) {
			Inoutput* iow;

			//Set width length
			if (words[1] == "Int2") {
				words[1] = "[1:0]";
				size = 2;
			}
			else if (words[1] == "Int1") {
				words[1] = "";
				size = 1;
			}
			else if (words[1] == "Int8") {
				words[1] = "[7:0]";
				size = 8;
			}
			else if (words[1] == "Int16") {
				words[1] = "[15:0]";
				size = 16;
			}
			else if (words[1] == "Int32") {
				words[1] = "[31:0]";
				size = 32;
			}
			else if (words[1] == "Int64") {
				words[1] = "[63:0]";
				size = 64;
			}

			//while loop to finish reading an indefinite amount of inputs/outputs listed in a lines.
			bool stop = false;

			for (int j = 0; !stop && (j <= 17); j++){

				if (words[j] == words[0] || words[j] == words[1]) { //ignore the first two words we've seen
					continue;
				}
				else if (words[j] == "") {
					stop = true;
				}
				else {
					//remove the comma if there is one in "input a, b,".
					if (words[j].back() == ','){
						words[j].pop_back();
					}

					//Create class object and insert to DP*****
					iow = new Inoutput(words[j], words[1], words[0], size);
					DP.insertPut(iow);
				}


			}

 		}

		//TODO: Detect components & create corresponding DP components---------------------------------------
		// DONE: ADD, SUB, MUL, REG, SHR, SHL, COMP
		else if (words[1] == "=") {

			int nameNumber = DP.getCompSize() + 1;

			// ADDER ****************************************************************************
			if (words[3] == "+") {
				Component* adder;
				Inoutput* a;
				Inoutput* b;
				Inoutput* c;

				stringstream CName;

				CName << "add" << nameNumber; //guarantees unique name

				adder = new Component("ADD", CName.str());

				a = DP.getInput(words[2]);
				b = DP.getInput(words[4]);
				c = DP.getOutputWire(words[0]);

				if (a == NULL || b == NULL || c == NULL) { //if the input/outputs/wire not found
					return false;
				}
				else {
					adder->insertInput(a);
					adder->insertInput(b);
					adder->setOutput(c);
					adder->setSize(c->getSizeInt());
					DP.insertComponent(adder);
				}
			}

			// SUBTRACTER ***********************************************************************
			else if (words[3] == "-") {
				Component* sub;
				Inoutput* a;
				Inoutput* b;
				Inoutput* c;
				stringstream CName;

				CName << "sub" << nameNumber; //guarantees unique name

				sub = new Component("SUB", CName.str());

				a = DP.getInput(words[2]);
				b = DP.getInput(words[4]);
				c = DP.getOutputWire(words[0]);

				if (a == NULL || b == NULL || c == NULL) { //if the input/outputs/wire not found
					return false;
				}
				else {
					sub->insertInput(a);
					sub->insertInput(b);
					sub->setOutput(c);
					sub->setSize(c->getSizeInt());
					DP.insertComponent(sub);
				}


			}

			// MULTIPLIER ***********************************************************************
			else if (words[3] == "*") {
				Component* mult;
				Inoutput* a;
				Inoutput* b;
				Inoutput* c;
				stringstream CName;

				CName << "mul" << nameNumber; //guarantees unique name

				mult = new Component("MUL", CName.str());

				a = DP.getInput(words[2]);
				b = DP.getInput(words[4]);
				c = DP.getOutputWire(words[0]);

				if (a == NULL || b == NULL || c == NULL) { //if the input/outputs/wire not found
					return false;
				}
				else {
					mult->insertInput(a);
					mult->insertInput(b);
					mult->setOutput(c);
					mult->setSize(c->getSizeInt());
					DP.insertComponent(mult);
				}

			}

			// COMPARATOR ***********************************************************************
			else if (words[3] == "<" || words[3] == ">" || words[3] == "==") {
				Component* comp;
				Inoutput* a;
				Inoutput* b;
				Inoutput* c;
				stringstream CName;

				CName << "comp" << nameNumber; //guarantees unique name

				comp = new Component("COMP", CName.str());

				a = DP.getInput(words[2]);
				b = DP.getInput(words[4]);
				c = DP.getOutputWire(words[0]);

				if (a == NULL || b == NULL || c == NULL) { //if the input/outputs/wire not found
					return false;
				}
				else {
					comp->insertInput(a);
					comp->insertInput(b);
					comp->setOutput(c);
					comp->setSize(c->getSizeInt());
					DP.insertComponent(comp);
				}


			}

			// 2X1MULTIPLEXER *******************************************************************
			//g = dLTe ? d : e                                                                  *
			//MUX2x1 #(64) mux1(e, d, dLTe, g);                                                 *
			//***********************************************************************************
			else if (words[3] == "?" && words[5] == ":") {
				Component* mux;
				Inoutput* a;
				Inoutput* b;
				Inoutput* c;
				Inoutput* d;
				stringstream CName;

				CName << "mux" << nameNumber; //guarantees unique name

				mux = new Component("MUX2X1", CName.str());

				a = DP.getInput(words[6]);
				b = DP.getInput(words[4]);
				c = DP.getInput(words[2]);
				d = DP.getOutputWire(words[0]);

				if (a == NULL || b == NULL || c == NULL || d == NULL) { //if the input/outputs/wire not found
					return false;
				}
				else {
					mux->insertInput(a);
					mux->insertInput(b);
					mux->insertInput(c);
					mux->setOutput(d);
					mux->setSize(d->getSizeInt());
					DP.insertComponent(mux);
				}


			}

			// REGISTER***************************************************************************
			if (words[3] == "") {
				Component* reg;
				Inoutput* a;
				Inoutput* b;

				stringstream CName;

				CName << "reg" << nameNumber; //guarantees unique name

				reg = new Component("REG", CName.str());

				a = DP.getInput(words[2]);
				b = DP.getOutputWire(words[0]);

				if (a == NULL || b == NULL) { //if the input/outputs/wire not found
					return false;
				}
				else {
					reg->insertInput(a);
					reg->setOutput(b);
					reg->setSize(b->getSizeInt());
					DP.insertComponent(reg);
				}
			}

			// RIGHT SHIFTER *********************************************************************
			//zrin = greg >> dEQe                                                                *
			//SHR #(64) shr1(greg, dEQe, zrin);                                                  *
			//************************************************************************************
			else if (words[3] == ">>") {
				Component* shr;
				Inoutput* a;
				Inoutput* b;
				Inoutput* c;
				stringstream CName;

				CName << "shr" << nameNumber; //guarantees unique name

				shr = new Component("SHR", CName.str());

				a = DP.getInput(words[2]);
				b = DP.getInput(words[4]);
				c = DP.getOutputWire(words[0]);

				if (a == NULL || b == NULL || c == NULL) { //if the input/outputs/wire not found
					return false;
				}
				else {
					shr->insertInput(a);
					shr->insertInput(b);
					shr->setOutput(c);
					shr->setSize(c->getSizeInt());
					DP.insertComponent(shr);
				}


			}

			// LEFT SHIFTER **********************************************************************
			////xrin = hreg << dLTe                                                              *
			//SHL #(64) shl1(hreg,dLTe,xrin);                                                    *
			//************************************************************************************
			else if (words[3] == "<<") {
				Component* shl;
				Inoutput* a;
				Inoutput* b;
				Inoutput* c;
				stringstream CName;

				CName << "shl" << nameNumber; //guarantees unique name

				shl = new Component("SHL", CName.str());

				a = DP.getInput(words[2]);
				b = DP.getInput(words[4]);
				c = DP.getOutputWire(words[0]);

				if (a == NULL || b == NULL || c == NULL) { //if the input/outputs/wire not found
					return false;
				}
				else {
					shl->insertInput(a);
					shl->insertInput(b);
					shl->setOutput(c);
					shl->setSize(c->getSizeInt());
					DP.insertComponent(shl);
				}


			}

			//ERROR*******************************************************************************
			/*else if ((words[3] != "+") || (words[3] != "-") || (words[3] != "*") || (words[3] != "<<") ||
				(words[3] != ">>") || (words[3] != "?") || (words[3] != "") ){
				cout << "Incorrect operator" << words[3] << " used.";
				return false;
			}*/
		}

		

	}

	return true;

}
