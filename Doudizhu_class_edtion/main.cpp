﻿// Doudizhu_class_edtion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Draw.h"
#include "Player.h"
#include "Card.h"
#include "Human.h"
#include "Ai.h"
#include "Function.h"
using namespace std;
int main()
{

	setConsoleFontSize(24);
	HideCursor();


	Card card;
	card.card();
	card.washCard();
	card.dealcard();
	card.change_card_to_matrix();

	Ai ai_1;
	Ai ai_2;

	ai_1.set_handcards(card.matrix_part2_);
	ai_2.set_handcards(card.matrix_part3_);
	
	ai_1.set_left_or_right(1);
	ai_1.set_left_or_right(2);

	Sleep(1000);
	Draw draw;
	draw.menu();
	Human human;

	Function function;

	int unknow = 0;
	human.set_happy_beans(unknow);
	human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, human.happy_numbers_, human.happy_beans_);



	//随机数
	srand((unsigned)time(NULL));
	int choosen_num = rand() % 3+1;

	int a[1] = { 1 };

	int landlord = function.choose_if_landlord(human,a,draw,ai_1, ai_2, choosen_num, draw.MapHeight / 2, 17, card.matrix_part1(), 1, 2, 20, draw.MapLength / 2 - 10, draw.MapHeight / 2 + 20);
	human.set_happy_numbers(a[0]);
	card.set_lord_card(landlord);
	

	
	human.set_handcards(card.matrix_part1());
	ai_1.set_handcards(card.matrix_part2_);
	ai_2.set_handcards(card.matrix_part3_);

	draw.Landlord_Card_Creat(card.landlord_);
	draw.print_ai_card(ai_1.card_num(ai_1.handcards_), ai_2.card_num(ai_2.handcards_), landlord);
	draw.basic_print_handcard(draw.MapHeight - 10, human.card_num(human.handcards_), human.handcards_);


	int orign_card[15] = { 0 };
	for (int i = 0; i < 15; i++) {
		orign_card[i] = card.orign_card_matrix[i];
		orign_card[i] = orign_card[i] - human.handcards_[i];
	}
	card.mark_card_print(draw.MapLength, draw.MapHeight, orign_card);


	///
	human.print_happy_numbers_and_beans(draw.MapLength, draw.MapHeight, human.happy_numbers_, human.happy_beans_);




	//游戏进程
	while (1) {
		if (landlord == 1) {
			if (K_order == 0 || K_order == 1) {
				human.chu_card(draw);

			}
			else {

				human.chu_card_first(draw);
			}

			card.mark_card_change(K_temp_card);
			card.mark_card_print(draw.MapLength, draw.MapHeight, card.orign_card_matrix);

			if (function.endgame(draw, human, ai_1, ai_2) != 0) {
				break;
			}

			Sleep(1000);

			if (K_order == 0 || K_order == 1) {
				ai_1.chu_card(draw);
			}
			else {

				ai_1.chu_card_first(draw);
			}
			card.mark_card_change(K_temp_card);
			card.mark_card_print(draw.MapLength, draw.MapHeight, card.orign_card_matrix);

			if (function.endgame(draw, human, ai_1, ai_2) != 0) {
				break;
			}

			Sleep(1000);

			if (K_order == 0 || K_order == 1) {
				ai_2.chu_card(draw);
			}
			else {

				ai_2.chu_card_first(draw);
			}
			card.mark_card_change(K_temp_card);
			card.mark_card_print(draw.MapLength, draw.MapHeight, card.orign_card_matrix);
			Sleep(1000);


			if (function.endgame(draw, human, ai_1, ai_2) != 0) {
				break;
			}

		}
		else if(landlord==2) {
		

			if (K_order == 0 || K_order == 1) {
				ai_1.chu_card(draw);
			}
			else {

				ai_1.chu_card_first(draw);
			}

			card.mark_card_change(K_temp_card);
			card.mark_card_print(draw.MapLength, draw.MapHeight, card.orign_card_matrix);

			if (function.endgame(draw, human, ai_1, ai_2) != 0) {
				break;
			}


			Sleep(1000);

			if (K_order == 0 || K_order == 1) {
				ai_2.chu_card(draw);
			}
			else {

				ai_2.chu_card_first(draw);
			}

			card.mark_card_change(K_temp_card);
			card.mark_card_print(draw.MapLength, draw.MapHeight, card.orign_card_matrix);
			Sleep(1000);




			if (function.endgame(draw, human, ai_1, ai_2) != 0) {
				break;
			}



			if (K_order == 0 || K_order == 1) {
				human.chu_card(draw);

			}
			else {

				human.chu_card_first(draw);
			}
			card.mark_card_change(K_temp_card);
			card.mark_card_print(draw.MapLength, draw.MapHeight, card.orign_card_matrix);
			Sleep(1000);



			if (function.endgame(draw, human, ai_1, ai_2) != 0) {
				break;
			}
		}
		else if (landlord == 3) {


			if (K_order == 0 || K_order == 1) {
				ai_2.chu_card(draw);
			}
			else {

				ai_2.chu_card_first(draw);
			}

			card.mark_card_change(K_temp_card);
			card.mark_card_print(draw.MapLength, draw.MapHeight, card.orign_card_matrix);
			if (function.endgame(draw, human, ai_1, ai_2) != 0) {
				break;
			}


			Sleep(1000);

			if (K_order == 0 || K_order == 1) {
				human.chu_card(draw);

			}
			else {

				human.chu_card_first(draw);
			}
			card.mark_card_change(K_temp_card);
			card.mark_card_print(draw.MapLength, draw.MapHeight, card.orign_card_matrix);
			Sleep(1000);


			if (function.endgame(draw, human, ai_1, ai_2) != 0) {
				break;
			}


            if (K_order == 0 || K_order == 1) {
				ai_1.chu_card(draw);
			}
			else {

				ai_1.chu_card_first(draw);
			}
			
			card.mark_card_change(K_temp_card);
			card.mark_card_print(draw.MapLength, draw.MapHeight, card.orign_card_matrix);

			if (function.endgame(draw, human, ai_1, ai_2) != 0) {
				break;
			}
              Sleep(1000);

			
		}


	}


	if (function.endgame(draw,human, ai_1, ai_2) == 1&&landlord==1) {
		cout << "地主赢力";
	}
	else if (function.endgame(draw, human, ai_1, ai_2) == 1 && landlord != 1) {
		cout << " 农民赢力";
	}
	else if (function.endgame(draw, human, ai_1, ai_2) == 2 && landlord == 2) {
		cout << " 农民赢力";
	}
	else if (function.endgame(draw, human, ai_1, ai_2) == 2 && landlord != 2) {
		cout << " 农民赢力";
	}
	else if (function.endgame(draw, human, ai_1, ai_2) == 3 && landlord == 3) {
		cout << " 农民赢力";
	}
	else if (function.endgame(draw, human, ai_1, ai_2) == 3 && landlord != 3) {
		cout << " 农民赢力";
	}


	//human.evaluate_happy_beans(human.happy_numbers_, human.happy_beans_, function.endgame(draw,human, ai_1, ai_2), landlord);

	//测试



	



}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
