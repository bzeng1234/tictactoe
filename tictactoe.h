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
    tictactoe(/* args */);
    ~tictactoe();
    int add_elem(int& row, int& col, player& player);
    void start_game(tictactoe& tictactoe_inst, player player1, player player2);
    int checkWinner();
    void print_map();
};