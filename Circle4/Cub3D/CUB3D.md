# Cub3D

![cub3D](https://img.shields.io/badge/42-Project-blue)
![Language](https://img.shields.io/badge/C-100%25-blue)
[![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/eltitoyisus/cub3D)

## Description

Cub3D is a 3D graphics project inspired by the classic Wolfenstein 3D game. Using raycasting techniques, you'll create a realistic 3D representation from a first-person perspective in a maze-like environment.

## Project Overview

Create a "realistic" 3D graphical representation of a maze from a first-person perspective using the raycasting technique, similar to the iconic Wolfenstein 3D (1992).

This project teaches you:
- Raycasting algorithms
- 3D projection from 2D maps
- Texture mapping
- Graphics optimization
- Event handling and game controls
- Mathematical concepts (vectors, angles, trigonometry)

## Mandatory Features

### Graphics
- Render a 3D view using raycasting
- Different wall textures based on direction (North, South, East, West)
- Different floor and ceiling colors
- Smooth window management

### Controls
- `W A S D` - Move forward, left, backward, right
- `←` `→` - Rotate camera left and right
- `ESC` - Exit program
- `X` (close button) - Exit program

### Map Requirements
- Walls represented by `1`
- Empty space by `0`
- Player starting position by `N`, `S`, `E`, or `W` (facing direction)
- Map must be surrounded by walls
- Valid `.cub` file format

## Scene Description File (.cub)

**Example configuration**:
```
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Configuration Elements
- `NO`, `SO`, `WE`, `EA` - Textures for each wall direction
- `F` - Floor color in RGB (0-255)
- `C` - Ceiling color in RGB (0-255)
- Map grid using `0`, `1`, and player position (`N`/`S`/`E`/`W`)

## Implementation Structure

```
Cub3D/
├── Makefile
├── README.md
├── mlx.supp
├── includes/         # Header files
│   ├── cub3d.h
│   └── structures.h
├── libft/           # Your libft library
├── minilibx/        # MiniLibX library
├── maps/            # Map files (.cub)
├── sprites/         # Texture files (.xpm)
└── src/             # Source files
    ├── parsing/     # Map and config parsing
    ├── raycasting/  # Raycasting engine
    ├── rendering/   # Graphics rendering
    ├── controls/    # Input handling
    └── utils/       # Utility functions
```

## Raycasting Algorithm

### Basic Steps:
1. **Cast rays** from player position for each screen column
2. **Calculate ray direction** based on player angle and field of view
3. **DDA algorithm** to find wall intersections
4. **Calculate wall distance** (perpendicular distance to avoid fisheye effect)
5. **Calculate wall height** based on distance
6. **Select texture** based on wall orientation
7. **Render texture column** from appropriate texture position

### Key Calculations:
```c
// Ray direction
rayDirX = dirX + planeX * cameraX;
rayDirY = dirY + planeY * cameraX;

// DDA algorithm for wall detection
// Texture mapping based on hit position
// Wall height calculation: screenHeight / perpWallDist
```

## Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## Usage

```bash
./cub3D maps/map.cub
```

## Error Handling

Must handle:
- Invalid map configuration
- Missing textures or colors
- Map not closed/surrounded by walls
- Invalid characters in map
- Multiple player positions or no player
- File not found or wrong extension
- Invalid RGB values
- Memory allocation failures

Display descriptive error messages for each case.

## Bonus Features

- Wall collisions
- Minimap system
- Doors that can open and close
- Animated sprites
- Mouse rotation
- Multiple texture variations
- Skybox

## Testing Maps

Create various test maps:
- Simple rectangular rooms
- Complex mazes
- Edge cases (single cell, large maps)
- Invalid maps (for error handling)

## Mathematical Concepts

### Vectors and Angles
- Player direction vector
- Camera plane perpendicular to direction
- Field of view calculations

### DDA Algorithm
- Digital Differential Analysis
- Efficient line drawing
- Grid traversal

### Texture Mapping
- UV coordinates
- Texture scaling
- Column-based rendering

## Common Challenges

- **Fisheye effect**: Use perpendicular distance, not Euclidean
- **Texture distortion**: Proper texture coordinate calculation
- **Performance**: Optimize raycasting loop
- **Off-by-one errors**: Careful with array bounds
- **Parsing edge cases**: Spaces, tabs, invalid characters

## External Functions Allowed

- MiniLibX functions: `mlx_init`, `mlx_new_window`, `mlx_pixel_put`, `mlx_new_image`, `mlx_get_data_addr`, `mlx_put_image_to_window`, `mlx_hook`, `mlx_loop`
- Math library: `math.h` functions
- File I/O: `open`, `read`, `close`
- Memory: `malloc`, `free`
- Standard output: `write`, `printf`
- Process: `exit`

## Skills Acquired

- Raycasting algorithm implementation
- 3D graphics from 2D data
- Texture mapping
- Mathematical problem solving
- Graphics optimization
- Game development basics
- Event-driven programming
- Complex project architecture
- Trigonometry and vector mathematics

## Circle

**Circle 4** - Advanced graphics project at 42 School
