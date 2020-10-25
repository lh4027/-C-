//#include<iostream>
//
//using namespace std;
//
//const int MaxSize = 10;//�������ֵ
//const int StackSize = 100;//ջ�������
//
//
//
//template<class T>
//class MGraph
//{
//public:
//	MGraph(T a[], int n, int e)  //����ͼ���ڽӾ���
//	{
//		vertexNum = n;
//		this->arcNum = e;
//		int x,y;
//		for ( int i = 0; i < this->vertexNum; i++) //��ʼ���ڽӾ���
//		{
//			vertex[i] = a[i];
//			for (int j = 0; j < this->vertexNum; j++)
//				arc[i][j] = 0;
//		}	
//		for (int k = 0; k < arcNum; k++)      //����ÿһ����
//		{
//			cout << "����������ͼ�������Ӷ����ţ�";
//			cin >> x >> y;
//			arc[x][y] = 1;                      //�ñ߱�־
//			arc[y][x] = 1;
//		}
//	}
//
//	~MGraph()
//	{
//
//	}
//	//������ȱ����㷨
//	void DFSTraverse(int v)
//	{
//		
//		cout << vertex[v];
//		//visited[v] = 1;
//		for (int j = 0; j < this->vertexNum; j++)
//		{
//			if (arc[v][j] == 1 && visited[j] != 1)
//				DFSTraverse(j);
//		}
//		
//	}
//
//	void BFSTraverse(int v)
//	{
//		int front = -1;
//		int rear = -1;  //��ʼ������
//		int Q[MaxSize];
//		int* visited = new int;
//
//		cout << vertex[v];   //��ӡ����v
//
//		visited[v] = 1;    //
//		Q[++rear] = v;    //����v���
//		while (front != rear)  //���зǿ�ʱ
//		{
//			v = Q[++front];     //���Ӷ�ͷԪ�س��Ӳ��͵�v
//			for (int i = 0; i < this->vertexNum; i++)
//			{
//				if (this->arc[v][i] == 1 && visited[i] != 1)
//				{
//					cout << this->vertex[i]<<" ";
//					visited[i] = 1;
//					Q[++rear] = i;
//				}
//			}
//		}
//		
//	}
//
//private:
//	T vertex[MaxSize];//���ͼ�ж�����Ϣ������
//	int arc[MaxSize][MaxSize];//��űߵ�����
//	int vertexNum, arcNum;//ͼ�Ķ������ͱ���
//	int visited[MaxSize];//
//	
//};
//
//
//
//int main()
//{
//	string a[] = { "lh","zhf","shz","cxk"};
//	MGraph<string> MG(a,4,4);
//	MG.BFSTraverse(0);
//	MG.DFSTraverse(0);
//	
//
//}
