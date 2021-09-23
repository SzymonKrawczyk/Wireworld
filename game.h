//
//          Klasa abstrakcyjna do Wireworld (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 14.04.2020
//
//          Modyfikacje:
//              20.05.2020, Szymon Krawczyk: Zmiana konstruktora na taki, ktory otwiera plik i wczytuje dane
//              20.05.2020, Szymon Krawczyk: Dodanie pola przechowujacego ilosc obliczen na sekunde
//


#ifndef GAME_H_
#define GAME_H_

#include "cellArray.h"
#include <string>

namespace KrawczykS {

    class Game {
    protected:

        CellArray _gameCellStorage;
        int _CPS;

    public:

        Game(std::string);
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        virtual ~Game();

        unsigned short howManyElectronHeads(unsigned short, unsigned short);
        void analyse();
        void play();

        virtual void view() const = 0;

    };
}

#endif