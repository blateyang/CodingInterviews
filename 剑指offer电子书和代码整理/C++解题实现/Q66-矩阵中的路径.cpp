#include <iostream>
using namespace std; 

//-----------测试用例----------------
/*
1.功能：字符矩阵中存在/不存在与给定字符串相匹配的路径
2.负面：字符矩阵指针或字符串指针为NULL；行数和列数均小于1 
*/ 
bool hasPathCore(char *matrix, int rows, int cols, char *str, int i, int j, int &pathLen, bool *visited)
{//回溯法判断矩阵中是否含有路径的核心思路：
//	整体使用递归实现，递归基为已判断到字符串末尾('\0')，一般情形是hasPath标志位先
//	设为false,然后判断字符矩阵中的当前位置的字符是否与str[pathLen]相等且当前位置的
//	字符未被访问过，若成立则更新pathLen和visited矩阵中对应的位置并递归判断当前位置
//	周围的四个位置是否存在路径；若不存在则回溯（撤销对pathLen和visited的更改) 
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
		{//路径不存在则回溯 
			--pathLen;
			visited[i*cols+j] = false;
		}
	}
	return hasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{//思路：使用回溯法。遍历字符矩阵每个位置，从当前位置开始判断是否存在路径，由于
//		访问过的位置不能再访问，所以还需要设置一个与字符矩阵相同大小的bool矩阵来进行标识
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
