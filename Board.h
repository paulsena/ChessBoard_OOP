/* 
 * File:        Board.h
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 8, 2010, 4:43 PM
 */

#ifndef _BOARD_H
#define	_BOARD_H

#include "Square.h" // For Square Class

class Board {
public:
    // Constructors
    Board();
    virtual ~Board();

    // Public Functions
    void Draw();
    bool MovePiece(Position fromPos, Position toPos);
    BasePiece* GetPiece(Position piecePos);
    
private:
    // Private Member Variables
    Square board[8][8];
    // Private Member Functions
    void InitializePieces();
    bool IsWithinBoard(Position pos);

};

#endif	/* _BOARD_H */

