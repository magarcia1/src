//------------------------------------------------------------------------------------------------
//
// Author: Rubi Ballesteros and Miguel Garcia
// Date Created: September 2013
//
// Description: General code for a datapath.
//------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include "dpgen.h"
#include "Datapath.h"


Datapath::Datapath() {

}
Datapath::~Datapath() {

}

void Datapath::insertPut(Inoutput* iow) {
	if (iow->getType() == "input") {
		inputs.push_back(iow);
	}
	else if (iow->getType() == "ouput") {
		outputs.push_back(iow);
	}
	else if (iow->getType() == "wire") {
		wires.push_back(iow);
	}
}

void Datapath::insertComponent(Component* dpcomp) {
	this->components.push_back(dpcomp);
}

Inoutput* Datapath::getInput(string name) {
	Inoutput* current;
	for (int i = 0; i < inputs.size(); i++) {
		current = inputs.at(i);
		if (name == current->getName()) {
			return current;
		}
	}

	cout << "The input " << name << "specified does not matched the inputs declared.\n Program terminated.";
	return NULL;
}

Inoutput* Datapath::getOutputWire(string name) {
	Inoutput* current;
	for (int i = 0; i < wires.size(); i++) {
		current = wires.at(i);
		if (name == current->getName()) {
			return current;
		}
	}

	for (int i = 0; i < outputs.size(); i++) {
		current = outputs.at(i);
		if (name == current->getName()) {
			return current;
		}
	}

	cout << "The wire/output " << name << "specified does not matched the inputs declared.\n Program terminated.";
	return NULL;

}