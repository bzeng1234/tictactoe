#include "tictactoe.h"
#include "player.h"
#include <cctype>

tictactoe::tictactoe(/* args */)
:tictactoe_map(3, std::vector<int>(3,0)),
playAgain(true)
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

void tictactoe::clear_map()
{
    for(int i = 0; i < tictactoe_map.size();i++)
    {
        for(int j = 0; j < tictactoe_map[i].size();j++)
        {
            tictactoe_map[i][j] = 0;
        }
    }
}

void tictactoe::start_game(tictactoe& tictactoe_inst, player player1, player player2)
{
    player current_player = player1;
    int row, col;

    while(playAgain == true)
    {
        row = current_player.chooseRow();
        col = current_player.chooseColumn();

        while(!tictactoe_inst.add_elem(row, col, current_player))
        {
            row = current_player.chooseRow();
            col = current_player.chooseColumn();
        }

        tictactoe_inst.print_map();

        int result = checkWinner();
        if(result == 0)
        {
            current_player = current_player.nextPlayer(current_player.getNum(), player1, player2);
        }
        else if(result >= 1){
            std::cout <<"Player "<< current_player.getNum() << " won!!!" << std::endl;
            playAgain = playagain();
            clear_map();
        }
        else if(result == -1){
            std::cout <<"Both players tied game "<< std::endl;
            playAgain = playagain();
        }
    }
    exit_game();
}

void tictactoe::exit_game()
{
    std::cout << "Thanks for playing!!!" << std::endl;
}

bool tictactoe::playagain()
{
    char response;
    std::cout << "Do you want to play again? [Y,N]" << std::endl;
    std::cin >> response;
    toupper(response);
    while(response != 'Y' && response != 'N')
    {
        std::cout << "Invalid Response, do you want to play again? [Y,N]" << std::endl;
        std::cin >> response;
    }
    switch (response)
    {
    case 'Y':
        return true;
        break;
    case 'N':
        return false;
        break;
    default:
        break;
    }
    return 0;
}

int tictactoe::add_elem(int& row, int& col, player& player)
{
    if(row >= tictactoe_map.size() || col >= tictactoe_map[0].size())
    {
        std::cout << "That index is invalid, please choose a different index" << std::endl;
        return 0;
    }

    if(tictactoe_map[row][col] > 0)
    {
        std::cout << "That index has already been selected, please choose a different index" << std::endl;
        return 0;
    }

    tictactoe_map[row][col] = player.getNum();
    return 1;
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
