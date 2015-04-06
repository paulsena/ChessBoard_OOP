/* 
 * File:   King.h
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 8, 2010, 2:34 PM
 */

#ifndef _KING_H
#define	_KING_H

#include "BasePiece.h"

class King : public BasePiece {

public:
    // Constructors
    King(Color color, Position pos);
    virtual ~King();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:

};

#endif	/* _KING_H */

