#include "log.h"
using namespace std;

void print_key_1(int x, int y) {
	gotoxy(x, y);
	cout << "》》";



}


void A::print_menu() {
	int point_key = 1;
	int keyborad_input = 0;

	int first_button_x = MapLength / 2 - 20;
	int first_button_y = MapHeight / 2;
	int buttons_distance = 2;

	int first_key_y = MapHeight / 2;
	int second_key_y = MapHeight / 2 + 2;
	int third_key_y = MapHeight / 2 + 4;
	int fourth_key_y = MapHeight / 2 + 6;
	int fifth_key_y = MapHeight / 2 + 8;




	gotoxy(MapLength / 2 - 20, MapHeight / 2);
	cout << "用户名：";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 - 1);
	cout << "-------------------";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 1);
	cout << "-------------------";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 2);
	cout << "密码  ：";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 3);
	cout << "-------------------";


	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 4);
	cout << "【登录】";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 6);
	cout << "【注册】";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 8);
	cout << "【返回】";






}

int A::choose_button_login() {
	//1：输入用户名 2：输入密码 3：登录  4：注册  5：返回
	int point_key = 1;
	int keyborad_input = 0;

	int first_button_x = MapLength / 2 - 20;
	int first_button_y = MapHeight / 2;
	int buttons_distance = 2;

	int first_key_y = MapHeight / 2;
	int second_key_y = MapHeight / 2 + 2;
	int third_key_y = MapHeight / 2 + 4;
	int fourth_key_y = MapHeight / 2 + 6;
	int fifth_key_y = MapHeight / 2 + 8;




	gotoxy(MapLength / 2 - 20, MapHeight / 2);
	cout << "用户名：";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 - 1);
	cout << "-------------------";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 1);
	cout << "-------------------";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 2);
	cout << "密码  ：";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 3);
	cout << "-------------------";


	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 4);
	cout << "【登录】";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 6);
	cout << "【注册】";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 8);
	cout << "【返回】";



	for (int j = first_button_x - 8; j <= first_button_x - 1; j++) {
		for (int i = first_button_y; i < first_button_y + 3; i++) {
			gotoxy(j, i);
			putchar(' ');
		}
	}

	gotoxy(MapLength / 2 - 25, MapHeight / 2);
	cout << "》》";

	int first_arrow_x = MapLength / 2 - 25;


	while (1) {
		//a,d移动箭头，按回车选中
		keyborad_input = _getch();


		//先把箭头清空
		for (int j = first_button_x - 8; j <= first_button_x - 1; j++) {
			for (int i = first_button_y; i < first_button_y + 10; i++) {
				gotoxy(j, i);
				putchar(' ');
			}
		}



		//向上
		if (keyborad_input == 119) {

			if (point_key == 1) {

				print_key_1(first_arrow_x, first_key_y);

				continue;
			}
			else if (point_key == 2) {

				print_key_1(first_arrow_x, first_key_y);
				point_key--;
				continue;
			}
			else if (point_key == 3) {

				print_key_1(first_arrow_x, second_key_y);
				point_key--;
				continue;
			}
			else if (point_key == 4) {

				print_key_1(first_arrow_x, third_key_y);
				point_key--;
				continue;
			}
			else if (point_key == 5) {

				print_key_1(first_arrow_x, fourth_key_y);
				point_key--;
				continue;
			}
		}


		//向下
		else if (keyborad_input == 115) {

			if (point_key == 1) {
				//再打印箭头
				print_key_1(first_arrow_x, second_key_y);

				point_key++;
				continue;
			}
			else if (point_key == 2) {
				print_key_1(first_arrow_x, third_key_y);
				point_key++;
				continue;
			}
			else if (point_key == 3) {
				//再打印箭头
				print_key_1(first_arrow_x, fourth_key_y);
				point_key++;
				continue;
			}
			else if (point_key == 4) {
				//再打印箭头
				print_key_1(first_arrow_x, fifth_key_y);
				point_key++;

				continue;
			}
			else if (point_key == 5) {
				//再打印箭头
				print_key_1(first_arrow_x, fifth_key_y);

				continue;
			}
		}






		else if (keyborad_input == 13 && point_key == 1) {

			return 1;

			break;
		}

		else if (keyborad_input == 13 && point_key == 2) {

			return 2;

			break;
		}
		else if (keyborad_input == 13 && point_key == 3) {

			return 3;

			break;
		}
		else if (keyborad_input == 13 && point_key == 4) {

			return 4;

			break;
		}
		else if (keyborad_input == 13 && point_key == 5) {

			return 5;

			break;
		}

		else {
			if (point_key == 1) {

				print_key_1(first_arrow_x, first_key_y);

				continue;
			}
			else if (point_key == 2) {

				print_key_1(first_arrow_x, second_key_y);

				continue;
			}
			else if (point_key == 3) {

				print_key_1(first_arrow_x, third_key_y);

				continue;
			}
			else if (point_key == 4) {

				print_key_1(first_arrow_x, fourth_key_y);

				continue;
			}
			else if (point_key == 5) {

				print_key_1(first_arrow_x, fifth_key_y);

				continue;
			}
		}

	}

}
int A::choose_button_sign() {
	//1：输入用户名 2：输入密码 3：注册  4：返回  
	int point_key = 1;
	int keyborad_input = 0;

	int first_button_x = MapLength / 2 - 20;
	int first_button_y = MapHeight / 2;
	int buttons_distance = 2;

	int first_key_y = MapHeight / 2;
	int second_key_y = MapHeight / 2 + 2;
	int third_key_y = MapHeight / 2 + 4;
	int fourth_key_y = MapHeight / 2 + 6;
	int fifth_key_y = MapHeight / 2 + 8;




	gotoxy(MapLength / 2 - 20, MapHeight / 2);
	cout << "用户名：";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 - 1);
	cout << "-------------------";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 1);
	cout << "-------------------";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 2);
	cout << "密码  ：";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 3);
	cout << "-------------------";


	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 4);
	cout << "【注册】";
	gotoxy(MapLength / 2 - 20, MapHeight / 2 + 6);
	cout << "【返回】";
	//gotoxy(MapLength / 2 - 20, MapHeight / 2 + 8);
	//cout << "【返回】";



	for (int j = first_button_x - 8; j <= first_button_x - 1; j++) {
		for (int i = first_button_y; i < first_button_y + 3; i++) {
			gotoxy(j, i);
			putchar(' ');
		}
	}

	gotoxy(MapLength / 2 - 25, MapHeight / 2);
	cout << "》》";

	int first_arrow_x = MapLength / 2 - 25;


	while (1) {
		//a,d移动箭头，按回车选中
		keyborad_input = _getch();


		//先把箭头清空
		for (int j = first_button_x - 8; j <= first_button_x - 1; j++) {
			for (int i = first_button_y; i < first_button_y + 10; i++) {
				gotoxy(j, i);
				putchar(' ');
			}
		}



		//向上
		if (keyborad_input == 119) {

			if (point_key == 1) {

				print_key_1(first_arrow_x, first_key_y);

				continue;
			}
			else if (point_key == 2) {

				print_key_1(first_arrow_x, first_key_y);
				point_key--;
				continue;
			}
			else if (point_key == 3) {

				print_key_1(first_arrow_x, second_key_y);
				point_key--;
				continue;
			}
			else if (point_key == 4) {

				print_key_1(first_arrow_x, third_key_y);
				point_key--;
				continue;
			}
			/*	else if (point_key == 5) {

					print_key_1(first_arrow_x, fourth_key_y);
					point_key--;
					continue;
				}*/
		}


		//向下
		else if (keyborad_input == 115) {

			if (point_key == 1) {
				//再打印箭头
				print_key_1(first_arrow_x, second_key_y);

				point_key++;
				continue;
			}
			else if (point_key == 2) {
				print_key_1(first_arrow_x, third_key_y);
				point_key++;
				continue;
			}
			else if (point_key == 3) {
				//再打印箭头
				print_key_1(first_arrow_x, fourth_key_y);
				point_key++;
				continue;
			}
			else if (point_key == 4) {
				//再打印箭头
				print_key_1(first_arrow_x, fourth_key_y);
				//	point_key++;

				continue;
			}
			//else if (point_key == 5) {
			//	//再打印箭头
			//	print_key_1(first_arrow_x, fifth_key_y);

			//	continue;
			//}
		}






		else if (keyborad_input == 13 && point_key == 1) {

			return 1;

			break;
		}

		else if (keyborad_input == 13 && point_key == 2) {

			return 2;

			break;
		}
		else if (keyborad_input == 13 && point_key == 3) {

			return 3;

			break;
		}
		else if (keyborad_input == 13 && point_key == 4) {

			return 4;

			break;
		}
		/*	else if (keyborad_input == 13 && point_key == 5) {

				return 5;

				break;
			}*/

		else {
			if (point_key == 1) {

				print_key_1(first_arrow_x, first_key_y);

				continue;
			}
			else if (point_key == 2) {

				print_key_1(first_arrow_x, second_key_y);

				continue;
			}
			else if (point_key == 3) {

				print_key_1(first_arrow_x, third_key_y);

				continue;
			}
			else if (point_key == 4) {

				print_key_1(first_arrow_x, fourth_key_y);

				continue;
			}
			/*else if (point_key == 5) {

				print_key_1(first_arrow_x, fifth_key_y);

				continue;
			}*/
		}

	}

}

