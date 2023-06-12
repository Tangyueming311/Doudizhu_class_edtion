#include "Card.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include <conio.h>
#include<iomanip>
#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
void Card::card() {
	int p1[54] = { 3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13,14,14,14,14,15,15,15,15,16,17 };
	for (int i = 0; i < 54; i++) {
		orign_card_[i] = p1[i];
	}
}

//将所有牌进行洗牌
void Card::washCard() {
	int temp1_x;
	int temp1_y;
	int temp2_x;
	int temp2_y;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5000; i++) {
		temp1_x = orign_card_[temp1_y = rand() % 54];
		temp2_x = orign_card_[temp2_y = rand() % 54];
		orign_card_[temp1_y] = temp2_x;
		orign_card_[temp2_y] = temp1_x;
	}

}

int* Card::matrix_landlord() {
	return matrix_landlord_;
}

void Card::set_lord_card(int num)
{
	for (int i = 0; i < 3; i++) {
		if (num == 1) {
			matrix_part1_[landlord_[i] - 3]++;
		}
		if(num == 2) {
			matrix_part2_[landlord_[i] - 3]++;
		}
		if (num == 3) {
			matrix_part3_[landlord_[i] - 3]++;
		}
	}




	
}

void Card::mark_card_change(int* K_temp_card,int* orign_card)
{
	for (int i = 0; i < 15; i++) {
		orign_card[i] = orign_card[i] - K_temp_card[i];
	}
}

void Card::mark_card_print(int MapLength,int MapHeight,int *orign_card)
{

	gotoxy(MapLength + 10, 8);
	cout << "记牌器：";

	for (int i = MapLength + 10; i < MapLength + 10 + 20; i++) {
		gotoxy(i, 10);
		putchar('~');
		gotoxy(i, 13);
		putchar('~');

		gotoxy(i, 15);
		putchar('~');
		gotoxy(i, 18);
		putchar('~');

		gotoxy(i, 20);
		putchar('~');
		gotoxy(i, 23);
		putchar('~');
	}
	for (int i =  10; i <= 23; i++) {
		if(i!=14&&i!=19){
			gotoxy(MapLength + 10, i);
			putchar('|');
			gotoxy(MapLength + 13, i);
			putchar('|');
			gotoxy(MapLength + 14, i);
			putchar('|');
			gotoxy(MapLength + 17, i);
			putchar('|');

			gotoxy(MapLength + 18, i);
			putchar('|');
			gotoxy(MapLength + 21, i);
			putchar('|');
			gotoxy(MapLength + 22, i);
			putchar('|');
			gotoxy(MapLength + 25, i);
			putchar('|');
			gotoxy(MapLength + 26, i);
			putchar('|');
			gotoxy(MapLength + 29, i);
			putchar('|');
		}
		
	}

	gotoxy(MapLength + 11, 11);
	putchar('3');
	gotoxy(MapLength + 15, 11);
	putchar('4');
	gotoxy(MapLength + 19, 11);
	putchar('5');
	gotoxy(MapLength + 23, 11);
	putchar('6');
	gotoxy(MapLength + 27, 11);
	putchar('7');

	gotoxy(MapLength + 11, 16);
	putchar('8');
	gotoxy(MapLength + 15, 16);
	putchar('9');
	gotoxy(MapLength + 19, 16);
	putchar('T');
	gotoxy(MapLength + 23,16);
	putchar('J');
	gotoxy(MapLength + 27, 16);
	putchar('Q');
	
	gotoxy(MapLength + 11, 21);
	putchar('K');
	gotoxy(MapLength + 15, 21);
	putchar('A');
	gotoxy(MapLength + 19, 21);
	putchar('2');
	gotoxy(MapLength + 23, 21);
	putchar('S');
	gotoxy(MapLength + 27, 21);
	putchar('B');

	gotoxy(MapLength + 11, 14);
	cout << orign_card[0];
	gotoxy(MapLength + 15, 14);
	cout << orign_card[1] ;
	gotoxy(MapLength + 19, 14);
	cout << orign_card[2] ;
	gotoxy(MapLength + 23, 14);
	cout << orign_card[3] ;
	gotoxy(MapLength + 27, 14);
	cout << orign_card[4] ;

	gotoxy(MapLength + 11, 19);
	cout << orign_card[5] ;
	gotoxy(MapLength + 15, 19);
	cout << orign_card[6] ;
	gotoxy(MapLength + 19, 19);
	cout << orign_card[7] ;
	gotoxy(MapLength + 23, 19);
	cout << orign_card[8] ;
	gotoxy(MapLength + 27, 19);
	cout << orign_card[9] ;

	gotoxy(MapLength + 11, 24);
	cout << orign_card[10];
	gotoxy(MapLength + 15, 24);
	cout << orign_card[11] ;
	gotoxy(MapLength + 19, 24);
	cout << orign_card[12] ;

	gotoxy(MapLength + 23, 24);
	cout << orign_card[13] ;
	gotoxy(MapLength + 27, 24);
	cout << orign_card[14] ;


}


//将所有牌分为三组基本牌和一组地主牌
void Card::dealcard() {


	for (int i = 0; i <= 16; i++)
	{
		orign_part1_[i] = orign_card_[i];
	}
	for (int i = 17; i <= 33; i++)
	{
		orign_part2_[i - 17] = orign_card_[i];
	}
	for (int i = 34; i <= 50; i++)
	{
		orign_part3_[i - 34] = orign_card_[i];
	}
	for (int i = 51; i <= 53; i++)
	{
		landlord_[i - 51] = orign_card_[i];
	}
}

void Card::change_card_to_matrix()
{
	for (int i = 0; i < 17; i++) {
		if (orign_part1_[i] != 0) {
			matrix_part1_[orign_part1_[i] - 3]++;
		}
		if (orign_part2_[i] != 0) {
			matrix_part2_[orign_part2_[i] - 3]++;
		}
		if (orign_part3_[i] != 0) {
			matrix_part3_[orign_part3_[i] - 3]++;
		}
		
	}
	for (int i = 0; i < 3; i++) {
		if (landlord_[i] != 0) {
			matrix_landlord_[landlord_[i] - 3]++;
		}
	}


}

int* Card::matrix_part1()
{
	return matrix_part1_;
}
int* Card::matrix_part2()
{
	return matrix_part2_;
}
int* Card::matrix_part3()
{
	return matrix_part3_;
}
