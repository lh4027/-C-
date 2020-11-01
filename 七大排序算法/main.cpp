#include<iostream>
using namespace std;


//ֱ�Ӳ��������㷨(ʱ�临�Ӷ�ΪO(n^2)�ȶ�������)
void StraightInsertSort(int r[], int n)
{
	int i, j;
	for ( i = 2; i <= n; i++)
	{
		r[0] = r[i];                        //0�ŵ�Ԫ�����ݴ浥Ԫ�ͼ��Ӹ�
		for ( j = i - 1; r[0] < r[j]; j--)  //Ѱ�Ҳ���λ��
			r[j + 1] = r[j];                //��¼����
		r[j+1] = r[0];
	}
}

//ϣ������(��ֱ�Ӳ�������ĸĽ���ʱ�临�Ӷ���O(n^2)��O(log2(n))֮�䣬�ǲ��ȶ�������
void ShellSort(int r[], int n)
{
	int i, j, d;
	for (d = n / 2; d >= 1; d = d / 2)  //������Ϊd��������Ĳ�������
	{
		for (i = d + 1; i <= n; i++)
		{
			r[0] = r[i];
			for (j = i - d; j > 0 && r[0] < r[j]; j = j - d)
				r[j + d] = r[j];
			r[j + d] = r[0];
		}
	}
}

//ð�ݷ�����(ʱ�临�Ӷ�ΪO(n^2)�ȶ�������)
void BubbleSort(int r[], int n)
{
	int i, j,temp;
	bool flag = true;
	i = n-1;
	while (i > 0 && flag)
	{
		flag = false;
		for (j = 0; j < i; j++)
		{
			if (r[j] > r[j + 1])
			{
				flag = true;
				temp = r[j + 1];
				r[j + 1] = r[j];
				r[j] = temp;
			}
		}
		i--;
	}
}

/*    ���������㷨(��ð���㷨�ĸĽ�)  
/*    ʱ�临�Ӷ�O(nlog2(n))
/*    ���ȶ�������                      
*/
//��������һ�λ����㷨
int Partition(int r[], int first,int end)  
{
	int temp;
	int i = first,j = end,pivot=r[first];
	while (i < j)
	{
		while (i < j && r[j]>=pivot)  //���ɨ��
			j--;
		if (i < j)
		{
			swap(r[i], r[j]);    //����С��¼������ǰ��
			i++;
		}

		while (i < j && r[i] <= pivot)
			i++;
		if (i < j)
		{
			swap(r[i], r[j]);//���ϴ��¼����������
			j--;
		}
	}
	return i;  //iΪ��ֵ��¼������λ��
}
void QuickSort(int r[], int first, int end)
{
	int pivot;
	if (first < end)
	{
		pivot = Partition(r, first, end);
		QuickSort(r, first, pivot-1);
		QuickSort(r, pivot + 1, end);
	}
}


/*     ��ѡ������
/*     ʱ�临�Ӷ�O(n^2)
/*     ���ȶ�
*/ 
void SelectSort(int r[], int n)  
{
	int i, j, index;
	for (i = 0; i < n; i++)
	{
		index = i;
		for (j = i + 1; j < n; j++)
			if (r[j] < r[index])
				index = j;
		if (index != i)
			swap(r[i], r[index]);
	}
}

/*     �������㷨
/*    ʱ�临�Ӷ�O(nlog2(n))
/*    ���ȶ�������  
*/
//ɸѡ��������
void Sift(int r[], int k, int n)//kΪ�������λ�ã�nΪ���д�С
{
	int i = k, j = 2 * k;//iΪ���ڵ�λ�ã�j=2*k��i�������λ��
	while (j <= n)   //��������ӣ�k������Ϊ2*k,�Һ���Ϊ2*k+1
	{
		if (j < n && r[j] < r[j + 1]) //������Һ��ӣ������ӱ��Һ���С
			j++;//jָ���Һ���
		if (r[i] > r[j]) //������ڵ�������Һ��ӣ�������ѣ�����
			break;
		else
			swap(r[i], r[j]);//��ϴ�ĺ��ӽ���
		i = j;  //iָ�򽻻����µ�λ�ã��������±Ƚϣ�һֱ�³���Ҷ�ӽ��
		j = 2 * i;//����j
	}
}
//������
void HeapSort(int r[], int n)  //0�ŵ�Ԫ���������������ݴ浥Ԫ
{
	//��ʼ���ѣ������һ����֧���n/2�����ڵ�
	for (int i = n / 2; i >= 1; i--)
		Sift(r, i, n);

	//�����ظ�ִ�����߶Ѷ������ؽ���
	for (int i = 1; i < n; i++)
	{
		swap(r[1], r[n - i + 1]);
		Sift(r, 1, n - i);
	}
}

/*     �鲢����ݹ��㷨
/*
/*
*/

void Merge(int r[], int low, int mid, int high)
{
	int* s = new int[high - low + 1];//����һ����������
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high)
	{
		if (r[i] <= r[j])   //���մ�С����˳���ŵ�����������
			s[k++] = r[i++];
		else
			s[k++] = r[j++];
	}
	while (i <= mid)
		s[k++] = r[i++];   //��������r[low:middle]ʣ������δ���
	while (j <= high)
		s[k++] = r[j++];   //��������r[middle+1:high]ʣ������δ���
	for (i = low, k = 0; i <= high; i++, k++)
		r[i] = s[k];      //����������ת�Ƶ�ԭʼ������
	delete[]s;//�ͷŸ�������
}
void MergeSort(int r[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(r, low, mid);
		MergeSort(r, mid + 1, high);
		Merge(r, low, mid, high);
	}
}

void test01()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	StraightInsertSort(a, 20);
	cout << "ֱ�Ӳ��뷨��������" << endl;
	for (int i = 1; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test02()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	ShellSort(a, 20);
	cout << "ϣ����������" << endl;
	for (int i = 1; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}

void test03()  
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	BubbleSort(a, 21);
	cout << "ð����������" << endl;
	for (int i = 0; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test04()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	QuickSort(a, 0,20);
	cout << "������������" << endl;
	for (int i = 0; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test05()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	SelectSort(a, 21);
	cout << "��ѡ����������" << endl;
	for (int i = 0; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test06()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	HeapSort(a,20);
	cout << "����������" << endl;
	for (int i = 0; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test07()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	MergeSort(a, 0, 20);
	cout << "�鲢�ݹ���������" << endl;
	for (int i = 0; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	system("pause");
	return 0;

}