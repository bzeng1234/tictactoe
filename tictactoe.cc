#include "tictactoe.h"
#include "player.h"

tictactoe::tictactoe(/* args */)
:tictactoe_map(3, std::vector<int>(3,0))
{
}

tictactoe::~tictactoe()
{
}

void tictactoe::print_map()
{
    std::cout << "---------" << std::endl;
    for(int i = 0; i < tictactoe_map.size();i++)
    {
        for(int j = 0; j < tictactoe_map[i].size();j++)
        {
            std::cout << "|" << tictactoe_map[i][j] << "|";
        }
        std::cout << std::endl << "---------" << std::endl;
    }
}

int tictactoe::add_elem(int& row, int& col, player& player)
{
    if(row >= tictactoe_map.size() || col >= tictactoe_map[0].size())
        return 0;

    if(tictactoe_map[row][col] > 0)
        return 0;

    tictactoe_map[row][col] = player.getNum();
    return 1;
}

void tictactoe::start_game(tictactoe& tictactoe_inst, player player1, player player2)
{
    player current_player = player1;
    int row, col;
    while(checkWinner() == 0)
    {
        std::cout << "Player " << current_player.getNum() << ", choose your index"<< std::endl;
        std::cin >> row >> col;
        std::cout << "Player " << current_player.getNum() << ", has selected row:"<< row << " and column:" << col << std::endl;

        while(!tictactoe_inst.add_elem(row, col, current_player))
        {
            std::cout << "That index is either invalid or has been selected, choose a different index" << std::endl;
            std::cout << "Player " << current_player.getNum() << ", choose your index"<< std::endl;
            std::cin >> row >> col;
            std::cout << "Player " << current_player.getNum() << ", has selected row:"<< row << " and column:" << col << std::endl;
        }

        tictactoe_inst.print_map();

        int nextid = current_player.nextPlayer(current_player.getNum());
        if(nextid == 2)
            current_player = player2;
        else if (nextid == 1)
            current_player = player1;
    }
    std::cout <<"Player "<< checkWinner() << " won!!!" << std::endl;
}

int tictactoe::checkWinner()
{
    //check all rows if the same
    for(int i = 0; i < tictactoe_map.size();i++)
    {
        if(tictactoe_map[i][0] == tictactoe_map[i][1] && tictactoe_map[i][1] == tictactoe_map[i][2] && tictactoe_map[i][0] != 0)
            return tictactoe_map[i][0];
    }

    //check all columns if the same
    for(int i = 0; i < tictactoe_map[0].size();i++)
    {
        if(tictactoe_map[0][i] == tictactoe_map[1][i] && tictactoe_map[1][i] == tictactoe_map[2][i] && tictactoe_map[0][i] != 0)
            return tictactoe_map[0][i];
    }
    
    //check diagonal from top left to bottom right
    if(tictactoe_map[0][0] == tictactoe_map[1][1] && tictactoe_map[1][1] == tictactoe_map[2][2] && tictactoe_map[0][0] != 0)
        return tictactoe_map[0][0];
    
    // check for diagonal from top right to bottom left
    if(tictactoe_map[0][2] == tictactoe_map[1][1] && tictactoe_map[1][1] == tictactoe_map[2][0] && tictactoe_map[0][2] != 0)
        return tictactoe_map[0][2];

    //if there is still 0 on map, play on...
    for(int i = 0; i < tictactoe_map.size();i++)
    {
        for(int j = 0; j < tictactoe_map[i].size();j++)
        {
            if(tictactoe_map[i][j] == 0)
                return tictactoe_map[i][j];
        }
    }

    //all box is filled but no winner
    return -1;
}
