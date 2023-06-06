#ifndef DRAW_H
#define DRAW_H
#include<iostream>
#include<string>
#include<Windows.h>
#include <conio.h>
#include<iomanip>
#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>


void HideCursor();
void gotoxy(unsigned char x, unsigned char y);
void SetFont(int size);
void print_key(int x, int y);
void setConsoleFontSize(int fontSize);

class Draw
{
	friend class Human;
	friend class Ai;

public:
	
	char map_matrix_[190][55] = { 0 };
	//地图的长
	int MapLength = 190;
	//地图的宽
	int MapHeight = 55;
	
	//长用“~”
	const int cardLength = 13;
	//宽用“|”
	const int cardHeight = 9;
	const int between_cards_Length = 4;

	int human_handcard_y = MapHeight - 10;


	void print(int left_x, int high_y, int length, int height);
	void basic_print_handcard(int card_y, int card_num, int* card);


	int menu();
	void log_in();
	int basic_choose_button(int orign_arrow,int buttons_number, int buttons_distance, int first_button_x, int first_button_y);

//	int choose_if_landlord(Ai ai_1, Ai ai_2, int choosen_player,int card_y, int card_num, int* card, int orign_arrow, int buttons_number, int buttons_distance, int first_button_x, int first_button_y, int arrow_direction = 1);

	void print_handcard_updown(int card_y, int card_num, int* card, int* card_up_no_matrix);

	void print_ai_card(int left_card_num, int right_card_num, int if_player_is_lanlord);
	void print_ai_card_left(int left_card_num);
	void print_ai_card_right(int right_card_num);
	void Landlord_Card_Creat(int* card);

	void clean_the_map();


	//int endgame(Human human, Ai ai_1, Ai ai_2);


};

#endif