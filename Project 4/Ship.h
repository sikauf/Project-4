/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.h
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 * Project 4: Battleship
 *
 * Represents a ship.
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "Position.h"
#include "utility.h"


class Ship {
 public:

    /**
     * Requires: Nothing.
     * Modifies: start, end, size, num_hits.
     * Effects:  Default constructor. Sets start and end to origin (0,0),
     *           num_hits to 0, and size to 0.
     */
    Ship();

    /**
     * Requires: start_in and end_in both represent valid and distinct
     *           positions on the grid and align either vertically or horizontally.
     *           Diagonal or L-shaped ships are not allowed. 
     * Modifies: start, end, size, num_hits.
     * Effects:  Non-default constructor. Sets start and end to start_in and
     *           end_in respectively and num_hits to 0.
     *           The size should be determined by the start and end positions.
     *
     * Note:     You will want to implement the member function
     *           is_horizontal() before implementing this constructor.
     */
    Ship(Position start_in, Position end_in);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the start position of the ship.
     */
    Position get_start();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the end position of the ship.
     */
    Position get_end();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the size of the ship.
     */
    int get_size();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if the ship is horizontal and false if the ship
     *           is vertical. For example, if start and end have the same row value, 
     *           the ship is horizontal, so return true.
     *
     * Note:     This function may be useful in implementing has_position()
     */
    bool is_horizontal();

    /**
     * Requires: pos must be a valid position in the grid.
     * Modifies: Nothing.
     * Effects:  Returns true if pos is in the range [start, end] or [end, start].
     *           Otherwise, return false.
     */
    bool has_position(Position pos);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Increments the num_hits if num_hits is less than size
     */
    void hit();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if the num_hits equals the size of the ship.
     *           Otherwise, return false.
     */
    bool has_sunk();

 private:
    Position start;
    Position end;
    int size;
    int num_hits;
};

#endif  // SHIP_H_
