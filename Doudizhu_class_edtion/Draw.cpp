#include "Draw.h"
#include "Player.h"
#include "Card.h"
#include "Ai.h"
using namespace std;
//字体
void SetFont(int size=30) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size;  //设置字体大小
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL; //字体粗细 FW_BOLD
	wcscpy_s(cfi.FaceName, L"黑体");  //设置字体，必须是控制台已有的
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	//获得当前字体
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_FONT_INFO consoleCurrentFont;
	//GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);
}
void setConsoleFontSize(int fontSize) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX fontInfo = { sizeof(fontInfo) };
	GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
	fontInfo.dwFontSize.Y = fontSize;
	SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}

//隐藏光标的函数
void HideCursor() {

	CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
	curInfo.dwSize = 1; //如果没赋值的话，光标隐藏无效
	curInfo.bVisible = FALSE; //将光标设置为不可见
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}

//将光标在控制台里跳到指定坐标
//形参为x坐标和y坐标
void gotoxy(unsigned char x, unsigned char y) {
	//COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标
	COORD cor;

	//句柄 
	HANDLE hout;

	//设定我们要定位到的坐标 
	cor.X = x;
	cor.Y = y;

	//GetStdHandle函数获取一个指向特定标准设备的句柄，包括标准输入，标准输出和标准错误。
	//STD_OUTPUT_HANDLE正是代表标准输出（也就是显示屏）的宏 
	hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//SetConsoleCursorPosition函数用于设置控制台光标的位置
	SetConsoleCursorPosition(hout, cor);
}

void print_key(int x, int y) {
	gotoxy(x, y);
	cout << "《《";

	gotoxy(x + 18, y);
	cout << "》》";

}






//打印指定位置
//形参left_x为最左边的横坐标，high_y为最上面的纵坐标，length为长度，height为高度
void Draw::print(int left_x, int high_y, int length, int height) {
	for (int i = left_x; i < left_x + length; i++) {
		for (int j = high_y; j <= high_y + height; j++) {
			gotoxy(i, j);
			if (map_matrix_[i][j] == '0') {
				putchar(' ');
			}
			else if (map_matrix_[i][j] == '2')
				putchar('~');
			else if (map_matrix_[i][j] == '3')
				putchar('|');
			else if (map_matrix_[i][j] == '4')
				putchar('$');
			else if (map_matrix_[i][j] == 3) putchar('3');
			else if (map_matrix_[i][j] == 4) putchar('4');
			else if (map_matrix_[i][j] == 5) putchar('5');
			else if (map_matrix_[i][j] == 6) putchar('6');
			else if (map_matrix_[i][j] == 7) putchar('7');
			else if (map_matrix_[i][j] == 8) putchar('8');
			else if (map_matrix_[i][j] == 9) putchar('9');
			else if (map_matrix_[i][j] == 10) putchar('T');
			else if (map_matrix_[i][j] == 11)putchar('J');
			else if (map_matrix_[i][j] == 12) putchar('Q');
			else if (map_matrix_[i][j] == 13) putchar('K');
			else if (map_matrix_[i][j] == 14) putchar('A');
			else if (map_matrix_[i][j] == 15) putchar('2');
			else if (map_matrix_[i][j] == 16) putchar('S');
			else if (map_matrix_[i][j] == 17) putchar('B');


		}

	}
}

