//
//          Klasa opisujaca komorke z czterema stanami(.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 14.04.2020
//
//          Modyfikacje:
//              21.05.2020, Szymon Krawczyk: Dodanie konwersji char na CellState i CellState na char
//

#ifndef CELL_H_
#define CELL_H_

namespace KrawczykS {

    enum class CellState {

        EMPTY, ELECTRON_HEAD, ELECTRON_TAIL, CONDUCTOR
    };

    inline CellState convertToCellstate(const char toConvert) {

        switch (toConvert) {

            case 'P': 

                return CellState::CONDUCTOR;
                break;

            case 'O': 

                return CellState::ELECTRON_HEAD;
                break;

            case 'o': 

                return CellState::ELECTRON_TAIL;
                break;

            default:

                return CellState::EMPTY;
                break;
        }
    }

    inline char convertCellStateToChar(CellState toConvert) {

        switch (toConvert) {

            case CellState::CONDUCTOR:

                return 'P';
                break;

            case  CellState::ELECTRON_HEAD:

                return 'O';
                break;

            case CellState::ELECTRON_TAIL:

                return 'o';
                break;

            default:

                return 'X';
                break;
        }
    }

    class Cell {
    private:

        CellState _state;

    public:        

        Cell(const char);
        Cell(CellState = CellState::EMPTY);
        Cell(const Cell&);
        Cell& operator=(const Cell&);
        virtual ~Cell();

        void setState(const char);
        void setState(CellState);
        CellState getState() const;

    };
}

#endif