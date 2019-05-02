#include "type.h"

std::array<Machine,1> machine_type;
Machine machine;

Type::Type() { }
Type::Type(int model)
     : _model{ model} { }

      void set_machine_type(){
       _machine=machine_type[_model];
      }

