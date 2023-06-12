#ifndef FUNCTION_H
#define FUNCTION_H
#include "AiYY.h"
#include "Human.h"
#include "Draw.h"
class Function
{

public:
	int endgame(Draw draw,Human human, AiYY ai_1, AiYY ai_2);
	int choose_if_landlord(Human human,int * a ,Draw draw,AiYY ai_1, AiYY ai_2, int choosen_player, int card_y, int card_num, int* card, int orign_arrow, int buttons_number, int buttons_distance, int first_button_x, int first_button_y, int arrow_direction = 1);

};


#endif