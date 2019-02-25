/*
Program written by 2019/Feb/17
Sudoku answer checking program v.0.1
Written by Hongjun Yun

contact: andylnag8445@gmail.com
*/
#include<stdio.h>
int organ[9];
int arrange()
{
	int tmp;
	for(int i=0;i<8;i++)
	{
		for(int j=i+1;j<9;j++)
		{
			if(organ[i]>organ[j])
			{
				tmp=organ[i];
				organ[i]=organ[j];
				organ[j]=tmp;
			}
		}
	}
	for(int i=0;i<9;i++)
	{
		if(organ[i]!=i+1)
			return 1;
	}
	return 0;
}
int main()
{
	int error[9][2];
	int x,y;
	int map[9][9];
	int num=0;
	int cnt=0;
	int cntx=0,cnty=0,cnts=0;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			organ[j]=map[i][j];
		error[cntx][0]=i+1;
		cntx+=arrange();
		for(int j=0;j<9;j++)
			organ[j]=map[j][i];
		error[cnty][1]=i+1;
		cnty+=arrange();
	}
	for(int i=0;i<=6;i+=3)
	{
		for(int j=0;j<=6;j+=3)
		{
			for(x=i;x<i+3;x++)
				for(y=j;y<j+3;y++)
					organ[num++]=map[x][y];
			num=0;
			cnts=arrange();
		}
	}
	cnt=cntx+cnty+cnts;
	printf("Vertical Line: %d error lines\nHorizontal line: %d error lines\nSection line: %d error sections\n",cnty,cntx,cnts);
	if(cntx>0)
		printf("Error locations: \n");
	for(int i=0;i<cntx;i++)
		printf("\t(%d,%d)\n",error[i][0],error[i][1]);
	printf("----------------------\nTotal error count: %d",cnt);
}
