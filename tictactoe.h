#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include "player.h"

class tictactoe
{
private:
    std::vector<std::vector<int>> tictactoe_map;
public:
    bool playAgain;

    tictactoe(/* args */);
    ~tictactoe();
    int add_elem(int& row, int& col, player& player);
    void start_game(tictactoe& tictactoe_inst, player player1, player player2);
    void exit_game();
    bool playagain();
    int checkWinner();
    void print_map();
    void clear_map();
};