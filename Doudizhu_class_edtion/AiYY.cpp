#include "AiYY.h"
#include <iostream>
#include <algorithm>
using namespace std;

//这个函数用来对前面打出了几张牌，就去除几张牌，同时在后面补零，num是去掉的牌数
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

//小到大排序，同时把零放后面
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

//对temp数组进行全部清零的函数
void AiYY::temp_initlize()
{
	for (int i = 0; i < 20; i++)
	{
		temp[i] = 0;
	}
}

//拆牌函数前对所有卡组初始化的函数
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
//拆牌函数
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
	//先找火箭
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
	//找炸弹
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
					//排序
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

	//再找三张
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


	//再找单顺
	int x = 0;
	for (int a = 0; a < 20; a++)
	{

		//先判断是否有五张能组成顺子
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
			//在有五张的情况下，如果发现还能继续组成顺子则继续往顺子的牌上加
			while (one[b + 1] == one[b] + 1)
			{

				b = b + 1;
				danshun[x] = one[b];
				x++;
				counter++;
				//temphandcard[b] = 0;
				//sort(temphandcard, temphandcard + 10);
			}
			//清零
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
		//重置two里面的数组
		for (int j = 0; j < 20; j++)
		{
			if (two[j] == danshun[k] && two[j] != 0)
			{
				//cout << "true" << "此次清的是" << two[j] << endl;

				two[j] = 0;
				sort(two, two + 20);
			}
		}
	}
	sort(temphandcard, temphandcard + 20);

	//再找双牌
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
//打出炸弹的函
void AiYY::BoomCard(Draw draw)
{
	//cout << "炸弹压死" << endl;

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
	//对handcard排序，0还是在前面
	sort(handcard, handcard + 20);
	chu_card(draw);
	double_happy_numbers();
	//Ai_Right_Chu(temp, get_handCard_num_());
}

