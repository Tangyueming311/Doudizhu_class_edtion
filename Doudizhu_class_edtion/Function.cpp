#include "Function.h"



using namespace std;


int Function::endgame(Human human, Ai ai_1, Ai ai_2)
{
	if (human.card_num(human.handcards_) == 0) {

		system("cls");
		return 1;

	}
	else if (ai_1.card_num(ai_1.handcards_) == 0) {
		system("cls");
		return 2;

	}
	else if (ai_2.card_num(ai_2.handcards_) == 0) {
		system("cls");
		return 3;

	}
	else {
		return 0;
	}
}
int Function::choose_if_landlord(Draw draw, Ai ai_1, Ai ai_2, int choosen_player, int card_y, int card_num, int* card, int orign_arrow, int buttons_number, int buttons_distance, int first_button_x, int first_button_y, int arrow_direction)
{
	system("cls");
	gotoxy(draw.MapLength / 2, 20);
	cout << "ϴ���У����Ժ�";
	Sleep(1000);
	system("cls");
	gotoxy(draw.MapLength / 2, 20);
	cout << "����������£�";
	draw.basic_print_handcard(card_y, card_num, card);

	int landlord_player_1 = 0;
	int landlord_player_2 = 0;
	int landlord_player_3 = 0;

	if (choosen_player == 1) {


		gotoxy(first_button_x - 4, first_button_y + 5);
		cout << "���е�����";
		gotoxy(first_button_x + 16, first_button_y + 5);
		cout << "�����С�";

		if (draw.basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1) {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "�е�����";
			landlord_player_1 = 1;
		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "���У�  ";
			landlord_player_1 = 0;
		}

		Sleep(2000);
		if (ai_1.choose_landord() == true) {
			landlord_player_2 = 1;
			gotoxy(20, 20);
			cout << "Ai 1����������";
		}
		else {
			landlord_player_2 = 0;
			gotoxy(20, 20);
			cout << "Ai 1������    ";
		}
		Sleep(2000);
		if (ai_2.choose_landord() == true) {
			landlord_player_3 = 1;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2����������";
		}
		else {
			landlord_player_3 = 0;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2������     ";
		}
		Sleep(2000);
		if (landlord_player_2 + landlord_player_3 != 0) {
			gotoxy(first_button_x - 4, first_button_y + 5);
			cout << "��������";
			gotoxy(first_button_x + 16, first_button_y + 5);
			cout << "��������";
			if (draw.basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1) {
				gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
				cout << "�������㣡";

				gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
				cout << "������  ";

				Sleep(2000);
				system("cls");
				return 1;
			}
			else {
				gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
				cout << "������  ";


				if (landlord_player_3 == 1) {
					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "������2��ai��";

					Sleep(2000);
					system("cls");
					return 3;
				}

				else {
					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "������1��ai��";
					Sleep(2000);
					system("cls");
					return 2;
				}

			}

		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
			cout << "�������㣡";

			Sleep(2000);
			system("cls");
			return 1;
		}








	}
	if (choosen_player == 2) {

		if (ai_1.choose_landord() == true) {
			landlord_player_2 = 1;
			gotoxy(20, 20);
			cout << "Ai 1���е�����";
		}
		else {
			landlord_player_2 = 0;
			gotoxy(20, 20);
			cout << "Ai 1������  ";
		}
		Sleep(2000);

		if (ai_2.choose_landord() == true) {
			landlord_player_3 = 1;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2����������";
		}
		else {
			landlord_player_3 = 0;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2������   ";
		}
		Sleep(2000);

		gotoxy(first_button_x - 4, first_button_y + 5);
		cout << "����������";
		gotoxy(first_button_x + 16, first_button_y + 5);
		cout << "��������";
		if (draw.basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1)
		{

			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "��������  ";
			landlord_player_1 = 1;
		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "������  ";
			landlord_player_1 = 0;
		}

		Sleep(2000);
		if (landlord_player_1 + landlord_player_3 != 0) {



			if (ai_1.choose_landord() == true) {
				gotoxy(20, 20);
				cout << "Ai 1��������  ";
				gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
				cout << "������1��ai��";

				Sleep(2000);
				system("cls");
				return 2;
			}
			else {
				if (landlord_player_1 == 1) {
					gotoxy(20, 20);
					cout << "Ai 1��������  ";
					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "�������㣡";
					Sleep(2000);
					system("cls");

					return 1;
				}
				else {
					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "������2��ai��";
					Sleep(2000);
					system("cls");
					return 3;
				}
			}

		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
			cout << "������1��ai��";
			Sleep(2000);
			system("cls");
			return 2;
		}



	}
	if (choosen_player == 3) {
		if (ai_2.choose_landord() == true) {
			landlord_player_3 = 1;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2���е�����";
		}
		else {
			landlord_player_3 = 0;
			gotoxy(draw.MapLength - 20, 20);
			cout << "Ai 2������   ";
		}

		Sleep(2000);

		gotoxy(first_button_x - 4, first_button_y + 5);
		cout << "����������";
		gotoxy(first_button_x + 16, first_button_y + 5);
		cout << "��������";
		if (draw.basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1) {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "��������  ";
			landlord_player_1 = 1;
		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 18);
			cout << "������  ";
			landlord_player_1 = 0;
		}
		Sleep(2000);

		if (ai_1.choose_landord() == true) {
			landlord_player_2 = 1;
			gotoxy(20, 20);
			cout << "Ai 1����������";
		}
		else {
			landlord_player_2 = 0;
			gotoxy(20, 20);
			cout << "Ai 1������   ";
		}
		Sleep(2000);





		if (landlord_player_1 + landlord_player_2 != 0) {



			if (ai_2.choose_landord() == true) {
				gotoxy(draw.MapLength - 20, 20);
				cout << "Ai 2��������   ";

				gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
				cout << "������2��ai��";
				Sleep(2000);
				system("cls");
				return 3;
			}
			else {
				if (landlord_player_1 == 1) {
					gotoxy(draw.MapLength - 20, 20);
					cout << "Ai 2��������";


					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "�������㣡";
					Sleep(2000);
					system("cls");
					return 1;
				}
				else {
					gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
					cout << "������1��ai��";
					Sleep(2000);
					system("cls");
					return 2;
				}
			}

		}
		else {
			gotoxy(draw.MapLength / 2, draw.MapHeight / 2 + 14);
			cout << "������2��ai��";
			Sleep(2000);
			system("cls");
			return 3;
		}



	}





}
