# Battleship-Game-
Battleship Game in C++
Project Description 
So this is a battleship game its classic naval combat game that was built in c++, it's an engaging experience for players. The game is designed to have a computer opponent and a human opponent in a battle that requires tactical thinking. Players which are the computer and human player take turns launching attacks at each other's board which both have to attempt to locate and sink the others ships until all the ships has been sunk. So the goal of this game is to design a computer opponent (Ai opponent) to be able to randomly target the enemy's ships (human opponent) until the entire fleet of ships has been destroyed. This game design focuses on using a traditional board game experience with a display board that functions with a visual representation using a 2D array and has attacks launched through a coordinate system when called in the format A5 for example. The game has many features to enhance playability and the user experience, one of these experiences is the customizable board size which allows players to choose. This allows for more complexity to the game, another thing is the manual ship placement it provides the player the opportunity to strategically place their ships to carefully position and has a user input whether they want to place ships horizontally or vertically which improves the defensivablilites. This game accurately tracks hits and misses and provides information on the effectiveness of each attack by placing X's and O's over the board. The game ends when the computer opponent or the human player has successfully sunk all the ships from the board. 



Features 
Customizable Board Size functionality - This feature allows players to choose the dimensions of the game board when playing based on the complexity they want.

Manual Ship Placement functionality - This feature allows players to choose the way they want to place their ships and also adds the functionality of choosing to place them horizontally or vertically.

Automated Computer Opponent functionality - This feature allows the computer opponent to choose randomly where to make moves.

Hits and Misses - This feature allows the game to track all of the hits and misses on the game board. 

Ship Sinking Awareness functionality - This feature allows the game to detect when a ship has been sunk. 

Move History and Undo Functionality - This feature allows the game to track the history of moves and allows the player to undo the last move made. 


Compilation 
To compile the game you will need a C++ compiler and save all the provided code files into the separate .h and .cpp files. Then you run and compile the main file with all the other .h and .cpp files in the compiler.


How to Play
1. Board Size: The game will first ask for you to enter the desired number of rows and columns for the game board. This is the Customizable board size.

2. Ship Placement: You will be asked to manually place your ships or have them automatically placed. This is the manual ship placement functionality.

3. Use the w, a, s, d keys to move the ship's display board position.
   
4. Then press Enter twice to confirm the placement.
 
5. You will be asked to choose horizontal (y) or vertical (n) placement.
  
6. Taking Turns: The game takes turns between the player and the computer.
  
7. Firing: To fire at the computer's board, the player must enter the coordinates in the format "A5" (it's the letter for row and number for column).

8. Winning: The first player to sink all of the opponent's ships wins the game.

