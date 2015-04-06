/* 
 * File:   Queen.cpp
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 8, 2010, 2:34 PM
 */

#include "Queen.h"

/**@summary Constructor
 * @color Color of this new piece
 * @pos Position of this new piece
 */
Queen::Queen(Color color, Position pos) {
    this->type = "Q";
    this->color = color;
    this->pos = pos;
}

/**@summary Default Destructor
 */
Queen::~Queen() {

}

/**@summary Validates that a possible move abides by this pieces move logic
 * @param moteToPos - Position of where this piece will move
 * @return bool - Success or Fail
 */
bool Queen::ValidateMove(Position moveToPos) {

    return false;
}

