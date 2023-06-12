
#ifndef AIYY_H
#define AIYY_H
#include "Player.h"
#include "Draw.h"
#include "Ai.h"
class AiYY :
	public Ai
{
public:
	//���ƺ����õ����м�����
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

	//chucardfirst��������������������chucard����û���õ��������֪���Ƿ����ã�
	int number = 0;
	//�����ǲ��������
	int huojian[2] = { 0 };
	int zhadan[20] = { 0 };
	int shuangpai[20] = { 0 };
	int sanzhang[20] = { 0 };
	int danshun[20] = { 0 };
	int temphandcard[20] = { 0 };

	//�������ʾ����ʣ��ĵ�������
	int left_right_;
	//��һ���˴������
	int temp[20] = { 0 };

	void Ai_Right_Buchu(Draw draw);
	void chu_card(Draw draw);
	void order2(int b[], int num);
	void order3(int a[]);
	void temp_initlize();
	void initlize();
	void chai_pai();
	void BoomCard(Draw draw);
	//chucard�������������ж��Ƿ�����ը������ը���Բ���ʲôtempfunction��ֱ�ӳ�
	void RocketCard(Draw draw);

	//�ж�ǰһ��Ҫ�Ȳ���,����ʱ�򷵻�true
	bool if_grab_landlord();

	void reset_danshun(int start, int num);

	//arr[]�Ǵ�����Ҫ�Ķ������飬b�Ǵ��밴��˭���Ķ������飬num�����õ�������start�Ǵ�������￪ʼ�Ķ�
	void reset_array(int arr[], int b[], int start, int num);

	void first_chu(Draw draw);

	void follow_chu(Draw draw);


	void set_left_or_right(int a);
	void matrix_to_no_matrix();
	void no_matrix_to_matrix();

};

#endif AIYY_H