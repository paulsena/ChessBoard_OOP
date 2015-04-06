/* 
 * File:   Bishop.h
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 8, 2010, 2:34 PM
 */

#ifndef _BISHOP_H
#define	_BISHOP_H

#include "BasePiece.h"

class Bishop : public BasePiece {

public:
    // Constructors
    Bishop(Color color, Position pos);
    virtual ~Bishop();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:

};

#endif	/* _BISHOP_H */