void Draw::basic_print_handcard(int card_y, int card_num, int* card)
{
	int all_card_long = (card_num - 1) * between_cards_Length + cardLength;

	int clean_all_card_long= (20 - 1) * between_cards_Length + cardLength;

	//先把牌所占空间,以及已经选中的突出的牌的空间清出来，赋0
	for (int i = MapLength/2- clean_all_card_long /2;   i < MapLength / 2 + clean_all_card_long / 2+ cardLength;    i++) {
		for (int j = card_y - 4; j <= card_y + cardHeight; j++) {
			map_matrix_[i][j] = '0';
			gotoxy(i, j);
			putchar(' ');
		}
	}

	//打印到第num张牌
	int num = 1;
	int Temp = MapLength / 2 - all_card_long / 2;

	//递增，0在最后
	int card_no_matrix[20] = { 0 };
	int card_no_matrix_index = 0;
	for (int i = 0; i < 15; i++) {
		if (card[i] != 0) {
			int temp_num = card[i];
			for (int j = 0; j < temp_num; j++) {
				card_no_matrix[card_no_matrix_index+j] = i + 3;
			}
			card_no_matrix_index += temp_num;
		}
	}


	while (num <= card_num) {
		//先把牌所占空间清出来，赋0
		for (int i = Temp; i < Temp + cardLength; i++) {
			for (int j = card_y; j <= card_y + cardHeight; j++) {
				map_matrix_[i][j] = '0';
			}
		}

		//这里是打印牌的上下边界
		for (int i = Temp; i < Temp + cardLength; i++) {
			map_matrix_[i][card_y] = '2';
			map_matrix_[i][card_y + cardHeight] = '2';
		}
		//这里是打印牌的竖线和牌数值

		for (int j = card_y; j <= card_y + cardHeight; j++) {
			map_matrix_[Temp][j] = '3';
			map_matrix_[Temp + cardLength][j] = '3';


			map_matrix_[Temp + 1][card_y + 1] = card_no_matrix[ num - 1];
		}

		num++;
		Temp += 4;
	}

	
	print(MapLength / 2 - all_card_long / 2, card_y - 4, all_card_long+13, cardHeight + 4);
}