//chucard函数里面用来判断是否有王炸，有王炸可以不管什么tempfunction都直接出
void AiYY::RocketCard(Draw draw )
{
	K_temp_card_class_ = 1;
	//重置卡牌
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
	//重新排序
	sort(danshun, danshun + 20);
	order3(danshun);

}
//arr[]是传入需要改动的数组，b是传入按照谁来改动的数组，num是重置的数量，start是传入从哪里开始改动
void AiYY::reset_array(int arr[], int b[], int start, int num)
{
	for (int i = 0; i < num; i++)
	{
		arr[i] = b[start];
		start++;
	}
}
//判断前一定要先拆牌,抢的时候返回true
bool AiYY::if_grab_landlord()
{

	int weight = 0;
	//火箭权重5分
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
	//顺子权重
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
	//三带一对权重
	number = 0;
	for (int i = 0; i < 20; i++)
	{
		if (sanzhang[i] != 0)
		{
			number++;
		}
	}
	//一个三带二
	if (number > 0 && number < 4) {
		weight += 2;
		if (shuangpai[0] != 0 || temphandcard[0] != 0)
		{
			weight += 1;
		}

	}
	//两个三带二
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
	//有点对子加分
	if (shuangpai[3] > 0)
	{
		weight += 2;
	}
	//太多扣分
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
	//找双顺子
	for (int i = 0; i < 20; i++)
	{
		if (shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i + 2] + 1 == shuangpai[i + 4])
		{
			flag = true;
			break;
		}
	};
	//先找飞机
	//没时间了，第一次出牌的人就先不要打飞机了吧

	//先扫描顺子
	if (danshun[0] != 0)
	{
		temp_initlize();
		int x = 0;
		for (int a = 0; a < 20; a++)
		{

			//先判断是否有五张能组成顺子
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
				//在有五张的情况下，如果发现还能继续组成顺子则继续往顺子的牌上加
				while (danshun[b + 1] == danshun[b] + 1)
				{

					b = b + 1;
					temp[x] = danshun[b];
					x++;
					number++;
				}
				//清零
				for (int c = 0; c < number; c++)
				{
					danshun[a + c] = 0;
				}
				order2(danshun, number);


				b = a;
			}

		}

		

		//重置tempfunction
		K_temp_card_class_ = 1100 + number;
		//重置handcard
		//顺子最多12张
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
		//对handcard排序，0还是在前面
		sort(handcard, handcard + 20);
		number = 0;
        chu_card(draw);

	}
	//找双顺子

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
				//如果还发现有，继续往上加
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
		//重置tempfunction
		K_temp_card_class_ = 1200 + number;
		//重置handcard
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
		//对handcard排序，0还是在前面
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);
	}
	//三带一对


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
		//重置tempfunction
		K_temp_card_class_ = 2205;
		//重置handcard
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
		//对handcard排序，0还是在前面
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);

	}
	//扫描三带一
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
		//重置handcard
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
		//对handcard排序，0还是在前面
		sort(handcard, handcard + 20);
		number = 0;

		chu_card(draw);
	}
	//三张什么也不带
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
		//重置handcard
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
		//对handcard排序，0还是在前面
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);
	}

	//找单牌
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
		//对handcard排序，0还是在前面
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);
	}
	//找双牌
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
		//对handcard排序，0还是在前面
		sort(handcard, handcard + 20);
		order2(shuangpai, number); number = 0;
		chu_card(draw);
	}
	//找炸弹
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
		//对handcard排序，0还是在前面
		sort(handcard, handcard + 20);
		number = 0;
		chu_card(draw);
	}
	//找火箭
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
		//对handcard排序，0还是在前面
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

	//单张
	if (K_temp_card_class_ == 101)
	{
		//flag为判断查找是否有打得过的牌
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temphandcard[i] > temp[0])
			{

				//重置tenpfunction的值
				K_temp_card_class_ = 101;
				//重置temp里面的值
				temp[0] = temphandcard[i];
				//手牌重置为0
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[i])
					{
						handcard[k] = 0;
						break;
					}
				}
				sort(handcard, handcard + 20);
				//重置为0
				temphandcard[i] = 0;
				//重新排序
				sort(temphandcard, temphandcard + 20);
				order3(temphandcard);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				break;
			}
			//循环完仍然没有找到
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

	//对子
	else if (K_temp_card_class_ == 202)
	{
		  int flag3 = 0; int flag = 0;
		for (int i = 0; i < 20; i++)
		{

			if (shuangpai[i] > temp[0])
			{

				//cout << "大你，我出一对  " << shuangpai[i] << shuangpai[i + 1] << endl;
				//重置tempfunction
				K_temp_card_class_ = 202;
				//重置temp里面的值
				temp[0] = shuangpai[i];
				temp[1] = shuangpai[i];
				 
				//重置手牌
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
				//重置双牌内的值
				shuangpai[i] = 0;
				shuangpai[i + 1] = 0;

				//重新排序
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				//Ai_Right_Chu(temp, get_handCard_num_());
				chu_card(draw);
				break;
			}
			//循环完仍然没有找到
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
		//判断是哪个牌有三张
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

				/*cout << "我也出三张" << endl;
				cout << sanzhang[i] << sanzhang[i + 1] << sanzhang[i + 2] << endl;*/

				//重置tempfunction
				K_temp_card_class_ = 1303;
				//重置并排序
				temp[0] = sanzhang[i];
				temp[1] = sanzhang[i + 1];
				temp[2] = sanzhang[i + 2];


				 
				//重置手牌
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
				//重置三张内的值
				sanzhang[i] = 0;
				sanzhang[i + 1] = 0;
				sanzhang[i + 2] = 0;

				//重新排序
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				break;
			}
			//循环完仍然没有找到
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
	//炸弹
	else if (K_temp_card_class_ == 1)
	{
		  int flag3 = 0; int flag = 0;
		for (int i = 0; i < 20; i++)
		{

			if (zhadan[i] > temp[0])
			{

				/*cout << "就你有炸弹是吧？我也出炸弹！！！" << endl;
				cout << zhadan[i] << zhadan[i + 1] << zhadan[i + 2] << zhadan[i + 3] << endl;*/
				//重置tempfunction
				K_temp_card_class_ = 1;

				temp[0] = zhadan[i];
				temp[1] = zhadan[i];
				temp[2] = zhadan[i];
				temp[3] = zhadan[i];
				 
				//重置手牌
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
				//重置炸弹内的值
				zhadan[i] = 0;
				zhadan[i + 1] = 0;
				zhadan[i + 2] = 0;
				zhadan[i + 3] = 0;
				//重新排序
				sort(zhadan, zhadan + 20);
				order3(zhadan);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//循环完仍然没有找到
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
	//三带一
	else if (K_temp_card_class_ == 2104)
	{
		int value = 0;
		//判断是哪个牌有三张
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

				/*cout << "想不到吧，我也有三带一，嘿嘿" << endl;
				cout << sanzhang[i] << sanzhang[i + 1] << sanzhang[i + 2] << temphandcard[0] << endl;*/

				//重置tempfunction
				K_temp_card_class_ = 2104;
				//重置并排序
				temp[0] = sanzhang[i];
				temp[1] = sanzhang[i + 1];
				temp[2] = sanzhang[i + 2];
				temp[3] = temphandcard[0];
				sort(temp, temp + 20);
				order3(temp);
				  int flag1 = 0;
				//重置手牌
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
				//重置三张内的值
				sanzhang[i] = 0;
				sanzhang[i + 1] = 0;
				sanzhang[i + 2] = 0;
				order2(temphandcard, 1);
				//重新排序
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//循环完仍然没有找到
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
	//三带二
	else if (K_temp_card_class_ == 2205)
	{
		int value = 0;
		//判断是哪个牌有三张
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

				//cout << "想不到吧，三带二我也有，嘿嘿" << endl;
				//cout << sanzhang[i] << sanzhang[i + 1] << sanzhang[i + 2] << shuangpai[0] << shuangpai[1] << endl;

				//重置tempfunction
				K_temp_card_class_ = 2205;
				//重置并排序
				temp[0] = sanzhang[i];
				temp[1] = sanzhang[i + 1];
				temp[2] = sanzhang[i + 2];
				temp[3] = shuangpai[0];
				temp[4] = shuangpai[1];
				sort(temp, temp + 20);
				order3(temp);
				  int flag1 = 0;
				//重置手牌
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
				//重置三张内的值
				sanzhang[i] = 0;
				sanzhang[i + 1] = 0;
				sanzhang[i + 2] = 0;
				shuangpai[0] = 0;
				shuangpai[1] = 0;
				//重新排序
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
			//循环完仍然没有找到
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

	//5张牌的单顺子
	else if (K_temp_card_class_ == 1105)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 4] > 0)
			{
				///*cout << "大你，我也有顺子！！" << endl;
				//cout << danshun[i] << danshun[i */+ 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << endl;
				//重置tempfunction
				K_temp_card_class_ = 1105;
				//将顺子值赋给temp
				reset_array(temp, danshun, i, 5);

				//重置手牌
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
			//循环完仍然没有找到
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
	//6张顺子
	else if (K_temp_card_class_ == 1106)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 5] > 0)
			{
				//cout << "大你，我也有顺子！！" << endl;
				//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << endl;
				//重置tempfunction
				K_temp_card_class_ = 1106;
				//重置temp
				reset_array(temp, danshun, i, 6);
				//重置手牌
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
				//重置单顺内的值
				reset_danshun(i, 6);
				//重新排序
				sort(danshun, danshun + 20);
				order3(danshun);
				//判断删除后的单顺能否重新组成单顺
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//	Ai_Right_Buchu(draw);
				break;
			}
			//循环完仍然没有找到
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
	//7张顺子
	else if (K_temp_card_class_ == 1107)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 6] > 0)
			{
				//cout << "大你，我也有顺子！！" << endl;
			//	cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << endl;
				//重置tempfunction
				K_temp_card_class_ = 1107;
				//重置temp
				reset_array(temp, danshun, i, 7);
				//重置手牌
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
				//重置单顺内的值
				reset_danshun(i, 7);

				//重新排序
				sort(danshun, danshun + 20);
				order3(danshun);
				//判断删除后的单顺能否重新组成单顺
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//循环完仍然没有找到
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
	//8张顺子
	else if (K_temp_card_class_ == 1108)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 7] > 0)
			{
				//	cout << "大你，我也有顺子！！" << endl;
					//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << endl;
					//重置tempfunction
				K_temp_card_class_ = 1108;
				//重置temp
				reset_array(temp, danshun, i, 8);
				//重置手牌
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
				//重置单顺内的值
				reset_danshun(i, 8);
				//重新排序
				sort(danshun, danshun + 20);
				order3(danshun);
				//判断删除后的单顺能否重新组成单顺
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//循环完仍然没有找到
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
	//9张顺子
	else if (K_temp_card_class_ == 1109)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 8] > 0)
			{

				//重置tempfunction
				K_temp_card_class_ = 1109;
				//重置temp
				reset_array(temp, danshun, i, 9);
				//重置手牌
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

				//重置单顺内的值
				reset_danshun(i, 9);
				//重新排序
				sort(danshun, danshun + 20);
				order3(danshun);
				//判断删除后的单顺能否重新组成单顺
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				break;
			}
			//循环完仍然没有找到
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
	//10张顺子
	else if (K_temp_card_class_ == 1110)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 9] > 0)
			{
				//cout << "大你，我也有顺子！！" << endl;
				///cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << danshun[i + 8] << danshun[i + 9] << endl;
				//重置tempfunction
				K_temp_card_class_ = 110;
				//重置temp
				reset_array(temp, danshun, i, 10);
				//重置手牌
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
				//重置单顺内的值
				reset_danshun(i, 10);
				//重新排序
				sort(danshun, danshun + 20);
				order3(danshun);
				//判断删除后的单顺能否重新组成单顺
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//	Ai_Right_Buchu(draw);
				break;
			}
			//循环完仍然没有找到
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


