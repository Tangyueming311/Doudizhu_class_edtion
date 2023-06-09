
#include "Player.h"
using namespace std;

int K_temp_card[15] = { 0 };
int K_order = 2;

void Player::set_handcards(int* handcards)
{
	for (int i = 0; i <15; i++) {
		
		handcards_[i] = handcards[i];
		
	}	
}

int* Player::handcards()
{
	return handcards_;
}

void Player::set_temp_cards(int* temp_cards)
{
	for (int i = 0; i < 15; i++) {
		temp_cards_[i] = temp_cards[i];
	}
}

int* Player::temp_cards()
{
	return temp_cards_;
}

void Player::set_if_lord(bool if_lord)
{
	if_lord_ = if_lord;
}

bool Player::if_lord()
{
	return if_lord_;
}

void Player::set_happy_beans(int happy_beans)
{
	happy_beans_ = happy_beans;
	happy_numbers_ = 1;
}

void Player::set_happy_numbers(int a)
{
	
	happy_numbers_ = a;
}


void Player::set_order_of_play(int order_of_play)
{
	order_of_play_ = order_of_play;
}

int Player::order_of_play()
{
	return order_of_play_;
}


bool Player::if_win_endgame(int* handcards)
{
	int temp = 0;
	for (int i = 0; i < 15; i++) {
		temp = handcards[i] + temp;
	}

	if (temp == 0) {
		return true;
	}
	else return false;
}

void Player::set_temp_card_class(int temp_card_class)
{
	temp_card_class_ = temp_card_class;
}

int Player::card_num(int* card) {
	int temp = 0;
	for (int i = 0; i < 15; i++) {
		temp += card[i];
	}
	return temp;
}






