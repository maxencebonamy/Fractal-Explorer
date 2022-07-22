#ifndef MINESWEEPER_CONFIG_H
#define MINESWEEPER_CONFIG_H

#include "vector2.h"
#include <vector>
#include <iostream>
#include "fractal.h"

extern const std::string WINDOW_TITLE;
extern const int WINDOW_FPS;

extern const Vector2 GRID_SIZE;

extern const float CELL_SIZE;
extern const Vector2 WINDOW_SIZE;

extern std::unique_ptr<Fractal> fractal;

#endif
