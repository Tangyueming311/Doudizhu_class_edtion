
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






//判断要打出的牌是否可以打出
// 属于初次出牌
//形参a为数组类型，为要打出的牌
//return值为1或0，可以打出为1，不可以为0
int Player::first_chu_judge(int* a) {
	int num = 0;
	int i = 0;


	//num为要打出的牌数量
	while (a[i] != 0)
	{
		num++;
		i++;

	}

	if (num == 1) {
		temp_card_class_ = 101;           //暂存值的牌的类型为单牌	
		//	cout << "你打出了单牌\n";
		return 1;
	}

	else if (num == 2) {
		if (a[0] == a[1]) {
			temp_card_class_ = 202;      //暂存值的牌的类型为对牌	
			//		cout << "你打出了对牌\n";
			return 1;
		}
		else if(a[0]==16&&a[1]==17) {
			//		cout << "出牌不符合规范" << endl;
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
			temp_card_class_ = 1303;         //暂存值的牌的类型为三牌	
			//		cout << "你打出了三张一样的牌\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 4) {
		if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
			temp_card_class_ = 1;         //暂存值的牌的类型为炸弹	
			double_happy_numbers();
			//		cout << "你直接打出了炸弹！!!!\n";
			return 1;
		}
		else if ((a[0] == a[1] && a[1] == a[2] && a[2] != a[3]) || (a[0] != a[1] && a[1] == a[2] && a[2] == a[3])) {
			temp_card_class_ = 2104;          //暂存值的牌的类型为三带一
			//		cout << "你打出了三带一\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 5) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1105;         //暂存值的牌的类型为顺子-5	
			//		cout << "你打出了5张顺子\n";
			return 1;
		}
		if (first_chu_judge_plane2(a)) {
			temp_card_class_ = 2205;        //暂存值的牌的类型为 三带二
			//		cout << "你打出了三带一对\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 6) {


		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1106;         //暂存值的牌的类型为顺子-6
			//		cout << "你打出了6张顺子\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1206;         //暂存值的牌的类型为双顺子-6
			//		cout << "你打出了6张的双顺子\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi3(a)) {
			temp_card_class_ = 1306;         //暂存值的牌的类型为三顺子-6
			//		cout << "你打出了6张的三顺子\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 7) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1107;         //暂存值的牌的类型为顺子-7
			//		cout << "你打出了7张顺子\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 8) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1108;         //暂存值的牌的类型为顺子-8
			//		cout << "你打出了8张顺子\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1208;         //暂存值的牌的类型为双顺子-8
			//		cout << "你打出了8张的双顺子\n";
			return 1;
		}
		else if (first_chu_judge_plane1(a)) {
			temp_card_class_ = 2108;         //暂存值的牌的类型为飞机带单-8
			//		cout << "你打出了8张的飞机带单\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}

	}

	else if (num == 9) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1109;         //暂存值的牌的类型为顺子-9
			//		cout << "你打出了9张顺子\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi3(a)) {
			temp_card_class_ = 1309;         //暂存值的牌的类型为三顺子-9
			//		cout << "你打出了9张的三顺子\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 10) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1110;         //暂存值的牌的类型为顺子-10
			//		cout << "你打出了10张顺子\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1210;         //暂存值的牌的类型为双顺子-10
			//		cout << "你打出了10张的双顺子\n";
			return 1;
		}
		else if (first_chu_judge_plane2(a)) {
			temp_card_class_ = 2210;         //暂存值的牌的类型为飞机带双-10
			//		cout << "你打出了10张的飞机带双\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 11) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1111;         //暂存值的牌的类型为顺子-11
			//		cout << "你打出了11张顺子\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 12) {
		if (first_chu_judge_Shunzi1(a)) {
			temp_card_class_ = 1112;         //暂存值的牌的类型为顺子-12
			//		cout << "你打出了12张顺子\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1212;         //暂存值的牌的类型为双顺子-12
			//		cout << "你打出了12张的双顺子\n";
			return 1;
		}
		else if (first_chu_judge_plane1(a)) {
			temp_card_class_ = 2112;         //暂存值的牌的类型为飞机带单-12
			//		cout << "你打出了12张的飞机带单\n";
			return 1;
		}
		else if (first_chu_judge_Shunzi3(a)) {
			temp_card_class_ = 1312;         //暂存值的牌的类型为三顺子-12
			//		cout << "你打出了12张的三顺子\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 13) {
		//	cout << "出牌不符合规范" << endl;
		return 0;
	}

	else if (num == 14) {
		if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1214;         //暂存值的牌的类型为双顺子-14
			//		cout << "你打出了14张的双顺子\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 15) {
		if (first_chu_judge_Shunzi3(a)) {
			temp_card_class_ = 1315;          // 暂存值的牌的类型为三顺子 - 15
			//		cout << "你打出了15张的三顺子\n";
			return 1;
		}

		else if (first_chu_judge_plane2(a)) {
			temp_card_class_ = 2215;         //暂存值的牌的类型为飞机带双-15
			//		cout << "你打出了15张的飞机带双\n";
			return 1;
		}

		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 16) {
		if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1216;          // 暂存值的牌的类型为双顺子 - 16
			//		cout << "你打出了16张的双顺子牌\n";
			return 1;
		}

		else if (first_chu_judge_plane1(a)) {
			temp_card_class_ = 2116;         //暂存值的牌的类型为飞机带单-16
			//		cout << "你打出了16张的飞机带单\n";
			return 1;
		}

		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}
	else if (num == 17) {
		//	cout << "出牌不符合规范" << endl;
		return 0;
	}

	else if (num == 18) {
		if (first_chu_judge_Shunzi3(a)) {
			temp_card_class_ = 1318;          // 暂存值的牌的类型为三顺子 - 18
			//		cout << "你打出了18张的三顺子\n";
			return 1;
		}

		if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1218;          // 暂存值的牌的类型为双顺子 - 18
			//		cout << "你打出了18张的双顺子\n";
			return 1;
		}
		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else if (num == 19) {
		//	cout << "出牌不符合规范" << endl;
		return 0;
	}

	else if (num == 20) {
		if (first_chu_judge_Shunzi2(a)) {
			temp_card_class_ = 1220;          // 暂存值的牌的类型为双顺子 - 20
			//		cout << "你打出了20张的双顺子\n";
			return 1;
		}

		else if (first_chu_judge_plane1(a)) {
			temp_card_class_ = 2120;         //暂存值的牌的类型为飞机带单-20
			//		cout << "你打出了20张的飞机带单\n";
			return 1;
		}
		else if (first_chu_judge_plane2(a)) {
			temp_card_class_ = 2220;         //暂存值的牌的类型为飞机带双-20
			//		cout << "你打出了20张的飞机带双\n";
			return 1;
		}

		else {
			//		cout << "出牌不符合规范" << endl;
			return 0;
		}
	}

	else {
		//	cout << "出牌不符合规范" << endl;
		return 0;
	}




}

