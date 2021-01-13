#include <stdio.h>
#include <iostream>
#include <vector>
#include "tictactoe.h"
#include "player.h"

int main()
{
    std::cout << "Welcome to Tic Tac Toe, Player 1 and 2 \nTo choose your coordinates please type in [row,col] as in the specified format." << std::endl;
    
    tictactoe tictactoe_inst;
    tictactoe_inst.print_map();
    
    player player1;
    player player2;

    //std::cout << "Player " << player1.getNum() << " has been created." << std::endl;
    //std::cout << "Player " << player2.getNum() << " has been created." << std::endl;

    std::cout << "Lets begin...\n\n";

    tictactoe_inst.start_game(tictactoe_inst, player1, player2);
    return 0;
}