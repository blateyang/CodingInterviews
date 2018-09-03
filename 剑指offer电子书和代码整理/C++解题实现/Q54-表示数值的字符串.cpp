#include <iostream>
using namespace std;

//------------测试用例---------------
/*
1.功能：纯数值、带符号的纯数值、带e/E的字符串、带小数点的字符串、同时带小数点和e/E的字符串
2.负面：字符串为空 
*/ 

void scanDigits(char **string) //使用指向指针的指针是为了需要修改主调函数中的指针变量 
{//将数字部分扫描过去 
	while(**string!='\0' && **string>='0' && **string<='9')
		++(*string);
}

bool isExpotional(char **string)
{//判断是否是合法的指数部分 
	++(*string); //过掉e/E 
	if(**string=='+' || **string=='-')
		++(*string);
	if(**string=='\0') //e/E后没有字符或只有正负号，非指数 
		return false;
	scanDigits(string);
	return (**string=='\0')? true:false;
}

bool isNumeric(char *string)
{//思路：找出表示数值的字符串格式 [sign]int-digits[.[fractional-digits]][e|E[sign]exp-digits]
	if(string == NULL)
		return false;
	if(*string=='+' || *string=='-')
		++string;
	if(*string == '\0')
		return false;
		
	scanDigits(&string);
	bool result = true;
	if(*string != '\0')
	{
		if(*string == '.')
			{//浮点数情况
				++string;
				scanDigits(&string);
				if(*string=='e' || *string=='E')
					result = isExpotional(&string);
				else if(*string != '\0')
					result = false;
			}
			//整数情况
		else if(*string=='e' || *string=='E')
			result = isExpotional(&string); 
		else
			result = false;
	}
	return result;
}

int main()
{
	char *string[8] = {"100", "-123", "3.14", "-1E-16", "12e", "1.2.3", "+-5", "12e+5.4"};
	for(int i=0; i<8; ++i)
		if(isNumeric(string[i]))
			cout<<string[i]<<endl;
	return 0; 
}
