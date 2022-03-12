/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <fstream>

#include "Player.h"


Player::Player() {
    // TODO: write implementation here.
}

Player::Player(string name_val) {
    // TODO: write implementation here.
}

void Player::init_grid() {
    // TODO: write implementation here.
    return;
}

string Player::get_name() {
    // TODO: write implementation here.
    return "";
}

int Player::get_num_ships() {
    // TODO: write implementation here.
    return -1;
}

int Player::get_remaining_ships() {
    // TODO: write implementation here.
    return -1;
}

char Player::get_grid_at(int row, int col) {
    // TODO: write implementation here.
    return '?';
}

char Player::get_guess_grid_at(int row, int col) {
    // TODO: write implementation here.
    return '?';
}

void Player::add_ship(Ship ship) {
    // TODO: write implementation here.
    return;
}

void Player::attack(Player &opponent, Position pos) {
    // TODO: write implementation here.
    return;
}

void Player::announce_ship_sunk(int size) {
    // TODO: write implementation here.
    return;
}

bool Player::load_grid_file(string filename) {
    // TODO: write implementation here.
    return false;
}

bool Player::destroyed() {
    // TODO: write implementation here.
    return false;
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
    ::print_grid(grid);
}

void Player::print_guess_grid() {
    ::print_grid(guess_grid);
}
