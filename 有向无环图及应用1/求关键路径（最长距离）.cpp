#include<iostream>
#include<vector>
#include"ALGraph.h"
using namespace std;

void ALGraph::FindKeyPath(ALGraph G)
{
	vector<int> topo;
	int ve[Maxsize];//�¼����緢��ʱ�䣨��Դ�㿪ʼ��������߼���ȡ���ֵ������
	int vl[Maxsize];//�¼�������ʱ�䣨���յ㿪ʼ����������������
	int ee;//����翪ʼʱ��
	int el;//�����ʼʱ��
	topo = G.TopSort(G);//���Ƚ�����������������������
	//test
	/*for (vector<int>::iterator it = topo.begin(); it != topo.end(); it++)
	{
		cout << (*it) << " ";
	}*/
	//��ʼ���¼������緢��ʱ��
	for (int i = 0; i < G.vertexNum; i++)
	{
		ve[i] = 0;
	}
	int j,k;
	//�����¼����緢��ʱ��
	for (vector<int>::iterator it = topo.begin(); it != topo.end(); it++) 
	{
		k = (*it);         //ȡ���������еĶ���
		ArcNode* p = G.adjlist[k].firstedge;
		while (p != NULL)
		{
			j = p->adjvex;  
			if (ve[k] + p->weight > ve[j])      
			{
				ve[j] = ve[k] + p->weight;     //���¶���j�����緢��ʱ��
			}
			p = p->next;
		}
	}
	//test
	/*for (int i = 0; i < G.vertexNum; i++)
	{
		cout << ve[i] << " ";
	}*/
	//�����¼�����ٷ���ʱ��  
	for (int i = 0; i < G.vertexNum; i++)
	{
		vl[i] = ve[G.vertexNum-1];        //��ÿ���¼�����ٷ���ʱ���ʼ��Ϊ�������緢��ʱ��
	}
	for (vector<int>::reverse_iterator it = topo.rbegin(); it != topo.rend(); it++)
	{
		k = (*it);         //ȡ���������еĶ���k
		ArcNode* p = G.adjlist[k].firstedge;
		//������ٷ���ʱ����������緢��ʱ��
		while (p != NULL)
		{
			j = p->adjvex;
			if (vl[k]>vl[j]-p->weight)
			{
				vl[k] = vl[j] - p->weight;     //���¶���j����ٷ���ʱ��
			}
			p = p->next;
		}
	}
	//test
	/*for (int i = 0; i < G.vertexNum; i++)
	{
		cout << vl[i] << " ";
	}*/

	//�ж�ÿһ�λ�Ƿ�Ϊ�ؼ��
	cout << "�ؼ��·��Ϊ��";
	for (int i = 0; i < G.vertexNum; i++)
	{
		ArcNode* p = G.adjlist[i].firstedge;
		while (p != NULL)
		{
			j = p->adjvex;
			ee = ve[i];
			el = vl[j] - p->weight;
			if (ee == el)
				cout << G.adjlist[i].vertex << "->" << G.adjlist[j].vertex << " ";
			p = p->next;
		}
	}
	cout << endl;
	cout << "�·������Ϊ��" << ve[G.vertexNum - 1];
}

void test()
{
	string v[9] = { "V0","V1","V2","V3","V4","V5","V6","V7","V8" };
	int b[11] = { 0,1,1,1,2,1,1,1,2 };
	ALGraph AL(v, b, 9, 11);
	AL.FindKeyPath(AL);
}

int main()
{
	test();
	system("pause");
	return 0;
}