int Draw::menu()
{
                                                          system("cls");


	int title_x = MapLength / 2 - 3;
	int title_y = MapHeight / 2 - 6;

	int all_button_x = MapLength / 2 - 3;

	int first_button_y = MapHeight / 2 + 6;
	int second_button_y = MapHeight / 2 + 10;
	int third_button_y = MapHeight / 2 + 14;
	int fourth_button_y = MapHeight / 2 + 18;


	int left_key_x = MapLength / 2 - 8;
	int right_key_x = MapLength / 2 +10;

	int first_key_y = MapHeight / 2 + 6;
	int second_key_y = MapHeight / 2 + 10;
	int third_key_y = MapHeight / 2 + 14;
	int fourth_key_y = MapHeight / 2 + 18;

	int point_key = 1;



	int keyborad_input = 0;
	int temp_char_size = 13;

	gotoxy(title_x, title_y-2);
	cout << "游戏健康忠告";
	gotoxy(title_x-17, title_y+4);
	cout << "抵制不良游戏，拒绝盗版游戏。注意自我防护，谨防受骗上当。";
	gotoxy(title_x - 17, title_y+8);
	cout << "适度游戏益脑，沉迷游戏伤身。合理安排时间，享受健康生活";
	gotoxy(title_x - 4, MapHeight -1);
	cout << "游戏加载中，请稍后。。。。。。。";
	Sleep(2000);




	                                                         system("cls");



	gotoxy(title_x, title_y);
	cout << "斗地主！！！！";

	gotoxy(all_button_x, first_button_y);
	cout << "【登陆账号】";
	gotoxy(all_button_x, second_button_y);
	cout << "【游客登陆】";
	gotoxy(all_button_x, third_button_y);
	cout << "【调整字体】";
	gotoxy(all_button_x, fourth_button_y);
	cout << "【退出游戏】";




	gotoxy(left_key_x, first_key_y);
	cout << "《《";
	gotoxy(right_key_x, first_key_y);
	cout << "》》";
	




	







	while (1) {
		//a,d移动箭头，按回车选中
		keyborad_input = _getch();


		//先把箭头清空
		for (int j = MapLength / 2 - 14; j < MapLength / 2 - 3; j++) {
			for (int i = 10; i < MapHeight ; i++) {
				gotoxy(j, i);
				putchar(' ');
			}
		}
		for (int j = MapLength / 2 + 10; j < MapLength / 2 + 20; j++) {
			for (int i = 10; i < MapHeight ; i++) {
				gotoxy(j, i);
				putchar(' ');
			}
		}



		//向上
		if (keyborad_input == 119) {

			if (point_key == 1) {
				
				print_key(left_key_x, first_key_y);
								
				continue;
			}
			else if (point_key == 2) {
				
				print_key(left_key_x, first_key_y);
				point_key--;
				continue;
			}
			else if (point_key == 3) {
				
				print_key(left_key_x, second_key_y);
				point_key--;
				continue;
			}
			else if (point_key == 4) {
				
				print_key(left_key_x, third_key_y);
				point_key--;
				continue;
			}
		}


		//向下
		else if (keyborad_input == 115) {

			if (point_key == 1) {
				//再打印箭头
				print_key(left_key_x, second_key_y);
				
				point_key++;
				continue;
			}
			else if (point_key == 2) {
				print_key(left_key_x, third_key_y);
				point_key++;
				continue;
			}
			else if (point_key == 3) {
				//再打印箭头
				print_key(left_key_x, fourth_key_y);
				point_key++;
				continue;
			}
			else if (point_key == 4) {
				//再打印箭头
				print_key(left_key_x, fourth_key_y);
				
				continue;
			}
		}


		//向右
		else if (keyborad_input == 100 && point_key == 3) {

			print_key(left_key_x, third_key_y);

			temp_char_size++;
			setConsoleFontSize(temp_char_size);

			continue;
		}
		//向左
		else if (keyborad_input == 97 && point_key == 3) {
			print_key(left_key_x, third_key_y);

			temp_char_size--;
			setConsoleFontSize(temp_char_size);

			continue;

		}

		else if ((keyborad_input == 100 || keyborad_input == 97) && point_key==1 ) {

			print_key(left_key_x, first_key_y);
			continue;
		}
		else if ((keyborad_input == 100 || keyborad_input == 97) && point_key==2) {

			print_key(left_key_x, second_key_y);
			continue;
		}
		else if ((keyborad_input == 100 || keyborad_input == 97) && point_key==4) {

			print_key(left_key_x, fourth_key_y);
			continue;
		}
		


		else if (keyborad_input == 13 && point_key == 2) {
			system("cls");
			return 2;
			
			break;
		}

		else if (keyborad_input == 13 && point_key == 4) {
			                                                           system("cls");
			exit(100);
		}
		else if (keyborad_input == 13 && point_key == 1) {
			                                                          system("cls");
			return 1;
			break;
		}
		else {
			if (point_key == 1) {

				print_key(left_key_x, first_key_y);

				continue;
			}
			else if (point_key == 2) {

				print_key(left_key_x, second_key_y);
				
				continue;
			}
			else if (point_key == 3) {

				print_key(left_key_x, third_key_y);
				
				continue;
			}
			else if (point_key == 4) {

				print_key(left_key_x, fourth_key_y);
				
				continue;
			}
		}

	}
}

void Draw::log_in() {

}