//�ж�Ҫ��������Ƿ���Դ��
// ���ڳ��γ���
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ1��0�����Դ��Ϊ1��������Ϊ0
int Player::first_chu_judge(int* a) {
	int num = 0;
	int i = 0;


	//numΪҪ�����������
	while (a[i] != 0)
	{
		num++;
		i++;

	}

	if (num == 1) {
		temp_card_class_ = 101;           //�ݴ�ֵ���Ƶ�����Ϊ����	
		//	cout << "�����˵���\n";
		return 1;
	}

	else if (num == 2) {
		if (a[0] == a[1]) {
			temp_card_class_ = 202;      //�ݴ�ֵ���Ƶ�����Ϊ����	
			//		cout << "�����˶���\n";
			return 1;
		}
		else if(a[0]==16&&a[1]==17) {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			double_happy_numbers();
			double_happy_numbers();
			return 1;
		}
		else {
			return 0;
		}
	}

	else if (num == 3) {
		if (a[0] == a[1] && a[1] == a[2]) {
			temp_card_class_ = 1303;         //�ݴ�ֵ���Ƶ�����Ϊ����	
			//		cout << "����������һ������\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 4) {
		if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
			temp_card_class_ = 1;         //�ݴ�ֵ���Ƶ�����Ϊը��	
			double_happy_numbers();
			//		cout << "��ֱ�Ӵ����ը����!!!\n";
			return 1;
		}
		else if ((a[0] == a[1] && a[1] == a[2] && a[2] != a[3]) || (a[0] != a[1] && a[1] == a[2] && a[2] == a[3])) {
			temp_card_class_ = 2104;          //�ݴ�ֵ���Ƶ�����Ϊ����һ
			//		cout << "����������һ\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 5) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1105;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-5	
			//		cout << "������5��˳��\n";
			return 1;
		}
		if (first_chu_judge_plane2(a)) {
			temp_card_class_ = 2205;        //�ݴ�ֵ���Ƶ�����Ϊ ������
			//		cout << "����������һ��\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 6) {


		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1106;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-6
			//		cout << "������6��˳��\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1206;         //�ݴ�ֵ���Ƶ�����Ϊ˫˳��-6
			//		cout << "������6�ŵ�˫˳��\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi3(a)) {
			temp_card_class_ = 1306;         //�ݴ�ֵ���Ƶ�����Ϊ��˳��-6
			//		cout << "������6�ŵ���˳��\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 7) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1107;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-7
			//		cout << "������7��˳��\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 8) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1108;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-8
			//		cout << "������8��˳��\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1208;         //�ݴ�ֵ���Ƶ�����Ϊ˫˳��-8
			//		cout << "������8�ŵ�˫˳��\n";
			return 1;
		}
		else if (first_chu_judge_plane1(a)) {
			temp_card_class_ = 2108;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ�����-8
			//		cout << "������8�ŵķɻ�����\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}

	}

	else if (num == 9) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1109;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-9
			//		cout << "������9��˳��\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi3(a)) {
			temp_card_class_ = 1309;         //�ݴ�ֵ���Ƶ�����Ϊ��˳��-9
			//		cout << "������9�ŵ���˳��\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 10) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1110;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-10
			//		cout << "������10��˳��\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1210;         //�ݴ�ֵ���Ƶ�����Ϊ˫˳��-10
			//		cout << "������10�ŵ�˫˳��\n";
			return 1;
		}
		else if (first_chu_judge_plane2(a)) {
			temp_card_class_ = 2210;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ���˫-10
			//		cout << "������10�ŵķɻ���˫\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 11) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1111;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-11
			//		cout << "������11��˳��\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 12) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1112;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-12
			//		cout << "������12��˳��\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1212;         //�ݴ�ֵ���Ƶ�����Ϊ˫˳��-12
			//		cout << "������12�ŵ�˫˳��\n";
			return 1;
		}
		else if (first_chu_judge_plane1(a)) {
			temp_card_class_ = 2112;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ�����-12
			//		cout << "������12�ŵķɻ�����\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi3(a)) {
			temp_card_class_ = 1312;         //�ݴ�ֵ���Ƶ�����Ϊ��˳��-12
			//		cout << "������12�ŵ���˳��\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 13) {
		//	cout << "���Ʋ����Ϲ淶" << endl;
		return 0;
	}

	else if (num == 14) {
		if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1214;         //�ݴ�ֵ���Ƶ�����Ϊ˫˳��-14
			//		cout << "������14�ŵ�˫˳��\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 15) {
		if (first_chu_judge_Shunzi3(a)) {
			temp_card_class_ = 1315;          // �ݴ�ֵ���Ƶ�����Ϊ��˳�� - 15
			//		cout << "������15�ŵ���˳��\n";
			return 1;
		}

		else if (first_chu_judge_plane2(a)) {
			temp_card_class_ = 2215;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ���˫-15
			//		cout << "������15�ŵķɻ���˫\n";
			return 1;
		}

		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 16) {
		if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1216;          // �ݴ�ֵ���Ƶ�����Ϊ˫˳�� - 16
			//		cout << "������16�ŵ�˫˳����\n";
			return 1;
		}

		else if (first_chu_judge_plane1(a)) {
			temp_card_class_ = 2116;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ�����-16
			//		cout << "������16�ŵķɻ�����\n";
			return 1;
		}

		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}
	else if (num == 17) {
		//	cout << "���Ʋ����Ϲ淶" << endl;
		return 0;
	}

	else if (num == 18) {
		if (first_chu_judge_Shunzi3(a)) {
			temp_card_class_ = 1318;          // �ݴ�ֵ���Ƶ�����Ϊ��˳�� - 18
			//		cout << "������18�ŵ���˳��\n";
			return 1;
		}

		if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1218;          // �ݴ�ֵ���Ƶ�����Ϊ˫˳�� - 18
			//		cout << "������18�ŵ�˫˳��\n";
			return 1;
		}
		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 19) {
		//	cout << "���Ʋ����Ϲ淶" << endl;
		return 0;
	}

	else if (num == 20) {
		if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1220;          // �ݴ�ֵ���Ƶ�����Ϊ˫˳�� - 20
			//		cout << "������20�ŵ�˫˳��\n";
			return 1;
		}

		else if (first_chu_judge_plane1(a)) {
			temp_card_class_ = 2120;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ�����-20
			//		cout << "������20�ŵķɻ�����\n";
			return 1;
		}
		else if (first_chu_judge_plane2(a)) {
			temp_card_class_ = 2220;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ���˫-20
			//		cout << "������20�ŵķɻ���˫\n";
			return 1;
		}

		else {
			//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else {
		//	cout << "���Ʋ����Ϲ淶" << endl;
		return 0;
	}




}

