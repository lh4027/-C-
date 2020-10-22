#include<iostream>
using namespace std;

const int MaxSize = 100;
//����߱���
class ArcNode
{
public:
	int adjvex;//�ڽӵ���
	ArcNode* next;//ָ����ָ��߱���һ�����
	int info;//�ߵ�Ȩֵ
};

template<class T>
class VertexNode   //���嶥�����
{
public:

	T vertex;     //����������
	ArcNode* firstedge;  //����ָ����ָ��߱��һ�����
};

template<class T>
class ALGraph     //�ڽӱ��캯��
{
public:
	ALGraph( int n, int e);
	~ALGraph()
	{

	}
	void DFSTraverse(int v);
	void BFSTraverse(int v);
private:
	VertexNode<T> adjlist[MaxSize];//��Ŷ���������
	int vertexNum, arcNum;//ͼ�Ķ�����������
	//int visited[MaxSize];
};

template<class T>
ALGraph<T>::ALGraph(int n, int e)
{
	//���붥����Ϣ����ʼ�������
	vertexNum = n;
	arcNum = e;
	int b1=0, b2=0, b_flag=0;//�ݴ涥����
	
	for (int i = 0;i < n; i++)
	{
		cout << "�����붥���ֵ��" << endl;
		cin>>adjlist[i].vertex ;
		adjlist[i].firstedge = NULL;
	}
	//����ÿһ���ߣ�������ͷ�巨�����±߱���β�巨���У�
	for (int i = 0; i < arcNum; i++)
	{
		ArcNode* s = new ArcNode;
		
		cout << "����������������������������ţ�";
		cin >> b1 >> b2 ;
		s->adjvex = b2;
		cout << "����������������Ӧ��Ȩֵ��";
		cin >> s->info;
		s->next = adjlist[b1].firstedge;
		adjlist[b1].firstedge = s;

	}
}

template<class T>
void ALGraph<T>::DFSTraverse(int v)
{
	int visited[MaxSize];
	cout << "����:" << adjlist[v].vertex << " ";
	visited[v] = 1;
	ArcNode* p = adjlist[v].firstedge;
	while (p != NULL)
	{
		if (visited[p->adjvex] != 1)
			DFSTraverse(p->adjvex);
		p = p->next; 
		
	}
}
template<class T>
void ALGraph<T>::BFSTraverse(int v)
{
	//��ʼ������
	int front = -1, rear = -1;
	int Q[MaxSize];
	int visited[MaxSize];
	cout << "���㣺" << adjlist[v].vertex << " ";
	 visited[v] = 1;
	Q[++rear] = v;
	
	while (front != rear)
	{
		v = Q[++front];
		ArcNode* s = adjlist[v].firstedge;
		while (s != NULL)
		{
			if (visited[s->adjvex] != 1)
			{
				cout << adjlist[s->adjvex].vertex<<" ";
				visited[s->adjvex] = 1;
				Q[++rear] = s->adjvex;
			}
			s = s->next;
		}
	}
}
int main()
{
	string a[] = { "lh","zhf","shz","cxk" };
	ALGraph<string> AL(4,4);
	AL.DFSTraverse(0);
	AL.BFSTraverse(0);
	system("pause");
}