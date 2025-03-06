#ifndef MAYORITY_H
#define MAYORITY_H

#include "Election.h"
#include "Cities.h"

class Mayority : public Election, public Cities {
public:
    void Mayor();
private:
    string mayor;

};

#endif