//��˳���жϣ��������������
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ0��1��1������˳�ӣ�0������
int Player::first_chu_judge_Shunzi1(int* b) {
	//�ñ��������ж�˳�����Ƿ��2����Ϊ1��û��Ϊ��һ����2��������0������������
	//������2 �Ĵ���ֵΪ15
	int flag_2 = 0;
	for (int i = 0; i < 20; i++) {
		if (b[i] == 15) {
			flag_2 = 1;
			break;
		}
	}

	if (flag_2 == 1) {
		return 0;
	}
	else {

		//�ں�������ʱ����һ�����飬���βθ��ƹ���
		int a[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			a[i] = b[i];
		}

		int temp = a[0];
		//��һ�����ô�������������ȥa[0]��i��������ȫ��Ϊ0������������μ�1��˳��
		int i = 0;
		while (a[i] != 0) {
			a[i] = a[i] - temp - i;
			i++;
		}

		//���a[]���������Ϊ0����ȷʵ��˳�ӣ�����1���෴�򷵻�0
		int temp1 = 1;
		for (int i = 0; i < 20; i++) {
			if (a[i] != 0) {
				temp1 = 0;
			}
		}

		if (temp1 == 1) {
			return 1;
		}
		else {
			return 0;
		}


	}
}

//˫˳���жϣ��������������
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ0��1��1������˳�ӣ�0������
int Player::first_chu_judge_Shunzi2(int* b) {
	//�ں�������ʱ����һ�����飬���βθ��ƹ���
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}



	int temp = a[0];
	//��һ�Σ������ö��ӵ�����һ����ȥǰ���һ��������˫˳�ӱ�ɵ�˳��
	//Ȼ��i��2�ۼӣ����е�˳�ӵ�������õ����ȫΪ0
	int i = 0;
	do {

		a[i + 1] = a[i + 1] - a[i];
		a[i] = a[i] - temp - i / 2;

		i = i + 2;
		//�޶�i�ķ�Χ�������
	} while (a[i] != 0 && i < 19);

	//���a[]���������Ϊ0����ȷʵ��˳�ӣ�����1���෴�򷵻�0
	int temp1 = 1;
	for (int i = 0; i < 20; i++) {
		if (a[i] != 0) {
			temp1 = 0;
		}
	}

	if (temp1 == 1) {
		return 1;
	}
	else {
		return 0;
	}

}


//��˳���жϣ��������������
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ0��1��1������˳�ӣ�0������
int Player::first_chu_judge_Shunzi3(int* b) {
	//�ں�������ʱ����һ�����飬���βθ��ƹ���
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}
	int temp = a[0];
	//��һ�Σ������ö��ӵ����ж�����ȥ��ǰ���һ����������˳�ӱ�ɼ��2��0�ĵ�˳��
	//Ȼ��i��3�ۼӣ����е�˳�ӵ�������õ����ȫΪ0
	int i = 0;
	//�޶�i�ķ�Χ�������
	while (a[i] != 0 && i < 18) {
		a[i + 2] = a[i + 2] - a[i];
		a[i + 1] = a[i + 1] - a[i];
		a[i] = a[i] - temp - i / 3;

		i = i + 3;
	}

	//���a[]���������Ϊ0����ȷʵ��˳�ӣ�����1���෴�򷵻�0
	int temp1 = 1;
	for (int i = 0; i < 20; i++) {
		if (a[i] != 0) {
			temp1 = 0;
		}
	}

	if (temp1 == 1) {
		return 1;
	}
	else {
		return 0;
	}


}

