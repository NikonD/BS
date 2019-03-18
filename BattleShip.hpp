#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include <stdlib.h>
#include <vector>


#define WMAP 10
#define HMAP 10
#define LIMSHIP 10

using namespace std;

const int  FIELD_DIM   = 10;
const char WATER_SYMB  = '~';
const char SHIP_SYMB   = '#';
const char DAMAGE_SYMB = '@';
const char MIS_SYMB    = '*';

enum TypeShip {
    BOAT        = 4,
    DESTROYER   = 3,
    CRUISER     = 2,
    BATTLESHIP  = 1
};

struct COORD {
    unsigned short int     x:4;
    unsigned short int     y:4;
    bool                   crash;
};

class SHIP {
private:
    //
public:
    //ostream& operator<<(ostream& os , SHIP& shp );
    vector<COORD> coords;
    TypeShip type;
    int print();
    int get_size();
    void Rotate();
    void MoveShip();
    bool CheckDestroy();
    void RecordCarr(COORD c_s);
};

class MainClass {
private:
    //something
public:
    MainClass() {}
    virtual ~MainClass() { }
    virtual void AutoSetShip() {}
    virtual bool GetResultShoting(int x , int y) {}
    int TrueStep;
    SHIP ships[10];
    void create_file(char *name);
protected:
    int iter_ships;
    bool ship_is_good(
        int         size ,
        bool        is_horiz ,
        int         row_top ,
        int         col_left ,
        const char  field[][FIELD_DIM]
    );
    void print_field(const char  field[][FIELD_DIM]);
    void set_ship_with_size(int  size, char  field[][FIELD_DIM], TypeShip type_count);
    void set_ships(char  field[][FIELD_DIM]);
    void set_water(char  field[][FIELD_DIM]);
};

//////////////////////////////////////////////////////////////////////////////////////////////

class BOT : public MainClass {
private:
    char Map[HMAP][WMAP];
    char field[HMAP][WMAP];
public:
    bool GetResultShoting(int x , int y);
    void AutoSetShip();
    void ShowMap();
    BOT() {
        iter_ships = 0;
        TrueStep = 0;
        for(int i = 0; i < HMAP; i++) {
            for(int j = 0; j < WMAP; j++) {
                Map[i][j] = WATER_SYMB;
            } 
        }
    }
    //~BOT();
};

//////////////////////////////////////////////////////////////////////////////////////////////

class PLR : public MainClass {
private:
    char Map[HMAP][WMAP];
    char field[HMAP][WMAP];
public:
    bool GetResultShoting(int x , int y);
    void AutoSetShip();
    void ShowMap();
    void Copy();
    PLR() {
        iter_ships=0;
        TrueStep = 0;
    }
    //~PLR();
};

void Game(PLR &plr , BOT &bot);

#endif //BATTLESHIP_HPP