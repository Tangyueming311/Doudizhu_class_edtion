#include "Human.h"
using namespace std;



void Human::chu_card(Draw draw) {


	int card_number = card_num(handcards_);
	int all_card_long = (card_number - 1) * draw.between_cards_Length + draw.cardLength;
	int clean_all_card_long = (20 - 1) * draw.between_cards_Length + draw.cardLength;

	for (int i = draw.MapLength / 2 - clean_all_card_long / 2 - 4; i < draw.MapLength / 2 + all_card_long / 2; i++) {
		gotoxy(i, draw.MapHeight - 15);
		putchar(' ');
	}


	gotoxy(draw.MapLength / 2 - all_card_long / 2 - 4, draw.MapHeight - 15);
	cout << "不出";
	gotoxy(draw.MapLength / 2 + all_card_long / 2 -8, draw.MapHeight - 15);
	cout << "出牌";

	int card_updown[20] = { 0 };

	int flag = 0;


	int orign_arrow = 1;

	while (1) {

		draw.print_handcard_updown(draw.MapHeight - 10, card_number, handcards_, card_updown);

		int num=draw.basic_choose_button(orign_arrow, card_number + 2, draw.between_cards_Length, draw.MapLength / 2 - all_card_long / 2 - draw.between_cards_Length+1, draw.MapHeight - 18);
		orign_arrow = num;

		//选项2对应第一张牌
		if (num!=1&&card_updown[num - 2]==  1&&num!= card_number + 2) {
			card_updown[num - 2] = 0;
		}
		else if (num != 1 && card_updown[num - 2] == 0 && num != card_number + 2) {
			card_updown[num - 2] = 1;
		}
		else if (num == card_number + 2) {

			//手牌转换成no matrix
			int card_no_matrix[20] = { 0 };
			int card_no_matrix_index = 0;
			for (int i = 0; i < 15; i++) {
				if (handcards_[i] != 0) {
					int temp_num = handcards_[i];
					for (int j = 0; j < temp_num; j++) {
						card_no_matrix[card_no_matrix_index + j] = i + 3;
					}
					card_no_matrix_index += temp_num;
				}
			}
			//挑出打出的牌
			int temp_card[20] = { 0 };
			int temp = 0;
			for (int i = 0; i < 20; i++) {
				if (card_no_matrix[i] != 0&& card_updown[i]==1) {
					temp_card[temp] = card_no_matrix[i];
					temp++;
				}
			}
			//转换成matrix
			int card_chu_matrix[15] = { 0 };
			for (int i = 0; i < 20; i++) {
				if (temp_card[i] != 0) {
					card_chu_matrix[temp_card[i] - 3]++;
				}
			}

			


			if (follow_chu_judge_matrix(card_chu_matrix, K_temp_card, 0) == 1) {
				flag = 1;
				//替换temp_card
				for (int i = 0; i < 15; i++) {
					K_temp_card[i] = card_chu_matrix[i];
				}
				//改变手牌
				for (int i = 0; i < 15; i++) {
					handcards_[i] = handcards_[i]- K_temp_card[i];
				}

				break;
			}



			
		}
		else if (num == 1) {
			flag = 0;
			break;
		}
		
	}
	

	if (flag == 1) {
		int num = card_num(K_temp_card);
		draw.basic_print_handcard(draw.MapHeight / 2, num, K_temp_card);
		draw.basic_print_handcard(draw.MapHeight - 10, card_num(handcards_), handcards_);
		
		
		//order++
		K_order = 0;
	}
	else if (flag == 0) {
		//order++
		K_order++;
	}


}


void Human::chu_card_first(Draw draw) {

	int card_number = card_num(handcards_);
	int all_card_long = (card_number - 1) * draw.between_cards_Length + draw.cardLength;

	gotoxy(draw.MapLength / 2 - all_card_long / 2 - 4, draw.MapHeight - 15);
	cout << "不出";
	gotoxy(draw.MapLength / 2 + all_card_long / 2 - 8, draw.MapHeight - 15);
	cout << "出牌";

	int card_updown[20] = { 0 };

	int flag = 0;


	int orign_arrow = 1;

	while (1) {

		draw.print_handcard_updown(draw.MapHeight - 10, card_number, handcards_, card_updown);

		int num = draw.basic_choose_button(orign_arrow, card_number + 2, draw.between_cards_Length, draw.MapLength / 2 - all_card_long / 2 - draw.between_cards_Length + 1, draw.MapHeight - 18);
		orign_arrow = num;

		//选项2对应第一张牌
		if (num != 1 && card_updown[num - 2] == 1 && num != card_number + 2) {
			card_updown[num - 2] = 0;
		}
		else if (num != 1 && card_updown[num - 2] == 0 && num != card_number + 2) {
			card_updown[num - 2] = 1;
		}
		else if (num == card_number + 2) {

			//手牌转换成no matrix
			int card_no_matrix[20] = { 0 };
			int card_no_matrix_index = 0;
			for (int i = 0; i < 15; i++) {
				if (handcards_[i] != 0) {
					int temp_num = handcards_[i];
					for (int j = 0; j < temp_num; j++) {
						card_no_matrix[card_no_matrix_index + j] = i + 3;
					}
					card_no_matrix_index += temp_num;
				}
			}
			//挑出打出的牌
			int temp_card[20] = { 0 };
			int temp = 0;
			for (int i = 0; i < 20; i++) {
				if (card_no_matrix[i] != 0 && card_updown[i] == 1) {
					temp_card[temp] = card_no_matrix[i];
					temp++;
				}
			}
			//转换成matrix
			int card_chu_matrix[15] = { 0 };
			for (int i = 0; i < 20; i++) {
				if (temp_card[i] != 0) {
					card_chu_matrix[temp_card[i] - 3]++;
				}
			}




			if (first_chu_judge_matrix(card_chu_matrix ) == 1) {
				flag = 1;
				//替换temp_card
				for (int i = 0; i < 15; i++) {
					K_temp_card[i] = card_chu_matrix[i];
				}
				//改变手牌
				for (int i = 0; i < 15; i++) {
					handcards_[i] = handcards_[i] - K_temp_card[i];
				}

				break;
			}




		}
	

	}


	if (flag == 1) {
		int num = card_num(K_temp_card);
		draw.basic_print_handcard(draw.MapHeight / 2, num, K_temp_card);
		draw.basic_print_handcard(draw.MapHeight - 10, card_num(handcards_), handcards_);


		//order++
		K_order = 0;
	}
	

}


