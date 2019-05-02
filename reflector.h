//This will inherit from rotor
#ifndef __REFLECTOR_H
#define __REFLECTOR_H

#include "rotor.h"

class Reflector : public Rotor{
   public:
   Reflector();
   int cref(int in, int go);

};
#endif
