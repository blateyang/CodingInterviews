#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
/*
public:
//�Լ��뵽��˼·����vector��Ϊ����������ÿ�λ�ȡ��λ��ʱ���Ե�ǰ�����������򣬸��Ӷ�ΪO(nlogn) 
    void Insert(int num)
    {
        stream.push_back(num);
    }

    double GetMedian()
    { 
    	int len = stream.size();
    	if(len == 0) return 0.0; //��δ���뼴��ͼ��ȡ��λ��ʱ���涨����0 
    	sort(stream.begin(), stream.end());
    	double result;
    	if(len%2 == 1)
    		result = stream[len/2];
    	else
    		result = double(stream[len/2-1] + stream[len/2])/2;
    	return result;
    }
private:
	vector<int> stream; */
	
//��ָoffer˼·�������˶��ַ�������δ���������(O(1),O(n))�����������(O(n),O(1))
//				���������(O(n),O(1))��������������ƽ��������������С�ѣ����
//				���ַ�����Ч����ߣ�����ΪO(logn)����ȡ��λ��ΪO(1)),�����������С�ѵ�ʵ��
private:
	vector<int> max;	//���ѣ����ڴ������������е�ǰ���ֵ��С��Ԫ�� 
	vector<int> min; 	//��С�ѣ����ڴ������������еĺ���ֵ�ϴ��Ԫ��
public:
	void Insert(int num)
	{//Ϊ��֤�����ѵĹ�ģ�൱����������Ϊż��ʱ��Ӧ����Ԫ�ز��뵽��С���У�������Ԫ�� 
	//�������еĶѶ�Ԫ�ػ�ҪСʱ��Ӧ�Ƚ�����������У���ȡ���ѶѶ�Ԫ�ز��뵽��С���У���������Ϊ����ʱ�������෴ 
		if((max.size()+min.size())%2 == 0) //������Ϊż�� 
		{
			if(max.size()>0 && num<max[0]) 
			{//����Ԫ�ر����ѶѶ�Ԫ��С 
				max.push_back(num); //�ȼӵ������У��ټӵ����У�����ʱ���෴ 
				//push_heap()ΪSTL��������Ԫ�صĺ���,�ȽϺ���less()ָ��������Ϊ���ѣ���ʹ�ñȽϺ������ѵ����ֵ��
				//��������ֵ�Ƚ�ʱ�������᷵��false,���http://www.cplusplus.com/reference/algorithm/make_heap/ 
				push_heap(max.begin(), max.end(), less<int>()); 
				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num); //����Ԫ�ز�����С�� 
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else
		{
			if(min.size()>0 && num>min[0])
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		 } 
	}
	double GetMedian()
	{
		int size = max.size() + min.size();
		if(size == 0)
			return 0.0; //��Ч��������0
		if(size%2 == 1) //������Ϊ�������򷵻�min�Ѷ�Ԫ��
			return double(min[0]);
		else
			return double(min[0]+max[0])/2; 
	 } 
};

int main()
{
	Solution s;
	s.Insert(1);
	s.Insert(2);
	cout<<s.GetMedian()<<endl;
	return 0;
}
