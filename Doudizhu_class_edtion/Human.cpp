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
	cout << "����";
	gotoxy(draw.MapLength / 2 + all_card_long / 2 -8, draw.MapHeight - 15);
	cout << "����";

	int card_updown[20] = { 0 };

	int flag = 0;


	int orign_arrow = 1;

	while (1) {

		draw.print_handcard_updown(draw.MapHeight - 10, card_number, handcards_, card_updown);

		int num=draw.basic_choose_button(orign_arrow, card_number + 2, draw.between_cards_Length, draw.MapLength / 2 - all_card_long / 2 - draw.between_cards_Length+1, draw.MapHeight - 18);
		orign_arrow = num;

		//ѡ��2��Ӧ��һ����
		if (num!=1&&card_updown[num - 2]==  1&&num!= card_number + 2) {
			card_updown[num - 2] = 0;
		}
		else if (num != 1 && card_updown[num - 2] == 0 && num != card_number + 2) {
			card_updown[num - 2] = 1;
		}
		else if (num == card_number + 2) {

			//����ת����no matrix
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
			//�����������
			int temp_card[20] = { 0 };
			int temp = 0;
			for (int i = 0; i < 20; i++) {
				if (card_no_matrix[i] != 0&& card_updown[i]==1) {
					temp_card[temp] = card_no_matrix[i];
					temp++;
				}
			}
			//ת����matrix
			int card_chu_matrix[15] = { 0 };
			for (int i = 0; i < 20; i++) {
				if (temp_card[i] != 0) {
					card_chu_matrix[temp_card[i] - 3]++;
				}
			}

			


			if (follow_chu_judge_matrix(card_chu_matrix, K_temp_card, 0) == 1) {
				flag = 1;
				//�滻temp_card
				for (int i = 0; i < 15; i++) {
					K_temp_card[i] = card_chu_matrix[i];
				}
				//�ı�����
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
	cout << "����";
	gotoxy(draw.MapLength / 2 + all_card_long / 2 - 8, draw.MapHeight - 15);
	cout << "����";

	int card_updown[20] = { 0 };

	int flag = 0;


	int orign_arrow = 1;

	while (1) {

		draw.print_handcard_updown(draw.MapHeight - 10, card_number, handcards_, card_updown);

		int num = draw.basic_choose_button(orign_arrow, card_number + 2, draw.between_cards_Length, draw.MapLength / 2 - all_card_long / 2 - draw.between_cards_Length + 1, draw.MapHeight - 18);
		orign_arrow = num;

		//ѡ��2��Ӧ��һ����
		if (num != 1 && card_updown[num - 2] == 1 && num != card_number + 2) {
			card_updown[num - 2] = 0;
		}
		else if (num != 1 && card_updown[num - 2] == 0 && num != card_number + 2) {
			card_updown[num - 2] = 1;
		}
		else if (num == card_number + 2) {

			//����ת����no matrix
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
			//�����������
			int temp_card[20] = { 0 };
			int temp = 0;
			for (int i = 0; i < 20; i++) {
				if (card_no_matrix[i] != 0 && card_updown[i] == 1) {
					temp_card[temp] = card_no_matrix[i];
					temp++;
				}
			}
			//ת����matrix
			int card_chu_matrix[15] = { 0 };
			for (int i = 0; i < 20; i++) {
				if (temp_card[i] != 0) {
					card_chu_matrix[temp_card[i] - 3]++;
				}
			}




			if (first_chu_judge_matrix(card_chu_matrix ) == 1) {
				flag = 1;
				//�滻temp_card
				for (int i = 0; i < 15; i++) {
					K_temp_card[i] = card_chu_matrix[i];
				}
				//�ı�����
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


