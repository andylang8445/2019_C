#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<iostream>
#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // �ܼ�â�� �ڵ����� �ޱ�
#define height 38
#define width 60
int map[height][width];
int Px, Py;
void gotoxy(int xxx, int yyy)  //x,y������ �Է�, Ŀ�� �̵�(�迭 ��ǥ�ƴ� ���� ��ǥ) 
{
	COORD pos = { xxx, yyy };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void fff(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; // bVisible ��� ����
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); // ���氪 ����
}
void setup_seq()
{
	fff();
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			map[i][j] = 0;
	for (int i = 0; i < height; i++)
	{
		map[i][0] = 1;
		map[i][width - 1] = 1;
	}
	for (int i = 0; i < width; i++)
	{
		map[0][i] = 1;
		map[height - 1][i] = 1;
	}
	Px = 30;
	Py = 30;

	//------Basic Map Form print-------//
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == 0)
				printf(" ");
			else if (map[i][j] == 1)
				printf("*");
		}
		printf("\n");
	}
}
void run_game()
{

}
int main()
{
	system("mode con cols=60 lines=40");
	system("title Run");
	setup_seq();
	gotoxy(Px, Py);
	printf("$");
	while (1)
	{
		break;
	}
	_getch();
}