#ifndef LOG_H
#define LOG_H
#include<Windows.h>



void gotoxy(unsigned char x, unsigned char y);

class log
{
public:
	int happy_beans_=0;
	int happy_numbers_=1;
	


	void double_happy_numbers();
	void evaluate_happy_beans(int happy_numbers, int happy_beans, int winner, int landlord);
	void print_happy_numbers_and_beans(int MapLength,int MapHeight, int happy_numbers, int happy_beans);

};
#endif
