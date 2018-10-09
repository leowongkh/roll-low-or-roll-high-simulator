/*
 * DiceRoll.h
 *
 */

#ifndef DICE_H_
#define DICE_H_

#include <cstdlib>

class Dice{
public:
	Dice(int Faces);
	~Dice();

	int Roll() const;
	int get_faces() const;

private:
	const int faces;
};



#endif /* DICE_H_ */
