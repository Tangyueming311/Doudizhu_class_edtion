#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include "Draw.h"

class Human :
    public Player
    
{
public:
    //地主牌是三个元素的数组
    void choose_landord(bool if_human_landlord, int* landlord_card);

    void chu_card(Draw draw);


    
    void chu_card_first(Draw draw);

    


};

#endif
