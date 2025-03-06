#ifndef PERCENTAGE_H
#define PERCENTAGE_H

#include "Election.h"
#include "Cities.h"

class Percentage : public Election, public Cities {
public:
    void percentage();
};

#endif