#include "BoardGameController.h"

void BoardGameController::play()
{
    int typeOfGame;
    int diffucltyLvl;
    Move player;
    Move computer;

    std::cout << "Insert the Game you'd like to play\n 1.Tic Tac Toe\n2.Catch The Bunny" << std::endl;
    std::cin >> typeOfGame;
    std::cout << "Choose difficulty:\n1.Easy\n2.Super AI Hell level difficulty" << std::endl;
    std::cin >> diffucltyLvl;

    if ((typeOfGame == 1) && (diffucltyLvl == 1))
    {
        _game = std::unique_ptr<BoardGame>(new TicTacToeRand());
        _view = std::unique_ptr<ConsoleBoard>(new ConsoleBoardTicTacToe());
    }

    if (typeOfGame == 1 && diffucltyLvl == 2)
    {
        _game = std::unique_ptr<BoardGame>(new TicTacToeEdu());
        _view = std::unique_ptr<ConsoleBoard>(new ConsoleBoardTicTacToe());
    }

    if (typeOfGame == 2 && diffucltyLvl == 1)
    {
        _game = std::unique_ptr<BoardGame>(new CatchTheBunnyRand(player, computer));
        _view = std::unique_ptr<ConsoleBoard>(new ConsoleBoardCatchTheBunny(player, computer));
    }

    if (typeOfGame == 2 && diffucltyLvl == 2)
    {
        _game = std::unique_ptr<BoardGame>(new CatchTheBunnyEdu(player, computer));
        _view = std::unique_ptr<ConsoleBoard>(new ConsoleBoardCatchTheBunny(player, computer));
    }

    _view->draw(_game->getGameState());

    while (_game->getGameState() == InProgress)
    {
        try
        {
            _game->getPlayerMove(player);
            _view->update(player, 0);
            std::cout << "The player move is:" << std::endl;
            _view->draw(_game->getGameState());

            if (_game->getGameState() != InProgress)
                break;
        }
        catch (const char *er)
        {
            std::cout << er << std::endl;
            continue;
        }

        _game->getComputerMove(computer);
        _view->update(computer, 1);
        std::cout << "The computer move is:" << std::endl;
        _view->draw(_game->getGameState());
    }
}