//�ɻ�-�����ж�
//�ɻ�����Ϊ��n��������ͬ������n�����ƻ���n������
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ0��1��1�����Ƿɻ���0������
int Player::first_chu_judge_plane1(int* b) {
	//�ں�������ʱ����һ�����飬���βθ��ƹ���
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}
	//�������飬��������ͬ���ƶ���ֵΪ1������ֵΪ0����Ϊ��ȱλΪ0���Լ�����Ӱ�죩����ֵһ��temp+1;
	//forֻ��18����Ϊ���������
	//����point��Ϊ�˴�����ֵ�������ͬ���Ƶ����棬��Ϊ�ɻ���Ҫ����
	int point[5] = { 0 };
	int temp = 0;
	for (int i = 0; i < 18; i++) {
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i] != 0 && a[i] != 1) {
			point[temp] = a[i];
			a[i] = 1, a[i + 1] = 1, a[i + 2] = 1;

			temp++;
		}
	}

	//�Ƚ�point�����ﴢ������֣�
	//��һ������point���������ȥpoint[0]��i��������ȫ��Ϊ0������������μ�1
	int i = 0;
	int Temp = point[0];
	while (point[i] != 0) {
		point[i] = point[i] - Temp - i;
		i++;
	}

	//���point[]���������Ϊ0����ȷʵ�Ƿɻ�������1���෴�򷵻�0
	int temp1 = 1;
	for (int i = 0; i < 5; i++) {
		if (point[i] != 0) {
			temp1 = 0;
		}
	}

	//�ٴα������飬�����в�Ϊ0����Ϊ1��������������������temp�Ƚϣ���ͬ�Ļ���Ϊ��
	int temp2 = 0;
	for (int i = 0; i < 20; i++) {
		if ((a[i] != 1) && (a[i] != 0)) {
			temp2++;

		}
	}
	if (temp == temp2 && temp1 == 1) {
		return 1;
	}
	else return 0;
}

//�ɻ�-��˫�ж�
//�ɻ�����Ϊ��n��������ͬ������n�����ƻ���n������
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ0��1��1�����Ƿɻ���0������
int Player::first_chu_judge_plane2(int* b) {
	//�ں�������ʱ����һ�����飬���βθ��ƹ���
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}

	//�������飬��������ͬ���ƶ���ֵΪ1������ֵΪ0����Ϊ��ȱλΪ0���Լ�����Ӱ�죩����ֵһ��temp+1;
	//forֻ��18����Ϊ���������
	int point[5] = { 0 };
	int temp = 0;
	for (int i = 0; i < 18; i++) {
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i] != 0 && a[i] != 1) {
			a[i] = 1, a[i + 1] = 1, a[i + 2] = 1;
			point[temp] = a[i];
			temp++;
		}
	}

	//�ٴα������飬�����в�Ϊ0����Ϊ1��������������������ֵ���µ�����b
	int c[20] = { 0 };
	int j = 0;

	for (int i = 0; i < 20; i++) {
		if ((a[i] != 1) && (a[i] != 0)) {
			c[j] = a[i];
			j++;
		}
	}
	//�Ƚ�point�����ﴢ������֣�
	//��һ������point���������ȥpoint[0]��i��������ȫ��Ϊ0������������μ�1
	int i = 0;
	int Temp = point[0];
	while (point[i] != 0) {
		point[i] = point[i] - Temp - i;
		i++;
	}

	//���point[]���������Ϊ0����ȷʵ�Ƿɻ�������1���෴�򷵻�0
	int temp1 = 1;
	for (int i = 0; i < 5; i++) {
		if (point[i] != 0) {
			temp1 = 0;
		}
	}

	//��ʱ��������b���Ѷ���ȫ�������ж�
	//��������b���±�ÿ��+2��b[i]Ӧ����b[i+1],���������flag=1���м���ֲ�������flag=0
	//ѭ��һ��temp2��һ��������¼���������������������������������һ����flag=1����ȷʵ�Ƿɻ��󣬷���1
	int flag = 1;
	int k = 0;
	int temp2 = 0;
	while (c[k] != 0) {
		if (c[k] != c[k + 1]) {
			flag = 0;
			break;
		}
		k = k + 2;
		temp2++;
	}

	if (flag == 1 && temp == temp2 && temp1 == 1) {
		return 1;
	}
	else return 0;
}



