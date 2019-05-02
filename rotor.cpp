#include "rotor.h"
#include <vector>
#include <array>

Rotor::Rotor() { }
Rotor::Rotor(int rotornum,int rotorPos) : _rotnum{rotornum}, _rotorpos{rotorPos} { }

//alphabet = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
// 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25
std::array<std::array<int,27>,27> buffer;

int position=0;
//defaults to Rotor 1
std::array<std::array<int,27>,27> rotorI ={{
{0, 15 }, {1, 4 }, {2, 25 }, {3, 20 }, {4, 14 }, {5, 7 }, {6, 23 }, {7, 18 }, {8, 2 }, {9, 21 }, {10, 5 }, {11, 12 }, {12, 19 }, {13, 1 }, {14, 6 }, {15, 11 }, {16, 17 }, {17, 8 }, {18, 13 }, {19, 16 }, {20, 9 }, {21, 22 }, {22, 0 }, {23, 24 }, {24, 3 }, {25, 10 }
}};
//RotorII
std::array<std::array<int,27>,27> rotorII ={{
{0, 25 }, {1, 14 }, {2, 20 }, {3, 4 }, {4, 18 }, {5, 24 }, {6, 3 }, {7, 10 }, {8, 5 }, {9, 22 }, {10, 15 }, {11, 2 }, {12, 8 }, {13, 16 }, {14, 23 }, {15, 7 }, {16, 12 }, {17, 21 }, {18, 1 }, {19, 11 }, {20, 6 }, {21, 13 }, {22, 9 }, {23, 17 }, {24, 0 }, {25, 19 }
}};
//RotorIII
std::array<std::array<int,27>,27> rotorIII = {{
{0, 4 }, {1, 7 }, {2, 17 }, {3, 21 }, {4, 23 }, {5, 6 }, {6, 0 }, {7, 14 }, {8, 1 }, {9, 16 }, {10, 20 }, {11, 18 }, {12, 8 }, {13, 12 }, {14, 25 }, {15, 5 }, {16, 11 }, {17, 24 }, {18, 13 }, {19, 22 }, {20, 10 }, {21, 19 }, {22, 15 }, {23, 3 }, {24, 9 }, {25, 2 }
}};

//Rotor 1 as numbers
//Theses are the rotors on Enigma K
               //Convert to vector
//              RotorII
//               {"ZOUESYDKFWPCIQXHMVBLGNJRAT"},
               //rotor III
//               {"EHRVXGAOBQUSIMZFLYNWKTPDJC"}}


               //Next
               //IMETCGFRAYSQBZXWLHKDVUPOJN
               //QWERTZUIOASDFGHJKPYXCVBNML

int Rotor::current(int in,int go){

     if (go == 0){
          in = (in+position) % 26;

          return buffer[in][1];

       }
     else{
         for (int i=0;i<26;i++){
           if(in == buffer[i][1]){
              int output = buffer[i][0]-position;
             while (output<0){
                output = 26+output;
             }
            output = output % 26;
            return output;
          }
         }
       }
//        return -1;

     }

void Rotor::set_or_mov_rot(int go){

if(go==0){
_rotnum = (_rotnum +1)%5;
}
       switch(_rotnum) {

       case 0:
       buffer = rotorI;
       break;
       case 1:
       buffer = rotorII;
       break;
       case 2:
       buffer = rotorIII;
       break;
       }

}

