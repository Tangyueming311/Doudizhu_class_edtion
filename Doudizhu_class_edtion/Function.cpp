#include "Function.h"



using namespace std;


int Function::endgame(Draw draw ,Human human, AiYY ai_1, AiYY ai_2)
{
	if (human.card_num(human.handcards_) == 0) {

		draw.clean_the_map();
		return 1;

	}
	else if (ai_1.card_num(ai_1.handcards_) == 0) {
		draw.clean_the_map();
		return 2;

	}
	else if (ai_2.card_num(ai_2.handcards_) == 0) {
		draw.clean_the_map();
		return 3;

	}
	else {
		return 0;
	}
}
int Function::choose_if_landlord(Human human ,int * a,Draw draw, AiYY ai_1, AiYY ai_2, int choosen_player, int card_y, int card_num, int* card, int orign_arrow, int buttons_number, int buttons_distance, int first_button_x, int first_button_y, int arrow_direction)
{
	draw.clean_the_map();
	gotoxy(draw.MapLength / 2, 20);
	cout << "洗牌中，请稍后：";
	Sleep(1000);
	draw.clean_the_map();
	gotoxy(draw.MapLength / 2, 20);
	cout << "你的手牌如下：";
	draw.basic_print_handcard(card_y, card_num, card);

	int landlord_player_1 = 0;
	int landlord_player_2 = 0;
	int landlord_player_3 = 0;

	if (choosen_player == 1) {


		gotoxy(first_button_x - 4, first_button_y + 5);
		cout << "【叫地主】";
		gotoxy(first_button_x + 16, first_button_y + 5);
		cout << "【不叫】";

		if (draw.basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1) {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "叫地主！";
			
			a[0] = a[0] * 2;	
			human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


			landlord_player_1 = 1;
		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "不叫！  ";
			landlord_player_1 = 0;
		}

		Sleep(2000);
		if (ai_1.if_grab_landlord() == true) {
			landlord_player_2 = 1;
			gotoxy(20, 20);
			cout << "Ai 1：抢地主！";
			a[0] = a[0] * 2;
			human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


		}
		else {
			landlord_player_2 = 0;
			gotoxy(20, 20);
			cout << "Ai 1：不抢    ";
		}
		Sleep(2000);
		if (ai_2.if_grab_landlord() == true) {
			landlord_player_3 = 1;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2：抢地主！";
			a[0] = a[0] * 2;
			human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


		}
		else {
			landlord_player_3 = 0;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2：不抢     ";
		}
		Sleep(2000);
		if (landlord_player_2 + landlord_player_3 != 0) {
			gotoxy(first_button_x - 4, first_button_y + 5);
			cout << "【再抢】";
			gotoxy(first_button_x + 16, first_button_y + 5);
			cout << "【不抢】";
			if (draw.basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1) {
				gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
				cout << "地主是你！";

				gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
				cout << "再抢！  ";
				a[0] = a[0] * 2;
				human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


				Sleep(2000);
				draw.clean_the_map();
				return 1;
			}
			else {
				gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
				cout << "不抢！  ";


				if (landlord_player_3 == 1) {
					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "地主是2号ai！";

					Sleep(2000);
					draw.clean_the_map();
					return 3;
				}

				else {
					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "地主是1号ai！";
					Sleep(2000);
					draw.clean_the_map();
					return 2;
				}

			}

		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
			cout << "地主是你！";

			Sleep(2000);
			draw.clean_the_map();
			return 1;
		}








	}
	if (choosen_player == 2) {

		if (ai_1.if_grab_landlord() == true) {
			landlord_player_2 = 1;
			gotoxy(20, 20);
			cout << "Ai 1：叫地主！";
			a[0] = a[0] * 2;
			human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


		}
		else {
			landlord_player_2 = 0;
			gotoxy(20, 20);
			cout << "Ai 1：不叫  ";
		}
		Sleep(2000);

		if (ai_2.if_grab_landlord() == true) {
			landlord_player_3 = 1;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2：抢地主！";
			a[0] = a[0] * 2;
			human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


		}
		else {
			landlord_player_3 = 0;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2：不抢   ";
		}
		Sleep(2000);

		gotoxy(first_button_x - 4, first_button_y + 5);
		cout << "【抢地主】";
		gotoxy(first_button_x + 16, first_button_y + 5);
		cout << "【不抢】";
		if (draw.basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1)
		{

			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "抢地主！  ";
			a[0] = a[0] * 2;
			human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


			landlord_player_1 = 1;
		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "不抢！  ";
			landlord_player_1 = 0;
		}

		Sleep(2000);
		if (landlord_player_1 + landlord_player_3 != 0) {



			if (ai_1.if_grab_landlord() == true) {
				gotoxy(20, 20);
				cout << "Ai 1：再抢！  ";
				a[0] = a[0] * 2;
				human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


				gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
				cout << "地主是1号ai！";

				Sleep(2000);
				draw.clean_the_map();
				return 2;
			}
			else {
				if (landlord_player_1 == 1) {
					gotoxy(20, 20);
					cout << "Ai 1：不抢！  ";
					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "地主是你！";
					Sleep(2000);
					draw.clean_the_map();

					return 1;
				}
				else {
					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "地主是2号ai！";
					Sleep(2000);
					draw.clean_the_map();
					return 3;
				}
			}

		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
			cout << "地主是1号ai！";
			Sleep(2000);
			draw.clean_the_map();
			return 2;
		}



	}
	if (choosen_player == 3) {
		if (ai_2.if_grab_landlord() == true) {
			landlord_player_3 = 1;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2：叫地主！";
			a[0] = a[0] * 2;
			human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


		}
		else {
			landlord_player_3 = 0;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2：不叫   ";
		}

		Sleep(2000);

		gotoxy(first_button_x - 4, first_button_y + 5);
		cout << "【抢地主】";
		gotoxy(first_button_x + 16, first_button_y + 5);
		cout << "【不抢】";
		if (draw.basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1) {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "抢地主！  ";
			a[0] = a[0] * 2;
			human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


			landlord_player_1 = 1;
		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "不抢！  ";
			landlord_player_1 = 0;
		}
		Sleep(2000);

		if (ai_1.if_grab_landlord() == true) {
			landlord_player_2 = 1;
			gotoxy(20, 20);
			cout << "Ai 1：抢地主！";
			a[0] = a[0] * 2;
			human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


		}
		else {
			landlord_player_2 = 0;
			gotoxy(20, 20);
			cout << "Ai 1：不抢   ";
		}
		Sleep(2000);





		if (landlord_player_1 + landlord_player_2 != 0) {



			if (ai_2.if_grab_landlord() == true) {
				gotoxy(draw.MapLength - 20, 20);
				cout << "Ai 2：再抢！   ";
				a[0] = a[0] * 2;
				human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, a[0], human.happy_beans_);


				gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
				cout << "地主是2号ai！";
				Sleep(2000);
				draw.clean_the_map();
				return 3;
			}
			else {
				if (landlord_player_1 == 1) {
					gotoxy(draw.MapLength - 20, 20);
					cout << "Ai 2：不抢！";


					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "地主是你！";
					Sleep(2000);
					draw.clean_the_map();
					return 1;
				}
				else {
					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "地主是1号ai！";
					Sleep(2000);
					draw.clean_the_map();
					return 2;
				}
			}

		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
			cout << "地主是2号ai！";
			Sleep(2000);
			draw.clean_the_map();
			return 3;
		}



	}





}
