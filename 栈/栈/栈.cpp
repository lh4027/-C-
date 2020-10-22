#include<iostream>
using namespace std;

//��׺���ʽת��Ϊ��׺���ʽ��δ�ɹ���
class Node
{
public:
	int data;
	Node* next;
};

class LinkStack
{
public:
	LinkStack()
	{
		top = NULL;
		base = NULL;
	}
	void Push(char x)
	{
		/*if ((top - base) > StackSpace)
		{
			cout << "ջ������" << endl;
		}*/
		Node* s = new Node;
		s->data = x;
		s->next = top;
		top = s;
	}
	
	char Pop()
	{
		Node* p;
		char x;
		if (top == NULL)
		{
			cout << "ջΪ�գ�" << endl;
		}
		p = top;
		x = p->data;
		top = top->next;
		delete p;
		return x;
	}
	int IsEmpty()
	{
		if (top == NULL)
			return 1;
		else return 0;
	}

	const int StackSpace = 100;
private:
	Node * top = new Node;
	Node * base = new Node;
};

void test01()
{
	LinkStack LS;
	char c,e;

	cout << "�������׺���ʽ����#��Ϊ������־" << endl;
	cin >> c;
	while (c != '#')
	{
		if (c >= '0' && c <= '9')
		{
			cout << c << " ";
		}
		else if (')' == c)  //���������ſ�ʼ��ջ
		{
			e = LS.Pop();
			while ('(' != e)//��ջ֪������������
			{
				cout << LS.Pop() << " "; 
			}
		}
		else if ('+' == c || '-' == c)
		{
			if (LS.IsEmpty())
			{
				LS.Push(c);
			}
			else
			{
				do
				{
					e = LS.Pop();
					if ('(' == e)
					{
						LS.Push(e);
					}
					else
					{
						cout << e << " ";
					}
				} while (!LS.IsEmpty() && '(' == e);
				LS.Push(c);

			}
		}
		else if ('*' == c || '/' == c || '(' == c)
		{
			LS.Push(c);
		}
		else
		{
			cout << "�����ʽ����" << endl;

		}
	
		cin >> c;
	}
}

int main()
{
	
	test01();
	
}