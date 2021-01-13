#include "player.h"

int player::id = 0;


player::player(/*args*/)
:num(++id)
{    
}

player::~player()
{    
}

int player::getNum()
{
    return num;
}

int player::nextPlayer(int playerid)
{
    if(playerid == 1)
        return 2;
    else if (playerid == 2)
        return 1;
}
