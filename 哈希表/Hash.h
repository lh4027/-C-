//#pragma once
//enum kind{Active,Empty,Deleted};
//
//#define Maxsize (int)20 
//class HashTable
//{
//public:
//
//	void CreatHT(int a[],int n);  //����һ����ϣ��
//	void Insert(int k);   //��ϣ������㷨
//	void Delete(int k);//��ϣ��ɾ���㷨
//	int HashSearch(int value);  //��ϣ������㷨
//
//	
//	HashTable(int size,int d,int m)
//	{
//		info = new kind[size];  
//		ht = new int[size];
//		Compare_Num = new int[size];
//		divitor = d;
//		this->m = m;
//
//		for (int i = 0; i < Maxsize; i++)
//		{
//			info[i] = Empty;
//			ht[i] = 0;
//			Compare_Num[i] = 0;
//		}
//	}
//	~HashTable()
//	{
//		delete[] info;
//		delete[] ht;
//		delete[] Compare_Num;
//	}
//
//private:
//	kind *info;      //��¼��ϣ��ÿ��λ��״̬������
//	int *ht;         //��ϣ��
//	int *Compare_Num; //��¼�Ƚϴ���������
//	int divitor;//k%divitor,�������෨ȡ��ϵ��
//	int m;//̽�����ʼ�±꣬һ��Ϊ��ϣ����
//};
