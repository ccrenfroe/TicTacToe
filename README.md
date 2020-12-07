# TicTacToe

Simple terminal TicTacToe game written in C++..

Played between 2 players. The game alternates between the two players and places their piece on the board based off of their input.

To play, make sure you read the the prompts to know when it is your turn. When it is your turn, enter your move as 2 numbers seperated by a space. These numbers will represent the x and y coordinates for the space you want to mplace your piece.

Ex:
```
Jill's turn.
Please enter your move as a row and column choice, seperated by a space. (Ex: 1 2);
1 3 // Valid move!
================================
Jill's turn

[ ][ ][x]
[ ][ ][ ]
[ ][ ][ ]
================================
```

```
Jill's turn.
Please enter your move as a row and column choice, seperated by a space. (Ex: 1 2);
0 4 // Not a valid move!
Invalid move. Please enter a valid move.Jill's turn.
Please enter your move as a row and column choice, seperated by a space. (Ex: 1 2);
4 0 // Not a valid move!
Invalid move. Please enter a valid move.Jill's turn.
Please enter your move as a row and column choice, seperated by a space. (Ex: 1 2);
```
