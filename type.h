#ifndef __TYPE_H
#define __TYPE_H

#include "machine.h"

class Type : public Machine{
    public:
    Type();
    Type(int model);
    void set_machine_type();
    void set_reflector_type();
    private:
    int _model;
    int _refmodel;
    Machine _machine;
#endif
