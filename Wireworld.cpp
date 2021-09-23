//
//          Program uruchamiajacy Aplikacje Wireworld
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 20.05.2020
//  


#include <iostream>
#include <string>

#include "gameConsole.h"


using std::cin;
using std::cout;

using KrawczykS::GameConsole;


int main() {


    std::string input;
    cout << "Podaj nazwe pliku do zaladowania ukladu komorek:\n";
    cin >> input;
    GameConsole mainGame(input);

    mainGame.play();

    return 0;
}