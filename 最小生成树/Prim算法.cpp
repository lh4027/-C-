#include<iostream>
#include"graph.h"
using namespace std;

//
MGraph::MGraph(string* v, int* a, int n)
{
	
	this->vertexNum= n;
	//��ʼ��arc��űߵľ���
	for (int i = 0; i < Maxsize; i++)
		for (int j = 0; j < Maxsize; j++)
			arc[i][j] = 10000;
	//�洢������Ϣ
	for (int i = 0; i < vertexNum; i++)
		vertex[i] = v[i];
	//�洢�ߵ���Ϣ
	for (int i = 0; i < vertexNum; i++)
		for (int j = 0; j < vertexNum; j++)
			arc[i][j] = *(a + i * n + j);
}

int MinEdge(EgdeArry *shortedge, int n)
{
	int k = 0,min=shortedge[1].lowcost;
	for (int i = 1; i < n; i++)
	{
		if (shortedge[i].lowcost <= min)
		{
			k = i;
			min = shortedge[i].lowcost;
		}
	}
	return k;
}
//��С�������㷨

void MGraph::Prim(MGraph G)
{
	EgdeArry shortedge[Maxsize];//prim�㷨��������
	int k;//�ߵ�Ȩֵ��С�ĸ��������±�
	//��ʼ����������
	for (int i = 1; i < G.vertexNum; i++)
	{
		shortedge[i].lowcost = G.arc[0][i];
		shortedge[i].adjvex = 0;
	}
	//�������v0��������0���뼯��U
	shortedge[0].lowcost = 0;
	
	for (int i = 1; i < G.vertexNum; i++)
	{
		k = MinEdge(shortedge, G.vertexNum);  //Ѱ����̱ߵ��ڽӵ�k
		cout << k << " " << shortedge[k].adjvex << " " << shortedge[k].lowcost << endl; //���
		shortedge[k].lowcost = 0;//������k���뼯��U
		for (int j = 1; j < G.vertexNum; j++)        //��������shortedge
		{
			if (G.arc[k][j] < shortedge[j].lowcost)
			{
				shortedge[j].lowcost = G.arc[k][j];
				shortedge[j].adjvex = k;
			}
		}
	}
}

int main()
{
	int cost[6][6] = { {0,34,46,10000,10000,19},
					  {34,0,10000,10000,12,10000},
					  {46,10000,0,17,10000,25},
					  {10000,10000,17,0,38,25},
					  {10000,12,10000,38,0,26},
					  {19,10000,25,25,26,0} };
	string vname[6] = { "V0","V1","V2","V3","V4","V5" };
	int* p;
		p=&cost[0][0];

	
	MGraph MG(vname, p, 6);
	//cout << MG.arc[0][1];
	//Prim(MG);

	system("pause");
	return 0;
}

