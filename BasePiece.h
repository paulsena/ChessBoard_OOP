/* 
 * File:   BasePiece.h
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 7, 2010, 1:04 AM
 */

#ifndef _BASEPIECE_H
#define	_BASEPIECE_H

#include <string>       // Included for String return types

// Foward Decleration since Board will be defined in a later include
class Board;

// Enumeration for Color of pieces
enum Color {
    Black,
    White
};

// Struct defining Position of Pieces
typedef struct Coordinates {
    int xpos;
    int ypos;
} Position;

// Class definition
class BasePiece {
public:
    // Constructors
    BasePiece();
    virtual ~BasePiece();

    // Public functions
    void Draw();
    void SetPosition(Position pos);
    Position GetPosition();
    Color GetColor();
    virtual bool ValidateMove(Position moveToPosition) = 0;
private:

protected:
    std::string type;
    Color color;
    Position pos;

};

#endif	/* _BASEPIECE_H */
