//
//          Klasa do Gry Wireworld obslugujaca konsole (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 14.04.2020
//
//          Modyfikacje:
//              20.05.2020, Szymon Krawczyk: Zmiana konstruktora na taki, ktory otwiera plik i wczytuje dane
//

#ifndef GAMECONSOLE_H_
#define GAMECONSOLE_H_

#include <string>
#include "game.h"

namespace KrawczykS {

    class GameConsole : public Game {
    public:

        GameConsole(std::string);
        GameConsole(const GameConsole&) = delete;
        GameConsole& operator=(const GameConsole&) = delete;
        virtual ~GameConsole();

        virtual void view() const;

    };
}

#endif