/* 
 * File:   Rook.h
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 8, 2010, 2:34 PM
 */

#ifndef _ROOK_H
#define	_ROOK_H

#include "BasePiece.h"

class Rook : public BasePiece {

public:
    // Constructors
    Rook(Color color, Position pos);
    virtual ~Rook();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:

};

#endif	/* _ROOK_H */

