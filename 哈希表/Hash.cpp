//#include<iostream>
//#include"Hash.h"
//using namespace std;
//
//
///**************************************************/
///*���ƣ���ɢ�б�*/
//
//void HashTable::CreatHT(int a[],int n)
//{
//
//	for (int i = 0; i < n; i++)
//	{
//		Insert(a[i]);
//	}
//	//test
//	for (int i = 0; i < Maxsize; i++)
//		cout << ht[i] << " ";
//	cout << endl;
//	for (int i = 0; i < Maxsize; i++)
//		cout << info[i] << " ";
//	cout << endl;
//}
//
//void HashTable::Insert(int k)
//{
//	int i, j;
//	j = k % divitor;
//
//	if (info[j] !=Active)
//	{
//		ht[j] = k; info[j] = Active;
//	}	
//	else
//	{
//		i = (j + 1) % m;
//		do
//		{
//			if (info[i] != Active)
//			{
//				ht[i] = k; info[i] = Active; break;
//			}
//			else
//				i = (i + 1) % m;
//		} while (i != j);
//	}
//	for (int i = 0; i < Maxsize; i++)
//		cout << ht[i] << " ";
//	cout << endl;
//	for (int i = 0; i < Maxsize; i++)
//		cout << info[i] << " ";
//	cout << endl;
//}
//void HashTable::Delete(int k)
//{
//	int i;
//	i = HashSearch(k);
//	if ( i!= false)
//	{
//		info[i] = Deleted;
//		ht[i] = 0;
//		cout << "ɾ���ɹ���" << endl;
//	}
//	else
//		cout << "δ�ҵ���ɾ��ʧ�ܣ�" << endl;
//	//test
//	for (int i = 0; i < Maxsize; i++)
//		cout << ht[i] << " ";
//	cout << endl;
//	for (int i = 0; i < Maxsize; i++)
//		cout << info[i] << " ";
//	cout << endl;
//}
//
////ɢ�б�����㷨
///*           ����̽�ⷨ               */
//int HashTable::HashSearch(int value)
//{
//	int i,j;
//	j = value % divitor;
//	if (ht[j] == value && info[j] == Active)
//	{
//		return j;
//	}	
//	else if (info[j] == Empty)
//	{
//		return false;
//	}
//	i = (j + 1) % m;
//	do
//	{
//		if (info[i] == Active && ht[i] == value)
//		{
//			return i;
//			break;
//		}
//		i = (i + 1) % m;
//		if (i == j)
//			return false;
//	} while (i != j);
//	
//}
//
////void test()
////{
////	HashTable HT(Maxsize, 11, Maxsize);
////	int a[9] = { 47,7,29,11,16,92,22,8,3 };
////	HT.CreatHT(a,9);
////	if (HT.HashSearch(92)!=false)
////	{
////		cout << "���ҳɹ���" << " λ�ã�" << HT.HashSearch(92) << endl;
////	}
////	else
////		cout << "����ʧ�ܣ�" << endl;
////	cout << endl;
////	HT.Delete(92);
////	cout << endl;
////}
////
////int main()
////{
////	test();
////	system("pause");
////	return 0;
////}