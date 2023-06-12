#include "AiYY.h"
#include <iostream>
#include <algorithm>
using namespace std;

//�������������ǰ�����˼����ƣ���ȥ�������ƣ�ͬʱ�ں��油�㣬num��ȥ��������
void AiYY::order2(int b[], int num)
{
	for (int i = 0; i < 20 - num; i++)
	{
		b[i] = b[i + num];
	}
	for (int k = 20 - num; k < 20; k++)
	{
		b[k] = 0;
	}
}

//С��������ͬʱ����ź���
void AiYY::order3(int a[])
{

	int v = 0;
	while (a[v] == 0 && v <= 19)
	{
		v++;
	}

	for (int i = 0; i < 20 - v; i++)
	{
		a[i] = a[i + v];
	}
	for (int k = 20 - v; k < 20; k++)
	{
		a[k] = 0;
	}
}

//��temp�������ȫ������ĺ���
void AiYY::temp_initlize()
{
	for (int i = 0; i < 20; i++)
	{
		temp[i] = 0;
	}
}

//���ƺ���ǰ�����п����ʼ���ĺ���
void AiYY::initlize()
{
	for (int i = 0; i < 20; i++)
	{
		zhadan[i] = 0;
		shuangpai[i] = 0;
		sanzhang[i] = 0;
		danshun[i] = 0;
		temphandcard[i] = handcard[i];
		one[i] = handcard[i];
	}
	huojian[0] = 0;
	huojian[1] = 0;
	a = 0;
	b = 0;
	c = 0;
}
//���ƺ���
void AiYY::chai_pai()
{
	initlize();
	int temp = 0;
	sort(handcard, handcard + 20);

	while (handcard[temp] == 0 && temp <= 19) {
		temp++;
	}

	for (int i = 0; i < 20; i++) {
		temphandcard[i] = handcard[i];
	}

	for (int j = temp; j < 20; j++)
	{
		if (temphandcard[j + 1] == temphandcard[j])
		{

			two[a] = temphandcard[j + 1];
			one[j + 1] = 0;
			a++;
			sort(temphandcard, temphandcard + 20);
			sort(one, one + 20);
			j++;
			if (temphandcard[j + 1] == temphandcard[j])
			{

				three[b] = temphandcard[j + 1];
				one[j + 1] = 0;
				b++;
				sort(temphandcard, temphandcard + 20);
				sort(one, one + 20);
				j++;
				int temp = 0;

				if (temphandcard[j + 1] == temphandcard[j])
				{
					four[c] = temphandcard[j + 1];

					one[j + 1] = 0;
					c++;
					sort(temphandcard, temphandcard + 20);
					sort(one, one + 20);
					j++;
				}
			}

		}
	}
	sort(four, four + 20);
	sort(three, three + 20);
	sort(two, two + 20);
	//���һ��
	for (int i = 0; i < 20; i++)
	{

		if (temphandcard[i] == 16 && temphandcard[i+1] == 17)
		{
			huojian[0] = temphandcard[i];
			huojian[1] = 17;
			temphandcard[i] = 0;
			temphandcard[i + 1] = 0;
			break;
		}
	}
	sort(temphandcard, temphandcard + 20);
	//��ը��
	int m = 0;
	for (int i = 0; i < 20; i++)
	{
		if (four[i] != 0)
		{
			int k = 0;
			while (k < 4)
			{
				zhadan[m] = four[i];
				k++;
				m++;
			}
			for (int j = 0; j < 20; j++)
			{
				if (three[j] == four[i] && four[i] != 0)
				{

					three[j] = 0;
					//����
					sort(three, three + 20);
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (two[j] == four[i])
				{
					two[j] = 0;
					sort(two, two + 10);
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (one[j] == four[i])
				{
					one[j] = 0;
					sort(one, one + 20);
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (temphandcard[j] == four[i])
				{
					int l = 0;
					while (l < 4)
					{
						temphandcard[j] = 0;
						j++;
						l++;
						sort(temphandcard, temphandcard + 20);
					}

					sort(temphandcard, temphandcard + 20);
				}
			}

		}
	}

	//��������
	int n = 0;
	for (int i = 0; i < 20; i++)
	{

		if (three[i] != 0)
		{
			int k = 0;
			while (k < 3)
			{
				sanzhang[n] = three[i];
				k++;
				n++;
			}
			for (int j = 0; j < 20; j++)
			{
				if (two[j] == three[i])
				{
					two[j] = 0;
					sort(two, two + 20);
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (one[j] == three[i])
				{
					one[j] = 0;
					sort(one, one + 20);
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (temphandcard[j] == three[i])
				{
					int l = 0;
					while (l < 3)
					{
						temphandcard[j] = 0;
						j++;
						l++;
						sort(temphandcard, temphandcard + 20);
					};
				}
			}

		}

	}


	//���ҵ�˳
	int x = 0;
	for (int a = 0; a < 20; a++)
	{

		//���ж��Ƿ������������˳��
		if (one[a] + 1 == one[a + 1] && one[a] + 2 == one[a + 2] && one[a] + 3 == one[a + 3] && one[a] + 1 == one[a + 1] && one[a] + 4 == one[a + 4] && one[a + 4] < 15)
		{

			int b = a;
			b = a;
			int counter = 0;

			for (int j = 0; j < 5; j++, x++)
			{

				danshun[x] = one[b];

				//temphandcard[b] = 0;
				if (j < 4) { b++; }

			}

			counter += 5;
			//�������ŵ�����£�������ֻ��ܼ������˳���������˳�ӵ����ϼ�
			while (one[b + 1] == one[b] + 1)
			{

				b = b + 1;
				danshun[x] = one[b];
				x++;
				counter++;
				//temphandcard[b] = 0;
				//sort(temphandcard, temphandcard + 10);
			}
			//����
			for (int c = 0; c < counter; c++)
			{
				one[a + c] = 0;
			}
			sort(one, one + 20);
			counter = 0;
			b = a;



		}



	}
	int tempdanshun[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		tempdanshun[i] = danshun[i];
	}
	for (int j = 0; j < 20; j++)
	{
		for (int k = 0; k < 20; k++)
		{
			if (temphandcard[j] == tempdanshun[k] && tempdanshun[k] != 0)
			{
				temphandcard[j] = 0;
				tempdanshun[k] = 0;
				sort(tempdanshun, tempdanshun + 20);

			}

		}
	}
	for (int k = 0; k < 20; k++)
	{
		//����two���������
		for (int j = 0; j < 20; j++)
		{
			if (two[j] == danshun[k] && two[j] != 0)
			{
				//cout << "true" << "�˴������" << two[j] << endl;

				two[j] = 0;
				sort(two, two + 20);
			}
		}
	}
	sort(temphandcard, temphandcard + 20);

	//����˫��
	int p = 0;
	for (int i = 0; i < 20; i++)
	{

		if (two[i] != 0)
		{
			int k = 0;
			while (k < 2)
			{
				shuangpai[p] = two[i];
				k++;
				p++;
			}
			for (int j = 0; j < 20; j++)
			{
				if (temphandcard[j] == two[i])
				{
					int l = 0;
					while (l < 2)
					{
						temphandcard[j] = 0;
						j++;
						l++;
						sort(temphandcard, temphandcard + 20);
					}
				}
			}

		}
	}
	sort(temphandcard, temphandcard + 20);
	order3(temphandcard);
	//
	for (int i = 0; i < 20; i++)
	{
		one[i] = 0;
		two[i] = 0;
		three[i] = 0;
		four[i] = 0;

	}
}
//���ը���ĺ�
void AiYY::BoomCard(Draw draw)
{
	//cout << "ը��ѹ��" << endl;

	K_temp_card_class_ = 1;
	for (int i = 0; i < 20; i++)
	{
		temp[0] = 0;

	}
	for (int i = 0; i < 4; i++)
	{
		temp[i] = zhadan[0];
	}


	for (int k = 0; k < 20; k++)
	{
		if (handcard[k] == zhadan[0])
		{
			handcard[k] = 0;

		}
	}

	order2(zhadan, 4);
	//��handcard����0������ǰ��
	sort(handcard, handcard + 20);
	chu_card(draw);
	double_happy_numbers();
	//Ai_Right_Chu(temp, get_handCard_num_());
}

//chucard�������������ж��Ƿ�����ը������ը���Բ���ʲôtempfunction��ֱ�ӳ�
void AiYY::RocketCard(Draw draw )
{
	K_temp_card_class_ = 1;
	//���ÿ���
	huojian[0] = 0;
	huojian[1] = 0;
	sort(handcard, handcard + 20);
	for (int i = 0; i < 20; i++)
	{
		temp[0] = 0;

	}
	temp[0] = 16;
	temp[1] = 17;
	for (int i = 0; i < 20; i++)
	{
		if (handcard[i] == 16 || handcard[i] == 17)
		{
			handcard[i] = 0;
		}

	}
	chu_card(draw);
	double_happy_numbers();
	double_happy_numbers();
	//Ai_Right_Chu(temp, get_handCard_num_());

}

void AiYY::reset_danshun(int start, int num)
{
	for (int i = 0; i < num; i++)
	{
		danshun[start] = 0;
		start++;
	}
	//��������
	sort(danshun, danshun + 20);
	order3(danshun);

}
//arr[]�Ǵ�����Ҫ�Ķ������飬b�Ǵ��밴��˭���Ķ������飬num�����õ�������start�Ǵ�������￪ʼ�Ķ�
void AiYY::reset_array(int arr[], int b[], int start, int num)
{
	for (int i = 0; i < num; i++)
	{
		arr[i] = b[start];
		start++;
	}
}
//�ж�ǰһ��Ҫ�Ȳ���,����ʱ�򷵻�true
bool AiYY::if_grab_landlord()
{

	int weight = 0;
	//���Ȩ��5��
	if (huojian[0] != 0 && huojian[1] != 0)
		weight += 5;
	//for (int i = 0; i < 20; i++)
	//{
	//	if (temphandcard[i] != 0)
	//	{
	//		weight--;
	//	}
	//}
	int number = 0;
	//˳��Ȩ��
	for (int i = 0; i < 20; i++)
	{
		if (danshun[i] != 0)
		{
			number++;
		}
	}
	if (number == 5 || number == 6)
		weight += 3;
	if (number == 7 || number == 8)
		weight += 4;
	if (number > 9)
		weight += 5;
	//����һ��Ȩ��
	number = 0;
	for (int i = 0; i < 20; i++)
	{
		if (sanzhang[i] != 0)
		{
			number++;
		}
	}
	//һ��������
	if (number > 0 && number < 4) {
		weight += 2;
		if (shuangpai[0] != 0 || temphandcard[0] != 0)
		{
			weight += 1;
		}

	}
	//����������
	if (number > 4)
	{
		weight += 4;
		if (shuangpai[0] != 0 || temphandcard[0] != 0)
		{
			weight += 1;
			if (shuangpai[2] != 0 || temphandcard[1] != 0)
				weight += 1;
		}
	}
	if (number > 6)
	{
		weight += 6;
	}
	number = 0;
	if (zhadan[0] != 0)
	{
		weight += 4;
		if (zhadan[4] != 0)
		{
			weight += 4;
			if (zhadan[8] != 0)
				weight += 4;
		}
	}
	//�е���Ӽӷ�
	if (shuangpai[3] > 0)
	{
		weight += 2;
	}
	//̫��۷�
	if (shuangpai[7] > 0)
	{
		weight -= 3;
	}
	if (weight > 6)
	{
		return true;
	}
	else
		return false;



}




void AiYY::first_chu(Draw draw)
{

	for (int j = 0; j < 20; j++) {
		temp[j] = 0;
	}

	bool flag = false;
	//��˫˳��
	for (int i = 0; i < 20; i++)
	{
		if (shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i + 2] + 1 == shuangpai[i + 4])
		{
			flag = true;
			break;
		}
	};
	//���ҷɻ�
	//ûʱ���ˣ���һ�γ��Ƶ��˾��Ȳ�Ҫ��ɻ��˰�

	//��ɨ��˳��
	if (danshun[0] != 0)
	{
		temp_initlize();
		int x = 0;
		for (int a = 0; a < 20; a++)
		{

			//���ж��Ƿ������������˳��
			if (danshun[a] + 1 == danshun[a + 1] && danshun[a] + 2 == danshun[a + 2] && danshun[a] + 3 == danshun[a + 3] && danshun[a] + 1 == danshun[a + 1] && danshun[a] + 4 == danshun[a + 4] && danshun[a + 4] < 15)
			{
				int b = a;
				b = a;
				number = 0;
				for (int j = 0; j < 5; j++, x++)
				{

					temp[x] = danshun[b];

					temphandcard[b] = 0;
					if (j < 4) { b++; }

				}

				number += 5;
				//�������ŵ�����£�������ֻ��ܼ������˳���������˳�ӵ����ϼ�
				while (danshun[b + 1] == danshun[b] + 1)
				{

					b = b + 1;
					temp[x] = danshun[b];
					x++;
					number++;
				}
				//����
				for (int c = 0; c < number; c++)
				{
					danshun[a + c] = 0;
				}
				order2(danshun, number);


				b = a;
			}

		}

		

		//����tempfunction
		K_temp_card_class_ = 1100 + number;
		//����handcard
		//˳�����12��
		for (int k = 0; k < 12; k++)
		{
			if (number - k >= 0)
			{
				for (int i = 0; i < 20; i++)
				{
					if (handcard[i] == temp[number - k])
					{
						handcard[i] = 0;
						break;
					}
				}
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
        chu_card(draw);

	}
	//��˫˳��

	else if (flag)
	{
		temp_initlize();
		int x = 0;
		int m = 0; int n = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i + 2] + 1 == shuangpai[i + 4])
			{
				int u = i;
				u = i;
				number = 6;
				for (; x < number; x++)
				{
					temp[x] = shuangpai[u];

					u++;
				}
				m = x - 1;
				n = u - 1;
				x = x - 2;
				u = u - 2;
				//����������У��������ϼ�
				while (shuangpai[u] + 1 == shuangpai[u + 2])
				{

					m += 1;
					n += 1;
					x += 1;
					u += 1;
					temp[m] = shuangpai[n];
					number++;
				}
				i = m + 1;
				order2(shuangpai, number);
				flag = false;
				break;
			}

		};
		
		//Ai_Right_Chu(temp, get_handCard_num_());
		//����tempfunction
		K_temp_card_class_ = 1200 + number;
		//����handcard
		for (int k = 0; k < 20; k++)
		{
			if (number - k >= 0)
			{
				for (int i = 0; i < 20; i++)
				{

					if (handcard[i] == temp[number - k])
					{
						handcard[i] = 0; break;
					}


				}
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);
	}
	//����һ��


	else if (sanzhang[0] != 0 && shuangpai[0] != 0 && shuangpai[0] < 14)
	{
		temp_initlize();
		number = 5;
		for (int i = 0; i < 5; i++)
		{
			if (i < 3)
				temp[i] = sanzhang[i];
			else
				temp[i] = shuangpai[i - 3];
		}

		
		//Ai_Right_Chu(temp, get_handCard_num_());
		order2(sanzhang, number - 2);
		order2(shuangpai, number - 3);
		//����tempfunction
		K_temp_card_class_ = 2205;
		//����handcard
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 3)
			{
				break;
			}
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0; b += 1;
			}
		}
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 2)
			{
				break;
			}
			if (handcard[i] == temp[3])
			{
				handcard[i] = 0; b += 1;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);

	}
	//ɨ������һ
	else if (sanzhang[0] != 0 && temphandcard[0] != 0 && temphandcard[0] < 14)
	{
		temp_initlize();
		number = 4;
		for (int i = 0; i < 4; i++)
		{
			if (i < 3)
				temp[i] = sanzhang[i];
			else
				temp[i] = temphandcard[i - 3];
		}
		
		//Ai_Right_Chu(temp, get_handCard_num_());
		order2(sanzhang, number - 1);
		order2(temphandcard, number - 3);
		//
		K_temp_card_class_ = 2104;
		//����handcard
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 3)
			{
				break;
			}
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0; b += 1;
			}
		}
		for (int i = 0; i < 20; i++)
		{

			if (handcard[i] == temp[3])
			{
				handcard[i] = 0; b += 1;
				break;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;

		chu_card(draw);
	}
	//����ʲôҲ����
	else if (sanzhang[0] != 0)
	{
		number = 3;
		temp_initlize();
		for (int i = 0; i < 3; i++)
		{
			temp[i] = shuangpai[i];
		}

		//Ai_Right_Chu(temp, get_handCard_num_());
		

		order2(sanzhang, number);

		K_temp_card_class_ = 1303;
		//����handcard
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 3)
			{
				break;
			}
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0; b += 1;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);
	}

	//�ҵ���
	else if (temphandcard[0] != 0)
	{
		number = 1;
		temp_initlize();
		temp[0] = temphandcard[0];
		
		//Ai_Right_Chu(temp, get_handCard_num_());
		order2(temphandcard, number);
		K_temp_card_class_ = 101;
		//
		for (int i = 0; i < 20; i++)
		{
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0;
				break;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);
	}
	//��˫��
	else if (shuangpai[0] != 0)
	{
		number = 2;
		temp_initlize();
		for (int i = 0; i < 2; i++)
		{
			temp[i] = shuangpai[i];
		}

		//Ai_Right_Chu(temp, get_handCard_num_());
		

		K_temp_card_class_ = 202;
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 2)
			{
				break;
			}
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0; b += 1;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		order2(shuangpai, number); number = 0;
		chu_card(draw);
	}
	//��ը��
	else if (zhadan[0] != 0)
	{
		number = 4;
		temp_initlize();
		for (int i = 0; i < 4; i++)
		{
			temp[i] = zhadan[i];
		}
		
		double_happy_numbers();
		//Ai_Right_Chu(temp, get_handCard_num_());
		order2(zhadan, number);
		K_temp_card_class_ = 1;
		//
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 4)
			{
				break;
			}
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0; b += 1;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);
	}
	//�һ��
	else if (huojian[0] != 0 && huojian[1] != 0)
	{
		number = 2;
		temp_initlize();
		for (int i = 0; i < 2; i++)
		{
			temp[i] = huojian[i];
		}
		double_happy_numbers();
		double_happy_numbers();
		
		//Ai_Right_Chu(temp, get_handCard_num_());
		order2(huojian, 2);
		K_temp_card_class_ = 1;
		for (int i = 0; i < 20; i++)
		{
			if (handcard[i] == 16 || handcard[i] == 17)
			{
				handcard[i] = 0;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);
	}
	chai_pai();
}
//
void AiYY::follow_chu(Draw draw)
{

	for (int j = 0; j < 20; j++) {
		temp[j] = 0;
	}

	int card_no_matrix_index = 0;
	for (int i = 0; i < 15; i++) {
		if (K_temp_card[i] != 0) {
			int temp_num = K_temp_card[i];
			for (int j = 0; j < temp_num; j++) {
				temp[card_no_matrix_index + j] = i + 3;
			}
			card_no_matrix_index += temp_num;
		}
	}

//
//
//
//
//
	int Flag = 0;

	//����
	if (K_temp_card_class_ == 101)
	{
		//flagΪ�жϲ����Ƿ��д�ù�����
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temphandcard[i] > temp[0])
			{

				//����tenpfunction��ֵ
				K_temp_card_class_ = 101;
				//����temp�����ֵ
				temp[0] = temphandcard[i];
				//��������Ϊ0
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[i])
					{
						handcard[k] = 0;
						break;
					}
				}
				sort(handcard, handcard + 20);
				//����Ϊ0
				temphandcard[i] = 0;
				//��������
				sort(temphandcard, temphandcard + 20);
				order3(temphandcard);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 19 && flag3 == 0)
			{
				Flag = 1;
			}

		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}

		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}

		//else if (flag == 1)
		//	Ai_Right_Buchu(draw);


	}

	//����
	else if (K_temp_card_class_ == 202)
	{
		  int flag3 = 0; int flag = 0;
		for (int i = 0; i < 20; i++)
		{

			if (shuangpai[i] > temp[0])
			{

				//cout << "���㣬�ҳ�һ��  " << shuangpai[i] << shuangpai[i + 1] << endl;
				//����tempfunction
				K_temp_card_class_ = 202;
				//����temp�����ֵ
				temp[0] = shuangpai[i];
				temp[1] = shuangpai[i];
				 
				//��������
				for (int k = 0; k < 20; k++)
				{

					if (handcard[k] == shuangpai[i])
					{
						flag += 1;
						if (flag > 2)
						{
							break;
						}
						handcard[k] = 0;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				shuangpai[i] = 0;
				shuangpai[i + 1] = 0;

				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				//Ai_Right_Chu(temp, get_handCard_num_());
				chu_card(draw);
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 18 && flag3 == 0)
			{
				Flag = 1;
			}


		}
	/*	if (zhadan[0] != 0 && flag == 1)
		{
			BoomCard(draw);
		}

		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			RocketCard(draw);
		}
		else if (flag == 1)

			Ai_Right_Buchu(draw);*/
	}
	else if (K_temp_card_class_ == 1303)
	{
		int value = 0;
		//�ж����ĸ���������
		for (int i = 0; i < 3; i++)
		{
			if (temp[i] == temp[i + 2])
			{
				value = temp[i];
			}
		}
		int flag3 = 0; int flag = 0;
		for (int i = 0; i < 20; i++)
		{

			if (sanzhang[i] > value)
			{

				/*cout << "��Ҳ������" << endl;
				cout << sanzhang[i] << sanzhang[i + 1] << sanzhang[i + 2] << endl;*/

				//����tempfunction
				K_temp_card_class_ = 1303;
				//���ò�����
				temp[0] = sanzhang[i];
				temp[1] = sanzhang[i + 1];
				temp[2] = sanzhang[i + 2];


				 
				//��������
				for (int k = 0; k < 20; k++)
				{

					if (handcard[k] == sanzhang[i])
					{
						flag += 1;
						if (flag > 3)
						{
							break;
						}
						handcard[k] = 0;
					}

				}
				//���������ڵ�ֵ
				sanzhang[i] = 0;
				sanzhang[i + 1] = 0;
				sanzhang[i + 2] = 0;

				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 17 && flag3 == 0)
			{
				Flag = 1;

			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
	}
	//ը��
	else if (K_temp_card_class_ == 1)
	{
		  int flag3 = 0; int flag = 0;
		for (int i = 0; i < 20; i++)
		{

			if (zhadan[i] > temp[0])
			{

				/*cout << "������ը���ǰɣ���Ҳ��ը��������" << endl;
				cout << zhadan[i] << zhadan[i + 1] << zhadan[i + 2] << zhadan[i + 3] << endl;*/
				//����tempfunction
				K_temp_card_class_ = 1;

				temp[0] = zhadan[i];
				temp[1] = zhadan[i];
				temp[2] = zhadan[i];
				temp[3] = zhadan[i];
				 
				//��������
				for (int k = 0; k < 20; k++)
				{

					if (handcard[k] == zhadan[i])
					{
						flag += 1;
						if (flag > 4)
						{
							break;
						}
						handcard[k] = 0;
					}
				}
				sort(handcard, handcard + 20);
				//����ը���ڵ�ֵ
				zhadan[i] = 0;
				zhadan[i + 1] = 0;
				zhadan[i + 2] = 0;
				zhadan[i + 3] = 0;
				//��������
				sort(zhadan, zhadan + 20);
				order3(zhadan);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 16 && flag3 == 0)
			{
				Flag = 1;
			}


		}

		if (huojian[0] != 0 && huojian[1] != 0 && Flag == 1)
		{
			RocketCard(draw);
		}
		else if (Flag == 1)

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu(draw);
	}
	//����һ
	else if (K_temp_card_class_ == 2104)
	{
		int value = 0;
		//�ж����ĸ���������
		for (int i = 0; i < 4; i++)
		{
			if (temp[i] == temp[i + 2])
			{
				value = temp[i];
			}
		}
		  int flag3 = 0; int flag = 0;
		for (int i = 0; i < 20; i++)
		{

			if (sanzhang[i] > value && temphandcard[0] != 0 && temphandcard[0] < 14)
			{

				/*cout << "�벻���ɣ���Ҳ������һ���ٺ�" << endl;
				cout << sanzhang[i] << sanzhang[i + 1] << sanzhang[i + 2] << temphandcard[0] << endl;*/

				//����tempfunction
				K_temp_card_class_ = 2104;
				//���ò�����
				temp[0] = sanzhang[i];
				temp[1] = sanzhang[i + 1];
				temp[2] = sanzhang[i + 2];
				temp[3] = temphandcard[0];
				sort(temp, temp + 20);
				order3(temp);
				  int flag1 = 0;
				//��������
				for (int k = 0; k < 20; k++)
				{

					if (handcard[k] == temphandcard[0] && flag1 < 1)
					{

						handcard[k] = 0;
						flag1 += 1;
					}
					if (handcard[k] == sanzhang[i])
					{
						flag += 1;
						if (flag > 3)
						{
							break;
						}
						handcard[k] = 0;
					}

				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				sanzhang[i] = 0;
				sanzhang[i + 1] = 0;
				sanzhang[i + 2] = 0;
				order2(temphandcard, 1);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 17 && flag3 == 0)
			{
				Flag = 1;
			}


		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)

		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
	}
	//������
	else if (K_temp_card_class_ == 2205)
	{
		int value = 0;
		//�ж����ĸ���������
		for (int i = 0; i < 4; i++)
		{
			if (temp[i] == temp[i + 2])
			{
				value = temp[i];
			}
		}
		  int flag3 = 0; int flag = 0;
		for (int i = 0; i < 20; i++)
		{

			if (sanzhang[i] > value && shuangpai[0] != 0 && shuangpai[0] < 14)
			{

				//cout << "�벻���ɣ���������Ҳ�У��ٺ�" << endl;
				//cout << sanzhang[i] << sanzhang[i + 1] << sanzhang[i + 2] << shuangpai[0] << shuangpai[1] << endl;

				//����tempfunction
				K_temp_card_class_ = 2205;
				//���ò�����
				temp[0] = sanzhang[i];
				temp[1] = sanzhang[i + 1];
				temp[2] = sanzhang[i + 2];
				temp[3] = shuangpai[0];
				temp[4] = shuangpai[1];
				sort(temp, temp + 20);
				order3(temp);
				  int flag1 = 0;
				//��������
				for (int k = 0; k < 20; k++)
				{

					if (handcard[k] == shuangpai[0] && flag1 < 2)
					{

						handcard[k] = 0;
						flag1 += 1;
					}
					if (handcard[k] == sanzhang[i])
					{
						flag += 1;
						if (flag > 3)
						{
							break;
						}
						handcard[k] = 0;
					}

				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				sanzhang[i] = 0;
				sanzhang[i + 1] = 0;
				sanzhang[i + 2] = 0;
				shuangpai[0] = 0;
				shuangpai[1] = 0;
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 17 && flag3 == 0)
			{
				Flag = 1;

			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)

		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
	}

	//5���Ƶĵ�˳��
	else if (K_temp_card_class_ == 1105)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 4] > 0)
			{
				///*cout << "���㣬��Ҳ��˳�ӣ���" << endl;
				//cout << danshun[i] << danshun[i */+ 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << endl;
				//����tempfunction
				K_temp_card_class_ = 1105;
				//��˳��ֵ����temp
				reset_array(temp, danshun, i, 5);

				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}


				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);

				reset_danshun(i, 5);

				flag3 = 1;
				//Ai_Right_Chu(temp, get_handCard_num_());

				chu_card(draw);
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 17 && flag3 == 0)
			{
				Flag = 1;

			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//{

		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
		//}
	}
	//6��˳��
	else if (K_temp_card_class_ == 1106)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 5] > 0)
			{
				//cout << "���㣬��Ҳ��˳�ӣ���" << endl;
				//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << endl;
				//����tempfunction
				K_temp_card_class_ = 1106;
				//����temp
				reset_array(temp, danshun, i, 6);
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				reset_danshun(i, 6);
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//	Ai_Right_Buchu(draw);
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 16 && flag3 == 0)
			{
				Flag = 1;

			}
		}
	/*	if (zhadan[0] != 0 && flag == 1)
		{
			BoomCard(draw);
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			RocketCard(draw);
		}
		else if (flag == 1)
		{

			Ai_Right_Buchu(draw);
		}*/
	}
	//7��˳��
	else if (K_temp_card_class_ == 1107)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 6] > 0)
			{
				//cout << "���㣬��Ҳ��˳�ӣ���" << endl;
			//	cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << endl;
				//����tempfunction
				K_temp_card_class_ = 1107;
				//����temp
				reset_array(temp, danshun, i, 7);
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 6])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				reset_danshun(i, 7);

				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				Flag = 1;

			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//{

		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
		//}
	}
	//8��˳��
	else if (K_temp_card_class_ == 1108)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 7] > 0)
			{
				//	cout << "���㣬��Ҳ��˳�ӣ���" << endl;
					//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << endl;
					//����tempfunction
				K_temp_card_class_ = 1108;
				//����temp
				reset_array(temp, danshun, i, 8);
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 6])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 7])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				reset_danshun(i, 8);
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 14 && flag3 == 0)
			{
				Flag = 1;

			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//{

		//	//	Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
		//}
	}
	//9��˳��
	else if (K_temp_card_class_ == 1109)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 8] > 0)
			{

				//����tempfunction
				K_temp_card_class_ = 1109;
				//����temp
				reset_array(temp, danshun, i, 9);
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 6])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 7])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 8])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);

				//���õ�˳�ڵ�ֵ
				reset_danshun(i, 9);
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 13 && flag3 == 0)
			{
				Flag = 1;

			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//{

		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
		//}
	}
	//10��˳��
	else if (K_temp_card_class_ == 1110)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 9] > 0)
			{
				//cout << "���㣬��Ҳ��˳�ӣ���" << endl;
				///cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << danshun[i + 8] << danshun[i + 9] << endl;
				//����tempfunction
				K_temp_card_class_ = 110;
				//����temp
				reset_array(temp, danshun, i, 10);
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 6])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 7])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 8])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 9])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				reset_danshun(i, 10);
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//	Ai_Right_Buchu(draw);
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 12 && flag3 == 0)
			{
				Flag = 1;

			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//{
		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
		//}
	}


