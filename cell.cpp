//
//          Klasa opisujaca komorke z czterema stanami (.cpp)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 20.05.2020
//

#include "cell.h"

namespace KrawczykS {

    
    Cell::Cell(CellState in_)
        :
        _state(in_)
    {}

    Cell::Cell(const char in_)
        :
        _state(convertToCellstate(in_))
    {}

    Cell::Cell(const Cell& copy_)
        :
        _state(copy_._state)
    {}

    Cell& Cell::operator=(const Cell& copy_) {

        if (this != &copy_) {

            _state = copy_._state;
        }
        return *this;
    }

    Cell::~Cell() {}


    void Cell::setState(CellState in_) {

        _state = in_;
    }

    void Cell::setState(const char in_) {

        setState(convertToCellstate(in_));
    }

    CellState Cell::getState() const {

        return _state;
    }

}