//	//11张顺子
//	else if (K_temp_card_class_ == 1111)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (danshun[i] > temp[0] && danshun[i + 10] > 0)
//		//	{
//		//		//	cout << "大你，我也有顺子！！" << endl;
//		//			//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << danshun[i + 8] << danshun[i + 9] << danshun[i + 10] << endl;
//		//			//重置tempfunction
//		//		K_temp_card_class_ = 1111;
//		//		//重置temp
//		//		reset_array(temp, danshun, i, 11);
//		//		//重置手牌
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
//		//		//重置单顺内的值
//		//		reset_danshun(i, 11);
//		//		//重新排序
//		//		sort(danshun, danshun + 20);
//		//		order3(danshun);
//		//		//判断删除后的单顺能否重新组成单顺
//		//		//ifshunzi(danshun, temphandcard, shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//		break;
//		//	}
//		//	//循环完仍然没有找到
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
//	//12张顺子
//	else if (K_temp_card_class_ == 1112)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (danshun[i] > temp[0] && danshun[i + 11] > 0)
//		//	{
//		//		//cout << "大你，我也有顺子！！" << endl;
//		//		//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << danshun[i + 8] << danshun[i + 9] << danshun[i + 10] << danshun[i + 11] << endl;
//		//		//重置tempfunction
//		//		K_temp_card_class_ = 1112;
//		//		//重置temp
//		//		reset_array(temp, danshun, i, 12);
//		//		//重置手牌
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
//		//		//重置单顺内的值
//		//		reset_danshun(i, 12);
//		//		//重新排序
//		//		sort(danshun, danshun + 20);
//		//		order3(danshun);
//		//		//判断删除后的单顺能否重新组成单顺
//		//		//ifshunzi(danshun, temphandcard, shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//		break;
//		//	}
//		//	//循环完仍然没有找到
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

	//6张牌的连对
	else if (K_temp_card_class_ == 1206)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
        {
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4])
			{

				//重置tempfunction的值
				K_temp_card_class_ = 1206;
				//重置temp里面的值
				for (int j = 0; j < 6; j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//重置handcard
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
				//重置双牌内的值
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p)
					{
						shuangpai[j] = 0;
					}
				}
				//重新排序
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				chu_card(draw);
				// 
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
			}
			//循环完仍然没有找到
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
	//8张牌的连对
	else if (K_temp_card_class_ == 1208)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6])
			{
				/*cout << "看我连对!!" << endl;
				for (int k = i; k < 8 + i; k++)
				{
					cout << shuangpai[k];
				}
				cout << endl;*/
				//重置tempfunction的值
				K_temp_card_class_ = 1208;
				//重置temp里面的值
				for (int j = 0; j < 8; j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//重置handcard
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
				//重置双牌内的值
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q)
					{
						shuangpai[j] = 0;
					}
				}
				//重新排序
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
			}
			//循环完仍然没有找到
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
//	//10张牌的连对
//	else if (K_temp_card_class_ == 1210)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8])
//		//	{
//
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 1210;
//		//		//重置temp里面的值
//		//		for (int j = 0; j < 10; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//重置handcard
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
//		//		//重置双牌内的值
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//重新排序
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//循环完仍然没有找到
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
//	//12张牌的连对
//	else if (K_temp_card_class_ == 1212)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10])
//		//	{
//		//		/*cout << "看我连对!!" << endl;
//		//		for (int k = i; k < 12 + i; k++)
//		//		{
//		//			cout << shuangpai[k];
//		//		}
//		//		cout << endl;*/
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 1212;
//		//		//重置temp里面的值
//		//		for (int j = 0; j < 12; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//重置handcard
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
//		//		//重置双牌内的值
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//重新排序
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//循环完仍然没有找到
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
//	//14张牌的连对
//	else if (K_temp_card_class_ == 1242)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12])
//		//	{
//
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 1242;
//		//		//重置temp里面的值
//		//		for (int j = 0; j < 14; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//重置handcard
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
//		//		//重置双牌内的值
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//重新排序
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//		chu_card(draw);
//		//	}
//		//	//循环完仍然没有找到
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
//	//16张牌的连对
//	else if (K_temp_card_class_ == 1262)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12] && shuangpai[i] + 7 == shuangpai[i + 14])
//		//	{
//
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 1262;
//		//		//重置temp里面的值
//		//		for (int j = 0; j < 16; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//重置handcard
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
//		//		//重置双牌内的值
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12];; int u = shuangpai[i + 14];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t || shuangpai[j] == u)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//重新排序
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//循环完仍然没有找到
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
//	//18张牌的连对
//	else if (K_temp_card_class_ == 1218)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12] && shuangpai[i] + 7 == shuangpai[i + 14] && shuangpai[i] + 8 == shuangpai[i + 16])
//		//	{
//
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 1218;
//		//		//重置temp里面的值
//		//		for (int j = 0; j < 18; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//重置handcard
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
//		//		//重置双牌内的值
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12]; int u = shuangpai[i + 14]; int v = shuangpai[i + 16];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t || shuangpai[j] == u || shuangpai[j] == v)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//重新排序
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//			//循环完仍然没有找到
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
//	//20张牌的连对
//	else if (K_temp_card_class_ == 1220)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12] && shuangpai[i] + 7 == shuangpai[i + 14] && shuangpai[i] + 8 == shuangpai[i + 16] && shuangpai[i] + 9 == shuangpai[i + 18])
//		//	{
//
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 1220;
//		//		//重置temp里面的值
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			temp[j] = shuangpai[i + j];
//		//		}
//		//		//重置handcard
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
//		//		//重置双牌内的值
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12]; int u = shuangpai[i + 14]; int v = shuangpai[i + 16]; int w = shuangpai[i + 18];
//		//			if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t || shuangpai[j] == u || shuangpai[j] == v || shuangpai[j] == w)
//		//			{
//		//				shuangpai[j] = 0;
//		//			}
//		//		}
//		//		//重新排序
//		//		sort(shuangpai, shuangpai + 20);
//		//		order3(shuangpai);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//循环完仍然没有找到
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





	//两个三张的飞机
	else if (K_temp_card_class_ == 1306)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3])
			{

				//重置tempfunction的值
				K_temp_card_class_ = 1306;
				//重置temp里面的值
				for (int j = 0; j < 6; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				//重置handcard
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
				//重置三张内的值
				int m = sanzhang[i]; int n = sanzhang[i + 3];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n && sanzhang[j] != 0)
					{
						sanzhang[j] = 0;
					}
				}
				//重新排序
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
			}
			//循环完仍然没有找到
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
	//三个三张的飞机
	else if (K_temp_card_class_ == 1309)
	{
		  int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6])
			{

				//重置tempfunction的值
				K_temp_card_class_ = 1309;
				//重置temp里面的值
				for (int j = 0; j < 9; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				//重置handcard
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
				//重置三张内的值
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p)
					{
						sanzhang[j] = 0;
					}
				}
				//重新排序
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//	Ai_Right_Buchu(draw);
			}
			//循环完仍然没有找到
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



