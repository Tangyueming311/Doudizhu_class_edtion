#ifndef PLAYER_H
#define PLAYER_H

#include "Draw.h"
#include "Card.h"

extern int K_temp_card[15];
extern int K_order;

class Player
{
public:

	 int handcards_[15];
	 int temp_cards_[15];
	 bool if_lord_;
	 int order_of_play_;
	 int temp_card_class_;

	 int happy_beans_ ;
	 int happy_numbers_ ;
	 void double_happy_numbers();
	 void evaluate_happy_beans(int happy_numbers, int happy_beans, int winner, int landlord);
	 void print_happy_numbers_and_beans(int MapLength, int MapHeight, int happy_numbers, int happy_beans);
	 void set_happy_beans(int happy_beans);
	 void set_happy_numbers(int a);


	 int card_num(int* card);

	 void set_handcards(int * handcards);
	 int* handcards();
	 

	 void set_temp_cards(int* temp_cards);
	 int* temp_cards();

	 void set_if_lord(bool if_lord);
	 bool if_lord();

	 void set_order_of_play(int order_of_play);
	 int order_of_play();

	 
	 bool first_chu_judge_matrix(int* chucards);
	 bool follow_chu_judge_matrix(int* chucards, int* temp_cards,int temp_card_class);

	 bool if_win_endgame(int* handcards);

	 void set_temp_card_class(int temp_card_class);



	 int first_chu_judge(int* a);
	 int first_chu_judge_plane2(int* b);
	 int first_chu_judge_plane1(int* b);
	 int first_chu_judge_Shunzi1(int* b);
	 int first_chu_judge_Shunzi2(int* b);
	 int first_chu_judge_Shunzi3(int* b);

	 int follow_chu_judge(int* a, int* b, int c);
	 int follow_chu_judge_Shunzi1(int* a, int* b);
	 int follow_chu_judge_Shunzi2(int* a, int* b);
	 int follow_chu_judge_Shunzi3(int* a, int* b);
	 int follow_chu_judge_plane1(int* a, int* b);
	 int follow_chu_judge_plane2(int* a, int* b);
	 int follow_chu_judge_BoomCard(int* a, int* b);
	 int follow_chu_judge_singleCard(int* a, int* b);
	 int follow_chu_judge_doubleCard(int* a, int* b);
	 int follow_chu_judge_threeCard(int* a, int* b);





};





#endif