int Draw::basic_choose_button(int orign_arrow,int buttons_number,int buttons_distance , int first_button_x,int first_button_y) {

	int order_arrow = orign_arrow;
	int keyborad_input = 0;
	int arrow_x = first_button_x + (orign_arrow - 1) * buttons_distance;
	int arrow_y = first_button_y;

	for (int j = first_button_x; j <= first_button_x + buttons_distance * (22 - 1); j++) {
		for (int i = first_button_y; i < first_button_y + 3; i++) {
			gotoxy(j, i);
			putchar(' ');
		}
	}
	gotoxy(first_button_x + buttons_distance * (orign_arrow - 1), first_button_y);
	putchar('|');
	gotoxy(first_button_x + buttons_distance * (orign_arrow - 1), first_button_y + 1);
	putchar('|');
	gotoxy(first_button_x + buttons_distance * (orign_arrow - 1), first_button_y + 2);
	putchar('+');
	while (1) {
		//a,d移动箭头，按回车选中
		keyborad_input = _getch();
		

		//先把箭头清空
		for (int j = first_button_x; j <= first_button_x + buttons_distance * (buttons_number - 1); j++) {
			for (int i = first_button_y; i < first_button_y + 3; i++) {
				gotoxy(j, i);
				putchar(' ');
			}
		}




		//向右
		if (keyborad_input == 100) {
			if (order_arrow != buttons_number) {
				order_arrow++;
				arrow_x + buttons_distance;

			}


		}
		//向左
		else if (keyborad_input == 97) {
			if (order_arrow != 1) {
				order_arrow--;
				arrow_x - buttons_distance;

			}

		}

		gotoxy(first_button_x + buttons_distance * (order_arrow - 1), first_button_y);
		putchar('|');
		gotoxy(first_button_x + buttons_distance * (order_arrow - 1), first_button_y + 1);
		putchar('|');
		gotoxy(first_button_x + buttons_distance * (order_arrow - 1), first_button_y + 2);
		putchar('+');


		if (keyborad_input == 13) {
			return order_arrow;
		}



	}


	

}