//	//11��˳��
//	else if (K_temp_card_class_ == 1111)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (danshun[i] > temp[0] && danshun[i + 10] > 0)
//		//	{
//		//		//	cout << "���㣬��Ҳ��˳�ӣ���" << endl;
//		//			//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << danshun[i + 8] << danshun[i + 9] << danshun[i + 10] << endl;
//		//			//����tempfunction
//		//		K_temp_card_class_ = 1111;
//		//		//����temp
//		//		reset_array(temp, danshun, i, 11);
//		//		//��������
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (handcard[j] == danshun[i])
//		//			{
//		//				handcard[j] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 1])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 2])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 3])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 4])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 5])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 6])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 7])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 8])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 9])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 10])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//���õ�˳�ڵ�ֵ
//		//		reset_danshun(i, 11);
//		//		//��������
//		//		sort(danshun, danshun + 20);
//		//		order3(danshun);
//		//		//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
//		//		//ifshunzi(danshun, temphandcard, shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//		break;
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 11 && flag3 == 0)
//		//	{
//		//		flag = 1;
//
//		//	}
//		//}
//int flag = 1;
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//12��˳��
//	else if (K_temp_card_class_ == 1112)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (danshun[i] > temp[0] && danshun[i + 11] > 0)
//		//	{
//		//		//cout << "���㣬��Ҳ��˳�ӣ���" << endl;
//		//		//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << danshun[i + 8] << danshun[i + 9] << danshun[i + 10] << danshun[i + 11] << endl;
//		//		//����tempfunction
//		//		K_temp_card_class_ = 1112;
//		//		//����temp
//		//		reset_array(temp, danshun, i, 12);
//		//		//��������
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (handcard[j] == danshun[i])
//		//			{
//		//				handcard[j] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 1])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 2])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 3])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 4])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 5])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 6])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 7])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 8])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 9])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 10])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == danshun[i + 11])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//���õ�˳�ڵ�ֵ
//		//		reset_danshun(i, 12);
//		//		//��������
//		//		sort(danshun, danshun + 20);
//		//		order3(danshun);
//		//		//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
//		//		//ifshunzi(danshun, temphandcard, shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//		break;
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 11 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//
//		//	}
//		//}
//int flag = 1;
//
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//
//			//	Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}

	//6���Ƶ�����
	else if (K_temp_card_class_ == 1206)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
        {
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4])
			{

				//����tempfunction��ֵ
				K_temp_card_class_ = 1206;
				//����temp�����ֵ
				for (int j = 0; j < 6; j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p)
					{
						shuangpai[j] = 0;
					}
				}
				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				chu_card(draw);
				// 
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				Flag = 1;
				break;
			}
		}
	/*	
		if (zhadan[0] != 0 && flag == 1)
		{
			BoomCard(draw);
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			RocketCard(draw);
		}
		else if (flag == 1)
		{		
		     Ai_Right_Buchu(draw);
		}*/
		
	}
	//8���Ƶ�����
	else if (K_temp_card_class_ == 1208)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6])
			{
				/*cout << "��������!!" << endl;
				for (int k = i; k < 8 + i; k++)
				{
					cout << shuangpai[k];
				}
				cout << endl;*/
				//����tempfunction��ֵ
				K_temp_card_class_ = 1208;
				//����temp�����ֵ
				for (int j = 0; j < 8; j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q)
					{
						shuangpai[j] = 0;
					}
				}
				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				Flag = 1;
				break;
			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//{

		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
		//}
	}



