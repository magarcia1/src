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
#include "Component.h"


//------------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------------------------

Component::Component() {
	this->type = "none";
	this->name = "default";
	this->output = NULL;
	this->sizeoOutput = 0;

}
Component::Component(string atype, string aname) {
	this->type = atype;
	this->name = aname;
	this->output = NULL;
	this->sizeoOutput = 0;
}

Component::~Component() {

}


void Component::setType(string type) {
	this->type = type;
}

void Component::setName(string name) {
	this->name = name;
}

void Component::insertInput(Inoutput* anInput) {
	this->inputs.push_back(anInput);
}

void Component::setOutput(Inoutput* anOutput) {
	this->output = anOutput;
}

void Component::setSize(int theSize) {
	this->sizeoOutput = theSize;
}

string Component::getType() {
	return this->type;
}

string Component::getName() {
	return this->name;
}

Inoutput* Component::getInput(int i) {
	return this->inputs.at(i);
}

Inoutput* Component::getOutput() {
	return this->output;
}

int Component::getSize() {
	return this->sizeoOutput;

}
//------------------------------------------------------------------------------------------------