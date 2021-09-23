//
//          Klasa do Wireworld obslugujaca konsole (.cpp)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 20.05.2020
//

#include <iostream>
#include <windows.h>
#include "gameConsole.h"
#include "ccolor.h"

namespace KrawczykS {

    GameConsole::GameConsole(std::string filename_)
        :
        Game(filename_)
    {}

    GameConsole::~GameConsole() {}

    void GameConsole::view() const {

        unsigned short tempW = _gameCellStorage.getWidth();
        unsigned short tempH = _gameCellStorage.getHeight();
        system("CLS");

        ccolor const* currentColor = nullptr;

        for (unsigned short height = 0u; height < tempH; height++) {
            for (unsigned short width = 0u; width < tempW; width++) {

                switch (_gameCellStorage.getCellRef(width, height).getState()) {

                case CellState::CONDUCTOR:

                    currentColor = &backgroundIntenseYellow;
                    break;

                case  CellState::ELECTRON_HEAD:

                    currentColor = &backgroundIntenseRed;
                    break;

                case CellState::ELECTRON_TAIL:
                    
                    currentColor = &backgroundRed;
                    break;

                default:

                    currentColor = &backgroundBlack;
                    break;
                }
                std::cout << *currentColor << ' ';
            }
            std::cout << defcolor << '\n';
        }
        currentColor = &defcolor;
        Sleep(1000 / _CPS);

    }
}