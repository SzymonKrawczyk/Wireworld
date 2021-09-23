//
//          Klasa przechowujaca komorki w tablicy 2-wymiarowej (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 14.04.2020
//
//          Modyfikacje:
//              20.05.2020, Szymon Krawczyk: Usuniecie metody getCellRef i dodanie metod setCell
//

#ifndef CELLARRAY_H_
#define CELLARRAY_H_

#include "cell.h"

namespace KrawczykS {

    class CellArray {
    private:

        unsigned short _width;
        unsigned short _height;

        Cell** _cellStorage;

    protected:

        void deleteCellStorage();
        void createCellStorage(unsigned short, unsigned short);

    public:

        CellArray(unsigned short, unsigned short);
        CellArray(const CellArray&);
        CellArray& operator=(const CellArray&);
        virtual ~CellArray();

        const Cell& getCellRef(unsigned short, unsigned short) const;

        void setCell(unsigned short, unsigned short, const char);
        void setCell(unsigned short, unsigned short, CellState);

        unsigned short getWidth()  const;
        unsigned short getHeight() const;

    };
}

#endif