int Draw::choose_if_landlord(Ai ai_1,Ai ai_2,int choosen_player,int card_y , int card_num, int* card, int orign_arrow, int buttons_number, int buttons_distance, int first_button_x, int first_button_y, int arrow_direction)
{
	                                             system("cls");
    gotoxy(MapLength / 2, 20);
	cout << "洗牌中，请稍后：";
	Sleep(1000);
	                                            system("cls");
	gotoxy(MapLength / 2, 20);
	cout << "你的手牌如下：";
	basic_print_handcard(card_y, card_num, card);
	
	int landlord_player_1 = 0;
	int landlord_player_2 = 0;
	int landlord_player_3 = 0;

	if (choosen_player == 1) {


		gotoxy(first_button_x - 4, first_button_y + 5);
		cout << "【叫地主】";
		gotoxy(first_button_x + 16, first_button_y + 5);
		cout << "【不叫】";

		if (basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1) {
			gotoxy(MapLength/2, MapHeight / 2 + 18);
			cout << "叫地主！";
			landlord_player_1 = 1;
		}
		else {
			gotoxy(MapLength/2, MapHeight / 2 + 18);
			cout << "不叫！  ";
			landlord_player_1 = 0;
		}

		Sleep(2000);
		if (ai_1.choose_landord() == true) {
			landlord_player_2 = 1;
			gotoxy(20, 20);
			cout << "Ai 1：抢地主！";
		}
		else {
			landlord_player_2 = 0;
			gotoxy(20, 20);
			cout << "Ai 1：不抢    ";
		}
		Sleep(2000);
		if (ai_2.choose_landord() == true) {
			landlord_player_3 = 1;
			gotoxy(MapLength-20, 20);
			cout << "Ai 2：抢地主！";
		}
		else {
			landlord_player_3 = 0;
			gotoxy(MapLength-20, 20);
			cout << "Ai 2：不抢     ";
		}
		Sleep(2000);
		if (landlord_player_2 + landlord_player_3 != 0) {
			gotoxy(first_button_x - 4, first_button_y + 5);
			cout << "【再抢】";
			gotoxy(first_button_x + 16, first_button_y + 5);
			cout << "【不抢】";
			if (basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1) {
				gotoxy(MapLength / 2, MapHeight/2+14);
				cout << "地主是你！";

				gotoxy(MapLength/2, MapHeight / 2 + 18);
				cout << "再抢！  ";

				Sleep(2000);
				system("cls");
				return 1;
			}
			else {
				gotoxy(MapLength/2, MapHeight / 2 + 18);
				cout << "不抢！  "; 


				if (landlord_player_3 == 1) {
					gotoxy(MapLength / 2, MapHeight/2+14);
					cout << "地主是2号ai！";

					Sleep(2000);
					system("cls");
					return 3;
				}
				
				else {
					gotoxy(MapLength / 2, MapHeight/2+14);
					cout << "地主是1号ai！";
					Sleep(2000);
					system("cls");
					return 2;
				}

			}

		}
		else {
			gotoxy(MapLength / 2, MapHeight/2+14);
			cout << "地主是你！";

			Sleep(2000);
			system("cls");
			return 1;
		}








	}
	if (choosen_player == 2) {

		if (ai_1.choose_landord() == true) {
			landlord_player_2 = 1;
			gotoxy(20, 20);
			cout << "Ai 1：叫地主！";
		}
		else {
			landlord_player_2 = 0;
			gotoxy(20, 20);
			cout << "Ai 1：不叫  ";
		}
		Sleep(2000);

		if (ai_2.choose_landord() == true) {
			landlord_player_3 = 1;
			gotoxy(MapLength - 20, 20);
			cout << "Ai 2：抢地主！";
		}
		else {
			landlord_player_3 = 0;
			gotoxy(MapLength - 20, 20);
			cout << "Ai 2：不抢   ";
		}
		Sleep(2000);

		gotoxy(first_button_x - 4, first_button_y + 5);
		cout << "【抢地主】";
		gotoxy(first_button_x + 16, first_button_y + 5);
		cout << "【不抢】";
		if (basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1)
		{
			
			gotoxy(MapLength/2, MapHeight / 2 + 18);
			cout << "抢地主！  "; 
			landlord_player_1 =1;
		}
		else {
			gotoxy(MapLength/2, MapHeight / 2 + 18);
			cout << "不抢！  ";
			landlord_player_1 = 0;
		}

		Sleep(2000);
		if (landlord_player_1 + landlord_player_3 != 0) {
			


			if (ai_1.choose_landord() == true) {
				gotoxy(20, 20);
				cout << "Ai 1：再抢！  ";
				gotoxy(MapLength / 2, MapHeight/2+14);
				cout << "地主是1号ai！";

				Sleep(2000);
				system("cls");
				return 2;
			}
			else {
				if (landlord_player_1 == 1) {
					gotoxy(20, 20);
					cout << "Ai 1：不抢！  ";
					gotoxy(MapLength / 2, MapHeight/2+14);
					cout << "地主是你！";
					Sleep(2000);
					system("cls");

					return 1;
				}
				else {
					gotoxy(MapLength / 2, MapHeight/2+14);
					cout << "地主是2号ai！";
					Sleep(2000);
					system("cls");
					return 3;
				}
			}

		}
		else {
			gotoxy(MapLength / 2, MapHeight/2+14);
			cout << "地主是1号ai！";
			Sleep(2000);
			system("cls");
			return 2;
		}
		


	}
	if (choosen_player == 3) {
		if (ai_2.choose_landord() == true) {
			landlord_player_3 = 1;
			gotoxy(MapLength - 20, 20);
			cout << "Ai 2：叫地主！";
		}
		else {
			landlord_player_3 = 0;
			gotoxy(MapLength - 20, 20);
			cout << "Ai 2：不叫   ";
		}

		Sleep(2000);

		gotoxy(first_button_x - 4, first_button_y + 5);
		cout << "【抢地主】";
		gotoxy(first_button_x + 16, first_button_y + 5);
		cout << "【不抢】";
		if (basic_choose_button(orign_arrow, buttons_number, buttons_distance, first_button_x, first_button_y) == 1) {
			gotoxy(MapLength/2, MapHeight / 2 + 18);
			cout << "抢地主！  ";
			landlord_player_1 = 1;
		}
		else {
			gotoxy(MapLength/2, MapHeight / 2 + 18);
			cout << "不抢！  ";
			landlord_player_1 = 0;
		}
		Sleep(2000);

		if (ai_1.choose_landord() == true) {
			landlord_player_2 = 1;
			gotoxy(20, 20);
			cout << "Ai 1：抢地主！";
		}
		else {
			landlord_player_2 = 0;
			gotoxy(20, 20);
			cout << "Ai 1：不抢   ";
		}
		Sleep(2000);

		


		
		if (landlord_player_1 + landlord_player_2 != 0) {



			if (ai_2.choose_landord() == true) {
				gotoxy(MapLength - 20, 20);
				cout << "Ai 2：再抢！   ";

				gotoxy(MapLength / 2, MapHeight/2+14);
				cout << "地主是2号ai！";
				Sleep(2000);
				system("cls");
				return 3;
			}
			else {
				if (landlord_player_1 == 1) {
					gotoxy(MapLength - 20, 20);
					cout << "Ai 2：不抢！";


					gotoxy(MapLength / 2, MapHeight/2+14);
					cout << "地主是你！";
					Sleep(2000);
					system("cls");
					return 1;
				}
				else { 
					gotoxy(MapLength / 2, MapHeight/2+14);
					cout << "地主是1号ai！";
					Sleep(2000);
					system("cls");
					return 2;
				}
			}

		}
		else {
			gotoxy(MapLength / 2, MapHeight/2+14);
			cout << "地主是2号ai！";
			Sleep(2000);
			system("cls");
			return 3;
		}
		


	}



	                                          











}

