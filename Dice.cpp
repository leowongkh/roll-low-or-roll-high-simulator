/*
 * Dice.cpp
 *
 */


#include "Dice.h"

Dice::Dice(int Faces):faces(Faces){

}

Dice::~Dice(){
}

int Dice::Roll() const{
	return rand()%faces;
}

int Dice::get_faces() const{

	return faces;
}
