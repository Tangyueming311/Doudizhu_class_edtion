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
//	//COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ�����
//	COORD cor;
//
//	//��� 
//	HANDLE hout;
//
//	//�趨����Ҫ��λ�������� 
//	cor.X = x;
//	cor.Y = y;
//
//	//GetStdHandle������ȡһ��ָ���ض���׼�豸�ľ����������׼���룬��׼����ͱ�׼����
//	//STD_OUTPUT_HANDLE���Ǵ����׼�����Ҳ������ʾ�����ĺ� 
//	hout = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	//SetConsoleCursorPosition�����������ÿ���̨����λ��
//	SetConsoleCursorPosition(hout, cor);
//}





vector<User> readCSV(string filename);

void writeCSV(string filename, vector<User> users);

bool searchUser(vector<User> users, string username, string password, int* happybeans);

void print_key_1(int x, int y);
void searchUser_change(vector<User> users, string username, string password, int* happybeans);

#endif
