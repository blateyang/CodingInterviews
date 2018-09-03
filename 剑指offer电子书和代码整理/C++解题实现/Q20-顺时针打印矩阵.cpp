#include <iostream>
#include <vector>
using namespace std;

//-------------��������---------------
/*
1.���ܲ��ԣ������ж��ж��У�����һ�ж��У�����һ�ж��У�����һ��һ��
2.������ԣ������ǿվ��� 
*/ 
void printMatrixInCircle(vector<vector<int> > const &matrix, int start, vector<int> &clock_wise)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
	int endY = rows-1-start;
	int endX = cols-1-start;
	//�����Ҵ�ӡһ�� 
	for(int i=start; i<=endX; ++i)
		clock_wise.push_back(matrix[start][i]);
	//���ϵ��´�ӡһ�� 
	if(endY > start)
	{
		for(int i=start+1; i<=endY; ++i)
			clock_wise.push_back(matrix[i][endX]);
	}
	//���ҵ����ӡһ�� 
	if(endX > start && endY > start)
	{
		for(int i=endX-1; i>=start; --i)
			clock_wise.push_back(matrix[endY][i]);
	}
	//���µ��ϴ�ӡһ�� 
	if(endX > start && endY > start+1)
	{
		for(int i=endY-1; i>=start+1; --i)
			clock_wise.push_back(matrix[i][start]);
	}
}
//bool invalidMat = false;
vector<int> printMatrix(vector<vector<int> > const &matrix)
{//˼·����������һȦȦ���ʣ�ÿһȦ��ӡ�����ߣ�ע��������߲�һ���У���Ҫ�жϣ� 
	vector<int> clock_wise;
	if(matrix.size()==0 || matrix[0].size()==0)
		return clock_wise;
	int rows = matrix.size();
	int cols = matrix[0].size();
	int start = 0;
	while(rows > 2*start && cols > 2*start) //ÿһȦ������������������ 
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
