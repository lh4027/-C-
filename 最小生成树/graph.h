#pragma once
#include<iostream>
#include<string>

const int Maxsize = 20;

//�����ڽӾ���ͼ�ṹ
class MGraph
{
private:
	string vertex[Maxsize];  //��Ŷ������ݵ�����
	int arc[Maxsize][Maxsize];//���ͼ�ߵ�����
	int vertexNum;//ͼ�Ķ�����

public:
	
	MGraph()
	{
		
	}
	MGraph(string *v, int* a, int n);
	void Prim(MGraph G);

};

class EgdeArry
{
public:
	int lowcost;//��ѡ��̱�Ȩֵ
	int adjvex;//��ѡ��̱ߵ��ڽӵ�
};