//
//	//10���Ƶ�����
//	else if (K_temp_card_class_ == 1210)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8])
//		//	{
//
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 1210;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 10; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 2])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 4])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 8])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//����˫���ڵ�ֵ
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//��������
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//		int flag = 1;
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//12���Ƶ�����
//	else if (K_temp_card_class_ == 1212)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10])
//		//	{
//		//		/*cout << "��������!!" << endl;
//		//		for (int k = i; k < 12 + i; k++)
//		//		{
//		//			cout << shuangpai[k];
//		//		}
//		//		cout << endl;*/
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 1212;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 12; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 2])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 4])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 8])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 10])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//����˫���ڵ�ֵ
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//��������
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//
//int flag = 1;
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//14���Ƶ�����
//	else if (K_temp_card_class_ == 1242)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12])
//		//	{
//
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 1242;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 14; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 2])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 4])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 8])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 10])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 12])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//����˫���ڵ�ֵ
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//��������
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//		chu_card(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//       int flag = 1;
//
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//16���Ƶ�����
//	else if (K_temp_card_class_ == 1262)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12] && shuangpai[i] + 7 == shuangpai[i + 14])
//		//	{
//
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 1262;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 16; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 2])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 4])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 8])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 10])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 12])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 14])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//����˫���ڵ�ֵ
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12];; int u = shuangpai[i + 14];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t || shuangpai[j] == u)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//��������
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//        int flag = 1;
//
//
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//18���Ƶ�����
//	else if (K_temp_card_class_ == 1218)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12] && shuangpai[i] + 7 == shuangpai[i + 14] && shuangpai[i] + 8 == shuangpai[i + 16])
//		//	{
//
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 1218;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 18; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 2])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 4])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 8])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 10])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 12])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 14])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 16])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//����˫���ڵ�ֵ
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12]; int u = shuangpai[i + 14]; int v = shuangpai[i + 16];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t || shuangpai[j] == u || shuangpai[j] == v)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//��������
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//			//ѭ������Ȼû���ҵ�
//		/*	if (i == 15 && flag3 == 0)
//			{
//				flag = 1;
//				break;
//			}
//		}*/
//
//int flag = 1;
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//20���Ƶ�����
//	else if (K_temp_card_class_ == 1220)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12] && shuangpai[i] + 7 == shuangpai[i + 14] && shuangpai[i] + 8 == shuangpai[i + 16] && shuangpai[i] + 9 == shuangpai[i + 18])
//		//	{
//
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 1220;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 2])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 4])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 8])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 10])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 12])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 14])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 16])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[i + 18])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//����˫���ڵ�ֵ
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12]; int u = shuangpai[i + 14]; int v = shuangpai[i + 16]; int w = shuangpai[i + 18];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t || shuangpai[j] == u || shuangpai[j] == v || shuangpai[j] == w)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//��������
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//int flag = 1;
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}





	//�������ŵķɻ�
	else if (K_temp_card_class_ == 1306)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3])
			{

				//����tempfunction��ֵ
				K_temp_card_class_ = 1306;
				//����temp�����ֵ
				for (int j = 0; j < 6; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n && sanzhang[j] != 0)
					{
						sanzhang[j] = 0;
					}
				}
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				Flag = 1;
				break;
			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//{
		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);

		//}
	}
	//�������ŵķɻ�
	else if (K_temp_card_class_ == 1309)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6])
			{

				//����tempfunction��ֵ
				K_temp_card_class_ = 1309;
				//����temp�����ֵ
				for (int j = 0; j < 9; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p)
					{
						sanzhang[j] = 0;
					}
				}
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//	Ai_Right_Buchu(draw);
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				Flag = 1;
				break;
			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//{
		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
		//}
	}



