#ifndef WINNERPARTY_H
#define WINNERPARTY_H

#include "Election.h"
#include "Cities.h"

class WinnerParty : public Election, public Cities {
public:
    void Party();
private:
    string party;
};

#endif