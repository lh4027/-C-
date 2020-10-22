#include<iostream>
using namespace std;


class DaulNode
{
public:
	string data;
	DaulNode* prior;//ǰ���ڵ�
	DaulNode* next;//��̽ڵ�
};

class DaulList
{
public:
	DaulList()
	{
		first = new DaulNode;
		first->next = NULL;
		first->prior = NULL;
	}

	DaulList(string a[], int n)//����˫����,β�巨
	{
		first = new DaulNode;    //����ͷ���ռ�
		DaulNode* p, * s;        //�����������
		first->next = NULL;
		first->prior = NULL;
		p = first;              //pָ��ͷ���

		for (int i = 0; i < n; i++)
		{
			s = new DaulNode;     //�����½��ռ�
			s->data = a[i];       //
			s->prior = p;
			s->next = p->next;
			p->next = s;

			p = s;//pָ��s��ʹ֮ѭ����������
		}
		//������������Ϊѭ��˫����
		p->next = first->next;   //�������ɺ�pָ�����һλ,p������ָ��first�����һλ���ɴ�ѭ��
		first->next->prior = p;//first�����һ����ǰ���ڵ�ָ�����һλp
	}

	void Print()
	{
		DaulNode* p=first->next;
		if (p == NULL)
		{
			cout << "empty" << endl;
		}
		while(p!=NULL)
		{
			cout << p->data << endl;
			p = p->next;
		}
	}

private:
	DaulNode* first;
};




int main()
{
	string a[3] = { "as","as","124" };
	DaulList DL(a, 3);
	DL.Print();
	system("pause");
	return 0;
}