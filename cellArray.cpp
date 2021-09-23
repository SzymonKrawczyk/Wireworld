//
//          Klasa przechowujaca komorki w tablicy 2-wymiarowej (.cpp)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 20.05.2020
//

#include "cellArray.h"

namespace KrawczykS {

    void CellArray::deleteCellStorage() {

        for (int i = 0; i < _width; i++) {

            delete[] _cellStorage[i];
        }
        delete[] _cellStorage;
    }

    void CellArray::createCellStorage(unsigned short width_, unsigned short height_) {

        _cellStorage = new Cell * [_width];

        for (int i = 0; i < _width; i++) {

            _cellStorage[i] = new Cell[_height];
        }
    }

    CellArray::CellArray(unsigned short width_, unsigned short height_)
        :
            _width(width_)
        ,   _height(height_)
        ,   _cellStorage(nullptr)
    {
        createCellStorage(_width, _height);
    }

    CellArray::CellArray(const CellArray& copy_)
        :
            _width(copy_._width)
        ,   _height(copy_._height)
        ,   _cellStorage(nullptr)
    {
        createCellStorage(_width, _height);

        for (int i = 0; i < _width; i++) {
            for (int j = 0; j < _height; j++) {
                _cellStorage[i][j] = copy_._cellStorage[i][j];
            }
        }
    }

    CellArray& CellArray::operator=(const CellArray& copy_) {

        if (this != &copy_) {

            deleteCellStorage();

            _width = copy_._width;
            _height = copy_._height;
            createCellStorage(_width, _height);

            for (int i = 0; i < _width; i++) {
                for (int j = 0; j < _height; j++) {
                    _cellStorage[i][j] = copy_._cellStorage[i][j];
                }
            }
        }
        return *this;
    }

    CellArray::~CellArray() {

        deleteCellStorage();
    }

    const Cell& CellArray::getCellRef(unsigned short PosX_, unsigned short PosY_) const {

        return _cellStorage[PosX_][PosY_];
    }

    void CellArray::setCell(unsigned short PosX_, unsigned short PosY_, const char set_) {

        _cellStorage[PosX_][PosY_].setState(set_);
    }

    void CellArray::setCell(unsigned short PosX_, unsigned short PosY_, CellState set_) {

        _cellStorage[PosX_][PosY_].setState(set_);
    }

    unsigned short CellArray::getWidth() const { return _width; }

    unsigned short CellArray::getHeight() const { return _height; }
}