#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int i = 0;
		int sum = 0;
		int sublength = 0;
		int result = INT32_MAX;//对应result判断条件
		for (int j = 0; j < nums.size(); j++) {
			sum += nums[j];//计算窗口内的和
			while (sum >= target) {
				sublength = j - i + 1;
				//判断result的返回，循环比较，result初始赋为INT_MAX，否则结果永远是0
				result = result < sublength ? result : sublength;
				sum -= nums[i];
				i++;//移动窗口的头部
			}
		}
		//三段式判断若真返回0假返回result
		return result == INT32_MAX ? 0 : result;
	}
};