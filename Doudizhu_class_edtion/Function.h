#ifndef FUNCTION_H
#define FUNCTION_H
#include "Ai.h"
#include "Human.h"
#include "Draw.h"
class Function
{

public:
	int endgame(Human human, Ai ai_1, Ai ai_2);
	int choose_if_landlord(Draw draw,Ai ai_1, Ai ai_2, int choosen_player, int card_y, int card_num, int* card, int orign_arrow, int buttons_number, int buttons_distance, int first_button_x, int first_button_y, int arrow_direction = 1);

};


#endif