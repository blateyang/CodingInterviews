#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//----------��������----------------
/*
1.���ܣ�n=1, 3, 6, 12
2.���棺n<1 
*/ 
int Range=6; //��һ��ȫ�ֱ����������ӵĿ��ܵ������ʹ�����ܾ�����չ�� 
void PrintProbability(int n)
{//˼·��ʹ�ö�̬�滮������������Ϊ6*n-n+1�Ļ�������arr1��arr2,��arr1�ĵ�k��Ԫ�ر�ʾ
//		��k�������͵�Ƶ����arr2��k��Ԫ�ر�ʾ����һ�����Ӻ��k�������͵�Ƶ����arr2[k-1]Ӧ
//		����arr1[k-1]+arr1[k-2]+arr1[k-3]+arr1[k-4]+arr1[k-5]+arr1[k-6]��˼������fibnacci����
	if(n < 1)
		return;
	int i, len = Range*n-n+1;	//���鳤�� 
	vector<int> arr1(len, 0), arr2(len, 0);
	for(i=0; i<Range; ++i)	//��ʼ״̬ 
		arr1[i] = 1;
	vector<int>::iterator p1, p2, tmp;
	p1 = arr1.begin();
	p2 = arr2.begin();
	for(int idx=2; idx<=n; ++idx)
	{
		//ÿ������ǰ6��Ԫ�ص�������
		p2[0] = p1[0];
		for(i=1; i<Range; ++i)
			p2[i] = p2[i-1] + p1[i];
		//��ʣ���Ԫ�ذ�������ʽ���� 
		for(i=Range; i<(Range-1)*idx+1; ++i)
//			p2[i] = p1[i] + p1[i-1] + p1[i-2] + p1[i-3] + p1[i-4] + p1[i-5];
		{
			p2[i] = p1[i];
			for(int j=1; j<Range; ++j)
				p2[i] += p1[i-j];
		}
		//����������
		tmp = p1;
		p1 = p2;
		p2 = tmp;	
	}
	//����������͵�Ƶ�� 
	for(i=0; i<len; ++i)
		cout<<p1[i]<<" ";
	cout<<endl;
	//����������͵ĸ���
	double total = pow(double(Range), n);
	for(i=0; i<len; ++i)
		cout<<double(p1[i])/total<<" ";
	cout<<endl;
 } 
 
int main()
{
	int n;
	while(cin>>n)
		PrintProbability(n);
//	vector<int> a{1, 2, 3};
//	vector<int> b{3, 2, 1};
//	vector<int>::iterator ita=a.begin(), itb=b.begin(), tmp;
//	tmp = ita;
//	ita = itb;
//	itb = tmp;
//	for(int i=0; i<3; ++i)
//		cout<<itb[i]<<" "<<endl;
	return 0;
}
