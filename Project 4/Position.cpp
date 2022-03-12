/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include "Position.h"
#include "utility.h"


Position::Position() {
    // TODO: write implementation here.
}

Position::Position(int row_in, int col_in) {
    // TODO: write implementation here.
}

Position::Position(char row_in, char col_in) {
    // TODO: write implementation here.
}

int Position::get_row() {
    // TODO: write implementation here.
    return -1;
}

void Position::set_row(int row_in) {
    // TODO: write implementation here.
    return;
}

int Position::get_col() {
    // TODO: write implementation here.
    return -1;
}

void Position::set_col(int col_in) {
    // TODO: write implementation here.
    return;
}

void Position::read(istream &is) {
    // TODO: write implementation here.
    return;
}

void Position::write(ostream &os) {
    // TODO: write implementation here.
    return;
}

int Position::check_range(int val) {
    // TODO: write implementation here.
    return -1;
}


// Your code goes above this line.
// Don't change the implementations below!

istream &operator>>(istream &is,  Position &pos) {
    pos.read(is);
    return is;
}

ostream &operator<<(ostream &os, Position pos) {
    pos.write(os);
    return os;
}