void A::login_settle(int button) {


	if (button == 1) {

		gotoxy(MapLength / 2 - 12, MapHeight / 2);
		cin >> username;

	}
	else if (button == 2) {

		gotoxy(MapLength / 2 - 12, MapHeight / 2 + 2);
		cin >> password;
	}


}
void A::sign_settle(int button) {


	if (button == 1) {

		gotoxy(MapLength / 2 - 12, MapHeight / 2);
		cin >> username;

	}
	else if (button == 2) {

		gotoxy(MapLength / 2 - 12, MapHeight / 2 + 2);
		cin >> password;
	}


}
vector<User> readCSV(string filename) {
	vector<User> users;
	ifstream file(filename);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			User user;
			int pos = 0;
			for (int i = 0; i < 3; i++) {
				int nextPos = line.find(',', pos);
				string value;
				if (i == 0) {
					value = line.substr(pos , nextPos - pos );
				}
				else if (i == 2) {
					value = line.substr(pos, nextPos - pos - 1);
				}

				else if (i == 1) {
					value = line.substr(pos, nextPos - pos);
				}

				if (i == 0) {
					user.username = value;
				}
				else if (i == 1) {
					user.password = value;
				}
				else {
					user.happyBeans = stoi(value);
				}
				pos = nextPos + 1;
			}

			users.push_back(user);
		}

		file.close();
	}
	return users;
}

void writeCSV(string filename, vector<User> users) {
	ofstream file(filename);
	if (file.is_open()) {
		for (User user : users) {
			file << user.username << "," << user.password << "," << user.happyBeans << endl;
		}
		file.close();
	}
}

bool searchUser(vector<User> users, string username, string password, int* happybeans) {
	for (User user : users) {
		if (user.username == username && user.password == password) {
			happybeans[0] = user.happyBeans;
			return true;
		}
	}
	return false;
}


void searchUser_change(vector<User> users, string username, string password, int* happybeans) {
	for (User user : users) {
		if (user.username == username && user.password == password) {
			 user.happyBeans=happybeans[0] ;
		
		}
	}
	
}