//
//          Klasa abstrakcyjna do Wireworld (.cpp)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 20.05.2020
//

#include <iostream>
#include <fstream>

#include "game.h"

namespace KrawczykS {

    Game::Game(std::string filename_)
        :
            _gameCellStorage(0, 0)
        ,   _CPS(1)
    {
        try {

            unsigned short gameWidth = 10, gameHeight = 10;

            std::ifstream fileIn;
            fileIn.open(filename_.c_str());

            if (!fileIn.is_open()) {

                throw std::string("\nNieudane otworzenie pliku \"" + filename_ + "\"\n");
            }

            fileIn >> _CPS;

            fileIn >> gameWidth >> gameHeight;

            CellArray tempStorage(gameWidth, gameHeight);
            _gameCellStorage = tempStorage;

            fileIn.get();
            char temp = '\0';
            for (unsigned int height = 0u; height < gameHeight; height++) {

                for (unsigned int width = 0u; width < gameWidth; width++) {

                    temp = fileIn.get();
                    _gameCellStorage.setCell(width, height, temp);
                }
                fileIn.get(); // Pobieranie \n
            }
            fileIn.close();
        }
        catch (const std::string error) {

            std::clog << "\n" << error << "\n";
            std::cin.get();
            std::cin.get();
            exit(EXIT_FAILURE);
        }
    }

    Game::~Game() {}

    unsigned short Game::howManyElectronHeads(unsigned short width, unsigned short height) {

        unsigned short tempW = _gameCellStorage.getWidth();
        unsigned short tempH = _gameCellStorage.getHeight();
        unsigned short total = 0;

        if (width > 0 && height > 0 && height < tempH - 1 && width < tempW - 1) {
            total += (_gameCellStorage.getCellRef(width - 1, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width - 1, height).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width - 1, height + 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width, height + 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height + 1).getState() == CellState::ELECTRON_HEAD);
        }
        else if (width == 0 && height > 0 && height < tempH - 1) {
            total += (_gameCellStorage.getCellRef(width, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width, height + 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height + 1).getState() == CellState::ELECTRON_HEAD);
        }
        else if (width > 0 && width < tempW - 1 && height == 0) {
            total += (_gameCellStorage.getCellRef(width - 1, height).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width - 1, height + 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width, height + 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height + 1).getState() == CellState::ELECTRON_HEAD);
        }
        else if (width == tempW - 1 && height > 0 && height < tempH - 1) {
            total += (_gameCellStorage.getCellRef(width, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width, height + 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width - 1, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width - 1, height).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width - 1, height + 1).getState() == CellState::ELECTRON_HEAD);
        }
        else if (width > 0 && width < tempW - 1 && height == tempH - 1) {
            total += (_gameCellStorage.getCellRef(width - 1, height).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width - 1, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height - 1).getState() == CellState::ELECTRON_HEAD);
        }
        else if (width == 0 && height == 0) {
            total += (_gameCellStorage.getCellRef(width, height + 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height + 1).getState() == CellState::ELECTRON_HEAD);
        }
        else if (width == tempW - 1 && height == 0) {
            total += (_gameCellStorage.getCellRef(width - 1, height).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width - 1, height + 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width, height + 1).getState() == CellState::ELECTRON_HEAD);
        }
        else if (width == tempW - 1 && height == tempH - 1) {
            total += (_gameCellStorage.getCellRef(width - 1, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width - 1, height).getState() == CellState::ELECTRON_HEAD);
        }
        else if (width == 0 && height == tempH - 1) {
            total += (_gameCellStorage.getCellRef(width, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height - 1).getState() == CellState::ELECTRON_HEAD);
            total += (_gameCellStorage.getCellRef(width + 1, height).getState() == CellState::ELECTRON_HEAD);
        }

        return total;
    }


    void Game::analyse() {

        unsigned short tempW = _gameCellStorage.getWidth();
        unsigned short tempH = _gameCellStorage.getHeight();

        CellArray temp(tempW, tempH);

        for (int width = 0; width < tempW; width++) {
            for (int height = 0; height < tempH; height++) {


                switch (_gameCellStorage.getCellRef(width, height).getState()) {

                    case CellState::CONDUCTOR:
                    
                        if (howManyElectronHeads(width, height) == 1 || howManyElectronHeads(width, height) == 2) {

                            temp.setCell(width, height, CellState::ELECTRON_HEAD);
                        }
                        else {

                            temp.setCell(width, height, CellState::CONDUCTOR);
                        }
                        break;

                    case  CellState::ELECTRON_HEAD:

                        temp.setCell(width, height, CellState::ELECTRON_TAIL);
                        break;

                    case CellState::ELECTRON_TAIL:

                        temp.setCell(width, height, CellState::CONDUCTOR);
                        break;

                    default:

                        temp.setCell(width, height, CellState::EMPTY);
                        break;
                }
            }
        }
        _gameCellStorage = temp;
    }

    void Game::play() {

        while (true) {

            analyse();
            view();
        }
    }

}