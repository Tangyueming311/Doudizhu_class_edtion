#ifndef LOG_H
#define LOG_H
#include<Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<iostream>
#include<string>
#include<Windows.h>
#include <conio.h>
#include<iomanip>
#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>

#include"Draw.h"
using namespace std;

class A {
public:
	string username;
	string password;
	int MapLength = 190;
	int MapHeight = 55;


	void print_menu();
	int choose_button_login();
	int choose_button_sign();
	void login_settle(int button);
	void sign_settle(int button);

};

class User {
public:
	string username;
	string password;
	int happyBeans;

	User() {}

	User(string username, string password, int happyBeans) {
		this->username = username;
		this->password = password;
		this->happyBeans = happyBeans;
	}


};




////void gotoxy(unsigned char x, unsigned char y) {
//	//COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标
//	COORD cor;
//
//	//句柄 
//	HANDLE hout;
//
//	//设定我们要定位到的坐标 
//	cor.X = x;
//	cor.Y = y;
//
//	//GetStdHandle函数获取一个指向特定标准设备的句柄，包括标准输入，标准输出和标准错误。
//	//STD_OUTPUT_HANDLE正是代表标准输出（也就是显示屏）的宏 
//	hout = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	//SetConsoleCursorPosition函数用于设置控制台光标的位置
//	SetConsoleCursorPosition(hout, cor);
//}





vector<User> readCSV(string filename);

void writeCSV(string filename, vector<User> users);

bool searchUser(vector<User> users, string username, string password, int* happybeans);

void print_key_1(int x, int y);
void searchUser_change(vector<User> users, string username, string password, int* happybeans);

#endif