//�ж�Ҫ��������Ƿ���Դ��
// ���ڸ������
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ���ƣ��β�cΪint���ͣ�Ϊ�Ƶ�����
//returnֵΪ1��0�����Դ��Ϊ1��������Ϊ0
int Player::follow_chu_judge(int* a, int* b, int c)
{
	int num = 0;
	int i = 0;
	int num2 = 0;
	int j = 0;
	while (a[i] != 0)
	{
		num++;
		i++;
	}
	while (b[j] != 0)
	{
		num2++;
		j++;
	}

	//���Ҫ����Ƶ��������ݴ���������ͬ�����Բ��ܴ�
	if (num != num2 && num != 4 && num != 2) {
		//		cout << "��������" << endl;
		//		cout << "�ݴ�������" << num2 << " " << "�������" << num << endl;
		return 0;
	}



	//�ֱ��жϸ������


	else if (num != num2 && num == 4) {
		if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && b[0] != 16 && b[1] != 17) {

			//			cout << "ը��ѹ����������" << endl;
			double_happy_numbers();
			return 1;
		}
		else {
			//			cout << "��������" << endl;
			//			cout << "�ݴ�������" << num2 << " " << "�������" << num << endl;
			return 0;
		}
	}
	else if (num != num2 && num == 2) {
		if (a[0] == 16 && a[1] == 17) {

			//			cout << "��ը��ɱ����������"<<endl;
			double_happy_numbers();
			double_happy_numbers();
			return 1;
		}
		else {
			//			cout << "��������" << endl;
			//			cout << "�ݴ�������" << num2 << " " << "�������" << num << endl;
			return 0;
		}
	}


	else if (num == num2) {

		if (num == 1) {
			if (follow_chu_judge_singleCard(a, b) == 1)
			{
				//				cout << "����" << endl;

				return 1;
			}
			else {

				//				cout << "С��" << endl;
				return 0;
			}
		}

		else if (num == 2) {
			if (a[0] == 16 && a[1] == 17) {
				//				cout << "��ը��ɱ����������" << endl;
				return 1;
			}
			else {
				if (follow_chu_judge_doubleCard(a, b) == 1)
				{
					//				cout << "����" << endl;

					return 1;
				}
				else if (follow_chu_judge_doubleCard(a, b) == 0) {

					//				cout << "С��" << endl;
					return 0;
				}
				else if (follow_chu_judge_doubleCard(a, b) == 2) {
					//					cout << "�����Ϲ淶" << endl;
					return 0;
				}
			}

		}

		else if (num == 3) {
			if (follow_chu_judge_threeCard(a, b) == 1)
			{
				//				cout << "����" << endl;

				return 1;
			}
			else if (follow_chu_judge_threeCard(a, b) == 0) {

				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_threeCard(a, b) == 2) {
				//				cout << "�����Ϲ淶" << endl;
				return 0;
			}
		}

		else if (num == 4) {
			if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && b[0] == b[1] && b[1] == b[2] && b[2] == b[3]) {
				if (follow_chu_judge_BoomCard(a, b) == 0) {
					//					cout << "С��" << endl;
					return 0;
				}
				else if (follow_chu_judge_BoomCard(a, b) == 1) {
					//				cout << "����ը��������" << endl;

					return 1;
				}
				else if (follow_chu_judge_BoomCard(a, b) == 2) {
					//					cout << "�����Ϲ淶" << endl;
					return 0;
				}
			}
			else {
				if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {

					//					cout << "ը��ѹ����������" << endl;
					return 1;
				}

				else if (follow_chu_judge_plane1(a, b) == 0) {
					//					cout << "С��" << endl;
					return 0;
				}
				else if (follow_chu_judge_plane1(a, b) == 1) {
					//					cout << "����һ" << endl;
					return 1;
				}
				else if (follow_chu_judge_plane1(a, b) == 2) {
					//					cout << "�����Ϲ淶" << endl;
					return 0;
				}
			}
		}

		else if (num == 5) {
			if (follow_chu_judge_plane1(a, b) == 0) {
				//				cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//				cout << "����һ" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//				cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//				cout << "˳��" << endl;
				return 1;
			}

			else {
				//				cout << "�����Ϲ淶" << endl;
				return 0;
			}
		}

		else if (num == 6) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "˳��" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "����" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 0) {
				//				cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 1) {
				//			cout << "�ɻ�û���" << endl;
				return 1;
			}
			else {
				//			cout << "�����Ϲ淶" << endl;
				return 0;
			}

		}

		else if (num == 7) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "˳��" << endl;
				return 1;
			}
			else {
				//			cout << "�����Ϲ淶" << endl;
				return 0;
			}

		}
		else if (num == 8) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "˳��" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "����" << endl;
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//			cout << "�ɻ�" << endl;
				return 1;
			}
			else {
				//			cout << "�����Ϲ淶" << endl;
				return 0;
			}

		}

		else if (num == 9) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "˳��" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 1) {
				//			cout << "�ɻ�û���" << endl;
				return 1;
			}
			else {
				//			cout << "�����Ϲ淶" << endl;
				return 0;
			}
		}
		else if (num == 10) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "˳��" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "����" << endl;
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//			cout << "�ɻ�" << endl;
				return 1;
			}
			else {
				//				cout << "�����Ϲ淶" << endl;
				return 0;
			}
		}
		else if (num == 11) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//				cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//				cout << "˳��" << endl;
				return 1;
			}
			else {
				//				cout << "�����Ϲ淶" << endl;
				return 0;
			}

		}
		else if (num == 12) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "˳��" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "����" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 1) {
				//			cout << "�ɻ�û���" << endl;
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//			cout << "����һ" << endl;
				return 1;
			}
			else {
				
				return 0;
			}

		}
		else if (num == 14) {
			if (follow_chu_judge_Shunzi2(a, b) == 0) {
				
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				
				return 1;
			}
			else {
				
				return 0;
			}

		}
		else if (num == 15) {
			if (follow_chu_judge_Shunzi3(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 1) {
				//			cout << "�ɻ�û���" << endl;
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//			cout << "�ɻ�" << endl;
				return 1;
			}
			else {
				//			cout << "�����Ϲ淶" << endl;
				return 0;
			}
		}
		else if (num == 16) {

			if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "����" << endl;
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//			cout << "����һ" << endl;
				return 1;
			}
			else {
				//			cout << "�����Ϲ淶" << endl;
				return 0;
			}

		}
		else if (num == 18) {

			if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "����" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 0) {
				//			cout << "С��" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 1) {
				//			cout << "�ɻ�û���" << endl;
				return 1;
			}
			else {
				//			cout << "�����Ϲ淶" << endl;
				return 0;
			}

		}
		else if (num == 20) {

			if (follow_chu_judge_Shunzi2(a, b) == 0) {
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				return 1;
			}
			else {
				return 0;
			}

		}
		else {
			return 0;
		}


	}



}


