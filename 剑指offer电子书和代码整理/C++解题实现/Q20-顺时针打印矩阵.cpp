#include <iostream>
#include <vector>
using namespace std;

//-------------测试用例---------------
/*
1.功能测试：矩阵有多行多列；仅有一行多列；仅有一列多行；仅有一行一列
2.负面测试：矩阵是空矩阵 
*/ 
void printMatrixInCircle(vector<vector<int> > const &matrix, int start, vector<int> &clock_wise)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
	int endY = rows-1-start;
	int endX = cols-1-start;
	//从左到右打印一行 
	for(int i=start; i<=endX; ++i)
		clock_wise.push_back(matrix[start][i]);
	//从上到下打印一列 
	if(endY > start)
	{
		for(int i=start+1; i<=endY; ++i)
			clock_wise.push_back(matrix[i][endX]);
	}
	//从右到左打印一行 
	if(endX > start && endY > start)
	{
		for(int i=endX-1; i>=start; --i)
			clock_wise.push_back(matrix[endY][i]);
	}
	//从下到上打印一列 
	if(endX > start && endY > start+1)
	{
		for(int i=endY-1; i>=start+1; --i)
			clock_wise.push_back(matrix[i][start]);
	}
}
//bool invalidMat = false;
vector<int> printMatrix(vector<vector<int> > const &matrix)
{//思路：从外向内一圈圈访问，每一圈打印四条边（注意后三条边不一定有，需要判断） 
	vector<int> clock_wise;
	if(matrix.size()==0 || matrix[0].size()==0)
		return clock_wise;
	int rows = matrix.size();
	int cols = matrix[0].size();
	int start = 0;
	while(rows > 2*start && cols > 2*start) //每一圈的起点坐标满足的条件 
	{
		printMatrixInCircle(matrix, start, clock_wise);
		++start;
	}
	return clock_wise; 
}

int main()
{
	vector<vector<int> > matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	vector<int> result = printMatrix(matrix);
	for(auto item:result)
		cout<<item<<" ";
	cout<<endl;
	return 0;
}
