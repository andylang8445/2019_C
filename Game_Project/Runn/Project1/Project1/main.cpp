#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<iostream>
#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // 콘솔창의 핸들정보 받기
#define height 38
#define width 60
#define original_Px 30
#define original_Py 30
int map[height][width];
int ex;
int Px, Py;
void gotoxy(int xxx, int yyy)  //x,y순서로 입력, 커서 이동(배열 좌표아닌 실제 좌표) 
{
	COORD pos = { xxx, yyy };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void fff(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; // bVisible 멤버 변경
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); // 변경값 적용
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
	Px = original_Px;
	Py = original_Py;

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
	int tmp;
	int beep_l = 0, beep_r = 0, beep_u = 0, beep_d = 0;
	system("mode con cols=60 lines=40");
	system("title Run");
	setup_seq();
	gotoxy(Px, Py);
	printf("$");
	while (1)
	{
		if (_kbhit())
		{
			tmp = _getch();
			if (tmp == 'w' || tmp == 'ㅈ')
			{
			up:
				if (Py == 1)
				{
					if (beep_u % 10 == 0)
						Beep(512, 200);
					beep_u++;
					goto end;
				}
				beep_l = beep_r = beep_d = beep_u = 0;
				gotoxy(Px, Py);
				printf(" ");
				Py--;
			}
			if (tmp == 's' || tmp == 'ㄴ')
			{
			down:
				if (Py == height - 2)
				{
					if (beep_d % 10 == 0)
						Beep(512, 200);
					beep_d++;
					goto end;
				}
				beep_l = beep_r = beep_u = beep_d = 0;
				gotoxy(Px, Py);
				printf(" ");
				Py++;
			}
			if (tmp == 'a' || tmp == 'ㅁ')
			{
			left:
				if (Px == 1)
				{
					if (beep_l % 10 == 0)
						Beep(512, 200);
					beep_l++;
					goto end;
				}
				beep_u = beep_r = beep_d = beep_l = 0;
				gotoxy(Px, Py);
				printf(" ");
				Px--;
			}
			if (tmp == 'd' || tmp == 'ㅇ')
			{
			right:
				if (Px == width - 2)
				{
					if (beep_r % 10 == 0)
						Beep(512, 200);
					beep_r++;
					goto end;
				}
				beep_l = beep_u = beep_d = beep_r = 0;
				gotoxy(Px, Py);
				printf(" ");
				Px++;
			}
			if (tmp == 224)
			{
				tmp = _getch();
				if (tmp == 72)
					goto up;
				if (tmp == 80)
					goto down;
				if (tmp == 75)
					goto left;
				if (tmp == 77)
					goto right;
			}

			gotoxy(Px, Py);
			printf("$");
		end:
			continue;
		}
	}
	_getch();
}