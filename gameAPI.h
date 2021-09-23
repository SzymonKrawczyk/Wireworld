//
//          Klasa do Gry W Zycie obslugujaca okno (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 16.03.2020
//
//

#ifndef GAMEAPI_H_
#define GAMEAPI_H_

#include "game.h"

namespace KrawczykS {


class GameAPI : public Game {
private:


public:

    GameAPI(unsigned short, unsigned short);
    GameAPI(const GameAPI&) = delete;
    GameAPI& operator=(const GameAPI&) = delete;
    virtual ~GameAPI();

    virtual void view() const;

};
}

#endif