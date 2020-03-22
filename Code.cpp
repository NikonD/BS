#include "BattleShip.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ColorLinux.hpp"

using namespace std;
/* 

*/
bool  MainClass::ship_is_good(
  int size ,
  bool is_horiz ,
  int row_top ,
  int col_left ,
  const char  field[][FIELD_DIM]
)
{
    if(is_horiz)
    {
        for(int i = std::max(0, row_top - 1); i <=  std::min(FIELD_DIM - 1,  row_top + 1); ++i)
        {
            for(int j = std::max(0, col_left - 1); j <= std::min(FIELD_DIM - 1,  col_left + size); ++j)
            {
                if(field[i][j] == SHIP_SYMB) return false;
            }        
        }
        return  true;
    }
    else//вертикальный
    {
        for(int i = std::max(0, row_top - 1); i <= std::min(FIELD_DIM - 1, row_top + size); ++i)
        {
            for(int j = std::max(0, col_left - 1); j <=  std::min(FIELD_DIM - 1, col_left + 1); ++j)
            {
                if(field[i][j] == SHIP_SYMB) return false;
            }        
        }
        return  true;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
void  MainClass::set_ship_with_size(int  size, char  field[][FIELD_DIM], TypeShip type_count ) {
    bool  is_horiz  = rand() % 2 == 0;
    int   row_top = 0 , y  = 0;
    int   col_left = 0, x = 0;
    COORD c_s;

    do
    {
        do
        {
            row_top = rand() % FIELD_DIM;
        }
        while(!is_horiz && row_top > FIELD_DIM - size);
 
        do
        {
            col_left = rand() % FIELD_DIM;
        }
      while(is_horiz && col_left > FIELD_DIM - size);        
    }while(!ship_is_good(size, is_horiz, row_top, col_left, field)); 

    if(is_horiz) {
        /*record ships*/
        /*set field*/
        for(size_t j = col_left; j < col_left + size; ++j)
        {
            c_s.x=j;
            c_s.y=row_top;
            c_s.crash=false;
            //cout << c_s.x << "-" << c_s.y;
            //cin.get();
            field[row_top][j] = SHIP_SYMB;
            //print_field(field);
            // ships[iter_ships].RecordCarr(c_s); //error!!!
            c_s.x=0;
            c_s.y=0;
        }
    }
    else {
        for(size_t i = row_top; i < row_top + size; ++i)
        {
            c_s.x=col_left;
            c_s.y=i;
            c_s.crash=false;
            //cout << c_s.x << "-" << c_s.y;
            //cin.get();
            field[i][col_left] = SHIP_SYMB;
            //print_field(field);
            // ships[iter_ships].RecordCarr(c_s);
            c_s.x=0;
            c_s.y=0;
        }    
    }
    iter_ships++;
}
////////////////////////////////////////////////////////////////////////////////////////
void  MainClass::set_ships(char  field[][FIELD_DIM]) {
    for(int i = 0; i < 1; ++i)
    {
        set_ship_with_size(4, field , BATTLESHIP);
    }
 
    for(int i = 0; i < 2; ++i)
    {
        set_ship_with_size(3, field , CRUISER);
    }
 
    for(int i = 0; i < 3; ++i)
    {
        set_ship_with_size(2, field , DESTROYER);
    }
 
    for(int i = 0; i < 4; ++i)
    {
        set_ship_with_size(1, field , BOAT);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
void  MainClass::print_field(const char  field[][FIELD_DIM]) {
    cout << GreenText << "  0 1 2 3 4 5 6 7 8 9"  << endl;
    for(int  i = 0; i < FIELD_DIM; ++i) {
        cout << i << " ";
        for(int  j = 0; j < FIELD_DIM; ++j) {
            switch(field[i][j]) {
                case SHIP_SYMB: cout << YellowTextBold << field[i][j] << " " << GreenText; break;
                case WATER_SYMB: cout << GreenText << field[i][j] << " " << GreenText; break;
                case DAMAGE_SYMB: cout << RedText << field[i][j] << " " << GreenText; break;
                case MIS_SYMB: cout << BlueText << field[i][j] << " " << GreenText; break;
            }
        }
        std::cout << std::endl;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
void  MainClass::set_water(char  field[][FIELD_DIM]) {
    for(int  i = 0; i < FIELD_DIM; ++i) {
        for(int  j = 0; j < FIELD_DIM; ++j) {
            field[i][j] = WATER_SYMB;
        }
    }
}


void BOT::AutoSetShip() {
  srand(time(0));
  set_water    (field);
  set_ships    (field);
  //print_field  (field);
}

void PLR::AutoSetShip() {
  srand(time(0));
  set_water    (field);
  set_ships    (field);
  print_field  (field);          
  Copy();
}

void BOT::ShowMap() {
    print_field(Map);
    cout << "score:" <<TrueStep << endl;
}

void PLR::ShowMap() {
    print_field(Map);
    cout << "score:" <<TrueStep << endl;
}

bool BOT::GetResultShoting(int x , int y) {
    if (field[y][x] == SHIP_SYMB) {
        Map[y][x] = DAMAGE_SYMB;
        TrueStep++;
        return true;
    }
    else if (field[y][x] == WATER_SYMB) {
        Map[y][x] = MIS_SYMB;
        return false;
    }
    else if (field[y][x] == MIS_SYMB) {
        return false;
    }
}

bool PLR::GetResultShoting(int x , int y) {
    if (field[y][x] == SHIP_SYMB) {
        Map[y][x] = DAMAGE_SYMB;
        TrueStep++;
        return true;
    }
    else if (field[y][x] == WATER_SYMB) {
        Map[y][x] = MIS_SYMB;
        return false;
    }
    else if (field[y][x] == MIS_SYMB) {
        return false;
    }
}



void PLR::Copy() {
    for(int i = 0; i < HMAP; i++){
        for(int j = 0; j < WMAP; j++){
            Map[i][j]=field[i][j];
        }   
    }
}

bool SHIP::CheckDestroy() {
    
}

void SHIP::RecordCarr(COORD c_s) {
    coords.push_back(c_s);
}

int SHIP::get_size() {
}

// ostream& operator<<(ostream& os , SHIP& shp) {
//     //
// }

void Game(PLR &plr , BOT &bot) {
    srand(time(0));
    plr.create_file("plr.shp");
    bot.create_file("bot.shp");
    //bot.create_file();
    int x , y;
    while ((plr.TrueStep<20) || (bot.TrueStep<20)) {
        cout << "START GAME!!!\n";
        do {
            system("clear");
            plr.ShowMap();
            bot.ShowMap();
            cout << "x="; cin >> x; cin.clear();
            cout << "y="; cin >> y; cin.clear();
        } while(bot.GetResultShoting(x , y));
        do {
            system("clear");
            plr.ShowMap();
            bot.ShowMap();
            x = rand() % 10; y = rand() % 10;
        } while(plr.GetResultShoting(x , y));
    }
}

void MainClass::create_file(char *name) {
    ofstream fout;
    fout.open(name);
    for(int i = 0 ; i < 10 ; i++) {
        fout << "SHIP: " << i << "\t";
        for(int j = 0; j < ships[i].coords.size(); j++) {
            fout << ships[i].coords[j].x << "-" << ships[i].coords[j].y << " | ";
        }
        fout << endl;
    }
    fout.close();
}