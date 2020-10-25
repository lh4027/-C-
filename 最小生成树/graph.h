#pragma once
#include<iostream>
#include<string.h>
using namespace std;
const int Maxsize = 20;
const int MaxEdge = 50;

class EgdeArry      //prim�㷨��������
{
public:
	int lowcost;//��ѡ��̱�Ȩֵ
	int adjvex;//��ѡ��̱ߵ��ڽӵ�
};
//prim�㷨ʹ���ڽӾ���ͼ�ṹ
class MGraph
{
private:
	string vertex1[Maxsize];  //��Ŷ������ݵ�����
	int arc[Maxsize][Maxsize];//���ͼ�ߵ�����
	int vertexNum1;//ͼ�Ķ�����

public:
	
	
	MGraph(string * v, int* a, int n);
	void Prim(MGraph G);

};

class Edgetype   //kruskal�㷨�ĸ�������
{
public:
	int from, to;//����������������
	int weight;//�ߵ�Ȩֵ

};
//kruskal�㷨ʹ�ñ߼�����洢�ṹ
class EdgeGraph
{
public:
	EdgeGraph(string *v ,int n,int e);  //�߼�����ṹ���캯��
	void Kruskal(EdgeGraph G);

private:
	string vertex2[Maxsize];//��������
	Edgetype edge[MaxEdge];//�߼�����
	int vertexNum2, edgeNum;//������������
};






