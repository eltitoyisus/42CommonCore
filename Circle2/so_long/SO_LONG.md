# so_long

## Description

so_long is a small 2D game project where you create a simple game using the MiniLibX graphics library. The player must collect all collectibles and reach the exit with the minimum number of moves.

## Project Overview

Create a basic 2D game where:
- The player navigates a map
- Collects all items
- Reaches the exit
- Movement count is displayed

This project teaches you:
- Graphics programming basics
- Event handling (keyboard input)
- Window management
- Sprite/texture rendering
- Map parsing and validation
- Game loop implementation
- MiniLibX library usage

## Game Rules

1. **Objective**: Collect all collectibles (C) and reach the exit (E)
2. **Movement**: Use W/A/S/D or arrow keys to move
3. **Restrictions**: 
   - Exit only opens after collecting all items
   - Player cannot move through walls
4. **Display**: Show move count in terminal/window

## Map Components

Maps are `.ber` files with these characters:

- `0` - Empty space
- `1` - Wall
- `C` - Collectible
- `E` - Exit
- `P` - Player starting position

**Example Map:**
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Map Requirements

The map must:
- Be rectangular
- Be surrounded by walls (1)
- Have exactly one exit (E)
- Have exactly one starting position (P)
- Have at least one collectible (C)
- Have a valid path to collect all items and reach the exit
- Be composed only of: 0, 1, C, E, P

## Implementation Structure

### Mandatory Files
- `Makefile` - Compilation rules
- `libft/` - Your libft library
- `minilibx/` - MiniLibX graphics library
- `mandatory/` - Main game implementation

### Key Components
- Map parsing and validation
- Player movement handling
- Collision detection
- Sprite/texture rendering
- Window and event management
- Game state tracking

## MiniLibX Functions

### Window Management
```c
mlx_init()           // Initialize MiniLibX
mlx_new_window()     // Create a new window
mlx_destroy_window() // Destroy window
```

### Image/Sprite Handling
```c
mlx_new_image()      // Create new image
mlx_xpm_file_to_image() // Load XPM file
mlx_put_image_to_window() // Display image
```

### Event Handling
```c
mlx_hook()           // Register event hook
mlx_key_hook()       // Register key hook
mlx_loop()           // Start event loop
```

## Controls

- `W` or `↑` - Move up
- `A` or `←` - Move left
- `S` or `↓` - Move down
- `D` or `→` - Move right
- `ESC` - Exit game

## Compilation

```bash
make        # Compile the game
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## Usage

```bash
./so_long maps/map.ber
```

## Game Features

### Mandatory
- 2D top-down view
- Player can move in 4 directions (W/A/S/D)
- Cannot move through walls
- Display move count in terminal
- Collect all items before exit opens
- Clean exit with ESC or window close

### Bonus (Optional)
- Enemy patrols (causes game over)
- Sprite animation
- Move counter displayed on screen
- More advanced graphics

## Error Handling

Handle these errors gracefully:
- Invalid map format
- Missing map file
- Map not surrounded by walls
- Invalid characters in map
- Multiple/missing player or exit positions
- No collectibles
- No valid path to complete the game
- MiniLibX initialization failures

## Skills Acquired

- Graphics programming basics
- Event-driven programming
- Window and input management
- Texture/sprite handling
- Map parsing and validation
- Pathfinding algorithms (flood fill)
- Game loop implementation
- Memory management with graphics
- MiniLibX library

## Circle

**Circle 2** - First graphics project at 42 School