void Draw::print_handcard_updown(int card_y, int card_num, int* card,int*card_up_no_matrix)
{
	int all_card_long = (card_num - 1) * between_cards_Length + cardLength;
	int clean_all_card_long = (20 - 1) * between_cards_Length + cardLength;

	//先把牌所占空间,以及已经选中的突出的牌的空间清出来，赋0
	for (int i = MapLength / 2 - clean_all_card_long / 2; i < MapLength / 2 + clean_all_card_long / 2+ cardLength; i++) {
		for (int j = card_y - 4; j <= card_y + cardHeight; j++) {
			map_matrix_[i][j] = '0';
		}
	}

	//打印到第num张牌
	int num = 1;
	int Temp = MapLength / 2 - all_card_long / 2;

	//递增，0在最后
	int card_no_matrix[20] = { 0 };
	int card_no_matrix_index = 0;
	for (int i = 0; i < 15; i++) {
		if (card[i] != 0) {
			int temp_num = card[i];
			for (int j = 0; j < temp_num; j++) {
				card_no_matrix[card_no_matrix_index + j] = i + 3;
			}
			card_no_matrix_index += temp_num;
		}
	}

	int temp_card_y = card_y;

	while (num <= card_num) {
		//如果该牌处于被选中的状态，则纵坐标向上移三个单位
		if (card_up_no_matrix[num - 1] == 0) {
			temp_card_y = card_y;
		}
		else {
			temp_card_y = card_y - 3;
		}
		//先把牌所占空间清出来，赋0
		for (int i = Temp; i < Temp + cardLength; i++) {
			for (int j = temp_card_y; j <= temp_card_y + cardHeight; j++) {
				map_matrix_[i][j] = '0';
			}
		}


		//这里是打印牌的上下边界
		for (int i = Temp; i < Temp + cardLength; i++) {
			map_matrix_[i][temp_card_y] = '2';
			map_matrix_[i][temp_card_y + cardHeight] = '2';
		}
		//这里是打印牌的竖线和牌数值

		for (int j = temp_card_y; j <= temp_card_y + cardHeight; j++) {
			map_matrix_[Temp][j] = '3';
			map_matrix_[Temp + cardLength][j] = '3';


			map_matrix_[Temp + 1][temp_card_y + 1] = card_no_matrix[num - 1];
		}

		num++;
		Temp += 4;
	}


	print(MapLength / 2 - all_card_long / 2, card_y - 4, all_card_long+9, cardHeight + 4);
}


