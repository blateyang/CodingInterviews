#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//----------测试用例----------------
/*
1.功能：n=1, 3, 6, 12
2.负面：n<1 
*/ 
int Range=6; //用一个全局变量保存骰子的可能点数情况使程序能具有扩展性 
void PrintProbability(int n)
{//思路：使用动态规划，设置两个长为6*n-n+1的缓存数组arr1和arr2,若arr1的第k个元素表示
//		第k个点数和的频数，arr2第k个元素表示增加一个骰子后第k个点数和的频数，arr2[k-1]应
//		等于arr1[k-1]+arr1[k-2]+arr1[k-3]+arr1[k-4]+arr1[k-5]+arr1[k-6]，思想类似fibnacci数列
	if(n < 1)
		return;
	int i, len = Range*n-n+1;	//数组长度 
	vector<int> arr1(len, 0), arr2(len, 0);
	for(i=0; i<Range; ++i)	//初始状态 
		arr1[i] = 1;
	vector<int>::iterator p1, p2, tmp;
	p1 = arr1.begin();
	p2 = arr2.begin();
	for(int idx=2; idx<=n; ++idx)
	{
		//每次数组前6个元素单独处理
		p2[0] = p1[0];
		for(i=1; i<Range; ++i)
			p2[i] = p2[i-1] + p1[i];
		//对剩余的元素按迭代公式更新 
		for(i=Range; i<(Range-1)*idx+1; ++i)
//			p2[i] = p1[i] + p1[i-1] + p1[i-2] + p1[i-3] + p1[i-4] + p1[i-5];
		{
			p2[i] = p1[i];
			for(int j=1; j<Range; ++j)
				p2[i] += p1[i-j];
		}
		//交换两数组
		tmp = p1;
		p1 = p2;
		p2 = tmp;	
	}
	//输出各点数和的频数 
	for(i=0; i<len; ++i)
		cout<<p1[i]<<" ";
	cout<<endl;
	//输出各点数和的概率
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
