//#include<iostream>
//
//using namespace std;
//
////���е�˳��洢�ṹ
//const int QueueSize = 5;
//template<class T>
//class CirQueue
//{
//public:
//	CirQueue()
//	{
//		front = rear = QueueSize - 1;
//	}
//
//	void EnQueue(T x)//���
//	{
//		if ((rear + 1) % QueueSize == front)
//		{
//			cout << "��������,���ʧ�ܣ�" << endl;
//			IsFull = true;
//			
//		}
//		else
//		{	
//			rear = (rear + 1) % QueueSize;//��βָ����ѭ�������¼�1
//			data[rear] = x;	
//			IsFull = false;
//		}
//	}
//	T DeQueue()//����
//	{
//		if (front  == rear)
//		{
//			cout << "�����ѿգ�" << endl;
//			
//			IsEmpty = true;
//			
//		}
//		front = (front + 1) % QueueSize;
//		return data[front];
//		
//		
//		IsEmpty = false;
//		
//	}
//
//
//	~CirQueue()
//	{
//
//	}
//
//	bool IsEmpty = 0;
//	bool IsFull = 0;
//private:
//	string data[QueueSize];//��Ŷ���Ԫ������
//	int front, rear;    //��ͷ�Ͷ�βָ��
//
//};
//
//
//void Test01()
//{
//
//	CirQueue<string> CQ;
//	string str;
//	cout << "��������ӵ�Ԫ�أ�" << endl;
//	while (cin >> str)
//	{
//		CQ.EnQueue(str);
//		if (CQ.IsFull)break;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << CQ.DeQueue() << endl;
//
//	}
//	//cout << CQ.DeQueue() << endl;
//
//
//}
//
//int main()
//{
//	Test01();
//	system("pause");
//}