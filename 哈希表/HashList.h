#pragma once
#define Maxsize 20
//����߱�����
class Node
{
public:
	int m_data;//������
	Node* next;//ָ����
};
//���嵥��������Ϊ��ɢ�б�
class hashlist
{
public:
	Node *first;
};

class HashList
{
public:
	void CreatHT(int a[], int n);  //����һ����ϣ��
	void Insert(int k);   //��ϣ������㷨
	void Delete(int k);//��ϣ��ɾ���㷨
	Node * HashSearch(int value);  //��ϣ������㷨
	HashList(int size, int d)
	{
		ht = new hashlist [size];
		divitor = d;
		for (int i = 0; i < size; i++)
		{
			ht[i].first= NULL;
		}
	}
private:
	hashlist *ht;
	int divitor;
	Node* last;//���ڼ�¼��Ҫɾ��������һ�����λ��
};