//��˳���ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int Player::follow_chu_judge_Shunzi3(int* a, int* b) {
	if (first_chu_judge_Shunzi3(a) == 1) {
		//�ں�������ʱ�����������飬���βθ��ƹ���
		//temp1�����Ӧa��ΪҪ������ƣ�tenp2�����Ӧb��Ϊ�ݴ����
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}

		if (temp1[0] > temp2[0]) {
			return 1;
		}
		else {
			return 0;
		}


	}
	else {
		return 2;        //�����Ϲ淶�ĳ��Ʒ���2ֵ
	}
}
//˫˳���ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int Player::follow_chu_judge_Shunzi2(int* a, int* b) {
	if (first_chu_judge_Shunzi2(a) == 1) {
		//�ں�������ʱ�����������飬���βθ��ƹ���
		//temp1�����Ӧa��ΪҪ������ƣ�tenp2�����Ӧb��Ϊ�ݴ����
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}

		if (temp1[0] > temp2[0]) {
			return 1;
		}
		else {
			return 0;
		}


	}
	else {
		return 2;        //�����Ϲ淶�ĳ��Ʒ���2ֵ
	}
}







//��˳���ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int Player::follow_chu_judge_Shunzi1(int* a, int* b) {
	if (first_chu_judge_Shunzi1(a) == 1) {
		//�ں�������ʱ�����������飬���βθ��ƹ���
		//temp1�����Ӧa��ΪҪ������ƣ�tenp2�����Ӧb��Ϊ�ݴ����
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}

		if (temp1[0] > temp2[0]) {
			return 1;
		}
		else {
			return 0;
		}


	}
	else {
		return 2;        //�����Ϲ淶�ĳ��Ʒ���2ֵ
	}
}



