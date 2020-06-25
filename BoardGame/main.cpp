#include "TicTacToe.h"
#include "CatchTheBunny.h"
#include "Move.h"
#include "Interface.h"
#include <iostream>
#include "BoardGameController.h"

int main()
{
    BoardGameController game;
    game.play();
}

// void printMap(std::vector<std::vector<char>> map)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//             std::cout << map[i][j] << " ";
//         std::cout << std::endl;
//     }
//     std::cout << std::endl;
// }

// int main()
// {
//     std::vector<std::string> enumConv{"Player wins", "Computer wins", "Tie", "In Progress"};

//     CatchTheBunny *game;
//     int choice = 0;
//     std::cout << "Enter the game you'd like to play - " << std::endl;
//     std::cin >> choice;

//     if (choice == 1)
//         game = new CatchTheBunnyRand();
//     if (choice == 2)
//         game = new CatchTheBunnyEdu();

//     Move m;
//     m.setMove(-1, -1);
//     std::vector<std::vector<char>> map;
//     map.resize(9);
//     for (int i = 0; i < 9; i++)
//         for (int j = 0; j < 9; j++)
//             map[i].push_back('-');

//     Move ply = game->getPlayerPosition();
//     Move bun = game->getBunnyPosition();

//     map[ply.getX()][ply.getY()] = 'P';
//     map[bun.getX()][bun.getY()] = 'B';

//     printMap(map);

//     // while (game->getGameState() == 3)
//     // {
//     //     try
//     //     {
//     //         game->getPlayerMove(m);
//     //         map[m.getX()][m.getY()] = 'X';
//     //         printMap(map);

//     //         if (game->getGameState() == InProgress)
//     //         {
//     //             game->getComputerMove(m);
//     //             map[m.getX()][m.getY()] = 'O';
//     //             printMap(map);
//     //         }
//     //     }
//     //     catch (const char *e)
//     //     {
//     //         std::cout << e << std::endl;
//     //     }
//     // }

//     while (game->getGameState() == InProgress)
//     {
//         try
//         {
//             Move tmp = game->getPlayerPosition();
//             std::cout << "Player position is: " << tmp.getX() << " " << tmp.getY() << std::endl;

//             game->getPlayerMove(m);
//             map[tmp.getX()][tmp.getY()] = '-';
//             map[m.getX()][m.getY()] = 'P';
//             printMap(map);

//             if(game->getGameState() == PlayerWins)
//                 continue;

//             tmp = game->getBunnyPosition();
//             game->getComputerMove(m);
//             map[tmp.getX()][tmp.getY()] = '-';
//             map[m.getX()][m.getY()] = 'B';
//             std::cout << "Bunny's next move is - " << std::endl;
//             printMap(map);
//         }
//         catch (const char *e)
//         {
//             std::cout << e << '\n';
//             continue;
//         }
//     }

//     std::cout << enumConv[game->getGameState()] << std::endl;
// }



/////////---------------------------------//////////////
    // int typeOfGame;
    // int diffucltyLvl;
    // BoardGame *game;
    // Interface *view;
    // Move player;
    // Move computer;

    // std::cout << "Insert the Game you'd like to play\n 1.Tic Tac Toe\n2.Catch The Bunny" << std::endl;
    // std::cin >> typeOfGame;
    // std::cout << "Choose difficulty:\n1.Easy\n2.Super AI Hell level difficulty" << std::endl;
    // std::cin >> diffucltyLvl;

    // if ((typeOfGame == 1) && (diffucltyLvl == 1))
    // {
    //     game = new TicTacToeRand();
    //     view = new ConsoleBoardTicTacToe();
    // }

    // if (typeOfGame == 1 && diffucltyLvl == 2)
    // {
    //     game = new TicTacToeEdu();
    //     view = new ConsoleBoardTicTacToe();
    // }

    // if (typeOfGame == 2 && diffucltyLvl == 1)
    // {
    //     game = new CatchTheBunnyRand(player, computer);
    //     view = new ConsoleBoardCatchTheBunny(player, computer);
    // }

    // if (typeOfGame == 2 && diffucltyLvl == 2)
    // {
    //     game = new CatchTheBunnyEdu(player, computer);
    //     view = new ConsoleBoardCatchTheBunny(player, computer);
    // }

    // view->draw(game->getGameState());

    // while (game->getGameState() == InProgress)
    // {
    //     try
    //     {
    //         game->getPlayerMove(player);
    //         view->update(player, 0);
    //         std::cout << "The player move is:" << std::endl;
    //         view->draw(game->getGameState());

    //         if (game->getGameState() != InProgress)
    //             break;
    //     }
    //     catch (const char *er)
    //     {
    //         std::cout << er << std::endl;
    //         continue;
    //     }

    //     game->getComputerMove(computer);
    //     view->update(computer, 1);
    //     std::cout << "The computer move is:" << std::endl;
    //     view->draw(game->getGameState());
    // }