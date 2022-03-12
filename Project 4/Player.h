/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.h
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 * Project 4: Battleship
 *
 * Represents a player.
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

#include "Position.h"
#include "Ship.h"
#include "utility.h"

using namespace std;

class Player {
 public:
    /**
     * Requires: Nothing.
     * Modifies: name, num_ships, remaining_ships, grid, guess_grid.
     * Effects:  Default constructor. Sets name to an empty string,
     *           num_ships to 0, remaining_ships to 0, and initialize the grid.
     *
     * Note:     You will want to implement the member function
     *           init_grid() before implementing this constructor.
     */
    Player();

    /**
     * Requires: name_val is not an empty string.
     * Modifies: name, num_ships, remaining_ships, grid, guess_grid.
     * Effects:  Non-default constructor. Sets name to name_val,
     *           num_ships to 0, remaining_ships to 0, and initialize the grid.
     *
     * Note:     You will want to implement the member function
     *           init_grid() before implementing this constructor.
     */
    Player(string name_val);
    
    /**
     * Requires: Nothing.
     * Modifies: grid, guess_grid.
     * Effects:  Sets each element in both grid and guess_grid to
     *           EMPTY_LETTER.
     */
    void init_grid();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the name of the player.
     */
    string get_name();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the number of ships of the player.
     */
    int get_num_ships();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the number of remaining ships of the player.
     */
    int get_remaining_ships();

    /**
     * Requires: row and col are valid positions in grid.
     * Modifies: Nothing.
     * Effects:  Returns the element at row, col of grid.
     */
    char get_grid_at(int row, int col);

    /**
     * Requires: row and col are valid positions in guess_grid.
     * Modifies: Nothing.
     * Effects:  Returns the element at row, col of guess_grid.
     */
    char get_guess_grid_at(int row, int col);

    /**
     * Requires: ship is a valid ship with start/end positions that 
     *           do not intersect with previously added ships. 
     * Modifies: ships, num_ships, remaining_ships, grid.
     * Effects:  Adds the ship to the next available index of ships and
     *           increment num_ships and remaining_ships.
     *           Set the positions on grid with SHIP_LETTER based on the
     *           start and end of ship. 
     *           If num_ships is already equall to MAX_NUM_SHIPS,
     *           the function should return without making any changes. 
     */
    void add_ship(Ship ship);

    /**
     * Requires: pos is a valid position.
     * Modifies: opponent, guess_grid, cout.
     * Effects:  If the pos is part of an opponent's ship that hasn't been hit 
     *           yet, hit that ship and mark both the opponent's grid and 
     *           the current player's guess_grid as HIT_LETTER at pos.
     *
     *           Otherwise, if pos is not a position in the opponent's ships
     *           (i.e. a miss), mark both the opponent's grid and the current
     *           player's guess_grid as MISS_LETTER.
     *
     *           If pos is already hit or miss for the opponent, the move is
     *           considered as a miss.
     *
     *           On hit, print the attacking player's name, the position,
     *           and "hit".
     *           On miss, print the attacking player's name, the position,
     *           and "miss".
     *
     *           If hitting the ship causes that ship to
     *           sink, decrement the opponent's remaining_ships, and use
     *           announce_ship_sunk() to print message.
     *
     * Example:
     *           [name] [pos] hit
     *           [name] [pos] miss
     */
    void attack(Player &opponent, Position pos);

    /**
     * Requires: size is [2, 5].
     * Modifies: cout.
     * Effects:  Prints a congratulating message followed by the name and the
     *           type of ships that was sunk.
     *
     * Example:
     *           if size = 2: "Congratulations [name]! You sunk a Destroyer"
     *           if size = 3: "Congratulations [name]! You sunk a Submarine"
     *           if size = 4: "Congratulations [name]! You sunk a Battleship"
     *           if size = 5: "Congratulations [name]! You sunk a Carrier"
     */
    void announce_ship_sunk(int size);
    
     /**
     * Requires: Nothing.
     * Modifies: ships, num_ships, remaining_ships, grid.
     * Effects: use filename to open a file stream and read in the start
     *          and end positions for each ship to be added. Returns true
     *          if the file opened successfully; false otherwise.
     *
     *          Note: should call add_ship function.
     *
     *          Note: The number of ships in the file <filename> may not
     *                be exactly MAX_NUM_SHIPS.
     */
    bool load_grid_file(string filename);
 
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if remaining_ships equal zero.
     *           Otherwise return false.
     */
    bool destroyed();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Prints grid.
     */
    void print_grid();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Prints guess_grid.
     */
    void print_guess_grid();

 private:
    string name;
    int num_ships;
    int remaining_ships;
    Ship ships[MAX_NUM_SHIPS];
    char grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
    char guess_grid[MAX_GRID_SIZE][MAX_GRID_SIZE];

};

#endif  // PLAYER_H_
