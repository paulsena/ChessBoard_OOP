/* 
 * File:   Queen.h
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 8, 2010, 2:34 PM
 */

#ifndef _QUEEN_H
#define	_QUEEN_H

#include "BasePiece.h"

class Queen : public BasePiece {

public:
    // Constructors
    Queen(Color color, Position pos);
    virtual ~Queen();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:

};

#endif	/* _QUEEN_H */

