/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <cmath>

#include "Ship.h"


Ship::Ship() {
    start.set_row(0);
    start.set_col(0);
    end.set_row(0);
    end.set_col(0);
    size = 0;
    num_hits = 0;
}

Ship::Ship(Position start_in, Position end_in) {
    // TODO: write implementation here.
}

Position Ship::get_start() {
    
    return start;
}

Position Ship::get_end() {
    
    return end;
}

int Ship::get_size() {
    // TODO: write implementation here.
    return -1;
}

bool Ship::is_horizontal() {
    if (start.get_row() == end.get_row()){
        return true;
    } else {
    return false;
    }
}

bool Ship::has_position(Position pos) {
    // TODO: write implementation here.
    return false;
}

void Ship::hit() {
    // TODO: write implementation here.
    return;
}

bool Ship::has_sunk() {
    // TODO: write implementation here.
    return false;
}