void Draw::print_ai_card_left(int left_card_num) {
	int num_left = 1;


	int temp_card_length = 20;
	int temp_card_height = 6;


	int temp_left_x = 5;
	int temp_left_y = 8;




	//左边
	while (num_left <= left_card_num) {
		//先把牌所占空间清出来，赋0
		for (int i = temp_left_x; i < temp_left_x + temp_card_length; i++) {
			for (int j = temp_left_y; j <= temp_left_y + temp_card_height; j++) {
				map_matrix_[i][j] = '0';
			}
		}

		//这里是打印牌的竖线
		for (int i = temp_left_y; i < temp_left_y + temp_card_height; i++) {
			map_matrix_[temp_left_x - 1][i] = '3';
			map_matrix_[temp_left_x + temp_card_length][i] = '3';
		}

		//这里是打印牌的上下边界

		for (int j = temp_left_x; j < temp_left_x + temp_card_length; j++) {
			map_matrix_[j][temp_left_y] = '2';
			map_matrix_[j][temp_left_y + temp_card_height] = '2';

		}

		num_left++;
		temp_left_y += 2;
	}


	print(4, 8, temp_card_length + 2, (left_card_num - 1) * 2 + 6);
	gotoxy(13, temp_left_y + 1);
	cout << left_card_num << "张";

}
void Draw::print_ai_card_right(int right_card_num)
{
	
	int num_right = 1;

	int temp_card_length = 20;
	int temp_card_height = 6;


	int temp_left_x = 5;
	int temp_left_y = 8;

	int temp_right_x = MapLength - 5 - temp_card_length;
	int temp_right_y = 8;
	while (num_right <= right_card_num) {
		//先把牌所占空间清出来，赋0
		for (int i = temp_right_x; i < temp_right_x + temp_card_length; i++) {
			for (int j = temp_right_y; j <= temp_right_y + temp_card_height; j++) {
				map_matrix_[i][j] = '0';
			}
		}

		//这里是打印牌的竖线
		for (int i = temp_right_y; i < temp_right_y + temp_card_height; i++) {
			map_matrix_[temp_right_x - 1][i] = '3';
			map_matrix_[temp_right_x + temp_card_length][i] = '3';
		}

		//这里是打印牌的上下边界

		for (int j = temp_right_x; j < temp_right_x + temp_card_length; j++) {
			map_matrix_[j][temp_right_y] = '2';
			map_matrix_[j][temp_right_y + temp_card_height] = '2';

		}

		num_right++;
		temp_right_y += 2;
	}

	//Map[temp_left_x + 10][temp_left_y + 2] = left_card_num;

	print(temp_right_x - 1, 8, temp_card_length + 2, (right_card_num - 1) * 2 + 6);
	gotoxy(MapLength - 13, temp_right_y + 1);
	cout << right_card_num << "张";

}
void Draw::print_ai_card(int left_card_num, int right_card_num,int if_player_is_lanlord) {
	int num_left = 1;
	int num_right = 1;

	int temp_card_length = 20;
	int temp_card_height = 6;


	int temp_left_x = 5;
	int temp_left_y = 8;

	int temp_right_x = MapLength - 5 - temp_card_length;
	int temp_right_y = 8;

	//for (int i = temp_left_x; i < temp_left_x + temp_card_length; i++) {
	//	for (int j = 1; j < MapHeight; j++) {
	//		Map[i][j] = '0';
	//	}
	//}

	gotoxy(10, 4);
	cout << "【AI】【1号】";

	gotoxy(MapLength - 22, 4);
	cout << "【AI】【2号】";





	//左边
	while (num_left <= left_card_num) {
		//先把牌所占空间清出来，赋0
		for (int i = temp_left_x; i < temp_left_x + temp_card_length; i++) {
			for (int j = temp_left_y; j <= temp_left_y + temp_card_height; j++) {
				map_matrix_[i][j] = '0';
			}
		}

		//这里是打印牌的竖线
		for (int i = temp_left_y; i < temp_left_y + temp_card_height; i++) {
			map_matrix_[temp_left_x - 1][i] = '3';
			map_matrix_[temp_left_x + temp_card_length][i] = '3';
		}

		//这里是打印牌的上下边界

		for (int j = temp_left_x; j < temp_left_x + temp_card_length; j++) {
			map_matrix_[j][temp_left_y] = '2';
			map_matrix_[j][temp_left_y + temp_card_height] = '2';

		}

		num_left++;
		temp_left_y += 2;
	}

	//Map[temp_left_x + 10][temp_left_y + 2] = left_card_num;

	print(4, 8, temp_card_length + 2, (left_card_num - 1) * 2 + 6);
	gotoxy(13, temp_left_y + 1);
	cout << left_card_num << "张";

	if (if_player_is_lanlord == 2) {
		gotoxy(13, 6);
		cout << "【地主】";
		gotoxy(MapLength - 20, 6);
		cout << "【农民】";
	}
	else if (if_player_is_lanlord == 1) {
		gotoxy(13, 6);
		cout << "【农民】";
		gotoxy(MapLength - 20, 6);
		cout << "【农民】";
	}
	else if (if_player_is_lanlord == 3) {
		gotoxy(13, 6);
		cout << "【农民】";
		gotoxy(MapLength - 20, 6);
		cout << "【地主】";
	}




	//右边
	while (num_right <= right_card_num) {
		//先把牌所占空间清出来，赋0
		for (int i = temp_right_x; i < temp_right_x + temp_card_length; i++) {
			for (int j = temp_right_y; j <= temp_right_y + temp_card_height; j++) {
				map_matrix_[i][j] = '0';
			}
		}

		//这里是打印牌的竖线
		for (int i = temp_right_y; i < temp_right_y + temp_card_height; i++) {
			map_matrix_[temp_right_x - 1][i] = '3';
			map_matrix_[temp_right_x + temp_card_length][i] = '3';
		}

		//这里是打印牌的上下边界

		for (int j = temp_right_x; j < temp_right_x + temp_card_length; j++) {
			map_matrix_[j][temp_right_y] = '2';
			map_matrix_[j][temp_right_y + temp_card_height] = '2';

		}

		num_right++;
		temp_right_y += 2;
	}

	//Map[temp_left_x + 10][temp_left_y + 2] = left_card_num;

	print(temp_right_x - 1, 8, temp_card_length + 2, (right_card_num - 1) * 2 + 6);
	gotoxy(MapLength - 13, temp_right_y + 1);
	cout << right_card_num << "张";

}

