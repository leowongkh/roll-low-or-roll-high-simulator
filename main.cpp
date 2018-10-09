/*
 * main.cpp
 *
 */


#include <iostream>
#include "Dice.h"
#include "Simulator.h"
#include <ctime>
using namespace std;

int main(){
	srand(0);

	char input = 'p';

	while (input != 'q'){
		cout << "Running Simulations..." << endl;
		Simulator* simulator = new Simulator(1000,100000000,1000);
		simulator->simulate();
		simulator->calculate();
		delete simulator;
		cout << "Type 'q' and Press ENTER to exit,\n or type other key and Press ENTER to run another simulation" << endl;
		cin >> input;
	}

	return 0;
}

