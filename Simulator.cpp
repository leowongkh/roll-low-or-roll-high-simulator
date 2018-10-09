/*
 * Simulator.cpp
 *
 */


#include "Simulator.h"
#include <iostream>
using namespace std;

Simulator::Simulator(int number_of_simulations, int number_of_rolls_per_simulation, int faces_of_dice):number_of_simulations(number_of_simulations),
		number_of_rolls_per_simulation(number_of_rolls_per_simulation){
	max_losing_streaks = new int[this->number_of_simulations];
	max_winning_streaks = new int[this->number_of_simulations];
	dice = new Dice(faces_of_dice);
	high = false;
	stake_multiplier = 2;
};

Simulator::~Simulator(){
	delete[] max_losing_streaks;
	delete[] max_winning_streaks;
}

void Simulator::simulate(){
	if (number_of_simulations < 1){
		return;
	}
	for (int i = 0; i < number_of_simulations; i++){
		int current_losing_streak = 0;
		int current_winning_streak = 0;
		int maximum_losing_streak = 0;
		int maximum_winning_streak = 0;
		for (int j = 0; j < number_of_rolls_per_simulation; j++){
			int result = dice->Roll();
			// Won dice roll
			if ((result < (dice->get_faces()/2) && !high) || (result >= (dice->get_faces()/2) && high)){

				current_losing_streak = 0;
				if (++current_winning_streak > maximum_winning_streak){
					maximum_winning_streak = current_winning_streak;
				}
			} else {

				current_winning_streak = 0;
				if (++current_losing_streak > maximum_losing_streak){
					maximum_losing_streak = current_losing_streak;
				}
			}
		}
		max_losing_streaks[i] = maximum_losing_streak;
		max_winning_streaks[i] = maximum_winning_streak;
		cout << "Simulation " << (i+1) << " ended. Maximum losing streak = " << maximum_losing_streak << endl;
	}
}

void Simulator::calculate() const{
	if (number_of_simulations < 1){
			return;
	}
	int maximum_losing = 0;
	double average_losing = 0;
	int minimum_losing = this->number_of_rolls_per_simulation;
	int maximum_winning = 0;
	double average_winning = 0;
	int minimum_winning = this->number_of_rolls_per_simulation;
	for (int i = 0; i < number_of_simulations; i++){
		maximum_losing = max(maximum_losing,max_losing_streaks[i]);
		average_losing += max_losing_streaks[i];
		minimum_losing = min(max_losing_streaks[i],minimum_losing);

		maximum_winning = max(maximum_winning,max_winning_streaks[i]);
		average_winning += max_winning_streaks[i];
		minimum_winning = min(max_winning_streaks[i],minimum_winning);
	}
	average_losing /= number_of_simulations;
	average_winning /= number_of_simulations;


	int maximum_drawdown = pow(static_cast<double>(this->stake_multiplier),static_cast<double>(maximum_losing));
	int average_drawdown = pow(static_cast<double>(this->stake_multiplier),average_losing);
	int minimum_drawdown = pow(static_cast<double>(this->stake_multiplier),static_cast<double>(minimum_losing));


	cout << "The maximum number of losing streaks among all " << number_of_simulations << " simulations is " << maximum_losing
			<< ", accounting for " << maximum_drawdown << " times of the initial bet." << endl;
	cout << "The average number of losing streaks among all " << number_of_simulations << " simulations is " << average_losing
			<< ", accounting for " << average_drawdown << " times of the initial bet." << endl;
	cout << "The minimum number of losing streaks among all " << number_of_simulations << " simulations is " << minimum_losing
			<< ", accounting for " << minimum_drawdown << " times of the initial bet." << endl;
}
