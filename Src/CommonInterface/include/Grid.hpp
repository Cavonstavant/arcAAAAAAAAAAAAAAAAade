/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** Grid
*/

#ifndef ARCADE_GRID_HPP
#define ARCADE_GRID_HPP

/// \brief The number of pixels in a grid cell
#define TILE_SIZE 32
/// \brief The number of horizontal cells in the grid
#define GRID_WIDTH 32
/// \brief The number of vertical cells in the grid
#define GRID_HEIGHT 32

/// \brief The default graphical window width
#define DEFAULT_WINDOW_WIDTH (GRID_WIDTH * TILE_SIZE)
/// \brief The default graphical window height
#define DEFAULT_WINDOW_HEIGHT (GRID_HEIGHT * TILE_SIZE)

/// \brief The minimum width of the terminal
#define MINIMUM_TERM_WIDTH (GRID_WIDTH)
/// \brief The minimum height of the terminal
#define MINIMUM_TERM_HEIGHT (GRID_HEIGHT)

/// \brief Gets a position in a window from a position in the grid
#define GRID_INT(x) x * TILE_SIZE
/// \brief Gets a pair of positions in a window from a pair of positions in the grid
#define GRID_PAIR(x) std::make_pair(GRID_INT(x.first), GRID_INT(x.second))

#endif
