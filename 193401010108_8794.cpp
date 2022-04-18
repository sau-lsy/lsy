#include<stdio.h>
#include<iostream>
using namespace std;
int w[10];
typedef struct vnode {     //����
	char data;
	struct anode* first;
}vnode, adjlist[100];
typedef struct anode {    //�߽ڵ� 
	int adj;
	struct anode* next;
}anode;
typedef struct    //ͼ�ṹ��
{
	adjlist ver;
	int num1, num2;
}def;
int locate(def g, char x)//���ҽڵ��±�
{
	int i;
	for (i = 0; i < g.num1; i++)
	{
		if (x == g.ver[i].data)
			break;
	}
	return i;
}
void cre(def& g)  //����ͼ�����ڽӱ�洢
{
	int a, b, i, j, x, y;
	char m, n;
	anode* p1 = NULL, * p2 = NULL;
	cout << "������ͼ�Ľ�������ߵĸ�����" << endl;
	cin >> a >> b;
	g.num1 = a;
	g.num2 = b;
	cout << "�����붥����Ϣ��(�Կո�ֿ�)" << endl;
	for (i = 0; i < a; i++)
	{
		cin >> g.ver[i].data;
		g.ver[i].first = NULL;
	}
	cout << endl;
	for (int i = 0; i < b; i++)
	{
		cout << "������ߵ���ż�ԣ����� a b" << endl;
		cin >> m >> n;
		x = locate(g, m);
		y = locate(g, n);
		p1 = new anode;
		p1->adj = y;
		p1->next = g.ver[x].first;
		g.ver[x].first = p1;
		p2 = new anode;
		p2->adj = x;
		p2->next = g.ver[y].first;
		g.ver[y].first = p2;
	}
}
int firstnode(def g, int r) //�±�Ϊr�ĵ���ڽӵ���±�
{
	if (g.ver[r].first)
		return g.ver[r].first->adj;
	else
		return -1;
}
int nextnode(def g, int r, int h) {
	int flag = 0;
	anode* p = NULL;
	p = g.ver[r].first;
	while (p)
	{
		if (p->adj == h)
		{
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag && p->next)
		return p->next->adj;
	else
		return -1;
}
void BFS(def g, int u) {    //������ȱ���
	int qu[20], front, rear;
	int k;
	rear = front = 0;
	anode* p = NULL;
	cout << g.ver[u].data << " ";
	w[u] = 1;
	rear = (rear + 1) % 20;
	qu[rear] = u;
	while (rear != front)
	{
		front = (front + 1) % 20;
		k = qu[front];
		p = g.ver[k].first;
		while (p)
		{
			if (w[p->adj] == 0)
			{
				cout << g.ver[p->adj].data << " ";
				w[p->adj] = 1;
				rear = (rear + 1) % 20;
				qu[rear] = p->adj;
			}
			p = p->next;
		}
	}

}
void BFStree(def g, int u) {    //���������ȱ������������ı߼�
	int qu[20], front, rear;
	int k;
	rear = front = 0;
	anode* p = NULL;
	w[u] = 0;
	rear = (rear + 1) % 20;
	qu[rear] = u;
	while (rear != front)
	{
		front = (front + 1) % 20;
		k = qu[front];
		p = g.ver[k].first;
		while (p)
		{
			if (w[p->adj] == 1)
			{
				cout << "(" << g.ver[k].data << "," << g.ver[p->adj].data << ")" << " ";
				w[p->adj] = 0;
				rear = (rear + 1) % 20;
				qu[rear] = p->adj;
			}
			p = p->next;
		}
	}

}
void DFS(def g, int u)  //������ȱ���
{
	int h;
	w[u] = 1;
	cout << g.ver[u].data << " ";
	for (h = firstnode(g, u); h >= 0; h = nextnode(g, u, h))
		if (!w[h])
			DFS(g, h);
}
void DFStree(def g, int u)   //���������ȱ������������ı߼�
{
	anode* p = NULL;
	w[u] = 0;
	p = g.ver[u].first;
	while (p)
	{
		if (w[p->adj] == 1)
		{
			cout << "(" << g.ver[u].data << "," << g.ver[p->adj].data << ")" << " ";
			DFStree(g, p->adj);
		}
		p = p->next;
	}
}
int main()
{
	int i, u;
	char r;
	for (i = 0; i < 10; i++)
		w[i] = 0;
	def g;
	cre(g);
	cout << "������ʼ�㣺" << endl;
	cin >> r;
	u = locate(g, r);
	cout << "������ȱ������У�" << endl;
	DFS(g, u);
	cout << endl << "������ȱ����������߼���" << endl;
	DFStree(g, u);
	cout << endl << "������ȱ������У�" << endl;
	BFS(g, u);
	cout << endl << "������ȱ����������߼���" << endl;
	BFStree(g, u);
	return 0;
}