#include<iostream>
#include"HashList.h"
using namespace std;

void HashList::Insert(int k)
{
	int j;
	j = k % divitor;//����ɢ�е�ַ
	Node* p = ht[j].first;
	//ͷ�巨
	Node* q = new Node;
	q->m_data = k;
	q->next = ht[j].first;
	ht[j].first = q;
}

void HashList::CreatHT(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		Insert(a[i]);
	}
	for (int i = 0; i < Maxsize; i++)
	{
		Node* p = ht[i].first;
		while (p != NULL) 
		{
			cout << p->m_data << " ";
			p = p->next;
		}
	}
}

void HashList::Delete(int k)
{
	Node* p = HashSearch(k);
	if (p)
	{
		p->m_data = NULL;
		//delete p;
		cout << "ɾ���ɹ���" << endl;
	}
	else
		cout << "�����ڣ�ɾ��ʧ�ܣ�" << endl;

	//test
	for (int i = 0; i < Maxsize; i++)
	{
		Node* p = ht[i].first;
		while (p != NULL)
		{
			cout << p->m_data << " ";
			p = p->next;
		}
	}
}

//��ɢ�б�����㷨
Node *HashList::HashSearch(int value)
{
	int j;
	
	j = value % divitor;
	
	last = ht[j].first;
	Node* p = last;
	while (p != NULL)
	{
		if (p->m_data == value)
		{
			cout << "�鵽" << p->m_data << endl;
			return p; 
			break;
		}
		else
		{
			last = p;
			p = p->next;
			
		}
	}
	cout << "����ʧ�ܣ�" << endl;
	return 0;
}


void test()
{
	HashList HL(Maxsize,11);
	int a[9] = { 47,7,29,11,16,92,22,8,3 };
	HL.CreatHT(a, 9);
	HL.HashSearch(92);
	HL.Delete(92);
	
}

int main()
{
	test();
	system("pause");
	return 0;
}