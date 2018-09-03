#include <iostream>
using namespace std; 

//-----------��������----------------
/*
1.���ܣ��ַ������д���/������������ַ�����ƥ���·��
2.���棺�ַ�����ָ����ַ���ָ��ΪNULL��������������С��1 
*/ 
bool hasPathCore(char *matrix, int rows, int cols, char *str, int i, int j, int &pathLen, bool *visited)
{//���ݷ��жϾ������Ƿ���·���ĺ���˼·��
//	����ʹ�õݹ�ʵ�֣��ݹ��Ϊ���жϵ��ַ���ĩβ('\0')��һ��������hasPath��־λ��
//	��Ϊfalse,Ȼ���ж��ַ������еĵ�ǰλ�õ��ַ��Ƿ���str[pathLen]����ҵ�ǰλ�õ�
//	�ַ�δ�����ʹ��������������pathLen��visited�����ж�Ӧ��λ�ò��ݹ��жϵ�ǰλ��
//	��Χ���ĸ�λ���Ƿ����·����������������ݣ�������pathLen��visited�ĸ���) 
	if(str[pathLen] == '\0')
		return true;
	bool hasPath = false;
	if((i>=0 && i<rows) && (j>=0 && j<cols) && matrix[i*cols+j] == str[pathLen] && !visited[i*cols+j])
	{
		++pathLen;
		visited[i*cols+j] = true;
		hasPath = hasPathCore(matrix, rows, cols, str, i, j+1, pathLen, visited)
				||hasPathCore(matrix, rows, cols, str, i+1, j, pathLen, visited)
				||hasPathCore(matrix, rows, cols, str, i, j-1, pathLen, visited)
				||hasPathCore(matrix, rows, cols, str, i-1, j, pathLen, visited);
		if(!hasPath)
		{//·������������� 
			--pathLen;
			visited[i*cols+j] = false;
		}
	}
	return hasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{//˼·��ʹ�û��ݷ��������ַ�����ÿ��λ�ã��ӵ�ǰλ�ÿ�ʼ�ж��Ƿ����·��������
//		���ʹ���λ�ò����ٷ��ʣ����Ի���Ҫ����һ�����ַ�������ͬ��С��bool���������б�ʶ
	if(matrix==NULL || str==NULL || rows<1 || cols<1) 
		return false;
	bool *visited = new bool[rows*cols];
	for(int i=0; i<rows*cols; ++i)
		visited[i] = false;
	bool result = false;
	int pathLength = 0;
	for(int i=0; i<rows; ++i)
		for(int j=0; j<cols; ++j)
			if(hasPathCore(matrix, rows, cols, str, i, j, pathLength, visited))
				{result = true; break;}
	delete []visited;
	return result;
}

int main()
{
//	char matrix[12]={'a', 'b', 'c', 'e', 's', 'f', 'c', 's', 'a', 'd', 'e', 'e'};
	char *matrix = "abcesfcsadee";
	char *str="abcb";
	if(hasPath(matrix, 3, 4, str))
		cout<<"has path"<<endl;
	return 0;
}
