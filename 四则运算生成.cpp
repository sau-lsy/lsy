#include<stdio.h>
#include<iostream>
using namespace std;
int a[4] = { 1,1,1,1 };
int question(int A, int k, int count, int s)
{
	
	int h = 0;
	int x;
	int r;
	int flag1 = 1;
	int flag2 = 0;
	int flag3 = 0;
	if (A == 1)
	{
		h = 10;
	}
	else if (A == 2)
	{
		h = 100;
	}
	else if (A == 3)
	{
		h = 1000;
	}
	for (int i = 0; i < count; i++)
	{
		printf("(%d) ", i + 1);
		
		r = rand() % 7 + 2;
		for (int j = 0; j < r + 1; j++)
		{
			flag3 = 0;
			if (j != r)
			{
				if (flag3 == 0) 
				{
					if (k == 1 && flag2 == 0 && rand() % 2 == 1)
					{
						printf(" ( ");

						flag2 = 1;
						flag1 = 1;
					}
					if (s == 1)
					{
						printf("%d", rand() % h);

					}
					else
					{
						printf("%.2f", rand() / (double)(RAND_MAX / h));

					}
					if (k == 1 && flag2 == 1 && rand() % 2 == 1 && flag1 != 1)
					{
						printf(" ) ");

						flag2 = 0;
					}
					flag1 = 0;
					flag3 = 1;
				}
				while(1)
				{
					x = rand() % 4;
					switch (x)
					{
					case 0:
					case 1:
						if (a[0] == 1)
						{
							printf(" + ");
							flag3 = 0;
							break;
						}

					case 2:
						if (a[1] == 1)
						{
							printf(" - ");
							flag3 = 0;
							break;
						}
					case 3:
						if (a[2] == 1)
						{
							printf(" * ");
							flag3 = 0;
							break;
						}
					case 4:
						if (a[3] == 1)
						{
							printf(" / ");
							flag3 = 0;
							break;
						}
					}
					if (flag3 == 0)
						break;
				}
			}
			else
			{
				printf("%d ", rand() % h);
				
				if (flag2 == 1)
				{
					printf(" ) ");
					
					flag2 = 0;
				}
				printf(" = ?\n");
				
			}
		}
	}
	return 0;
}

void set(int i, int j, int m, int n)
{
	a[0] = i;
	a[1] = j;
	a[2] = m;
	a[3] = n;
}
int main()
{
	int q, w, e, r;
	int i, j, m, n;
	cout << "��ѡ���Ƿ��мӼ��˳������  1Ϊ��Ҫ  0Ϊ����Ҫ   �������磺1  1  0   1" << endl;
	cin >> i >> j >> m >> n;
	set(i, j, m, n);
	cout << "��ѡ�����ֵ    1Ϊ10   2Ϊ100   3Ϊ1000" << endl;
	cin >> q;
	cout << "��ѡ����������    1��   0Ϊ��" << endl;
	cin >> w;
	cout << "��ѡ����������С��    1Ϊ����   0ΪС��" << endl;
	cin >> r;
	cout << "��������Ŀ������" << endl;
	cin >> e;
		question(q, w, e, r);
	return 0;
}

