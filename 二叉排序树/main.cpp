#include<iostream>
#include"BiTree.h"
using namespace std;

//���������������㷨
void BiSortTree::InsertBST(BiNode<int> *&root, int key)  //�����ڵ�root�����õķ�ʽ����
{
	if (root == NULL)   
	{
		root = new BiNode<int>;
		root->data = key;
		root->lchild = NULL; root->rchild = NULL;
	}
	else
	{
		if (root->data > key)
			InsertBST(root->lchild, key);//�����������ݱȸ��ڵ������С���Ͳ嵽��������
		else if(root->data < key)
			InsertBST(root->rchild, key);//ͬ���෴
	}
}


//�������������캯��
BiSortTree::BiSortTree(int a[], int n)
{
	this->root = NULL;
	for (int i = 0; i < n; i++)//nΪ����Ľ����
	{
		InsertBST(this->root,a[i]);
	}
	InOrder(this->root); //��������鿴�Ƿ������ȷ
}

//���������������㷨
BiNode<int>* BiSortTree:: SearchBST(BiNode<int>* root, int k)//����ֵΪk�Ľ��
{
	if (root == NULL||root->data == k)
		return root;
    if (root->data > k)
		return SearchBST(root->lchild, k);
	else
		return SearchBST(root->rchild, k);
}
void BiSortTree::SearchBST(int k)
{
	if (SearchBST(root, k) != NULL)
	{
		cout << "����" << SearchBST(root, k)->data << "�ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}
}

//����������ɾ���㷨
void BiSortTree::DeleteNode(BiNode<int>*& p) //p��ɾ����㣬fΪ��˫�׽��
{
	BiNode<int>* q;
	BiNode<int>* s;
	if (p->rchild == NULL) //ֻ��������
	{
		q = p;
		p = p->lchild;
		delete q;
	}
	else if (p->lchild == NULL)//ֻ��������
	{
		q = p;
		p = p->rchild;
		delete q;
	}
	else //�����������У��ҳ�����ɾ�����������������Ľ�㣬������ֵ��������ɾ����㣬�ٽ���ɾ��
	{
		//Delete_Key_Node(p, p->lchild);
		q = p;
		s = p->lchild;
		while (s->rchild)   //��p���������м���������ǰ���ڵ㣬�������½��
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;//s��ֵ������ɾ�����p��Ȼ��ɾ��s���
		if (q != p)
			q->rchild = s->lchild;//�ؽ�q��������
		else
			q->lchild = s->lchild;//�ؽ�q��������
		delete s;
	}
}
void BiSortTree::DeleteBFS(int key)
{
	if (root == NULL) return;
	else
	{
		if (root->data == key)
			DeleteNode(root);
		else if (root->data > key)
			DeleteNode(root->lchild);
		else
			DeleteNode(root->rchild);
	}
	cout << "ɾ��" <<key << "�ɹ���" << endl;
	InOrder(root); //��������鿴�Ƿ�ɾ����ȷ

}

void test1()
{
	int a[10] = { 63,55,90,42,58,70,10,45,67,83 };
	BiSortTree BST(a, 10);
	cout << endl;
	BST.SearchBST(83);
	BST.DeleteBFS(63);
}

int main()
{
	test1();
	return 0;
	system("pause");
}