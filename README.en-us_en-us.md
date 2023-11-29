# BattleShip:
The BattleShip game developed in C is a modern and graphical reinterpretation of the classic Battleship naval game. Using the Raylib library, it provides an interactive and visually appealing experience. The code is well-structured, incorporating elements such as matrices, textures, and music to create an engaging dynamic. Different screens smoothly transition between game phases, while mouse-click interaction logic adds a strategic component. In summary, BattleShip represents a well-crafted implementation that combines the nostalgia of the original game with modern programming features.

# Authors:
Game developed in 2023 by Gabriel Leite Soares Ramos && Luis Otavio Albergoni Santos, students of the Computer Science Course at PUC MINAS, Poços de Caldas.

# General Structure:
The C code develops a game based on the classic Battleship naval game, using the external Raylib library for graphics and game functionalities. Below is a detailed description of the general code structure:

# Initial Comments:
At the beginning of the code, there are comments providing information about the project's purpose, group members, game objectives, and changes made over time.

# Definition of Structures:
There is the definition of a structure "embarcacao" to represent information about each type of ship in the game, such as size and number of hits.

# Matrix and Variables:
A 5x5 matrix (matriz) is declared to represent the game field. In addition, various variables such as coordinates (i and j), a screen control variable (tela), ammunition (ammo), score (pontos), and others are declared.

# Game Initialization:
Initial game settings are made, such as window initialization using Raylib, FPS definition, and loading of textures and music.

# Main Loop Structure:
The game is controlled by a main loop that runs while the window is not closed (WindowShouldClose()). Within this loop, there are distinct sections for different game screens (initial screen, game screen, rules screen, defeat screen, victory screen).

# Initial Screen (tela==0):
In this section, elements of the initial screen are drawn, such as the title "BattleShip" and instructions to start or view the rules. Transition to the game screen occurs by pressing Enter, and to the rules screen by pressing R.

# Game Screen (tela==1):
Here, the game logic is updated, and graphic elements are drawn. The matrix is displayed with coordinates, and player interactions are detected by mouse clicks to shoot. Information about ammunition, score, and sunken ships is displayed.

# Victory/Defeat Condition Check:
The code checks if the player has won or lost based on the score and ammunition.

# Rules Screen (tela==2):
If the player presses the F key, the rules screen is displayed, explaining how to play.

# Defeat (tela==3) and Victory (tela==4) Screens:
In these sections, defeat or victory screens are displayed, respectively. The player can restart the game by pressing Enter.

# Closing and Unloading:
At the end of the code, the music is unloaded, the audio device is closed, and the window is closed.

# Additional Function (retornadados):
There is an additional function called "retornadados" that resets the score and ammunition if the player wins or loses.

# Textures and Music:
Textures representing different types of ships and music for different moments of the game are loaded.

# Drawing Graphic Elements:
The drawing of graphic elements, such as ship textures, is done based on player interactions.

# Music Control:
The code uses the Raylib library to load and play music during different game phases.

# Resource Release:
In the end, all music is unloaded, and the audio device is closed before ending the program.