//	//�ĸ����ŵķɻ�
//	else if (K_temp_card_class_ == 1312)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9])
//		//	{
//		//		/*cout << "���ҵķɻ�û���!!" << endl;
//		//		for (int k = i; k < 12 + i; k++)
//		//		{
//		//			cout << sanzhang[k];
//		//		}
//		//		cout << endl;*/
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 1312;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 12; j++)
//		//		{
//		//			temp[j] = sanzhang[i + j];
//		//		}
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 3])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 9])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//���������ڵ�ֵ
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//��������
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//
//		int flag = 1;
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//������ŵķɻ�
//	else if (K_temp_card_class_ == 1315)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && sanzhang[i] + 4 == sanzhang[i + 12])
//		//	{
//		//		/*	cout << "���ҵķɻ�û���!!" << endl;
//		//			for (int k = i; k < 15 + i; k++)
//		//			{
//		//				cout << sanzhang[k];
//		//			}
//		//			cout << endl;*/
//		//			//����tempfunction��ֵ
//		//		K_temp_card_class_ = 1315;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 15; j++)
//		//		{
//		//			temp[j] = sanzhang[i + j];
//		//		}
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 3])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 9])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 12])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//���������ڵ�ֵ
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9]; int r = sanzhang[i + 12];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q || sanzhang[j] == r)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//��������
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//
//int flag = 1;
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//�������ŵķɻ�
//	else if (K_temp_card_class_ == 1318)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && sanzhang[i] + 4 == sanzhang[i + 12] && sanzhang[i] + 5 == sanzhang[i + 14])
//		//	{
//		//		/*	cout << "���ҵķɻ�û���!!" << endl;
//		//			for (int k = i; k < 18 + i; k++)
//		//			{
//		//				cout << sanzhang[k];
//		//			}
//		//			cout << endl;*/
//		//			//����tempfunction��ֵ
//		//		K_temp_card_class_ = 1318;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 18; j++)
//		//		{
//		//			temp[j] = sanzhang[i + j];
//		//		}
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 3])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 9])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 12])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 15])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//���������ڵ�ֵ
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9]; int r = sanzhang[i + 12]; int x = sanzhang[i + 12];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q || sanzhang[j] == r || sanzhang[j] == x)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//��������
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//int flag = 1;
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}


	//�ɻ������ŵ���
	else if (K_temp_card_class_ == 2108)
	{
		int value = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
			{
				value = temp[i + 2];
				break;
			}

		}
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && temphandcard[0] != 0 && temphandcard[1] != 0)
			{
				/*	cout << "���ҵķɻ��������" << endl;
					for (int k = i; k < 6 + i; k++)
					{
						cout << sanzhang[k];
					}
					cout << temphandcard[0] << temphandcard[1] << endl;*/
					//����tempfunction��ֵ
				K_temp_card_class_ = 2108;
				//����temp�����ֵ
				for (int j = 0; j < 6; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				temp[6] = temphandcard[0];
				temp[7] = temphandcard[1];
				//��������
				sort(temp, temp + 20);
				order3(temp);
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[0])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[1])
					{
						handcard[k] = 0;
						break;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n && sanzhang[j] != 0)
					{
						sanzhang[j] = 0;
					}
				}
				//����temphandcard
				order2(temphandcard, 2);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				Flag = 1;
				break;
			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//{

		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
		//}
	}
	//�ɻ�������˫��
	else if (K_temp_card_class_ == 2210)
	{
		int value = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
			{
				value = temp[i + 2];
			}
		}
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && shuangpai[0] != 0 && shuangpai[2] != 0)
			{
				/*cout << "���ҵķɻ���������" << endl;
				for (int k = i; k < 6 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << shuangpai[0] << shuangpai[1] << shuangpai[2] << shuangpai[3] << endl;*/
				//����tempfunction��ֵ
				K_temp_card_class_ = 2210;
				//����temp�����ֵ
				for (int j = 0; j < 6; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				for (int k = 0, l = 6; k < 4; k++, l++)
				{
					temp[l] = shuangpai[k];
				}

				//��������
				sort(temp, temp + 20);
				order3(temp);
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[0])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n)
					{
						sanzhang[j] = 0;
					}
				}
				//����shuangpai
				order2(shuangpai, 4);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				chu_card(draw);
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				Flag = 1;
				break;
			}
		}
		//if (zhadan[0] != 0 && flag == 1)
		//{
		//	BoomCard(draw);
		//}
		//else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		//{
		//	RocketCard(draw);
		//}
		//else if (flag == 1)
		//{
		//	//Ai_Right_Chu(temp, get_handCard_num_());
		//	Ai_Right_Buchu(draw);
		//}
	}



