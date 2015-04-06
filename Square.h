/* 
 * File:   Square.h
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 7, 2010, 12:56 AM
 */

#ifndef _SQUARE_H
#define	_SQUARE_H

#include "BasePiece.h"  // For Base Class

class Square {
public:
    // Constructors
    Square();
    virtual ~Square();

    // Public functions
    BasePiece* GetPiece();
    void SetPiece(BasePiece *piece);
    void Clear();
    
private:
    // Each Square has a pointer to a chess piece
    BasePiece *chessPiece;
};

#endif	/* _SQUARE_H */