//单顺子判断（包括多个数量）
//形参a为数组类型，为要打出的牌
//return值为0或1，1代表是顺子，0代表不是
int Player::first_chu_judge_Shunzi1(int* b) {
	//该变量用来判断顺子里是否带2，有为1，没有为；一旦带2则函数返回0，函数不成立
	//牌组里2 的储存值为15
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

		//在函数内临时建立一个数组，将形参复制过来
		int a[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			a[i] = b[i];
		}

		int temp = a[0];
		//这一段是让打出牌数组逐个减去a[0]加i，如果最后全都为0，则代表都是依次加1的顺子
		int i = 0;
		while (a[i] != 0) {
			a[i] = a[i] - temp - i;
			i++;
		}

		//如果a[]数组所有项都为0，则确实是顺子，返回1，相反则返回0
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

//双顺子判断（包括多个数量）
//形参a为数组类型，为要打出的牌
//return值为0或1，1代表是顺子，0代表不是
int Player::first_chu_judge_Shunzi2(int* b) {
	//在函数内临时建立一个数组，将形参复制过来
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}



	int temp = a[0];
	//这一段，首先让对子的其中一个减去前面的一个数，让双顺子变成单顺子
	//然后i以2累加，进行单顺子的相减，得到最后全为0
	int i = 0;
	do {

		a[i + 1] = a[i + 1] - a[i];
		a[i] = a[i] - temp - i / 2;

		i = i + 2;
		//限定i的范围担心溢出
	} while (a[i] != 0 && i < 19);

	//如果a[]数组所有项都为0，则确实是顺子，返回1，相反则返回0
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


//三顺子判断（包括多个数量）
//形参a为数组类型，为要打出的牌
//return值为0或1，1代表是顺子，0代表不是
int Player::first_chu_judge_Shunzi3(int* b) {
	//在函数内临时建立一个数组，将形参复制过来
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}
	int temp = a[0];
	//这一段，首先让对子的其中二个减去最前面的一个数，让三顺子变成间隔2个0的单顺子
	//然后i以3累加，进行单顺子的相减，得到最后全为0
	int i = 0;
	//限定i的范围担心溢出
	while (a[i] != 0 && i < 18) {
		a[i + 2] = a[i + 2] - a[i];
		a[i + 1] = a[i + 1] - a[i];
		a[i] = a[i] - temp - i / 3;

		i = i + 3;
	}

	//如果a[]数组所有项都为0，则确实是顺子，返回1，相反则返回0
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

//飞机-带单判断
//飞机规则为：n个三张相同，加上n个单牌或者n个对牌
//形参a为数组类型，为要打出的牌
//return值为0或1，1代表是飞机，0代表不是
int Player::first_chu_judge_plane1(int* b) {
	//在函数内临时建立一个数组，将形参复制过来
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}
	//遍历数组，将三个相同的牌都赋值为1（不赋值为0是因为空缺位为0，对计数有影响），赋值一次temp+1;
	//for只到18是因为担心有溢出
	//数组point是为了储存出现的三张相同的牌的牌面，因为飞机需要连续
	int point[5] = { 0 };
	int temp = 0;
	for (int i = 0; i < 18; i++) {
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i] != 0 && a[i] != 1) {
			point[temp] = a[i];
			a[i] = 1, a[i + 1] = 1, a[i + 2] = 1;

			temp++;
		}
	}

	//比较point数组里储存的数字，
	//这一段是让point数组逐个减去point[0]加i，如果最后全都为0，则代表都是依次加1
	int i = 0;
	int Temp = point[0];
	while (point[i] != 0) {
		point[i] = point[i] - Temp - i;
		i++;
	}

	//如果point[]数组所有项都为0，则确实是飞机，返回1，相反则返回0
	int temp1 = 1;
	for (int i = 0; i < 5; i++) {
		if (point[i] != 0) {
			temp1 = 0;
		}
	}

	//再次遍历数组，将所有不为0，不为1的数的数量数出来，与temp比较，相同的话即为真
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