//	//�ɻ������ŵ���
//	else if (K_temp_card_class_ == 2112)
//	{
//		//int value = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
//		//	{
//		//		value = temp[i + 2];
//		//	}
//		//}
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && temphandcard[0] != 0 && temphandcard[1] != 0 && temphandcard[2] != 0 && temphandcard[0] < 15)
//		//	{
//		//		/*cout << "���ҵ�C919��ɻ�����" << endl;
//		//		for (int k = i; k < 9 + i; k++)
//		//		{
//		//			cout << sanzhang[k];
//		//		}
//		//		cout << temphandcard[0] << temphandcard[1] << temphandcard[2] << endl;*/
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 2112;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 9; j++)
//		//		{
//		//			temp[j] = sanzhang[i + j];
//		//		}
//		//		for (int k = 0, l = 9; k < 3; k++, l++)
//		//		{
//		//			temp[l] = temphandcard[k];
//		//		}
//		//		sort(temp, temp + 20);
//		//		order3(temp);
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 3])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == temphandcard[0])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == temphandcard[1])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == temphandcard[2])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//���������ڵ�ֵ
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//����temphandcard
//		//		order2(temphandcard, 3);
//		//		//��������
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//
//int flag = 1;
//
//
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//
//			//	Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//�ɻ�������˫��
//	else if (K_temp_card_class_ == 2215)
//	{
//		//int value = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
//		//	{
//		//		value = temp[i + 2];
//		//	}
//		//}
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && shuangpai[0] != 0 && shuangpai[2] != 0 && shuangpai[4] != 0)
//		//	{
//		//		/*cout << "���ҵķɻ���������" << endl;
//		//		for (int k = i; k < 9 + i; k++)
//		//		{
//		//			cout << sanzhang[k];
//		//		}
//		//		cout << shuangpai[0] << shuangpai[1] << shuangpai[2] << shuangpai[3] << shuangpai[4] << shuangpai[5] << endl;*/
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 2215;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 9; j++)
//		//		{
//		//			temp[j] = sanzhang[i + j];
//		//		}
//		//		for (int k = 0, l = 9; k < 6; k++, l++)
//		//		{
//		//			temp[l] = shuangpai[k];
//		//		}
//		//		sort(temp, temp + 20);
//		//		order3(temp);
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 3])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[0])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[2])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[4])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//���������ڵ�ֵ
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//����shuangpai
//		//		order2(shuangpai, 6);
//		//		//��������
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//int flag = 1;
//
//
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//�ɻ������ŵ���
//	else if (K_temp_card_class_ == 2116)
//	{
//	//	int value = 0;
//	//	for (int i = 0; i < 20; i++)
//	//	{
//	//		if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
//	//		{
//	//			value = temp[i + 2];
//	//		}
//	//	}
//	//	  int flag3 = 0;
//	//	for (int i = 0; i < 20; i++)
//	//	{
//	//		if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && temphandcard[0] != 0 && temphandcard[1] != 0 && temphandcard[2] != 0 && temphandcard[3] != 0 && temphandcard[0] < 15)
//	//		{
//	//			/*cout << "���ҵ�C919��ɻ�����" << endl;
//	//			for (int k = i; k < 12 + i; k++)
//	//			{
//	//				cout << sanzhang[k];
//	//			}
//	//			cout << temphandcard[0] << temphandcard[1] << temphandcard[2] << endl;*/
//	//			//����tempfunction��ֵ
//	//			K_temp_card_class_ = 2116;
//	//			//����temp�����ֵ
//	//			for (int j = 0; j < 12; j++)
//	//			{
//	//				temp[j] = sanzhang[i + j];
//	//			}
//	//			for (int k = 0, l = 12; k < 4; k++, l++)
//	//			{
//	//				temp[l] = temphandcard[k];
//	//			}
//	//			sort(temp, temp + 20);
//	//			order3(temp);
//	//			//����handcard
//	//			for (int k = 0, b = 0; k < 20; k++)
//	//			{
//	//				if (b >= 3)
//	//				{
//	//					break;
//	//				}
//	//				if (handcard[k] == sanzhang[i])
//	//				{
//	//					handcard[k] = 0; b += 1;
//	//				}
//	//			}
//	//			for (int k = 0, b = 0; k < 20; k++)
//	//			{
//	//				if (b >= 3)
//	//				{
//	//					break;
//	//				}
//	//				if (handcard[k] == sanzhang[i + 3])
//	//				{
//	//					handcard[k] = 0; b += 1;
//	//				}
//	//			}
//	//			for (int k = 0, b = 0; k < 20; k++)
//	//			{
//	//				if (b >= 3)
//	//				{
//	//					break;
//	//				}
//	//				if (handcard[k] == sanzhang[i + 6])
//	//				{
//	//					handcard[k] = 0; b += 1;
//	//				}
//	//			}
//	//			for (int k = 0, b = 0; k < 20; k++)
//	//			{
//	//				if (b >= 3)
//	//				{
//	//					break;
//	//				}
//	//				if (handcard[k] == sanzhang[i + 9])
//	//				{
//	//					handcard[k] = 0; b += 1;
//	//				}
//	//			}
//	//			for (int k = 0; k < 20; k++)
//	//			{
//	//				if (handcard[k] == temphandcard[0])
//	//				{
//	//					handcard[k] = 0;
//	//					break;
//	//				}
//	//			}
//	//			for (int k = 0; k < 20; k++)
//	//			{
//	//				if (handcard[k] == temphandcard[1])
//	//				{
//	//					handcard[k] = 0;
//	//					break;
//	//				}
//	//			}
//	//			for (int k = 0; k < 20; k++)
//	//			{
//	//				if (handcard[k] == temphandcard[2])
//	//				{
//	//					handcard[k] = 0;
//	//					break;
//	//				}
//	//			}
//	//			for (int k = 0; k < 20; k++)
//	//			{
//	//				if (handcard[k] == temphandcard[3])
//	//				{
//	//					handcard[k] = 0;
//	//					break;
//	//				}
//	//			}
//	//			sort(handcard, handcard + 20);
//	//			//���������ڵ�ֵ
//	//			int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9];
//	//			for (int j = 0; j < 20; j++)
//	//			{
//	//				if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q)
//	//				{
//	//					sanzhang[j] = 0;
//	//				}
//	//			}
//	//			//����temphandcard
//	//			order2(temphandcard, 4);
//	//			//��������
//	//			sort(sanzhang, sanzhang + 20);
//	//			order3(sanzhang);
//	//			flag3 = 1;
//	//			chu_card(draw);
//	//			//Ai_Right_Chu(temp, get_handCard_num_());
//	//			//Ai_Right_Buchu(draw);
//	//		}
//	//		//ѭ������Ȼû���ҵ�
//	//		if (i == 15 && flag3 == 0)
//	//		{
//	//			flag = 1;
//	//			break;
//	//		}
//	//	}
//         int flag = 1;
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//�ɻ������ŵ���
//	else if (K_temp_card_class_ == 2120)
//	{
//		//int value = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
//		//	{
//		//		value = temp[i + 2];
//		//	}
//		//}
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && sanzhang[i] + 4 == sanzhang[i + 12] && temphandcard[0] != 0 && temphandcard[1] != 0 && temphandcard[2] != 0 && temphandcard[3] != 0 && temphandcard[4] != 0 && temphandcard[0] < 15)
//		//	{
//		//		/*cout << "���ҵ�C919��ɻ�����" << endl;
//		//		for (int k = i; k < 15 + i; k++)
//		//		{
//		//			cout << sanzhang[k];
//		//		}
//		//		cout << temphandcard[0] << temphandcard[1] << temphandcard[2] << endl;*/
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 2120;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 15; j++)
//		//		{
//		//			temp[j] = sanzhang[i + j];
//		//		}
//		//		for (int k = 0, l = 15; k < 5; k++, l++)
//		//		{
//		//			temp[l] = temphandcard[k];
//		//		}
//		//		sort(temp, temp + 20);
//		//		order3(temp);
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 3])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 9])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 12])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == temphandcard[0])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == temphandcard[1])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == temphandcard[2])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == temphandcard[3])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		for (int k = 0; k < 20; k++)
//		//		{
//		//			if (handcard[k] == temphandcard[4])
//		//			{
//		//				handcard[k] = 0;
//		//				break;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//���������ڵ�ֵ
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9]; int r = sanzhang[i + 12];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q || sanzhang[j] == r)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//����temphandcard
//		//		order2(temphandcard, 5);
//		//		//��������
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//        int flag = 1;
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}
//	//�ɻ�������˫��
//	else if (K_temp_card_class_ == 2220)
//	{
//		//int value = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
//		//	{
//		//		value = temp[i + 2];
//		//	}
//		//}
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && shuangpai[0] != 0 && shuangpai[2] != 0 && shuangpai[4] != 0 && shuangpai[6] != 0)
//		//	{
//		//		/*cout << "���ҵķɻ����Ĵ���" << endl;
//		//		for (int k = i; k < 12 + i; k++)
//		//		{
//		//			cout << sanzhang[k];
//		//		}
//		//		cout << shuangpai[0] << shuangpai[1] << shuangpai[2] << shuangpai[3] << shuangpai[4] << shuangpai[5] << shuangpai[6] << shuangpai[7] << endl;*/
//		//		//����tempfunction��ֵ
//		//		K_temp_card_class_ = 2220;
//		//		//����temp�����ֵ
//		//		for (int j = 0; j < 12; j++)
//		//		{
//		//			temp[j] = sanzhang[i + j];
//		//		}
//		//		for (int k = 0, l = 12; k < 8; k++, l++)
//		//		{
//		//			temp[l] = temphandcard[k];
//		//		}
//		//		sort(temp, temp + 20);
//		//		order3(temp);
//		//		//����handcard
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 3])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 3)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == sanzhang[i + 9])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[0])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[2])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[4])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		for (int k = 0, b = 0; k < 20; k++)
//		//		{
//		//			if (b >= 2)
//		//			{
//		//				break;
//		//			}
//		//			if (handcard[k] == shuangpai[6])
//		//			{
//		//				handcard[k] = 0; b += 1;
//		//			}
//		//		}
//		//		sort(handcard, handcard + 20);
//		//		//���������ڵ�ֵ
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];; int q = sanzhang[i + 9];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//����shuangpai
//		//		order2(shuangpai, 8);
//		//		//��������
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//ѭ������Ȼû���ҵ�
//		//	if (i == 15 && flag3 == 0)
//		//	{
//		//		flag = 1;
//		//		break;
//		//	}
//		//}
//         int flag = 1;
//
//		if (zhadan[0] != 0 && flag == 1)
//		{
//			BoomCard(draw);
//		}
//		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
//		{
//			RocketCard(draw);
//		}
//		else if (flag == 1)
//		{
//
//			//Ai_Right_Chu(temp, get_handCard_num_());
//			Ai_Right_Buchu(draw);
//		}
//	}

	else {
		int Flag = 1;

	
	}


     if (zhadan[0] != 0 && Flag == 1&&K_temp_card_class_!=1)
     {
	    BoomCard(draw);
     }

     else if (huojian[0] != 0 && huojian[1] != 0 && Flag == 1&&K_temp_card_class_ != 1)
     {
		RocketCard(draw);
     }

	else if (Flag == 1&&K_temp_card_class_ != 1) {
		Ai_Right_Buchu(draw);
	}




	chai_pai();
}
//
//





