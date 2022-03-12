/**
 * Copyright 2020 Umich EECS 183
 *
 * battleship.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Project 4: Battleship
 *
 * Driver of the Battleship game.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <utility>
#include <limits>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


void battleship() {

    // print the welcome message and get p1 name
    print_initial_header();
    string p1_name;
    cout << "Enter your name: ";
    cin >> p1_name;
    cout << endl;

    // create two Player instances, p2 is always named CPU
    Player p1(p1_name);
    Player p2("CPU");

    // initialize grid from file or random
    char p1_mode;
    cout << "Read your grid from file grid1.txt? (y or n): ";
    cin >> p1_mode;
    cout << endl;

    char p2_mode;
    cout << "Read CPU grid from file grid2.txt? (y or n): ";
    cin >> p2_mode;
    cout << endl;

    // declare and Game instance, set values
    Game battleship;
    if (p1_mode == 'y' && p2_mode == 'y') {
        battleship = Game(p1, "grid1.txt", p2, "grid2.txt");
    } else if (p1_mode == 'y' && p2_mode == 'n') {
        battleship = Game(p1, "grid1.txt", p2, "");
    } else if (p1_mode == 'n' && p2_mode == 'y') {
        battleship = Game(p1, "", p2, "grid2.txt");
    } else if (p1_mode == 'n' && p2_mode == 'n') {
        battleship = Game(p1, "", p2, "");
    } else {
        cout << "Error in input" << endl;
        return;
    }
    
    // get menu choice and play game
    int menu_choice = get_menu_choice();    
    if (menu_choice == 1) {
        cout << "Starting game with EASY AI" << endl << endl;
        battleship.start(EASY, MAX_ROUNDS);
    } else if (menu_choice == 2) {
        cout << "Starting game with MEDIUM AI" << endl << endl;
        battleship.start(MEDIUM, MAX_ROUNDS);
    } else if (menu_choice == 3) {
        cout << "Starting game with CPU EMULATION" << endl << endl;
        battleship.start(EMULATE, MAX_ROUNDS);
    }
    
    print_closer();

    return;
}