void Draw::Landlord_Card_Creat(int* card) {
	int num = 1;

	int temp_x = MapLength / 2 - (3) * 4;
	int temp_y = 5;
	while (num <= 3) {
		//先把牌所占空间清出来，赋0
		for (int i = temp_x; i < temp_x + cardLength; i++) {
			for (int j = temp_y; j <= temp_y + cardHeight; j++) {
				map_matrix_[i][j] = '0';
			}
		}

		//这里是打印牌的上下边界
		for (int i = temp_x; i < temp_x + cardLength; i++) {
			map_matrix_[i][temp_y] = '2';
			map_matrix_[i][temp_y + cardHeight] = '2';
		}
		//这里是打印牌的竖线和牌数值

		for (int j = temp_y; j < temp_y + cardHeight; j++) {
			map_matrix_[temp_x][j] = '3';
			map_matrix_[temp_x + cardLength][j] = '3';
			map_matrix_[temp_x + 1][temp_y + 1] = card[num - 1];
		}

		num++;
		temp_x += 4;
	}

	print(MapLength / 2 - (3) * 4, temp_y, (3 - 1) * 4 + 14, cardHeight + 4);

}


int Draw::endgame(Human human, Ai ai_1, Ai ai_2) {
	if (human.card_num(human.handcards_) == 0) {

		                                            system("cls");
		return 1;

	}
	else if (ai_1.card_num(ai_1.handcards_) == 0) {
		                                       system("cls");
		return 2;

	}
	else if (ai_2.card_num(ai_2.handcards_) == 0) {
		                                         system("cls");
		return 3;

	}
	else {
		return 0;
	}
}