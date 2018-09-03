#include <iostream>
#include <ctime>
using namespace std;

//----------쳲��������е�����ʵ��------------------- 
int FibnacciRecursive(int n) //nΪ�Ǹ����� 
{// �ݹ�棬O(2^n)
	return (n<2) ? n : FibnacciRecursive(n-1) + FibnacciRecursive(n-2); 
}

int fib_tail(int n, int f, int g) 
{//β�ݹ飨���Եݹ飩,����ʱf,g��Ҫ�ֱ𸳳�ֵ0,1 ,O(n)
	if(n<1)	//�ݹ�� 
		return f;
	return fib_tail(n-1, g, f+g);
}

int FibnacciIterative(int n)
{// �����棬O(n)
	int preNum = 0, postNum = 1;
	while(n-->0)
	{
		postNum = preNum + postNum;
		preNum = postNum - preNum; 
	} 
	return preNum;	 
}

//---------------쳲��������е�Ӧ��-------------------
int jumpFloorII(int number) 
	{//��̬��̨�� 
        if(number<1)
            return 0;
        //�ݹ�棬fibN(n) = fibN(n-1)+fibN(n-2)+...+fib(1)+1=2^n, n>1 
//        int result = 1;
//        while(number-->1)
//            result += jumpFloorII(number);
//        return result;
		//�����棨���ݵ�����ʽ�����ͨ�ʽ��2^n�� 
		int result = 1;
		for(int i=1; i<number; ++i)
			result *= 2;
		return result;
    } 

int (*matMul(int (*arr1)[2], int (*arr2)[2]))[2] //�������ص���ָ�������ָ�� 
{
	int (*arr)[2] = new int[2][2];
	for(int i=0; i<2; ++i)
		for(int j=0; j<2; ++j)
			arr[i][j] = arr1[i][0] * arr2[0][j] + arr1[i][1] * arr2[1][j];
	return arr;
}

int (*matPow(int (*arr)[2], int n))[2]
{
	if(n == 1)
		return arr;
	if(n == 2)
		return matMul(arr, arr);
	if(n%2==0) //nΪ����2��ż�� 
	{
		int (*arr_tmp)[2] = matPow(arr, n/2);
		return matMul(arr_tmp, arr_tmp);
	}
	else	//nΪ����1������ 
	{
		int (*arr_tmp)[2] = matPow(arr, (n-1)/2);
		int arr0[][2] = {1,1,1,0};
		return matMul(matMul(arr_tmp, arr_tmp), arr0);
	}
}

int FibnacciMatPow(int n)
{//���ý�ָoffer�ϵ���ѧ��ʽʵ�֣�O(logn) 
	if(n<2) return n;
	int arr_in[][2]={1,1,1,0};
	int (*arr)[2];
	arr = matPow(arr_in, n-2); //arr[0]={fib(n-1),fib(n-2)}
	return arr[0][0]+arr[0][1];
}

int main()
{
	int n;
	while(cin>>n) // test input:45 
	{
		clock_t t_start;
		t_start = clock();
//		cout<<FibnacciRecursive(n)<<endl;
//		cout<<"fib_binary time:"<<(double)(clock()-t_start)/CLOCKS_PER_SEC<<endl;
//		cout<<FibnacciMatPow(n)<<endl;
//		cout<<"fib_mat_pow time:"<<(double)(clock()-t_start)/CLOCKS_PER_SEC<<endl;		
		
		t_start = clock();
		cout<<fib_tail(n, 0, 1)<<endl;
		cout<<"fib_tail time:"<<(double)(clock()-t_start)/CLOCKS_PER_SEC<<endl;
		
		t_start = clock();
		cout<<FibnacciIterative(n)<<endl;
		cout<<"fib_iter time:"<<(double)(clock()-t_start)/CLOCKS_PER_SEC<<endl;
	}

/* 
	//����matPow()
	int arr_in[][2]={1,1,1,0};
	int (*arr)[2];
	arr = matPow(arr_in, 5);
	for(int i=0; i<2; ++i)
		{
			for(int j=0; j<2; ++j)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}
*/		
	return 0;
}
