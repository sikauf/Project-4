/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Jared Klein, Sam Kaufman
 * jaredkle, sikauf
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include "Position.h"
#include "utility.h"


Position::Position() {
    row = 0;
    col = 0;
}

Position::Position(int row_in, int col_in) {
    row = check_range(row_in);
    col = check_range(col_in);
}

Position::Position(char row_in, char col_in) {
    row = check_range(row_in - 49);
    if (col_in >= 65 && col_in <= 72) {
        col = check_range(col_in - 65);
    }
    else {
        col = check_range(col_in - 97);
    }
}

int Position::get_row() {
    return row;
}

void Position::set_row(int row_in) {
    row = check_range(row_in);
}

int Position::get_col() {
    return col;
}

void Position::set_col(int col_in) {
    col = check_range(col_in);
}

void Position::read(istream &is) {
    string input;
    is >> input;
    if (input.at(0) == '(') {
        row = check_range(input.at(1) - 49);
        if (input.at(3) >= 65 && input.at(3) <= 72) {
            col = check_range(input.at(3) - 65);
        }
            else {
                col = check_range(input.at(3) - 97);
            }
        }
    else {
        row = check_range(input.at(0) - 49);
        if (input.at(1) >= 65 && input.at(1) <= 72) {
            col = check_range(input.at(1) - 65);
        }
            else {
                col = check_range(input.at(1) - 97);
            }
    }
}

void Position::write(ostream &os) {
    int newRow = row + 1;
    char newCol = col + 65;
    os << "(" << newRow << "," << newCol << ")";
}

int Position::check_range(int val) {
    if (val >= 0 && val < MAX_GRID_SIZE) {
        return val;
    }
    else if (val > MAX_GRID_SIZE) {
        return MAX_GRID_SIZE - 1;
    }
    else {
        return 0;
    }
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
