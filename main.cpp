#include "BattleShip.hpp"
#include "ColorLinux.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;


void title_screen() {
    system("clear");
    cout << AtributBold << OrangeText << endl;
    cout << "\n\n" << endl;
    cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
    cout << "                                                                       " << endl;
    cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
    cout << "▒▒▒▒▒▒████▒▒▒████▒█████▒█████▒█▒▒▒▒▒█████▒▒████▒█▒▒▒█▒█████▒████▒▒▒▒▒▒▒" << endl;
    cout << "▒▒▒▒▒▒█▒▒▒█▒█▒▒▒█▒▒▒█▒▒▒▒▒█▒▒▒█▒▒▒▒▒█▒▒▒▒▒█▒▒▒▒▒█▒▒▒█▒▒▒█▒▒▒█▒▒▒█▒▒▒▒▒▒" << endl;
    cout << "▒▒▒▒▒▒████▒▒█████▒▒▒█▒▒▒▒▒█▒▒▒█▒▒▒▒▒█████▒▒███▒▒█████▒▒▒█▒▒▒████▒▒▒▒▒▒▒" << endl;
    cout << "▒▒▒▒▒▒█▒▒▒█▒█▒▒▒█▒▒▒█▒▒▒▒▒█▒▒▒█▒▒▒▒▒█▒▒▒▒▒▒▒▒▒█▒█▒▒▒█▒▒▒█▒▒▒█▒▒▒▒▒▒▒▒▒▒" << endl;
    cout << "▒▒▒▒▒▒████▒▒█▒▒▒█▒▒▒█▒▒▒▒▒█▒▒▒█████▒█████▒████▒▒█▒▒▒█▒█████▒█▒▒▒▒▒▒▒▒▒▒" << endl;
    cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
    cout << "                                                                       " << endl;
    cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
    cout << "\n\n" << endl;
    cout << AtributNone << DefaultColor << "                  Hit [ENTER] to start, CTRL+C to exit!                ";
    cout << "\n\n\n" << endl;
    cout << AtributBold << OrangeText << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
    cout << "\n\n" << endl;
    cin.get();
}

void exit_screen() {
    system("clear");
    cout << endl;
    cout << "\n\n\n" << endl;
    cout << AtributBold << OrangeText << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
    cout << "\n\n\n" << endl;
    cout << AtributNone << DefaultColor << "                            Have a nice day!                        ";
    cout << "\n\n\n" << endl;
    cout << AtributBold << OrangeText << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
    cout << "\n\n\n" << endl;
    exit(0);
}

void autoset_ship(PLR &plr, BOT &bot) {
    system("clear");
    cout << "\n\n" << endl;
    cout << AtributNone << DefaultColor << "  This is your battlefield \n" << endl;
    plr.AutoSetShip();
    cout << AtributNone << DefaultColor << "\n  [R] - Reset (Generate new battle positions)" << endl;
    cout << AtributNone << DefaultColor << "\n  [С] - Continue (Play with current positions)" << endl;
    cout << AtributNone << DefaultColor << "\n  [E] - Exit (Leave arena)" << endl;
    cout << "\n" << endl;
    char ch;
    cin >> ch;
    
    switch (ch) {
        case 'r':
        case 'R':
            autoset_ship(plr, bot);
            cin >> ch;
            break;
        case 'c':
        case 'C':
            cin.clear();
            system("sleep 2");
            bot.AutoSetShip();
            Game(plr, bot);
            break;
        case 'e':
        case 'E':
            exit_screen();
            break;
        default:
            cerr << "Sorry, only [R], [C] or [E] keys are allowed, please try again." << endl;
            cout << "Okay, my answer is: ";
            cin >> ch;
            break;
    }
}

int main(int argc, char const *argv[]) {
    cout << AtributBold << GreenText << endl;
    BOT Bot;
    PLR Plr;
    title_screen();
    autoset_ship(Plr, Bot);
    cout << AtributNone << DefaultColor << endl;
    return 0;
}