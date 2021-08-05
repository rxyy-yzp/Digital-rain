#include"stdio.h"
#include"graphics.h"
#include"windows.h"
#include"time.h"

#define WIDTH 960
#define HEIGHT 640
#define STR_SIZE 20//ÿ��������ַ�����
#define STR_NUM 128//�����괮��
#define STR_WIDTH 15//ÿ������

struct Rain//������ṹ��
{
	int x;//���������λ��
	int y;//����������λ��
	int speed;//�½��ٶ�
	char str[STR_SIZE];//�������ַ�����
}rain[STR_NUM];

char CreateCh()
{
	char temp = 0;
	int flag = rand() % 3;//0 1 2
	if (flag == 0)
	{
		temp = rand() % 26 + 'a';
	}
	else if (flag == 1)
	{
		temp = rand() % 26 + 'A';
	}
	else
	{
		temp = rand() % 10 + '0';
	}
	return temp;
}

void GameInit()
{
	int i, j;
	for (i = 0;i < STR_NUM;i++)
	{
		rain[i].x = i * STR_WIDTH;
		rain[i].y = rand() % HEIGHT;
		rain[i].speed = rand() % 5 + 5;
	}
	//��ʼ���ַ���
	for (i = 0;i < STR_NUM;i++)
	{
		for (j = 0;j < STR_SIZE;j++)
		{
			rain[i].str[j] = CreateCh();
		}
	}
}

void GameDraw()
{
	int i, j;
	cleardevice();
	for (i = 0;i < STR_NUM;i++)
	{
		for (j = 0;j < STR_SIZE;j++)
		{
			outtextxy(rain[i].x, rain[i].y - STR_WIDTH * j, rain[i].str[j]);
			settextcolor(RGB(0, 255 - 13 * j, 0));
		}
	}
}

void GamePlay()
{
	int i;
	for (i = 0;i < STR_NUM;i++)
	{
		rain[i].y += rain[i].speed;
		if (rain[i].y - STR_SIZE * STR_WIDTH > HEIGHT)
		{
			rain[i].y = 0;
		}
	}
}

void ChangeCh()
{
	int i;
	for (i = 0;i < STR_NUM;i++)
	{
		rain[rand() % STR_NUM].str[rand() % STR_SIZE] = CreateCh();
	}
}

int main()
{
	initgraph(WIDTH, HEIGHT);
	srand(GetTickCount());
	GameInit();
	DWORD t1, t2;
	t1 = t2 = GetTickCount();
	while (1)
	{
		BeginBatchDraw();
		GameDraw();
		ChangeCh();
		if (t2 - t1 > 20)
		{
			GamePlay();
			t1 = t2;
		}
		t2 = GetTickCount();
		EndBatchDraw();
	}
	closegraph();
	return 0;
}