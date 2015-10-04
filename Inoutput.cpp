
//------------------------------------------------------------------------------------------------
//
// Author: Rubi Ballesteros and Miguel Garcia
// Date Created: September 2015
//
// Description:  General input/output/wire
//------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include "Inoutput.h"


//------------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------------------------

Inoutput::Inoutput() {
	this->size = 0;
}
Inoutput::Inoutput(string nameString, string sizeSpecString, string type, int sizeInteger) {
	this->name = nameString;
	this->getSizeSpec = sizeSpecString;
	this->size = sizeInteger;
	this->type = type;

}
Inoutput::~Inoutput() {
	//done in datapath.h/.c
}

string Inoutput::getName(){
	return this->name;

}
string Inoutput::getSizeSpec() {
	return this->sizeSpec;

}
int Inoutput::getSizeInt() {
	return this->size;
}
string Inoutput::getType() {
	return this->type;
}