//�ɻ���˫�ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int Player::follow_chu_judge_plane2(int* a, int* b) {
	if (first_chu_judge_plane2(a) == 1) {
		//�ں�������ʱ�����������飬���βθ��ƹ���
		//temp1�����Ӧa��ΪҪ������ƣ�tenp2�����Ӧb��Ϊ�ݴ����
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}
		//�������飬��������ͬ���ƶ���ֵΪ1������ֵΪ0����Ϊ��ȱλΪ0���Լ�����Ӱ�죩����ֵһ��temp+1;
		//forֻ��18����Ϊ���������
		//����point��Ϊ�˴�����ֵ�������ͬ���Ƶ����棬��Ϊ�ɻ���Ҫ����
		int point1 = 0;
		for (int i = 0; i < 18; i++) {
			if (temp1[i] == temp1[i + 1] && temp1[i + 1] == temp1[i + 2] && temp1[i] != 0) {
				point1 = temp1[i];
				break;
			}
		}

		int point2 = 0;
		for (int i = 0; i < 18; i++) {
			if (temp2[i] == temp2[i + 1] && temp2[i + 1] == temp2[i + 2] && temp2[i] != 0) {
				point2 = temp2[i];
				break;
			}
		}

		if (point1 > point2) {
			return 1;
		}
		else {
			return 0;
		}

	}
	else {
		return 2;        //�����Ϲ淶�ĳ��Ʒ���2ֵ
	}
}




//�ɻ������ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int Player::follow_chu_judge_plane1(int* a, int* b) {
	if (first_chu_judge_plane1(a) == 1) {
		//�ں�������ʱ�����������飬���βθ��ƹ���
		//temp1�����Ӧa��ΪҪ������ƣ�tenp2�����Ӧb��Ϊ�ݴ����
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}

		//�������飬��������ͬ���ƶ���ֵΪ1������ֵΪ0����Ϊ��ȱλΪ0���Լ�����Ӱ�죩����ֵһ��temp+1;
		//forֻ��18����Ϊ���������
		//����point��Ϊ�˴�����ֵ�������ͬ���Ƶ����棬��Ϊ�ɻ���Ҫ����
		int point1 = 0;
		for (int i = 0; i < 18; i++) {
			if (temp1[i] == temp1[i + 1] && temp1[i + 1] == temp1[i + 2] && temp1[i] != 0) {
				point1 = temp1[i];
				break;
			}
		}

		int point2 = 0;
		for (int i = 0; i < 18; i++) {
			if (temp2[i] == temp2[i + 1] && temp2[i + 1] == temp2[i + 2] && temp2[i] != 0) {
				point2 = temp2[i];
				break;
			}
		}

		if (point1 > point2) {
			return 1;
		}
		else {
			return 0;
		}


	}
	else {
		return 2;        //�����Ϲ淶�ĳ��Ʒ���2ֵ
	}
}


