#pragma once
#include<iostream>
using namespace std;
const int Maxsize = 20;

class ArcNode //�߱�ڵ�
{
public:
	int adjvex;// �ڽӵ���
	ArcNode* next;//ָ����
	int weight;//Ȩֵ

};

class VertexNode // �������
{
public:
	string vertex;
	int in;//���
	ArcNode* firstedge;//�����ڽӵ���
	

};

class ALGraph
{
public:
	ALGraph(string a[],int b[], int n, int e);
	vector<int> TopSort(ALGraph G);
	void FindKeyPath(ALGraph G);

	

	
private:
	int vertexNum, arcNum;
	VertexNode adjlist[Maxsize];
};
