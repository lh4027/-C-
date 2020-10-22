#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node<T> *next;
};

template<class T>
class LinkQueue
{
public:
	LinkQueue()
	{
		Node<T> *s = new Node<T>;     //����ͷ���
		s->next = NULL;          
		front = rear = s; //����ͷָ��Ͷ�βָ���ָ��ͷ���s
		
	}



	~LinkQueue()
	{

	}

	void EnQueue(T x)   //���
	{
		Node<T> *s = new Node<T>;   //�����½��
		s->data = x;            //������ݸ���x
		s->next = NULL;
		rear->next = s;      //�����S�嵽��β
		rear = s;       //��βָ��ָ��s��㣨����ƣ�
	}

	T Dequeue()
	{
		T x;
		if (rear == front)
		{
			cout << "����Ϊ��" << endl;
		}
		
		Node<T>* p = new Node<T>;
		p = front->next;
		x = p->data;           //�ݴ��ͷԪ��
		front->next = p->next;    //����ͷԪ�����ڽ��ժ��
		if (p->next == NULL)     //�жϳ���ǰ���г����Ƿ�Ϊ1
		{
			rear = front;
		}
		delete p;
		return x;
	}

private:
	Node<T> * front,*rear;
};


int main()
{
	LinkQueue<string> LQ;
	LQ.EnQueue("���1");
	LQ.EnQueue("���2");
	LQ.EnQueue("���3");
	LQ.EnQueue("���4");

	for (int i = 0; i <4; i++)
	{
		cout << LQ.Dequeue() << endl;
	}
	system("pause");
}
