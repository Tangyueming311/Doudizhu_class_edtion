#ifndef CARD_H
#define CARD_H
class Card
{
public:
	//�±�Ϊ˳����ֵΪ����
	int orign_part1_[17] = { 0 };
	int orign_part2_[17] = { 0 };
	int orign_part3_[17] = { 0 };

	//�±�����Ϊ���棬��ֵΪ����
	int matrix_part1_[15] = { 0 };
	int matrix_part2_[15] = { 0 };
	int matrix_part3_[15] = { 0 };
	int matrix_landlord_[15] = {0};

	int landlord_[3] = { 0 };
	int orign_card_[54] = { 0 };


	void card();     
		
		
		
		
	//���ƽ��и�ֵ
	void washCard();
	void dealcard();

	void change_card_to_matrix();

	int* matrix_part1();
	int* matrix_part2();
	int* matrix_part3();
	int* matrix_landlord();

    void set_lord_card(int num);




};

#endif