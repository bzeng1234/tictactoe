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
    int nextPlayer(int playerid);
    ~player();
};

