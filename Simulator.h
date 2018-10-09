/*
 * Simulator.h
 *
 */

#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include "Dice.h"
#include <cmath>

class Simulator{
public:
	Simulator(int number_of_simulations, int number_of_rolls_per_simulation, int faces_of_dice);
	~Simulator();


	void calculate() const;

	void simulate();
private:
	bool high;
	int stake_multiplier;
	const int number_of_simulations;
	const int number_of_rolls_per_simulation;
	int* max_losing_streaks;
	int* max_winning_streaks;
	Dice* dice;
};




#endif /* SIMULATOR_H_ */
