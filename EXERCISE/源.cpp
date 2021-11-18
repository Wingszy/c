#include<iostream>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;
		for (int i = 0; i < s.length(); ++i) {
			char c = s[i];
			if (!stack.empty()) {
				char t = stack.top();
				if (t == '(' && c == ')'
					|| t == '[' && c == ']'
					|| t == '{' && c == '}') {
					stack.pop();
					continue;
				}
			}
			stack.push(c);
		}
		return stack.empty();
	}
};