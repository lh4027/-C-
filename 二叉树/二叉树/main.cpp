//#include<iostream>
//using namespace std;
//
//template <class T>
//class BiNode
//{
//public:
//	T data;
//	BiNode <T>* lchild=NULL, * rchild=NULL;
//};
//
//
//template <class T>
//class BiTree
//{
//public:
//	BiTree()
//	{
//		root = NULL;
//		root = Create(root);
//	}
//
//	~BiTree()
//	{
//		Release(root);
//	}
//	
//	void PreOrder()
//	{
//		PreOrder(root);
//	}
//
//	void InOrder()
//	{
//		InOrder(root);
//	}
//
//	void PostOrder()
//	{
//		PostOrder(root);
//	}
//	�������
//	void LeverOrder();
//	
//	
//
//private:
//	BiNode<T> * root;
//	
//	
//
//	���������캯��
//	BiNode<T>* Create(BiNode<T>* bt);
//	��������������
//	void Release(BiNode<T>* bt);
//
//	void PreOrder(BiNode<T>* bt);
//	�������������
//	void InOrder(BiNode<T>* bt);
//	�������������
//	void PostOrder(BiNode<T>* bt);
//	
//};
//
//template <class T>
//BiNode<T>* BiTree<T>::Create(BiNode<T>* bt)  //Լ���û�����ǰ�������ʽ�������ݣ���������������#����
//{
//	T ch;
//	cin >> ch;
//	if (ch == '#')
//	{
//		bt = NULL;	
//	}
//	else
//	{ 
//		bt = new BiNode<T>;  //����һ���½��
//		bt->data = ch;       //������
//		bt->lchild = Create(bt->lchild);  //�ݹ齨��������
//		bt->rchild = Create(bt->rchild);  //�ݹ齨��������
//		����bt�ǵ�ַ��btָ�����������������ĵ�ַ��*Create����bt��ַ
//	}
//	return bt;
//}
//
//���ú�������ͷŽ��
//template <class T>
//void BiTree<T>::Release(BiNode<T>* bt)
//{
//	if (bt != NULL)
//	{
//		Release(bt->lchild);
//		Release(bt->rchild);
//		delete bt;
//	}
//}
//
//������ǰ�����
//template <class T>
//void BiTree<T>::PreOrder(BiNode<T>* bt)
//{
//	if (bt != NULL)
//	{
//		cout << bt->data << " ";
//		PreOrder(bt->lchild);
//		PreOrder(bt->rchild);
//	}
//	else
//	{
//		return;
//	}
//}
//
//
//�������������
//template <class T>
//void BiTree<T>::InOrder(BiNode<T>* bt)
//{
//	if (bt != NULL)
//	{
//		InOrder(bt->lchild);
//		cout << bt->data << " ";
//		InOrder(bt->rchild);
//	}
//	else
//	{
//		return;
//	}
//}
//
//�������������
//template <class T>
//void BiTree<T>::PostOrder(BiNode<T>* bt)
//{
//	if (bt != NULL)
//	{
//		PostOrder(bt->lchild);
//		PostOrder(bt->rchild);
//		cout << bt->data << " ";
//	}
//	else
//	{
//		return;
//	}
//}
//
//�������������:�Ƚ����ڵ���ӣ��ٳ��ӷ���������������������������Ϊ��������ӣ�
//��˳������ڷ����������������Դ�ѭ��
//template <class T>
//void BiTree<T>::LeverOrder()
//{
//	int front = -1;
//	int rear = -1;  //����ͷβָ��
//	 ����һ������	
//	BiNode<T>* Q[100]; 
//	BiNode<T>* q;     //����һ��qָ�����ڽ��ս��ָ��
//
//	         
//	if (root != NULL)
//	{
//		Q[++rear] = root;    //ͷ��������
//	}
//	else return;
//	while (front != rear)
//	{
//		q = Q[++front];     //������
//		cout << q->data<<" ";    
//		if (q->lchild != NULL)
//		{
//			Q[++rear] = q->lchild;      //������������
//		}
//		if (q->rchild != NULL)
//		{
//			Q[++rear] = q->rchild; //������������
//		}
//	}
//}
//
//
//void test01()
//{
//	BiTree<char> BT;
//	cout << "ǰ�������";
//	BT.PreOrder();
//	cout << endl;
//	cout << "���������";
//	BT.InOrder();
//	cout << endl;
//	cout << "���������";
//	BT.PostOrder();
//	cout << endl;
//	cout << "���������";
//	BT.LeverOrder();
//	cout << endl;
//	
//}
//
//int main()
//{
//	test01();
//	system("pause");
//}