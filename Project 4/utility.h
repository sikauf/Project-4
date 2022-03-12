/**
 * Copyright University of Michigan EECS183
 *
 * utility.h
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Project 4: Battleship
 *
 * Contains constants and helper functions.
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <sys/types.h>
#include <ctime>
#include <limits>
#include <chrono>

using namespace std;

//////////////////////////////////////////////////////////////////////
// GLOBAL CONSTANTS                                                 //
// ----------------                                                 //
// These constants should be used where appropriate.                //
//////////////////////////////////////////////////////////////////////

const int MAX_GRID_SIZE = 8;

const int MAX_SHIP_SIZE = 5;
const int MAX_NUM_SHIPS = 5;
const int MAX_ROUNDS = 20;

const char EASY = 'E';
const char MEDIUM = 'M';
const char EMULATE = 'S';

const char EMPTY_LETTER = '-';
const char SHIP_LETTER = '*';
const char HIT_LETTER = 'O';
const char MISS_LETTER = 'X';

//////////////////////////////////////////////////////////////////////
// STAFF-IMPLEMENTED UTILITY FUNCTIONS                              //
// -----------------------------------                              //
// These are functions you will likely need to call in your         //
// solution or test suite.                                          //
//////////////////////////////////////////////////////////////////////

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints grid.
 */
void print_grid(char grid[MAX_GRID_SIZE][MAX_GRID_SIZE]);

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints initial header.
 */
void print_initial_header();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints menu.
 */
void print_menu();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints closer.
 */
void print_closer();

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns a random integer.
 */
int get_random_number();

/**
 * Requires: Nothing.
 * Modifies: cin, cout.
 * Effects:  Prints menu and continously gets menu choice from 
 *           keyboard input until a choice in the valid range is entered.
 */
int get_menu_choice();

#endif  // UTILITY_H_
