#include <iostream>
using namespace std;

//------------测试用例---------------
/*
1.功能：行列数在10以内、行列数超过10
2.负面：行列数小于1
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
	if((i>=0 && i<rows) && (j>=0 && j<cols) && getSum(i)+getSum(j)<=threshold && !visited[i*cols+j]) //检查当前位置i,j是否可以被访问 
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
{//思路：类似Q66,也可以用回溯法，只不过要考虑的情况稍微多一些，包括位置是否越界
//		行列各数位和是否超过阈值、当前位置是否已访问过（题目的意思应该是走过的位置不可以再经过) 
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
