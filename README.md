# so_long - @42Paris
### 🎮 About the project

so_long is a simple 2D game developed using the MiniLibX (a small graphics library). The goal is to guide a character through a map, collecting items and reaching the exit with the minimum number of moves.

This project is an introduction to graphical programming, window management, event handling (keyboard/mouse), and sprite rendering.

<p align="center">
  <img src="assets/so_long.gif" alt="so_long" width="800">
</p>


### 🏗️ Bonus Features Included

   * Enemy Patrols: Added moving enemies that cause a game over if touched.

    * Sprite Animation: The exit is animated when the player has colleced all the items on the map.

    * On-screen Move Counter: The current number of moves is displayed directly on the game window instead of just the terminal.

### 🗺️ Map Rules

The game parses a .ber file which must follow these constraints:

    * Walls: The map must be surrounded by walls (1).

    * Components: Must contain at least one exit (E), one starting position (P), and at least one collectible (C).

    * Shape: The map must be rectangular.

    * Path: There must be a valid path to all collectibles and the exit.

### 🛠️ Controls

* W Move Up
* A Move Left
* S Move Down
* D Move Right
* ESC	Close the game
### 🚀 Getting Started
Requirements

The project requires the MiniLibX and its dependencies (X11, AppKit, or OpenGL depending on your OS).
Compilation
```Bash

 Compile the game with bonus features
make bonus

# Remove object files
make clean

# Remove all generated files
make fclean

Execution

Run the game by providing a map file as an argument:
Bash

./so_long maps/map.ber
```

### 🎨 Graphics & Assets

I used a custom sprite set to create a unique atmosphere.

   * Tileset size: 64x64 pixels.

    * Game Loop: Utilizes the mlx_loop_hook to handle animations and enemy movements smoothly.

### 📂 Project Structure

  *  /src: Source files for the game logic.

  * /xpm: XPM files for player, walls, collectibles, and enemies.

  * /libft: My custom C library (Libft).

  * /map: Sample .ber maps for testing.

##### 📬 Contact

    Login: qsomarri

    School: 42 Paris
