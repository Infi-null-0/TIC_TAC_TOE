/*
 * This is a C++ program to implement a digital tic tac toe game.
 * developed by Sedhu Madhav B
 * in the year 2023
 */

#include <iostream>
#include <stdlib.h>
#include <limits>

class TIC_TAC_TOE
{

private:
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    short int choice;
    short int row, column;

public:
    short int round = 0;
    char turn = 'X';
    bool draw = false;

public:
    // show
    static char show(const char &c)
    {
        if (c == 'X')
            return 'X';
        else if (c == 'O')
            return 'O';
        else
            return ' ';
    }

    // initial rule board
    static void rule_board()
    {
        ////players
        std::cout << "\t PLAYER - 1 [X]  PLAYER - 2 [O]\n\n";
        ////board
        std::cout << "\t\t     |     |     \n";
        std::cout << "\t\t  1  |  2  |  3  \n";
        std::cout << "\t\t_____|_____|_____\n";
        std::cout << "\t\t     |     |     \n";
        std::cout << "\t\t  4  |  5  |  6  \n";
        std::cout << "\t\t_____|_____|_____\n";
        std::cout << "\t\t     |     |     \n";
        std::cout << "\t\t  7  |  8  |  9  \n";
        std::cout << "\t\t     |     |     \n";
    }

    // initialize terminal
    static void _INIT_TERMINAL()
    {
        system("cls");
        std::cout << "\tT I C -- T A C -- T O E -- G A M E\t";
        std::cout << "\n\t\t  FOR 2 PLAYERS\n";
    }

    // function to render game board layout
    void show_board()
    {
        ////players
        std::cout << "\t PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
        ////board
        std::cout << "\t\t     |     |     \n";
        std::cout << "\t\t  " << show(board[0][0]) << "  |  " << show(board[0][1]) << "  |  " << show(board[0][2]) << " \n";
        std::cout << "\t\t_____|_____|_____\n";
        std::cout << "\t\t     |     |     \n";
        std::cout << "\t\t  " << show(board[1][0]) << "  |  " << show(board[1][1]) << "  |  " << show(board[1][2]) << " \n";
        std::cout << "\t\t_____|_____|_____\n";
        std::cout << "\t\t     |     |     \n";
        std::cout << "\t\t  " << show(board[2][0]) << "  |  " << show(board[2][1]) << "  |  " << show(board[2][2]) << " \n";
        std::cout << "\t\t     |     |     \n";
    };

    // gets choice and fills board
    void player_turn()
    {
        if (turn == 'X')
        {
            std::cout << "\n\t      Player - 1 [X] turn : ";
        }
        else if (turn == 'O')
        {
            std::cout << "\n\t      Player - 2 [O] turn : ";
        }
        std::cin >> choice; //// choice of box

        //// define row and column
        switch (choice)
        {
        case 1:
            row = 0;
            column = 0;
            break;
        case 2:
            row = 0;
            column = 1;
            break;
        case 3:
            row = 0;
            column = 2;
            break;
        case 4:
            row = 1;
            column = 0;
            break;
        case 5:
            row = 1;
            column = 1;
            break;
        case 6:
            row = 1;
            column = 2;
            break;
        case 7:
            row = 2;
            column = 0;
            break;
        case 8:
            row = 2;
            column = 1;
            break;
        case 9:
            row = 2;
            column = 2;
            break;
        default:
            std::cout << "\t\t   Invalid Move\n";
            player_turn();
            return;
        }

        if (board[row][column] == 'X' || board[row][column] == 'O')
        {
            //// if input position already filled
            std::cout << "\t\tBox already filled!\n\t      Please choose another!!\n\n";
            player_turn();
            return;
        }
        else if (turn == 'X')
        {
            //// fill 'X'
            board[row][column] = 'X';
            turn = 'O';
        }
        else if (turn == 'O')
        {
            //// fill 'O'
            board[row][column] = 'O';
            turn = 'X';
        }
    };

    // check if gameover
    bool gameover()
    {
        //// row and column check
        for (int i = 0; i < 3; i++)
            if (((board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) || ((board[0][i] == board[1][i]) && (board[0][i] == board[2][i])))
                return true;
        //// diagonal check
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
            return true;
        //// is any space left ?
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;

        ////game draw
        draw = true;
        return true;
    }

    static void run_game()
    {
        //// newgame
        TIC_TAC_TOE new_game;

        //// while game not over
        while (!new_game.gameover())
        {
            TIC_TAC_TOE::_INIT_TERMINAL();
            if (new_game.round == 0)
            {
                new_game.rule_board();
                new_game.player_turn();
                new_game.round++;
                continue;
            }
            new_game.show_board();
            new_game.player_turn();
            new_game.round++;
        }

        //// show board a last time
        TIC_TAC_TOE::_INIT_TERMINAL();
        new_game.show_board();
        //// draw
        if (new_game.draw)
            std::cout << "\n\nGAME DRAW!!!\n\n";
        //// winner X
        else if (new_game.turn == 'X')
            std::cout << "\n\nCongratulations!Player with 'O' has won the game";
        //// winner O
        else if (new_game.turn == 'O')
            std::cout << "\n\nCongratulations!Player with 'X' has won the game";

        // press any key to exit
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\n\t Press Enter key to exit ..! ";
        std::cin.get();
    }
};

int main()
{
    TIC_TAC_TOE::run_game();
    return 0;
}