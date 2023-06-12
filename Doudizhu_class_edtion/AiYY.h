
#ifndef AIYY_H
#define AIYY_H
#include "Player.h"
#include "Draw.h"
#include "Ai.h"
class AiYY :
	public Ai
{
public:
	//拆牌函数用到的中间数组
	int one[20] = { 0 };
	int two[20] = { 0 };
	int three[20] = { 0 };
	int four[20] = { 0 };
	int a = 0;
	int b = 0;
	int c = 0;
	int left_or_right;
	//int K_temp_card_class_;

	int handcard[20] = { 0 };

	//chucardfirst函数里面打出的牌数（在chucard里面没有用到这个，不知道是否有用）
	int number = 0;
	//以下是拆出来的牌
	int huojian[2] = { 0 };
	int zhadan[20] = { 0 };
	int shuangpai[20] = { 0 };
	int sanzhang[20] = { 0 };
	int danshun[20] = { 0 };
	int temphandcard[20] = { 0 };

	//这个最后表示的是剩余的单牌杂牌
	int left_right_;
	//上一个人打出的牌
	int temp[20] = { 0 };

	void Ai_Right_Buchu(Draw draw);
	void chu_card(Draw draw);
	void order2(int b[], int num);
	void order3(int a[]);
	void temp_initlize();
	void initlize();
	void chai_pai();
	void BoomCard(Draw draw);
	//chucard函数里面用来判断是否有王炸，有王炸可以不管什么tempfunction都直接出
	void RocketCard(Draw draw);

	//判断前一定要先拆牌,抢的时候返回true
	bool if_grab_landlord();

	void reset_danshun(int start, int num);

	//arr[]是传入需要改动的数组，b是传入按照谁来改动的数组，num是重置的数量，start是传入从哪里开始改动
	void reset_array(int arr[], int b[], int start, int num);

	void first_chu(Draw draw);

	void follow_chu(Draw draw);


	void set_left_or_right(int a);
	void matrix_to_no_matrix();
	void no_matrix_to_matrix();

};

#endif AIYY_H