//	//四个三张的飞机
//	else if (K_temp_card_class_ == 1312)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9])
//		//	{
//		//		/*cout << "看我的飞机没翅膀!!" << endl;
//		//		for (int k = i; k < 12 + i; k++)
//		//		{
//		//			cout << sanzhang[k];
//		//		}
//		//		cout << endl;*/
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 1312;
//		//		//重置temp里面的值
//		//		for (int j = 0; j < 12; j++)
//		//		{
//		//			temp[j] = sanzhang[i + j];
//		//		}
//		//		//重置handcard
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
//		//		//重置三张内的值
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//重新排序
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//循环完仍然没有找到
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
//	//五个三张的飞机
//	else if (K_temp_card_class_ == 1315)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && sanzhang[i] + 4 == sanzhang[i + 12])
//		//	{
//		//		/*	cout << "看我的飞机没翅膀!!" << endl;
//		//			for (int k = i; k < 15 + i; k++)
//		//			{
//		//				cout << sanzhang[k];
//		//			}
//		//			cout << endl;*/
//		//			//重置tempfunction的值
//		//		K_temp_card_class_ = 1315;
//		//		//重置temp里面的值
//		//		for (int j = 0; j < 15; j++)
//		//		{
//		//			temp[j] = sanzhang[i + j];
//		//		}
//		//		//重置handcard
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
//		//		//重置三张内的值
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9]; int r = sanzhang[i + 12];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q || sanzhang[j] == r)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//重新排序
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//循环完仍然没有找到
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
//	//六个三张的飞机
//	else if (K_temp_card_class_ == 1318)
//	{
//		//  int flag3 = 0;
//		//for (int i = 0; i < 20; i++)
//		//{
//		//	if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && sanzhang[i] + 4 == sanzhang[i + 12] && sanzhang[i] + 5 == sanzhang[i + 14])
//		//	{
//		//		/*	cout << "看我的飞机没翅膀!!" << endl;
//		//			for (int k = i; k < 18 + i; k++)
//		//			{
//		//				cout << sanzhang[k];
//		//			}
//		//			cout << endl;*/
//		//			//重置tempfunction的值
//		//		K_temp_card_class_ = 1318;
//		//		//重置temp里面的值
//		//		for (int j = 0; j < 18; j++)
//		//		{
//		//			temp[j] = sanzhang[i + j];
//		//		}
//		//		//重置handcard
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
//		//		//重置三张内的值
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9]; int r = sanzhang[i + 12]; int x = sanzhang[i + 12];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q || sanzhang[j] == r || sanzhang[j] == x)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//重新排序
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//循环完仍然没有找到
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


	//飞机带两张单牌
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
				/*	cout << "看我的飞机带俩翅膀" << endl;
					for (int k = i; k < 6 + i; k++)
					{
						cout << sanzhang[k];
					}
					cout << temphandcard[0] << temphandcard[1] << endl;*/
					//重置tempfunction的值
				K_temp_card_class_ = 2108;
				//重置temp里面的值
				for (int j = 0; j < 6; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				temp[6] = temphandcard[0];
				temp[7] = temphandcard[1];
				//重新排序
				sort(temp, temp + 20);
				order3(temp);
				//重置handcard
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
				//重置三张内的值
				int m = sanzhang[i]; int n = sanzhang[i + 3];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n && sanzhang[j] != 0)
					{
						sanzhang[j] = 0;
					}
				}
				//重置temphandcard
				order2(temphandcard, 2);
				//重新排序
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				chu_card(draw);
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
			}
			//循环完仍然没有找到
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
	//飞机带两张双牌
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
				/*cout << "看我的飞机带俩大翅膀" << endl;
				for (int k = i; k < 6 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << shuangpai[0] << shuangpai[1] << shuangpai[2] << shuangpai[3] << endl;*/
				//重置tempfunction的值
				K_temp_card_class_ = 2210;
				//重置temp里面的值
				for (int j = 0; j < 6; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				for (int k = 0, l = 6; k < 4; k++, l++)
				{
					temp[l] = shuangpai[k];
				}

				//重新排序
				sort(temp, temp + 20);
				order3(temp);
				//重置handcard
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
				//重置三张内的值
				int m = sanzhang[i]; int n = sanzhang[i + 3];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n)
					{
						sanzhang[j] = 0;
					}
				}
				//重置shuangpai
				order2(shuangpai, 4);
				//重新排序
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				//Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu(draw);
				chu_card(draw);
			}
			//循环完仍然没有找到
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



