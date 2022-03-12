/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.h
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 * Project 4: Battleship
 *
 * Represents a position point in a grid.
 */

#ifndef POSITION_H_
#define POSITION_H_

#include <iostream>

using namespace std;


class Position {
 public:
    /**
     * Requires: Nothing.
     * Modifies: row, col.
     * Effects:  Default constructor. Sets position to origin (0,0).
     */
    Position();

    /**
     * Requires: Nothing.
     * Modifies: row, col.
     * Effects:  Constructs a position and sets row and col positions.
     *
     * Note:     You will need to implement the member function
     *           check_range() before implementing this one. This will
     *           help make sure row_in and col_in are valid.
     */
    Position(int row_in, int col_in);

    /**
     * Requires: Nothing.
     * Modifies: row, col.
     * Effects:  Constructs a position and sets row and col positions.
     *           You must convert the character position to its integer
     *           equivalent position (see example). Also, case should not matter for col_in.
     *
     * Example:
     *           '1' should be 0 for row, '2' should be 1 for row, and so on.
     *           'A' or 'a' should be 0 for col, 'B' or 'b' should be 1 for col and so on.
     *
     * Note:     You will need to implement the member function
     *           check_range() before implementing this one. This will
     *           help make sure row_in and col_in are valid.
     */
    Position(char row_in, char col_in);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns row position.
     */
    int get_row();

    /**
     * Requires: Nothing.
     * Modifies: row.
     * Effects:  Sets row position.
     *           Note: must call check_range.
     */
    void set_row(int row_in);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns col position.
     */         
    int get_col();

    /**
     * Requires: Nothing.
     * Modifies: col.
     * Effects:  Sets col position.
     *           Note: must call check_range.
     */     
    void set_col(int col_in);

    /**
     * Requires: is stream in good state.
     * Modifies: is, row, col.
     * Effects:  Reads position in format rowcol, e.g., "1A". If it is not in
     *           that format or the operation fails, it will try to read
     *           position using format (row,col), e.g., "(1,A)"
     *           col is NOT case senstive, so reading should work for, 
     *           e.g., "(1,a)" or "1a". 
     *  
     * Hint:     Take advantage of the fail-state flag in an input stream.
     *
     * Example:  An input of (1,A) should result in row being 0 and col being 0.
     *           An input of 1A should result in row being 0 and col being 0.
     *
     * Note:     You will need to implement the member function
     *           check_range() before implementing this one.
     */
    void read(istream &is);

    /**
     * Requires: os is in good state.
     * Modifies: os.
     * Effects:  Writes position in form (row,col) where row is in range [1, 8]
     *           and col should be an uppercase letter in range [A, H].
     */
    void write(ostream &os);

 private:
    int row;
    int col;
     
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  Returns val if val is in range [0,MAX_GRID_SIZE),
     *           otherwise returns the closest of 0 and MAX_GRID_SIZE - 1 to val.
     *
     * Example: check_range(-10) would return 0
     */
    int check_range(int val);

};

/**
 * Overloading >> and << for reading a Position from streams.
 * Example on how to use these:
 * Position pos;
 * cout << "Please enter a position using format (row,col) : ";
 * cin >> pos;
 * cout << "\nthe position you just entered is: ";
 * cout << pos << endl;
 */
istream &operator>>(istream &ins, Position &pos);
ostream &operator<<(ostream &outs, Position pos);

#endif  // POSITION_H_
