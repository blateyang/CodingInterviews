#include <iostream>
using namespace std;

//------------��������---------------
/*
1.���ܣ���������10���ڡ�����������10
2.���棺������С��1
*/ 
int getSum(int n)
{
	int sum = 0;
	while(n>0)
	{
		sum += n%10;
		n = n/10;
	}
	return sum;
}

int movingCountCore(int threshold, int rows, int cols, int i, int j, int *visited)
{
	int count = 0;
	if((i>=0 && i<rows) && (j>=0 && j<cols) && getSum(i)+getSum(j)<=threshold && !visited[i*cols+j]) //��鵱ǰλ��i,j�Ƿ���Ա����� 
	{
		visited[i*cols+j] = true;
		count = 1 + movingCountCore(threshold, rows, cols, i-1, j, visited)
				+ movingCountCore(threshold, rows, cols, i, j-1, visited)
				+ movingCountCore(threshold, rows, cols, i+1, j, visited)
				+ movingCountCore(threshold, rows, cols, i, j+1, visited);
	}	
	return count;
}

int movingCount(int threshold, int rows, int cols)
{//˼·������Q66,Ҳ�����û��ݷ���ֻ����Ҫ���ǵ������΢��һЩ������λ���Ƿ�Խ��
//		���и���λ���Ƿ񳬹���ֵ����ǰλ���Ƿ��ѷ��ʹ�����Ŀ����˼Ӧ�����߹���λ�ò������پ���) 
    if(rows<1 || cols<1)
    	return 0;
	int *visited = new int[rows*cols];
	for(int i=0; i<rows*cols; ++i)
		visited[i] = false;
	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
	delete []visited;
	return count; 
} 

int main()
{
	cout<<movingCountIter(10, 1, 100)<<endl;
	return 0;
}
