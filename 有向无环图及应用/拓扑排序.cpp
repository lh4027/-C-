#include<iostream>
#include<vector>
#include"ALGraph.h"
using namespace std;

ALGraph::ALGraph(string a[],int b[], int n, int e)
{
	this->vertexNum = n;
	this->arcNum = e;
	for (int i = 0; i < this->vertexNum; i++)
	{
		this->adjlist[i].vertex = a[i];
		this->adjlist[i].firstedge = NULL;
		this->adjlist[i].in = b[i];
	}
	//���������
	
	int i1, i2,w;
	for (int i = 0; i < this->arcNum; i++)
	{
		cout << "����һ���������������������ţ�" << endl;
		cin >> i1 >> i2;
		cout << "������ߵ�Ȩֵ��" << endl;
		cin >> w;
		ArcNode* s = new ArcNode;
		s->weight = w;
		s->adjvex = i2;
		s->next = this->adjlist[i1].firstedge;
		this->adjlist[i1].firstedge = s;
	}

}
//���������㷨��ʱ�临�Ӷ�ΪO(n+e)
vector<int> ALGraph::TopSort(ALGraph G)
{
	vector<int> vec;
	//ջs��ʼ�����ۼ�����ʼ��
	int top = -1, count = 0;
	int S[Maxsize];
	int j,k;
	//ɨ�趥��������Ϊ0�Ķ�����ջ
	for (int i = 0; i < G.vertexNum; i++)
	{ 
		if (G.adjlist[i].in == 0)
		{
			S[++top]=i;
		}
	}
	//��ջ�ǿ�ʱѭ��
	while (top != -1)
	{
		//ջ��Ԫ�س�ջ��������㣬count�Լ�
		j = S[top--];
		cout << G.adjlist[j].vertex;
		vec.push_back(j);
		count++;
		
		//�Զ���j��ÿһ���ڽӵ�kִ���������
		ArcNode* p = G.adjlist[j].firstedge;
		while (p != NULL)//ɨ�趥����ҳ�����j �����г���
		{
			k = p->adjvex;
			G.adjlist[k].in--; //��ȼ�һ
			if (G.adjlist[k].in == 0) //������Ϊ0
			{
				S[++top] = k;   //������ջ
			}
			p = p->next;
		}
	}
	if (count < G.vertexNum)
	{
		cout << "�л�·��" << endl;
		return ;
	}
		
	return vec;

}


//int main()
//{
//	string v[6] = { "A","B","C","D","E","F" };
//	int b[6] = { 3,0,1,3,0,2 };
//	ALGraph AL(v, b, 6, 9);
//	AL.TopSort(AL);
//	system("pause");
//	return 0;
//}