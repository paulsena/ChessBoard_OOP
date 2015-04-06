/* 
 * File:   Board.cpp
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on May 8, 2010, 4:43 PM
 *
 */

#include "Board.h"      // Header file for this class
#include "BasePiece.h"  // For Base Piece Class
#include "Pawn.h"       // For Pawn Class
#include "Rook.h"       // For Rook Class
#include "Queen.h"      // For Queen Class
#include "Knight.h"     // For Knight Class
#include "King.h"       // For King Class
#include "Bishop.h"     // For Bishop Class
#include <iostream>     // FOr output to screen

using namespace std;    // declare namespace to eliminate need for std::

/**@summary Default Constructor
 */
Board::Board() {
    InitializePieces();
}

/**@summary Default Destructor
 */
Board::~Board() {
}

/**@summary Draws the 8x8 chess board on the screen
 * @return void
 */
void Board::Draw() {
    for (int row = 7; row >= 0; row--) {

        // Draws Horizontal Row Dividers
        cout << "   ";
        for (int col = 0; col < 8; col++) {
            cout << "-----";
        }
        cout << "-" << endl;


        // Draws Vertical Row Divider and Chess Piece
        cout << row + 1 << "  ";
        for (int col = 0; col < 8; col++) {
            cout << "| ";
            BasePiece *currPiece = board[row][col].GetPiece();
            if (currPiece != NULL) {
                currPiece->Draw();
            } else {
                cout << "  ";
            }
            cout << " ";
        }

        // Draws Divider for end of Row
        cout << "|" << endl;

    }

    // Draws Horitonal Divider for last Row
    cout << "   ";
    for (int col = 0; col < 8; col++) {
        cout << "-----";
    }
    cout << "-" << endl;

    // Draws Letters on botton of board
    cout << "   ";
    for (int col = 0; col < 8; col++) {
        cout << "  " << (char) (col + 97) << "  ";
    }
    cout << endl << endl;

}

/**@summary Instantiates and sets chess pieces to where they should be on the board
 * @return void
 */
void Board::InitializePieces() {

    // ****** Initialize Board with Pieces *******

    // Pawns
    for (int col = 0; col < 8; col++) {
        Position blackPawnPos = {col,6};
        board[blackPawnPos.ypos][blackPawnPos.xpos].SetPiece(new Pawn(Black, blackPawnPos));

        Position whitePawnPos = {col,1};
        board[whitePawnPos.ypos][blackPawnPos.xpos].SetPiece(new Pawn(White, whitePawnPos));
    }

    
    // Rooks
    Position whiteRookPos = {0,0};
    board[whiteRookPos.ypos][whiteRookPos.xpos].SetPiece(new Rook(White, whiteRookPos));

    Position whiteRookPos2 = {7,0};
    board[whiteRookPos2.ypos][whiteRookPos2.xpos].SetPiece(new Rook(White, whiteRookPos2));
    
    Position blackRookPos = {0,7};
    board[blackRookPos.ypos][blackRookPos.xpos].SetPiece(new Rook(Black, blackRookPos));

    Position blackRookPos2 = {7,7};
    board[blackRookPos2.ypos][blackRookPos2.xpos].SetPiece(new Rook(Black, blackRookPos2));


    // Knights
    Position whiteKnightPos = {1,0};
    board[whiteKnightPos.ypos][whiteKnightPos.xpos].SetPiece(new Knight(White, whiteKnightPos));

    Position whiteKnightPos2 = {6,0};
    board[whiteKnightPos2.ypos][whiteKnightPos2.xpos].SetPiece(new Knight(White, whiteKnightPos2));

    Position blackKnightPos = {1,7};
    board[blackKnightPos.ypos][blackKnightPos.xpos].SetPiece(new Knight(Black, blackKnightPos));

    Position blackKnightPos2 = {6,7};
    board[blackKnightPos2.ypos][blackKnightPos2.xpos].SetPiece(new Knight(Black, blackKnightPos2));

    
    // Bishops
    Position whiteBishopPos = {2,0};
    board[whiteBishopPos.ypos][whiteBishopPos.xpos].SetPiece(new Bishop(White, whiteBishopPos));

    Position whiteBishopPos2 = {5,0};
    board[whiteBishopPos2.ypos][whiteBishopPos2.xpos].SetPiece(new Bishop(White, whiteBishopPos2));

    Position blackBishopPos = {2,7};
    board[blackBishopPos.ypos][blackBishopPos.xpos].SetPiece(new Bishop(Black, blackBishopPos));

    Position blackBishopPos2 = {5,7};
    board[blackBishopPos2.ypos][blackBishopPos2.xpos].SetPiece(new Bishop(Black, blackBishopPos2));

    
    // King
    Position whiteKingPos = {4,0};
    board[whiteKingPos.ypos][whiteKingPos.xpos].SetPiece(new King(White, whiteKingPos));

    Position blackKingPos = {4,7};
    board[blackKingPos.ypos][blackKingPos.xpos].SetPiece(new King(Black, blackKingPos));

    
    // Queens
    Position blackQueenPos = {3,0};
    board[blackQueenPos.ypos][blackQueenPos.xpos].SetPiece(new Queen(Black, blackQueenPos));

    Position blackQueenPos2 = {3,7};
    board[blackQueenPos2.ypos][blackQueenPos2.xpos].SetPiece(new Queen(White, blackQueenPos2));




}

/**@summary Moves a chess piece from one position to another. Validates move.
 * @param fromPos - Starting Position
 * @param toPos - Ending Position
 * @return bool - Success or Failure
 */
bool Board::MovePiece(Position fromPos, Position toPos) {

    // Return status flag
    bool moveCompleted = false;

    // Get Piece from the square object array (board)
    BasePiece *origPiece = board[fromPos.ypos][fromPos.xpos].GetPiece();

    // Check if we can make this move. Is this a valid move and within the board
    if (origPiece != NULL && origPiece->ValidateMove(toPos) && IsWithinBoard(toPos)) {

        // Make the move
        origPiece->SetPosition(toPos);
        board[toPos.ypos][toPos.xpos].SetPiece(origPiece);
        board[fromPos.ypos][fromPos.xpos].Clear();

        moveCompleted = true;
    }

    // Return move status
    return moveCompleted;
}

/**@summary Getter for chessPiece
 * @param Board Position to retrieve piece from
 * @return Pointer to piece
 */
BasePiece* Board::GetPiece(Position piecePos) {
    return board[piecePos.ypos][piecePos.xpos].GetPiece();
}

/**@summary Check if position is within board boundry
 * @param Piece Position
 * @return bool - Success or Failure
 */
bool Board::IsWithinBoard(Position pos) {

    // Check boundry
    if ((0 <= pos.xpos && pos.xpos <= 7) && (0 <= pos.ypos && pos.ypos <= 7)) {
        return true;
    }

    return false;
}
