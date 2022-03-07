DERAILED
Drew James and Skye Pritchard

--------------------------------------------------------------------

Code Breakdown
Board - Initializes spaces and train for a given level, reading the board layout from a file
Cosmetics - Handles sprites that are irrelevant to the actual function of the game
EventWin - Event to be referenced in other classes
game - sets up the game environment and initializes everything
Level - Both a view object used to select a level, and a class that persists once a level has started to handle the win event.
LevelMenu - the menu used to select the initial level
LevelTransition - the menu that appears when a level is beaten and handles moving to the next level
Menu - the menu that appears at the start of the game
Score - Handles the score, timer, and save system (as the only persistent static object)
Space - Each individual space in a board. Each space is a node that has connections to its neighboring spaces or a NULL pointer. This class handles the space's sprite, which changes when the train has driven over it
Train - The physical train, handles player input for movement. It also rotates when the puzzle first starts. Handles train sprite based on direction last traveled.
--------------------------------------------------------------------

To build:

0) Setup development environment for Windows, Linux or MacOS.
See http://dragonfly.wpi.edu/engine/index.html#setup for details.

1) Build, as appropriate for the platform (e.g., "make" on Linux or
Mac, F7 on Windows from Visual Studio).

2) Run game, as appropriate for the platform (e.g., "./game" on
Linux or Mac, F5 on Windows from Visual Studio)

--------------------------------------------------------------------

Directories:

sounds/ - contains the sound files used in Derailed    
sprites/ - contains the sprite files used in Derailed
boards/ - contains the level files used in Derailed


-- Skye
stpritchard@wpi.edu
-- Drew
dtjames@wpi.edu