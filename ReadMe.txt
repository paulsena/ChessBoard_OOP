#--
#  Project:   Assignment 7
#  Course:   	91.201 - Computing III
#  Author:    Paul Senatillaka
# ++

Description / Comment
===========================================
This is an implementation of a two player, turn based, chess game that uses concepts covered in Computing III.
Note that just the pawn movement is implemented. However they are fully functional, including
moving, opening double jumps, attacking diagonal, movement obstacle detection, and board bound checking.

Much work went into setting up the chess framework, and as this was a time limited assigment, I wasn't
able writeup the rest of the chess piece move functionality. However, some strong OOP
concepts were implemented, so new piece movement can be implemented very easily by filling out
one abstract function, ValidateMove(Position newPos), in the derived class. 

Features:
  - Intro screen
  - 2 Player turn based Interface
  - Input uses standard chess algebriac notation
  - User can bring up help any time with "help" command
  - User Input Validation
  - Complete move validation for pawn chess piece along with attacking



End
===================================================




