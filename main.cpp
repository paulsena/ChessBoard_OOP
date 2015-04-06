/*
 * File:        main.cpp
 * Author:      Paul Senatillaka , psenatil@cs.uml.edu
 *              UMass Lowell Computer Science
 * Class:       91.201 Computing III
 * Assignment:  7 - Implementing an Object-Oriented Game
 *
 * Created on:  May 6, 2010
 *
 * Description: This program is a two person chess game using the techniques
 *              covered over the course.
 *
 */

#include "Board.h"      // Board Class
#include "BasePiece.h"  // Base Chess Piece Class
#include <iostream>     // For Output and Input to screen

using namespace std; // declare namespace to eliminate need for std::

// Function Declerations
void DisplayIntro();

void DisplayInstructions();

void ToLowerCase(string *str);

bool ValidateInput(string input1, string input2);

Position ConvertChessNotation(string move);

// Definition for our chess board. Only Global Var
Board board;

/******************************************
 *  @summary main method - program entry point
 *  @param arc - number of arguments
 *  @param argv - command line parameter array
 *  @return success flag
 ******************************************/
int main(int argc, char** argv) {

    // ***** Variable Initialization ******
    string input1, input2; // Input from users temp variables
    Color turnColor = White; // the current color's turn
    bool moveSucceed = false; // control workflow flag
    Position moveFrom; // Position struct for source location
    Position moveTo; // Position struct for target location
    //*************************************

    // Displays game intro screen
    DisplayIntro();

    // Main Game Loop
    /************************************************/
    while (input1 != "quit") {

        // Output a few carriage returns
        cout << string(4, '\n');

        // Draws the board to the screen
        board.Draw();

        // Move Validation Loop
        do {

            // Display who's turn it is
            if (turnColor == White) {
                cout << endl << "White's turn" << endl;
            } else {
                cout << endl << "Blacks's turn" << endl;
            }

            // Input Retrieval and Validation Loop
            /****************************************************/
            do {
                // Read source piece location
                cout << "Please enter where to move from: ";
                cin >> input1;

                // Make the input non case sensitive
                ToLowerCase(&input1);

                // Check for quit or help commands where entered
                if (input1 == "quit") {

                    // Exit
                    return 0;

                } else if (input1 == "help") {

                    // Display instructions
                    DisplayInstructions();

                } else {
                    // If a command was not issued, it must be a move, continue.
                    cout << "Please enter where to move to: ";
                    cin >> input2;

                    // Make the input non case sensitive
                    ToLowerCase(&input2);
                }

                // Validate the input, if invalid, loop to prompt for new input
            } while (input1 == "help" || !ValidateInput(input1, input2));
            /****************************************************/

            
            // Input must be valid, Convert Algebriac Notation into Cartesian based Coordinates
            moveFrom = ConvertChessNotation(input1);
            moveTo = ConvertChessNotation(input2);

            // Check that we selected the right colored piece for whos turn it is
            if (board.GetPiece(moveFrom)->GetColor() != turnColor) {

                cout << "Move Invalid: Wrong color pawn selected" << endl;
                moveSucceed = false;

            } else {

                // Attempt to move chess piece. Validation relating to specific chess
                // piece rules is made here.
                moveSucceed = board.MovePiece(moveFrom, moveTo);

                // Give feedback if move failed or not
                if (moveSucceed == false) {
                    cout << "Move Invalid" << endl;
                } else {
                    cout << "Move Completed" << endl;
                }
            }

            // If move failed, loop back without redrawing board
        } while (moveSucceed == false);

        // Move succeeded. Change whos turn it is.
        if (turnColor == White) {
            turnColor = Black;
        } else if (turnColor == Black) {
            turnColor = White;
        }

    }
    // End of Main Game Loop
    /***********************************************/

    return (EXIT_SUCCESS);
}

/******************************************
 *  @summary Displays the intro screen to user
 *  @return void
 ******************************************/
void DisplayIntro() {

    cout << "\n\n\t\t Welcome to Deep Blue Chess Master 2600 " << endl
            << "\t\t\t   By Paul Senatillaka" << endl << endl;
    DisplayInstructions();
    cout << "\n\n\t\t\tPress enter to start game" << endl;
    cin.ignore();
}

/******************************************
 *  @summary Displays the game instructions
 *  @return void
 ******************************************/
void DisplayInstructions() {

    cout << "\nInstructions:" << endl
            << "To move chess pieces, use standard chess algebriac notation." << endl
            << "The board is labeled around the edges with the algebriac notation." << endl
            << "It consists of a letter (column), followed by a number (row)." << endl
            << "Pieces are designated by w or b for color, followed by the piece's first char. Note* N = Knight" << endl
            << "At any time you can enter 'quit' to exit the program or 'help' to receive these instructions again." << endl << endl;
}

/******************************************
 *  @summary Changes a string to all lower case characters
 *  @summary str - input string by reference
 *  @return void
 ******************************************/
void ToLowerCase(string *str) {
    for (size_t i = 0; i < str->length(); ++i) {
        (*str)[i] = tolower((*str)[i]);
    }
}

/******************************************
 *  @summary Validates the user move input and displays a friendly message
 *  @param input1 - User input string
 *  @param input2 - User input string
 *  @return bool - True if there are any input errors
 ******************************************/
bool ValidateInput(string input1, string input2) {

    // Check if input is right size
    if (input1.size() != 2 || input2.size() != 2) {

        cout << "Incorrect input size. Please check that the input is only a letter followed by number" << endl;
    } else {

        // Convert Algebriac Notation into Cartesian based Coordinates
        Position moveFrom = ConvertChessNotation(input1);
        Position moveTo = ConvertChessNotation(input2);

        // Check if x or y Position from the source location falls outside of the chess board
        if (moveFrom.xpos < 0 || moveFrom.xpos > 7 || moveFrom.ypos < 0 || moveFrom.ypos > 7) {
            cout << "Source location out of bounds" << endl;
        // Check if x or y Position from the target location falls outside of the chess board
        } else if (moveTo.xpos < 0 || moveTo.xpos > 7 || moveTo.ypos < 0 || moveTo.ypos > 7) {
            cout << "Destination location out of bounds" << endl;
        } else {
            return true;
        }
    }

    return false;
}

/** 
 **  These are Cartesian coordinates and 0 based starting at bottom left corner of board
 */
Position ConvertChessNotation(string moveInputStr) {

    Position movePosition;

    // Index first character , cast to an int, and subtract 97 to make acii
    // letter based, 0 based
    movePosition.xpos = (int) moveInputStr[0] - 97;
    // Convert numeric char to a number. Subtract 1 to make 0 based
    movePosition.ypos = atoi(&moveInputStr[1]) - 1;

    // Return 0 based Cartesion position information
    return movePosition;
}


