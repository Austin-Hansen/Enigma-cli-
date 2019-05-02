#include "reflector.h"
#include <array>

Reflector::Reflector() { }

std::array<std::array<int,27>,27> reflect = {{
{0, 21}, {1, 10}, {2, 22}, {3, 17}, {4, 6}, {5, 8}, {6, 4}, {7, 19}, {8, 5}, {9, 25}, {10, 1}, {11, 20}, {12, 18}, {13, 15}, {14, 16}, {15, 13}, {16, 14}, {17, 3}, {18, 12}, {19, 7}, {20, 11}, {21, 0}, {22, 2}, {23, 24}, {24, 23}, {25, 9}
}};

int Reflector::cref(int in, int go){

// will reflect accross the wheel

        in = in % 26;
        if(go=2){
          return reflect[in][1];
         }
        else{
          return reflect[in][0];
          }
}

//Pretty much a reflector repository
//But need to add a "current" like function, to make the two easier to understand