//飞机-带双判断
//飞机规则为：n个三张相同，加上n个单牌或者n个对牌
//形参a为数组类型，为要打出的牌
//return值为0或1，1代表是飞机，0代表不是
int Player::first_chu_judge_plane2(int* b) {
	//在函数内临时建立一个数组，将形参复制过来
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}

	//遍历数组，将三个相同的牌都赋值为1（不赋值为0是因为空缺位为0，对计数有影响），赋值一次temp+1;
	//for只到18是因为担心有溢出
	int point[5] = { 0 };
	int temp = 0;
	for (int i = 0; i < 18; i++) {
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i] != 0 && a[i] != 1) {
			a[i] = 1, a[i + 1] = 1, a[i + 2] = 1;
			point[temp] = a[i];
			temp++;
		}
	}

	//再次遍历数组，将所有不为0，不为1的数的数量数出来，赋值进新的数组b
	int c[20] = { 0 };
	int j = 0;

	for (int i = 0; i < 20; i++) {
		if ((a[i] != 1) && (a[i] != 0)) {
			c[j] = a[i];
			j++;
		}
	}
	//比较point数组里储存的数字，
	//这一段是让point数组逐个减去point[0]加i，如果最后全都为0，则代表都是依次加1
	int i = 0;
	int Temp = point[0];
	while (point[i] != 0) {
		point[i] = point[i] - Temp - i;
		i++;
	}

	//如果point[]数组所有项都为0，则确实是飞机，返回1，相反则返回0
	int temp1 = 1;
	for (int i = 0; i < 5; i++) {
		if (point[i] != 0) {
			temp1 = 0;
		}
	}

	//此时遍历数组b，把对子全部进行判断
	//遍历数组b，下标每次+2，b[i]应等于b[i+1],遍历完毕则flag=1，中间出现不等于则flag=0
	//循环一次temp2加一，用来记录对子数量，如果对子数量与三张牌数量一样且flag=1，则确实是飞机捏，返回1
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



