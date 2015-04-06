/* 
 * File:   Pawn.h
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 8, 2010, 2:34 PM
 */

#ifndef _PAWN_H
#define	_PAWN_H

#include "BasePiece.h"

class Pawn : public BasePiece {

public:
    // Constructors
    Pawn(Color color, Position pos);
    virtual ~Pawn();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:
    // Indicates whether a double jump first move is available
    bool doubleJumpAvailable;
    
};

#endif	/* _PAWN_H */

