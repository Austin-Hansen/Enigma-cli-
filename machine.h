#ifndef __MACHINE_H
#define __MACHINE_H
#include "reflector.h"
#include "rotor.h"
#include <array>
#include <vector>
#include <string>

class Machine{

    public:
         Machine();
         char runmach(char input);
         void turn();
         std::vector<char> word(std::string go);
         void setRot(int R,int M,int L);
         void setRotpos(int R,int M,int L);
         void cli();
         void execute_cmd(int cmd);
         private:
         Rotor rotor1;
         Rotor rotor2;
         Rotor rotor3;

};
#endif