//判断要打出的牌是否可以打出
// 属于跟随出牌
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌；形参c为int类型，为牌的类型
//return值为1或0，可以打出为1，不可以为0
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

	//如果要打出牌的数量与暂存牌数量不同，明显不能打
	if (num != num2 && num != 4 && num != 2) {
		//		cout << "数量不对" << endl;
		//		cout << "暂存牌数：" << num2 << " " << "打出牌数" << num << endl;
		return 0;
	}



	//分别判断各种情况


	else if (num != num2 && num == 4) {
		if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && b[0] != 16 && b[1] != 17) {

			//			cout << "炸弹压死！！！！" << endl;
			double_happy_numbers();
			return 1;
		}
		else {
			//			cout << "数量不对" << endl;
			//			cout << "暂存牌数：" << num2 << " " << "打出牌数" << num << endl;
			return 0;
		}
	}
	else if (num != num2 && num == 2) {
		if (a[0] == 16 && a[1] == 17) {

			//			cout << "王炸绝杀！！！！！"<<endl;
			double_happy_numbers();
			double_happy_numbers();
			return 1;
		}
		else {
			//			cout << "数量不对" << endl;
			//			cout << "暂存牌数：" << num2 << " " << "打出牌数" << num << endl;
			return 0;
		}
	}


	else if (num == num2) {

		if (num == 1) {
			if (follow_chu_judge_singleCard(a, b) == 1)
			{
				//				cout << "单牌" << endl;

				return 1;
			}
			else {

				//				cout << "小了" << endl;
				return 0;
			}
		}

		else if (num == 2) {
			if (a[0] == 16 && a[1] == 17) {
				//				cout << "王炸绝杀！！！！！" << endl;
				return 1;
			}
			else {
				if (follow_chu_judge_doubleCard(a, b) == 1)
				{
					//				cout << "对牌" << endl;

					return 1;
				}
				else if (follow_chu_judge_doubleCard(a, b) == 0) {

					//				cout << "小了" << endl;
					return 0;
				}
				else if (follow_chu_judge_doubleCard(a, b) == 2) {
					//					cout << "不符合规范" << endl;
					return 0;
				}
			}

		}

		else if (num == 3) {
			if (follow_chu_judge_threeCard(a, b) == 1)
			{
				//				cout << "三牌" << endl;

				return 1;
			}
			else if (follow_chu_judge_threeCard(a, b) == 0) {

				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_threeCard(a, b) == 2) {
				//				cout << "不符合规范" << endl;
				return 0;
			}
		}

		else if (num == 4) {
			if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && b[0] == b[1] && b[1] == b[2] && b[2] == b[3]) {
				if (follow_chu_judge_BoomCard(a, b) == 0) {
					//					cout << "小了" << endl;
					return 0;
				}
				else if (follow_chu_judge_BoomCard(a, b) == 1) {
					//				cout << "又是炸弹！！！" << endl;

					return 1;
				}
				else if (follow_chu_judge_BoomCard(a, b) == 2) {
					//					cout << "不符合规范" << endl;
					return 0;
				}
			}
			else {
				if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {

					//					cout << "炸弹压死！！！！" << endl;
					return 1;
				}

				else if (follow_chu_judge_plane1(a, b) == 0) {
					//					cout << "小了" << endl;
					return 0;
				}
				else if (follow_chu_judge_plane1(a, b) == 1) {
					//					cout << "三带一" << endl;
					return 1;
				}
				else if (follow_chu_judge_plane1(a, b) == 2) {
					//					cout << "不符合规范" << endl;
					return 0;
				}
			}
		}

		else if (num == 5) {
			if (follow_chu_judge_plane1(a, b) == 0) {
				//				cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//				cout << "三带一" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//				cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//				cout << "顺子" << endl;
				return 1;
			}

			else {
				//				cout << "不符合规范" << endl;
				return 0;
			}
		}

		else if (num == 6) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "顺子" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "连对" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 0) {
				//				cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 1) {
				//			cout << "飞机没翅膀" << endl;
				return 1;
			}
			else {
				//			cout << "不符合规范" << endl;
				return 0;
			}

		}

		else if (num == 7) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "顺子" << endl;
				return 1;
			}
			else {
				//			cout << "不符合规范" << endl;
				return 0;
			}

		}
		else if (num == 8) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "顺子" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "连对" << endl;
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//			cout << "飞机" << endl;
				return 1;
			}
			else {
				//			cout << "不符合规范" << endl;
				return 0;
			}

		}

		else if (num == 9) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "顺子" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 1) {
				//			cout << "飞机没翅膀" << endl;
				return 1;
			}
			else {
				//			cout << "不符合规范" << endl;
				return 0;
			}
		}
		else if (num == 10) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "顺子" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "连对" << endl;
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//			cout << "飞机" << endl;
				return 1;
			}
			else {
				//				cout << "不符合规范" << endl;
				return 0;
			}
		}
		else if (num == 11) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//				cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//				cout << "顺子" << endl;
				return 1;
			}
			else {
				//				cout << "不符合规范" << endl;
				return 0;
			}

		}
		else if (num == 12) {
			if (follow_chu_judge_Shunzi1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi1(a, b) == 1) {
				//			cout << "顺子" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "连对" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 1) {
				//			cout << "飞机没翅膀" << endl;
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//			cout << "三带一" << endl;
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
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 1) {
				//			cout << "飞机没翅膀" << endl;
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//			cout << "飞机" << endl;
				return 1;
			}
			else {
				//			cout << "不符合规范" << endl;
				return 0;
			}
		}
		else if (num == 16) {

			if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "连对" << endl;
				return 1;
			}
			else if (follow_chu_judge_plane1(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_plane1(a, b) == 1) {
				//			cout << "三带一" << endl;
				return 1;
			}
			else {
				//			cout << "不符合规范" << endl;
				return 0;
			}

		}
		else if (num == 18) {

			if (follow_chu_judge_Shunzi2(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi2(a, b) == 1) {
				//			cout << "连对" << endl;
				return 1;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 0) {
				//			cout << "小了" << endl;
				return 0;
			}
			else if (follow_chu_judge_Shunzi3(a, b) == 1) {
				//			cout << "飞机没翅膀" << endl;
				return 1;
			}
			else {
				//			cout << "不符合规范" << endl;
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


//三顺子判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1,2;1和0指符合规范后是否能打出，2指不符合规范
int Player::follow_chu_judge_Shunzi3(int* a, int* b) {
	if (first_chu_judge_Shunzi3(a) == 1) {
		//在函数内临时建立两个数组，将形参复制过来
		//temp1数组对应a，为要打出的牌；tenp2数组对应b，为暂存的牌
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
		return 2;        //不符合规范的出牌返回2值
	}
}
//双顺子判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1,2;1和0指符合规范后是否能打出，2指不符合规范
int Player::follow_chu_judge_Shunzi2(int* a, int* b) {
	if (first_chu_judge_Shunzi2(a) == 1) {
		//在函数内临时建立两个数组，将形参复制过来
		//temp1数组对应a，为要打出的牌；tenp2数组对应b，为暂存的牌
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
		return 2;        //不符合规范的出牌返回2值
	}
}







//单顺子判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1,2;1和0指符合规范后是否能打出，2指不符合规范
int Player::follow_chu_judge_Shunzi1(int* a, int* b) {
	if (first_chu_judge_Shunzi1(a) == 1) {
		//在函数内临时建立两个数组，将形参复制过来
		//temp1数组对应a，为要打出的牌；tenp2数组对应b，为暂存的牌
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
		return 2;        //不符合规范的出牌返回2值
	}
}



//飞机带双判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1,2;1和0指符合规范后是否能打出，2指不符合规范
int Player::follow_chu_judge_plane2(int* a, int* b) {
	if (first_chu_judge_plane2(a) == 1) {
		//在函数内临时建立两个数组，将形参复制过来
		//temp1数组对应a，为要打出的牌；tenp2数组对应b，为暂存的牌
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}
		//遍历数组，将三个相同的牌都赋值为1（不赋值为0是因为空缺位为0，对计数有影响），赋值一次temp+1;
		//for只到18是因为担心有溢出
		//数组point是为了储存出现的三张相同的牌的牌面，因为飞机需要连续
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
		return 2;        //不符合规范的出牌返回2值
	}
}




//飞机带单判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1,2;1和0指符合规范后是否能打出，2指不符合规范
int Player::follow_chu_judge_plane1(int* a, int* b) {
	if (first_chu_judge_plane1(a) == 1) {
		//在函数内临时建立两个数组，将形参复制过来
		//temp1数组对应a，为要打出的牌；tenp2数组对应b，为暂存的牌
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}

		//遍历数组，将三个相同的牌都赋值为1（不赋值为0是因为空缺位为0，对计数有影响），赋值一次temp+1;
		//for只到18是因为担心有溢出
		//数组point是为了储存出现的三张相同的牌的牌面，因为飞机需要连续
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
		return 2;        //不符合规范的出牌返回2值
	}
}


//炸弹判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1,2;1和0指符合规范后是否能打出，2指不符合规范
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
		return 2;        //不符合规范的出牌返回2值
	}
}

//单牌判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1,2;1和0指符合规范后是否能打出，2指不符合规范
int Player::follow_chu_judge_singleCard(int* a, int* b) {
	if (a[0] > b[0]) {
		return 1;

	}
	else {

		return 0;

	}
}

//双牌判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1,2;1和0指符合规范后是否能打出，2指不符合规范
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
		return 2;        //不符合规范的出牌返回2值
	}
}

//三牌判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1,2;1和0指符合规范后是否能打出，2指不符合规范
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
		return 2;        //不符合规范的出牌返回2值
	}
}



bool Player::first_chu_judge_matrix(int* chucards)
{

	//牌转换成no matrix
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


	//牌转换成no matrix
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




	//牌转换成no matrix
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
	cout << "【当前倍数】：" << happy_numbers;

	gotoxy(MapLength / 2 + 15, MapHeight+2);
	cout << "【欢乐豆余额】：" << happy_beans;


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
	cout << change_happy_beans << "  " << "欢乐豆余额" << happy_beans;
	return happy_beans;

}