void AiYY::matrix_to_no_matrix()
{

	for (int i = 0; i < 20; i++) {
		handcard[i] = 0;
		temp[i] = 0;
	}
	//int card_no_matrix[20] = { 0 };
	int card_no_matrix_index = 0;

	for (int i = 0; i < 15; i++) {

		if (handcards_[i] != 0) {
			int temp_num = handcards_[i];
			for (int j = 0; j < temp_num; j++) {
				handcard[card_no_matrix_index + j] = i + 3;
			}
			card_no_matrix_index += temp_num;
		}
	}



	int card_no_matrix_index_1 = 0;
	for (int i = 0; i < 15; i++) {
		if (temp_cards_[i] != 0) {
			int temp_num = temp_cards_[i];
			for (int j = 0; j < temp_num; j++) {
				temp[card_no_matrix_index_1 + j] = i + 3;
			}
			card_no_matrix_index_1 += temp_num;
		}
	}
}

void AiYY::no_matrix_to_matrix()
{
	for (int i = 0; i < 15; i++) {
		handcards_[i] = 0;
	}
	for (int i = 0; i < 15; i++) {
		
		temp_cards_[i]=0;
		
	}






	for (int i = 0; i < 20; i++) {
		if (handcard[i] != 0) {
			handcards_[handcard[i] - 3]++;
		}
	}

	for (int i = 0; i < 20; i++) {
		if (temp[i] != 0) {
			temp_cards_[temp[i] - 3]++;
		}
	}
}