//ը���ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int Player::follow_chu_judge_BoomCard(int* a, int* b) {
	if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
		if (a[0] > b[0]) {
			double_happy_numbers();
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 2;        //�����Ϲ淶�ĳ��Ʒ���2ֵ
	}
}

//�����ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int Player::follow_chu_judge_singleCard(int* a, int* b) {
	if (a[0] > b[0]) {
		return 1;

	}
	else {

		return 0;

	}
}

//˫���ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int Player::follow_chu_judge_doubleCard(int* a, int* b) {
	if (a[0] == a[1]) {

		if (a[0] > b[0]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 2;        //�����Ϲ淶�ĳ��Ʒ���2ֵ
	}
}

//�����ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int Player::follow_chu_judge_threeCard(int* a, int* b) {
	if (a[0] == a[1] && a[1] == a[2]) {

		if (a[0] > b[0]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 2;        //�����Ϲ淶�ĳ��Ʒ���2ֵ
	}
}



bool Player::first_chu_judge_matrix(int* chucards)
{

	//��ת����no matrix
	int card_no_matrix[20] = { 0 };
	int card_no_matrix_index = 0;
	for (int i = 0; i < 15; i++) {
		if (chucards[i] != 0) {
			int temp_num = chucards[i];
			for (int j = 0; j < temp_num; j++) {
				card_no_matrix[card_no_matrix_index + j] = i + 3;
			}
			card_no_matrix_index += temp_num;
		}
	}



	if (first_chu_judge(card_no_matrix) == 1) {
		return true;
	}
	else return false;


	
}

bool Player::follow_chu_judge_matrix(int* chucards, int* temp_cards, int temp_card_class) {


	//��ת����no matrix
	int temp_chucard[20] = { 0 };
	int temp_chucard_index = 0;
	for (int i = 0; i < 15; i++) {
		if (chucards[i] != 0) {
			int temp_num = chucards[i];
			for (int j = 0; j < temp_num; j++) {
				temp_chucard[temp_chucard_index + j] = i + 3;
			}
			temp_chucard_index += temp_num;
		}
	}




	//��ת����no matrix
	int temp_temp_cards[20] = { 0 };
	int temp_temp_cards_index = 0;
	for (int i = 0; i < 15; i++) {
		if (temp_cards[i] != 0) {
			int temp_num = temp_cards[i];
			for (int j = 0; j < temp_num; j++) {
				temp_temp_cards[temp_temp_cards_index + j] = i + 3;
			}
			temp_temp_cards_index += temp_num;
		}
	}









	if (follow_chu_judge(temp_chucard, temp_temp_cards, temp_card_class) == 1) {
		return true;
	}
	else return false;

}





void Player::double_happy_numbers()
{
	happy_numbers_ = happy_numbers_ * 2;
}

void Player::print_happy_numbers_and_beans(int MapLength, int MapHeight, int happy_numbers, int happy_beans)
{
	gotoxy(MapLength / 2 - 18, MapHeight+2);
	cout << "����ǰ��������" << happy_numbers;

	gotoxy(MapLength / 2 + 15, MapHeight+2);
	cout << "�����ֶ�����" << happy_beans;


}

int Player::evaluate_happy_beans(int happy_numbers, int happy_beans, int winner, int landlord)
{
	int change_happy_beans = 0;
	if (landlord == 1 && winner == 1) {
		change_happy_beans = 5 * 2 * happy_numbers;
	}
	else if (landlord == 1 && winner != 1) {
		change_happy_beans = -5 * 2 * happy_numbers;
	}
	else if (landlord != 1 && winner == 1) {
		change_happy_beans = 5 * happy_numbers;
	}
	else if (landlord != 1 && winner != 1) {
		change_happy_beans = -5 * happy_numbers;
	}

	if ((change_happy_beans + happy_beans) < 0) {
		happy_beans = 0;
	}
	else {
		happy_beans = happy_beans + change_happy_beans;
	}

	gotoxy(190 / 2, 55 / 2);
	cout << change_happy_beans << "  " << "���ֶ����" << happy_beans;
	return happy_beans;

}


