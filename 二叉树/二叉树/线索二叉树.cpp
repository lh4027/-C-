//#include<iostream>
//using namespace std;
//
//enum flag {Child,Thread};  //ö�����ͣ�ö�ٳ���Child=0,Thread=1
//template<class T>
//class ThrNode
//{
//public:
//	T data;
//	ThrNode<T>* lchild, * rchild;
//	bool ltag=0, rtag=0;
//};
//
//template<class T>
//class InThrBiTree
//{
//public:
//	InThrBiTree();//�������������캯��
//	~InThrBiTree();
//	ThrNode<T>* Next(ThrNode<T>* p);//���ҽ��p�ĺ��
//	void InOrder();  //���������������
//
//
//	ThrNode<T>* Create(ThrNode<T>* bt);//���캯������
//	void ThrBiTree(ThrNode<T>* bt, ThrNode<T>* pre);
//
//	ThrNode<T>* root;   //ָ�����������ͷָ��
//
//	
//};
//
//template<class T>
//ThrNode<T>* InThrBiTree<T>::Create(ThrNode<T>* bt)
//{
//	T ch;
//	cin >> ch;
//	if (ch == '#')
//	{
//		bt = NULL;
//	}
//	else
//	{
//		bt = new ThrNode<T>;  //����һ���½��
//		bt->data = ch;       //������
//		bt->ltag = 0; bt->rtag = 0;//���ұ�־����0
//		bt->lchild = Create(bt->lchild);  //�ݹ齨��������
//		bt->rchild = Create(bt->rchild);  //�ݹ齨��������
//		//����bt�ǵ�ַ��btָ�����������������ĵ�ַ��*Create����bt��ַ
//	}
//	return bt;
//}
//
//template<class T>
//InThrBiTree<T>::InThrBiTree()
//{
//	root = Create(root); //�����������Ķ�������
//	ThrNode<T> *pre = NULL;//��ǰ���ʽڵ��ǰ���ڵ�pre��ʼ��ΪNULL
//	ThrBiTree(root, pre);//��������������������
//
//}
//
//template<class T>
//void InThrBiTree<T>::ThrBiTree(ThrNode<T>* bt, ThrNode<T>* pre)
//{
//	if (bt == NULL)
//		return;
//	
//	ThrBiTree(bt->lchild, pre);//��bt����������������
//	if (bt->lchild == NULL)   //�����ǰ����������Ϊ��
//	{
//		bt->ltag = 1;         //���־��Ϊ1
//		bt->lchild = pre;     //��ǰ����������ָ��ָ��ǰ�����
//	}
//	if (bt->rchild == NULL) //�����ǰ����������Ϊ��
//		bt->rtag = 1;       //�ұ�־��1������Ҫָ��ĺ�̽�㻹δ���ʵ�����ʱ�������������ȵ��´�
//	if (pre->rtag == 1)     //���ǰ������ұ�־Ϊ1
//		pre->rchild = bt;    //pre���ָ���̽�㣬Ҳ���ǵ�ǰbt���
//
//	pre = bt;              //����ǰ�����pre
//	ThrBiTree(bt->rchild, pre);//��bt����������������
//}
//
//
//template<class T>
//ThrNode<T>* InThrBiTree<T>::Next(ThrNode<T>* p)
//{
//	ThrNode<T>* q;
//	if (p->rtag == 1)
//	{
//		q = p->rchild;
//	}
//	else
//	{
//		q = p->rchild;
//		while (q->rtag == 0)
//		{
//			q = q->lchild;
//		}
//	}
//	return q;
//}
//
//template<class T>
//void InThrBiTree<T>::InOrder()
//{
//	ThrNode<T>* p;
//	if (root = NULL)
//	{
//		return;
//	}
//	p = root;
//	while (p->ltag == 0)
//	{
//		p = p->lchild;
//	}
//	cout << p->data << " ";
//	while (p->rchild != NULL)
//	{
//		p = Next(p);
//		cout << p->data << " ";
//	}
//}
//
//
//
//
//int main()
//{
//	InThrBiTree<string> InBitree;
//	InBitree.InOrder();
//
//	system("pause");
//
//}