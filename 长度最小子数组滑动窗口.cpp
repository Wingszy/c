#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int i = 0;
		int sum = 0;
		int sublength = 0;
		int result = INT32_MAX;//��Ӧresult�ж�����
		for (int j = 0; j < nums.size(); j++) {
			sum += nums[j];//���㴰���ڵĺ�
			while (sum >= target) {
				sublength = j - i + 1;
				//�ж�result�ķ��أ�ѭ���Ƚϣ�result��ʼ��ΪINT_MAX����������Զ��0
				result = result < sublength ? result : sublength;
				sum -= nums[i];
				i++;//�ƶ����ڵ�ͷ��
			}
		}
		//����ʽ�ж����淵��0�ٷ���result
		return result == INT32_MAX ? 0 : result;
	}
};