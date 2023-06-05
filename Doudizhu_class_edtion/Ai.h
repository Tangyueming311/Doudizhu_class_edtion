#ifndef AI_H
#define AI_H
#include "Player.h"
#include "Draw.h"
class Ai :
    public Player
{
public:

    int left_or_right;

    bool choose_landord();

    void chu_card(Draw draw);
    void chu_card_first(Draw draw);

    void set_left_or_right(int a);

};

#endif
