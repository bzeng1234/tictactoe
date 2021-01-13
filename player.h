#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>

class player
{
private:
    int num;
public:
static int id;
    player(/* args */);
    int getNum();
    player nextPlayer(int playerid, player player1,player player2);
    int chooseRow();
    int chooseColumn();
    void printSelectedIndex(int row, int col);
    ~player();
};