//�����Ƶĺ��������ǿ�ʵ��
void AiYY::Ai_Right_Buchu(Draw draw) {
	K_order++;

	if (left_or_right == 1) {
		gotoxy(27, 10);
		cout << "<----��߳���";

		gotoxy(27, draw.MapHeight / 2);
		cout << "    ";
		gotoxy(27, draw.MapHeight / 2);
		cout << "����";
	}
	else {
		gotoxy(27, 10);
		cout << "              ";
		gotoxy(draw.MapLength - 40, 10);
		cout << "��߳���---->";

		gotoxy(draw.MapLength - 32, draw.MapHeight / 2);
		cout << "    ";
		gotoxy(draw.MapLength - 32, draw.MapHeight / 2);
		cout << "����";
	}
	//print buchu
};






//����������������Ƶģ�����Ĳ�������һ���˴�����ƣ����ǿ�ʵ��
void AiYY::chu_card(Draw draw )
{
	//int chu_or_buchu = 0;

	// �ô˺����ж��Ƿ��ܳ�  follow_chu_judge_matrix()



	no_matrix_to_matrix();

		//���ƾ��м��ӡ���������
		for (int i = 0; i < 15; i++) {
			K_temp_card[i] = temp_cards_[i];
		}
	
		//����
		for (int i = 0; i < 15; i++) {
			temp_cards_[i] = 0;
		}



		draw.basic_print_handcard(draw.MapHeight / 2, card_num(K_temp_card), K_temp_card);


		K_order = 0;

		if (left_or_right == 1) {
			draw.print_ai_card_left(card_num(handcards_));
		}
		else {
			draw.print_ai_card_right(card_num(handcards_));

		}
	


		if (left_or_right == 1) {
			gotoxy(27, 10);
			cout << "<----��߳���";

			gotoxy(27, draw.MapHeight / 2);
			cout << "    ";
		
		}
		else {
			gotoxy(27, 10);
			cout << "              ";
			gotoxy(draw.MapLength - 40, 10);
			cout << "��߳���---->";

			gotoxy(draw.MapLength - 32,draw.MapHeight / 2);
			cout << "    ";
		
		}
	
}





void AiYY::set_left_or_right(int a)
{
	left_or_right = a;
}
