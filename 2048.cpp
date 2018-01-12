#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int const ROW = 4;
int const COL = 4;
int game[ROW][COL] = { 0 };

//��������
int const UP = 1;
int const DOWN = 2;
int const LEFT = 3;
int const RIGHT = 4;

//��Ϸ������״̬
int const GAME_OVER = 1;
int const GAME_CONTINUE = 2;

//��ӡ���õ�����
void Print()
{
	system("cls");
	for (int i = 0; i < ROW; ++i)
	{
		cout << "---------------------------------" << endl;
		for (int j = 0; j < COL; ++j)
		{
			if (game[i][j] == 0)
			{
				cout << "|   \t";
			}
			else
			{
				cout << "|" << game[i][j] << "\t";
			}
		}
		cout << "|" << endl;
	}
	cout << "---------------------------------" << endl;
}
bool CreateNumber()
{
	int x = -1;
	int y = -1;
	int times = 0;
	int maxTimes = ROW * COL;
	int whitch = rand() % 7;
	do
	{
		x = rand() % ROW;
		y = rand() % COL;
		++times;
	} while (game[x][y] != 0 && times <= maxTimes);

	//˵�������Ѿ�����
	if (times >= maxTimes)
	{
		return false;
	}
	else
	{
		int num;
		if (whitch == 0)
		{
			num = 4;
		}
		else if (whitch)
		{
			num = 2;
		}
		game[x][y] = num;
	}

	return true;
}
void Process(int direction)
{
	
	switch (direction)
	{
	case UP:
		//������һ�в���
		for (int row = 1; row < ROW; ++row)
		{
			int flag[4] = { 0 };
			for (int crow = row; crow >= 1; --crow)
			{
				for (int col = 0; col < COL; ++col)
				{
					//��һ������Ϊ��
					if (game[crow - 1][col] == 0)
					{
						game[crow - 1][col] = game[crow][col];
						game[crow][col] = 0;
					}
					else if (!flag[col])
					{
						//�ϲ�
						if (game[crow - 1][col] == game[crow][col])
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;		
						}
					flag[col] = 1;
					}
				}
			}
		}
		break;
	case DOWN:
		//������һ�в���
		for (int row = ROW - 2; row >= 0; --row)
		{
			int flag[4] = { 0 };
			for (int crow = row; crow < ROW - 1; ++crow)
			{
				for (int col = 0; col < COL; ++col)
				{
					//��һ������Ϊ��
					if (game[crow + 1][col] == 0)
					{
						game[crow + 1][col] = game[crow][col];
						game[crow][col] = 0;
					}
					else if (!flag[col])
					{
						//�ϲ�
						if (game[crow + 1][col] == game[crow][col])
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
						}
						flag[col] = 1;

					}
				}
			}
		}
		break;
	case LEFT:
		//�����һ�в���
		for (int col = 1; col < COL; ++col)
		{
			int flag[4] = { 0 };
			for (int ccol = col; ccol >= 1; --ccol)
			{
				for (int row = 0; row < ROW; ++row)
				{
					//��һ������Ϊ��
					if (game[row][ccol - 1] == 0)
					{
						game[row][ccol - 1] = game[row][ccol];
						game[row][ccol] = 0;
					}
					else if (!flag[row])
					{
						//�ϲ�
						if (game[row][ccol - 1] == game[row][ccol])
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
						}
						flag[row] = 1;
					}
				}
			}
		}
		break;
	case RIGHT:
		//���ұ�һ�в���
		for (int col = COL - 2; col >= 0; --col)
		{
			int flag[4] = { 0 };
			for (int ccol = col; ccol <= COL - 2; ++ccol)
			{
				for (int row = 0; row < ROW; ++row)
				{
					//��һ������Ϊ��
					if (game[row][ccol + 1] == 0)
					{
						game[row][ccol + 1] = game[row][ccol];
						game[row][ccol] = 0;
					}
					else if (!flag[row])
					{
						//�ϲ�
						if (game[row][ccol + 1] == game[row][ccol])
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
						}
						flag[row] = 1;
					}
				}
			}
		}
		break;
	}

}
//�������������������������
int Input()
{
	//��ȡ���������ĸ������
	int upArrow = 0;
	int downArrow = 0;
	int leftArrow = 0;
	int rightArrow = 0;
	int direction = 0;
	while (true)
	{
		upArrow = GetAsyncKeyState(VK_UP);
		downArrow = GetAsyncKeyState(VK_DOWN);
		leftArrow = GetAsyncKeyState(VK_LEFT);
		rightArrow = GetAsyncKeyState(VK_RIGHT);

		if (upArrow)
		{
			direction = UP;
			break;
		}
		else if (downArrow)
		{
			direction = DOWN;
			break;
		}
		else if (leftArrow)
		{
			direction = LEFT;
			break;
		}
		else if (rightArrow)
		{
			direction = RIGHT;
			break;
		}

		//Sleep(100);
	}

	return direction;
}
//�ж���Ϸ״̬
int Judge()
{
	int flag = 0;
	//Ӯ����Ϸ
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (game[i][j] == 2048&&!flag)
			{
				cout << "����������";
				flag = 1;
				return GAME_CONTINUE;
				break;
			}
		}
	}

	//������
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL - 1; ++j)
		{
			if (!game[i][j] || (game[i][j] == game[i][j + 1]))
			{
				return GAME_CONTINUE;
				break;
			}
		}
	}
	//������
	for (int j = 0; j < COL; ++j)
	{
		for (int i = 0; i < ROW - 1; ++i)
		{
			if (!game[i][j] || (game[i][j] == game[i + 1][j]))
			{
				return GAME_CONTINUE;
				break;
			}
		}
	}

	//��������������״������Ϸ����
	return GAME_OVER;

}
bool Compare(int origame[4][4], int game[4][4])
{
	bool eq = true;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			if (origame[i][j]!=game[i][j])
			{
				eq = false;
				break;
			}
		if (!eq) break;
	}
	return eq;
}
int main()
{
	//����һ�����������
	srand((unsigned int)time(0));
	CreateNumber();
	CreateNumber();
	Print();
	int direction = 0;
	int gameState = -1;
	while (true)
	{
		direction = Input();

		gameState = Judge();
		if (direction && gameState == GAME_CONTINUE)
		{
			int origame[ROW][COL];
			for (int row = 0; row < ROW; row++)
				for (int col = 0; col < COL; col++)
					origame[row][col] = game[row][col];
			Process(direction);
			if(!Compare(origame,game))
				CreateNumber();
			Print();
			sleep(100);
		}
		else if (gameState == GAME_OVER)
		{
			Print();
			cout << "���ɵ����" << endl;
			//break;
		}
	}
	return 0;
}