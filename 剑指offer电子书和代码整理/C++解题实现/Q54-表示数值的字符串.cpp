#include <iostream>
using namespace std;

//------------��������---------------
/*
1.���ܣ�����ֵ�������ŵĴ���ֵ����e/E���ַ�������С������ַ�����ͬʱ��С�����e/E���ַ���
2.���棺�ַ���Ϊ�� 
*/ 

void scanDigits(char **string) //ʹ��ָ��ָ���ָ����Ϊ����Ҫ�޸����������е�ָ����� 
{//�����ֲ���ɨ���ȥ 
	while(**string!='\0' && **string>='0' && **string<='9')
		++(*string);
}

bool isExpotional(char **string)
{//�ж��Ƿ��ǺϷ���ָ������ 
	++(*string); //����e/E 
	if(**string=='+' || **string=='-')
		++(*string);
	if(**string=='\0') //e/E��û���ַ���ֻ�������ţ���ָ�� 
		return false;
	scanDigits(string);
	return (**string=='\0')? true:false;
}

bool isNumeric(char *string)
{//˼·���ҳ���ʾ��ֵ���ַ�����ʽ [sign]int-digits[.[fractional-digits]][e|E[sign]exp-digits]
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
			{//���������
				++string;
				scanDigits(&string);
				if(*string=='e' || *string=='E')
					result = isExpotional(&string);
				else if(*string != '\0')
					result = false;
			}
			//�������
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
