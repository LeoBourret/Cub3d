# 🎮 Cub3D: First-Person Raycasting Engine

![Language: C](https://img.shields.io/badge/Language-C-blue.svg)
![Build: Makefile](https://img.shields.io/badge/Build-Makefile-green.svg)
![Graphics: MinilibX](https://img.shields.io/badge/Graphics-MinilibX-orange.svg)
![School: 42 Paris](https://img.shields.io/badge/School-42_Paris-orange.svg)
![Grade: 104/100](https://img.shields.io/badge/Grade-104/100-brightgreen.svg)

## ✨ Overview

`Cub3D` is a challenging graphical project from 42 Paris, inspired by the classic first-person shooter *Wolfenstein 3D*. The core objective was to **implement a 3D graphic representation of a maze using the ray-casting technique**, enabling a subjective view for the player to navigate.

This project provided a deep dive into fundamental 3D graphics concepts, mathematical computations for rendering, parsing complex map files, and managing interactive elements with the MinilibX graphical library. It solidified my understanding of how a simple 2D map can be translated into an immersive 3D experience.

## 🌟 Key Features & Implementation Details

The project involves parsing a `.cub` map file to render a 3D maze and allow player interaction.

### **1. Core Raycasting Engine (Mandatory Part)**

*   **3D Raycasting:** Implemented the ray-casting algorithm from scratch to render 2D maps into a pseudo-3D perspective.
*   **Dynamic Viewport:** Generates a dynamic first-person view as the player moves and rotates within the maze.
*   **Map Parsing:** Reads and interprets `.cub` map files, defining maze structure (walls, empty spaces, player start/orientation), resolution, textures (North, South, East, West walls), and floor/ceiling colors.
*   **Texture Mapping:** Applies different textures to walls based on their orientation (North, South, East, West).
*   **Player Movement:** Allows basic player navigation using WASD keys for movement and arrow keys for camera rotation (left/right).
*   **Window Management:** Handles window events (minimization, focus, close button) using MinilibX.
*   **Error Handling:** Robustly manages errors related to invalid map configurations or parsing issues.
*   **First Image Save:** Ability to save the first rendered image as a `.bmp` file.

### **2. Enhanced Gameplay Features (Bonus Part - Achieved)**

*   **Wall Collision:** Implemented accurate **collision detection with walls**, preventing the player from passing through obstacles.
*   **Vertical Look (Look Up/Down):** Added the ability for the player to **look up and down**, enhancing immersion and perspective beyond a simple horizontal plane.
*   **Object Collision:** Integrated **collision detection with objects (sprites)** placed within the maze, adding another layer of interaction and challenge.

## 🛠️ Technologies Used

*   **Language:** C
*   **Build System:** Makefile
*   **Graphics Library:** MinilibX (42's custom graphical library)
*   **Mathematics:** Trigonometry, Vector Math for raycasting calculations.
*   **Memory Management:** Explicit `malloc` and `free` for dynamic allocations (e.g., textures, map data).
*   **File I/O:** `open`, `close`, `read` for map parsing.

## 🚀 How to Use

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/yourusername/Cub3D.git
    cd Cub3D
    ```
2.  **Compile the program:**
    ```bash
    make
    # This will generate the 'cub3D' executable.
    ```
    *Note: MinilibX must be properly installed and configured on your system (common in 42 environments).*

3.  **Run Cub3D:**
    ```bash
    ./cub3D <path/to/your/map.cub>
    ```
    *Example:*
    ```bash
    ./cub3D maps/example.cub
    ```
    (Optional: to save the first image as BMP)
    ```bash
    ./cub3D <path/to/your/map.cub> --save
    ```

## 🎓 Learning Outcomes

This project was pivotal in deepening my understanding of:

*   **3D Graphics Fundamentals:** Practical implementation of ray-casting, a core technique in early 3D rendering.
*   **Geometric & Vector Math:** Extensive application of trigonometry and vector operations for camera movement, rotations, and projection.
*   **Game Development Logic:** Designing and implementing player movement, collision detection, and interactive elements.
*   **Map Parsing & Data Structures:** Efficiently parsing and representing complex map data from files.
*   **Graphical Programming:** Working with a low-level graphics library (MinilibX) for pixel-by-pixel rendering.
*   **Performance Optimization:** Considerations for rendering speed and smooth gameplay.

---
