#include "Ai.h"

bool Ai::choose_landord()
{
	return true;

}


void Ai::chu_card(Draw draw) {
	int chu_or_buchu = 0;



	if (chu_or_buchu == 1) {
		//在牌局中间打印出将打的牌
		for (int i = 0; i < 15; i++) {
			K_temp_card[i] = temp_cards_[i];
		}
		//改变手牌
		for (int i = 0; i < 15; i++) {
			handcards_[i] = handcards_[i] - temp_cards_[i];
		}
		//清零
		for (int i = 0; i < 15; i++) {
			temp_cards_[i] = 0;
		}
		draw.basic_print_handcard(draw.MapHeight / 2, card_num(K_temp_card), K_temp_card);
		K_order = 0;
		
		if (left_or_right == 1) {
			draw.print_ai_card_left(card_num(handcards_));
		}
		else {
			draw.print_ai_card_right(card_num(handcards_));

		}
	}
	else if (chu_or_buchu == 0) {
		K_order++;
	}
}

void Ai::chu_card_first(Draw draw) {



	//在牌局中间打印出将打的牌
	for (int i = 0; i < 15; i++) {
		K_temp_card[i] = temp_cards_[i];
	}
	//改变手牌
	for (int i = 0; i < 15; i++) {
		handcards_[i] = handcards_[i] - temp_cards_[i];
	}
	//清零
	for (int i = 0; i < 15; i++) {
		temp_cards_[i] = 0;
	}
	draw.basic_print_handcard(draw.MapHeight / 2, card_num(K_temp_card), K_temp_card);
	K_order = 0;
	if (left_or_right == 1) {
		draw.print_ai_card_left(card_num(handcards_));
	}
	else {
		draw.print_ai_card_right(card_num(handcards_));

	}
}

void Ai::set_left_or_right(int a)
{
	left_or_right = a;
}
