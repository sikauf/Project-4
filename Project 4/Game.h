/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Game.h
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 * Project 4: Battleship
 *
 * Represents a game.
 */

#ifndef GAME_H_
#define GAME_H_

#include <string>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "utility.h"


class Game {
 public:
    /**
     * Requires: Nothing.
     * Modifies: p1, p2.
     * Effects:  Default constructor. Sets both p1 and p2 to a default-constructed player.
     */
    Game();

    /**
     * Requires: grid1 and grid2 are filenames and contain valid grid inputs.
     * Modifies: p1, p2, cout
     * Effects:  Non-default constructor.
     *           Sets p1 to player1 and p2 to player2.
     *
     *           If grid1 is an non-empty string, p1's grid should be read from
     *           file grid1 using Player::load_grid_file. If grid1 is empty or the grid
     *           file was not opened successfully, p1's grid should be randomly
     *           generated using a call to generate_random_grid.
     *
     *           If grid2 is an non-empty string, p2's grid should be read from
     *           file grid2 using Player::load_grid_file. If grid2 is empty or the grid
     *           file was not opened successfully, p2's grid should be randomly
     *           generated using a call to generate_random_grid.
     *          
     *           When a random grid is generated, it should print the prompt:
     *           "Generating random grid for [name]" where [name] is the name 
     *           of the player for which the grid was generated. 
     *
     */
    Game(Player player1, string grid1, Player player2, string grid2);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns p1.
     */
    Player get_p1();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns p2.
     */
    Player get_p2();

    /**
     * Requires: player_name is an existing player's name.
     * Modifies: cin, cout.
     * Effects:  Prompts the user for an input and returns it as a string.
     *           Note: no input validation is required here. 
     *
     * Prompt:   <player_name> enter your move:
     */
    string get_move(string player_name);

    /**
     * Requires: Nothing.
     * Modifies: cout.
     * Effects:  Checks if the move entered by player p1 is valid. Move is invalid if
     *           Error 1: it is not a string of length 2 or
     *           Error 2: the row or column is out of bounds on the grid (i.e.,
     *           row is not between 1 and 8 or col is not in between A and H).
     *           Errors should be checked in the above order.
     *           Note: Lowercase letters are considered valid input.
     *           If the move is invalid for either one of the errors, the appropriate
     *           error message should be printed. Returns false immediately
     *           after identifying an error; otherwise returns true. 
     *
     * Prompt:   If error 1 occurs, print:
     *           "<p1 name> you entered an invalid input"
     *
     *           If error 2 occurs, print:
     *           "<p1 name> you entered an invalid position"
     *
     *           Note: move format is '[1-8][A-H]' i.e "1A", "3b"
     */
    bool check_valid_move(string move);

    /**
     * Requires: Nothing.
     * Modifies: p1, p2, cout.
     * Effects:  Starts the game. The argument difficulty represents EASY or
     *           MEDIUM and max_num_rounds indicates the maximum number of rounds.
     *           p1 is prompted for a position to attack each turn, and p2's
     *           attack will be randomly generated. p1 should be continuously prompted
     *           until they enter a valid move. After each round, once both
     *           players have made a move, print out your grid and
     *           guess grid.
     *
     *           The game will continue until either p1 or p2  has all their ships sunk
     *           or the number of completed rounds has reached max_num_rounds.
     *           Once the game is over, the winner will be announced along with
     *           how many moves it took for the winner to win, followed by a
     *           closing message.
     *      
     *           NOTE: The round in which either the `p1` or `p2` win should be 
     *           counted. Also, the grids for both players should be printed 
     *           regardless of whether the round is a winning round. 
     *           
     *           IMPORTANT: If either player has won during a round, the following 
     *           player should not be able to make a move since they already lost.
     *
     * Prompt:  When printing YOUR grid:
     *           "<p1 name> enter your move: " <new line>
     *           "Your grid" <new line>
     *           <Your Grid>
     *
     *           When printing GUESS_GRID's grid:
     *           "<p2 name>'s grid" <new line>
     *           <Your Guess Grid>
     *
     *           When game is over, print:
     *           "Game over, winner is <winner name> in <num of rounds> rounds"
     *
     *           Hint: This function will call many other functions,
     *           check the function table in the spec.
     *  
     * Functions called by start: Player::destroyed(), Game::get_move(), 
     *           Game::check_valid_move(), Player::get_name(), Player::attack(), 
     *           Player::print_grid(), Player::print_guess_grid(), 
     *           Game::opponent_make_move()
     */
    void start(char difficulty, int max_num_rounds);

 private:
    Player p1;
    Player p2;

    /**
     * Requires: Nothing.
     * Modifies: p2.
     * Effects:  Generates a random grid for p. p will have one
     *           ship of each of the following sizes: 2, 3, 4, and 5.
     */
    void generate_random_grid(Player &p);

    /**
     * Requires: diffculty is either EASY or MEDIUM.
     * Modifies: p1, p2, cout.
     * Effects:  The opponent will make a random move. The difficulty of the
     *           opponent is determined by difficulty.
     *
     *           After your opponent makes a move print:
     *           "You received an attack at <position>"
     */
    void opponent_make_move(char difficulty);
    
};

#endif  // GAME_H_
