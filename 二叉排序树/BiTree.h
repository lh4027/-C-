#pragma once
#include<iostream>
using namespace std;

template<class T>
class BiNode
{
public:
	T data;
	BiNode<T>* lchild, * rchild;
};

//����������������
class BiSortTree
{
public:
	BiSortTree( int a[], int n);
	void InsertBST(BiNode<int> * &root, int key); //����һ�����
	void DeleteBFS(int key);//ɾ�����f������p

	BiNode<int>* SearchBST(BiNode<int>* root, int k);//����ֵΪk�Ľ��
	void SearchBST(int k);

private:
	BiNode<int>* root;  //�����������
	void InOrder(BiNode<int>* bt);
	void DeleteNode(BiNode<int>*& p);
	
};

void BiSortTree::InOrder(BiNode<int>* bt)  //�������������
{
	if (bt == NULL)return;
	else
	{
		InOrder(bt->lchild);
		cout << bt->data << " ";
		InOrder(bt->rchild);
	}
}