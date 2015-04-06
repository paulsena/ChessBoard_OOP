/* 
 * File:   Knight.h
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 8, 2010, 2:34 PM
 */

#ifndef _KNIGHT_H
#define	_KNIGHT_H

#include "BasePiece.h"

class Knight : public BasePiece {

public:
    // Constructors
    Knight(Color color, Position pos);
    virtual ~Knight();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:

};

#endif	/* _KNIGHT_H */