//	//飞机带三张单牌
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
//		//		/*cout << "看我的C919大飞机！！" << endl;
//		//		for (int k = i; k < 9 + i; k++)
//		//		{
//		//			cout << sanzhang[k];
//		//		}
//		//		cout << temphandcard[0] << temphandcard[1] << temphandcard[2] << endl;*/
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 2112;
//		//		//重置temp里面的值
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
//		//		//重置handcard
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
//		//		//重置三张内的值
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//重置temphandcard
//		//		order2(temphandcard, 3);
//		//		//重新排序
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//循环完仍然没有找到
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
//	//飞机带三张双牌
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
//		//		/*cout << "看我的飞机带三大翅膀" << endl;
//		//		for (int k = i; k < 9 + i; k++)
//		//		{
//		//			cout << sanzhang[k];
//		//		}
//		//		cout << shuangpai[0] << shuangpai[1] << shuangpai[2] << shuangpai[3] << shuangpai[4] << shuangpai[5] << endl;*/
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 2215;
//		//		//重置temp里面的值
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
//		//		//重置handcard
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
//		//		//重置三张内的值
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//重置shuangpai
//		//		order2(shuangpai, 6);
//		//		//重新排序
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//循环完仍然没有找到
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
//	//飞机带四张单牌
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
//	//			/*cout << "看我的C919大飞机！！" << endl;
//	//			for (int k = i; k < 12 + i; k++)
//	//			{
//	//				cout << sanzhang[k];
//	//			}
//	//			cout << temphandcard[0] << temphandcard[1] << temphandcard[2] << endl;*/
//	//			//重置tempfunction的值
//	//			K_temp_card_class_ = 2116;
//	//			//重置temp里面的值
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
//	//			//重置handcard
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
//	//			//重置三张内的值
//	//			int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9];
//	//			for (int j = 0; j < 20; j++)
//	//			{
//	//				if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q)
//	//				{
//	//					sanzhang[j] = 0;
//	//				}
//	//			}
//	//			//重置temphandcard
//	//			order2(temphandcard, 4);
//	//			//重新排序
//	//			sort(sanzhang, sanzhang + 20);
//	//			order3(sanzhang);
//	//			flag3 = 1;
//	//			chu_card(draw);
//	//			//Ai_Right_Chu(temp, get_handCard_num_());
//	//			//Ai_Right_Buchu(draw);
//	//		}
//	//		//循环完仍然没有找到
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
//	//飞机带五张单牌
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
//		//		/*cout << "看我的C919大飞机！！" << endl;
//		//		for (int k = i; k < 15 + i; k++)
//		//		{
//		//			cout << sanzhang[k];
//		//		}
//		//		cout << temphandcard[0] << temphandcard[1] << temphandcard[2] << endl;*/
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 2120;
//		//		//重置temp里面的值
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
//		//		//重置handcard
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
//		//		//重置三张内的值
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9]; int r = sanzhang[i + 12];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q || sanzhang[j] == r)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//重置temphandcard
//		//		order2(temphandcard, 5);
//		//		//重新排序
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//	}
//		//	//循环完仍然没有找到
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
//	//飞机带四张双牌
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
//		//		/*cout << "看我的飞机带四大翅膀" << endl;
//		//		for (int k = i; k < 12 + i; k++)
//		//		{
//		//			cout << sanzhang[k];
//		//		}
//		//		cout << shuangpai[0] << shuangpai[1] << shuangpai[2] << shuangpai[3] << shuangpai[4] << shuangpai[5] << shuangpai[6] << shuangpai[7] << endl;*/
//		//		//重置tempfunction的值
//		//		K_temp_card_class_ = 2220;
//		//		//重置temp里面的值
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
//		//		//重置handcard
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
//		//		//重置三张内的值
//		//		int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];; int q = sanzhang[i + 9];
//		//		for (int j = 0; j < 20; j++)
//		//		{
//		//			if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q)
//		//			{
//		//				sanzhang[j] = 0;
//		//			}
//		//		}
//		//		//重置shuangpai
//		//		order2(shuangpai, 8);
//		//		//重新排序
//		//		sort(sanzhang, sanzhang + 20);
//		//		order3(sanzhang);
//		//		flag3 = 1;
//		//		chu_card(draw);
//		//		//Ai_Right_Chu(temp, get_handCard_num_());
//		//		//Ai_Right_Buchu(draw);
//		//	}
//		//	//循环完仍然没有找到
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

