
#ifndef __ROTOR_H
#define __ROTOR_H

#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>


class Rotor{
    public:
    Rotor();
    int current(int input,int go);
    Rotor(int rotnum, int rotorpos);
    void return_rot();
    void set_or_mov_rot(int go);
    void posplus();
    int position;
      private:
      int _rotnum;
      int _rotorpos;
  };
#endif
