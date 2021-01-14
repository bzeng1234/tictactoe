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
    return this->num;
}

player player::nextPlayer(player player1,player player2)
{
    return (this->getNum() == 1) ? player2 : player1;
}

int player::chooseRow()
{
    int row = 0;
    std::cout << "Player " << this->getNum() << ", choose your row: ";
    std::cin >> row;
    return row;
}
int player::chooseColumn()
{
    int column = 0;
    std::cout << "Player " << this->getNum() << ", choose your column: ";
    std::cin >> column;
    return column;
}

void player::printSelectedIndex(int row, int col)
{
    std::cout << "Player " << this->getNum() << " chose [" <<row<<","<<col<<"]" << std::endl;
}