//不出牌的函数，还是空实现
void AiYY::Ai_Right_Buchu(Draw draw) {
	K_order++;

	if (left_or_right == 1) {
		gotoxy(27, 10);
		cout << "<----这边出牌";

		gotoxy(27, draw.MapHeight / 2);
		cout << "    ";
		gotoxy(27, draw.MapHeight / 2);
		cout << "不出";
	}
	else {
		gotoxy(27, 10);
		cout << "              ";
		gotoxy(draw.MapLength - 40, 10);
		cout << "这边出牌---->";

		gotoxy(draw.MapLength - 32, draw.MapHeight / 2);
		cout << "    ";
		gotoxy(draw.MapLength - 32, draw.MapHeight / 2);
		cout << "不出";
	}
	//print buchu
};






//这个函数是用来打牌的，传入的参数是上一个人打出的牌，还是空实现
void AiYY::chu_card(Draw draw )
{
	//int chu_or_buchu = 0;

	// 用此函数判断是否能出  follow_chu_judge_matrix()



	no_matrix_to_matrix();

		//在牌局中间打印出将打的牌
		for (int i = 0; i < 15; i++) {
			K_temp_card[i] = temp_cards_[i];
		}
	
		//清零
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
			cout << "<----这边出牌";

			gotoxy(27, draw.MapHeight / 2);
			cout << "    ";
		
		}
		else {
			gotoxy(27, 10);
			cout << "              ";
			gotoxy(draw.MapLength - 40, 10);
			cout << "这边出牌---->";

			gotoxy(draw.MapLength - 32,draw.MapHeight / 2);
			cout << "    ";
		
		}
	
}





void AiYY::set_left_or_right(int a)
{
	left_or_right = a;
}
