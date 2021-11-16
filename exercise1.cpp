#include<iostream>
using namespace std;

template<class DataType>
struct Node
{
	DataType data;
	Node<DataType>*next;
};

template<class DataType>
class LinkList
{
public:
	LinkList();
	LinkList(DataType a[], int n);
	~LinkList();
	int Length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();
private:
	Node<DataType> *first;
};

template<class DataType>
LinkList<DataType>::LinkList() {
	first = new Node<DataType>;
	first->next = NULL;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
	first = new Node<DataType>;
	first->next = NULL;
	for (int i = 0; i < n; i++)
	{
		Node<DataType> *s = new Node<DataType>;
		s->data = a[i];
		s->next = first->next;
		first->next = s;//头插法，注意初始化条件也为终结点
	}
}
//template<class DataType>
//LinkList<DataType>::LinkList(DataType a[], int n)
//{
//	first = new Node<DataType>;
//	Node<DataType>*r = first;
//	for (int i = 0; i < n; i++)
//	{
//		Node<DataType>*s = new Node<DataType>;
//		s->data = a[i];
//		r->next = s;
//		r = s;// 尾插法，注意最后r指向空
//	}
//	r->next = NULL;
//}


template<class DataType>
LinkList<DataType>::~LinkList() {
	while(first != NULL){
	Node<DataType>*q = first;
	first->next = first;
	delete q;
}
}


template<class DataType>
int LinkList<DataType>::Length()
{
	Node<DataType>* p = first->next;
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<class DataType>
DataType LinkList<DataType>::Get(int i)
{
	Node<DataType>* p = first->next;
	int count = 1;
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL) throw "Location";
	else return p->data;
}

template<class DataType>
int LinkList<DataType>::Locate(DataType x)
{
	Node<DataType> *p = first->next;
	int count = 1;
	while (p != NULL)
	{
		if (p->data == x) return count;
		p = p->next;
		count++;
	}
	return 0;
}

template<class DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
	Node<DataType> *p = first;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL) throw "Location";
	else {
		Node<DataType> *s = new Node<DataType>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}

template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
	Node<DataType> *p = first;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL) throw "Location";
	else {
		Node<DataType> *q = p->next;
		int x = q->data;
		p->next = q->next;
		return x;
	}
}

template<class DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType> *p = first->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

int main()
{
	LinkList<int> p;
	cout << "ok" << endl;
	p.Insert(1, 6);
	p.Insert(2, 9);
	p.PrintList();
	p.Insert(2, 3);
	p.PrintList();
	cout << p.Get(2) << endl;
	cout << p.Locate(9) << endl;
	cout << p.Length() << endl;
	p.Delete(1);
	p.PrintList();
	return 0;
}

const int MaxSize = 100;
template <class DataType>
class SeqList
{
public:
	SeqList() { length = 0; }
	SeqList(DataType a[], int n);
	~SeqList() {}
	int Length() { return length; }
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();
private:
	DataType data[MaxSize];
	int length;
};

template <class DataType>
SeqList<DataType>::SeqList(DataType a[], int n)
{
	if (n > MaxSize) throw "wrong parameter";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
}

template <class DataType>
DataType SeqList<DataType>::Get(int i)
{
	if (i<1 && i>length) throw "wrong Location";
	else return data[i - 1];
}

template <class DataType>
int SeqList<DataType>::Locate(DataType x)
{
	for (int i = 0; i < length; i++)
		if (data[i] == x) return i + 1;
	return 0;
}

template <class DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
	if (length >= MaxSize) throw "Overflow";
	if (i<1 || i>length + 1) throw "Location";
	for (int j = length; j >= i; j--)
		data[j] = data[j - 1];
	data[i - 1] = x;
	length++;
}

template <class DataType>
DataType SeqList<DataType>::Delete(int i)
{
	int x;
	if (length == 0) throw "Underflow";
	if (i<1 || i>length) throw "Location";
	x = data[i - 1];
	for (int j = i; j < length; j++)
		data[j - 1] = data[j];
	length--;
	return x;
}

template <class DataType>
void SeqList<DataType>::PrintList()
{
	for (int i = 0; i < length; i++)
		cout << data[i] << endl;
}

int main()
{
	SeqList<int> p;
	p.Insert(1, 5);
	p.Insert(2, 9);
	p.PrintList();
	p.Insert(2, 3);
	cout << p.Length() << endl;
	p.PrintList();
	cout << p.Get(3) << endl;
	p.Delete(2);
	p.PrintList();
	return 0;
}

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size() - 1; i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target)
					return { i,j };
			}
		}
		return {};
	}
};

int main() {
	Solution solution;
	vector<int> position;
	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
	int target = 9;
	position = solution.twoSum(arr, target);
	for (auto i : position)
		cout << i << endl;
	return 0;
}

class Solution {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
				return 0;
			}
			int digit = x % 10;
			x /= 10;
			rev = rev * 10 + digit;
		}
		return rev;
	}
};


int main()
{
	Solution solution;
	int result = solution.reverse(123);

	cout << INT_MAX << "--" << INT_MIN << endl;
	cout << result << endl;


	return 0;
}
int main()
{
	bool hui(int n);
	int a;
	while (cin >> a)
	{
		if (hui(a))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

	return 0;
}
bool hui(int n)
{
	if (n < 0 || (n % 10 == 0 && n != 0)) {
		return false;
	}
	unsigned i = n;
	unsigned m = 0;
	while (i > 0)
	{
		m = m * 10 + i % 10;
		i /= 10;
	}
	return m == n;
}
int romanToInt(string s) {
	int res = 0;
	map<char, int> m = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };

	for (int i = 0; i < s.size(); i++) {
		if (m[s[i + 1]] <= m[s[i]])
			res += m[s[i]];
		else
			res -= m[s[i]];
	}

	return res;

}


int main()
{
	char input[99999999];
	cin >> input;

	int result = romanToInt(input);
	cout << result << endl;
	return 0;
}

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int count = strs.size();
		string common = "";
		if (count == 0)
			return common;
		if (count == 1)
			return strs[0];
		for (size_t i = 0; i < strs[0].size(); i++)
		{
			for (size_t j = 1; j < count; j++)
			{
				//对于每个字符串的第i个字符，判断全相同转为如果不相同就结束
				if (strs[0][i] != strs[j][i])
					return strs[0].substr(0, i);
			}
			//strs[0][i]为公共字符
			common = common + strs[0][i];
		}
		return common;
	}
};

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

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) {
			return l2;
		}
		else if (l2 == nullptr) {
			return l1;
		}
		else if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) {
			return head;
		}

		ListNode* cur = head;
		while (cur->next) {
			if (cur->val == cur->next->val) {
				cur->next = cur->next->next;
			}
			else {
				cur = cur->next;
			}
		}

		return head;
	}
};

//class Solution {
//	class Pair {
//		int val;
//		int index;
//	public: Pair(int val, int index) {
//			this.val = val;
//			this.index = index;
//		}
//	}
//
//public: int[] twoSum(int[] nums, int target) {
//		if (nums == null || nums.length == 0) {
//			return null;
//		}
//		int[] res = new int[2];
//
//		Pair[] pairs = new Pair[nums.length];
//		//0. 将数组元素值和index进行绑定
//		for (int i = 0; i < nums.length; i++) {
//			pairs[i] = new Pair(nums[i], i);
//		}
//		//1. 双指针解法的第一步永远是排序
//		Arrays.sort(pairs, new Comparator<Pair>() {
//			@Override
//				public int compare(Pair o1, Pair o2) {
//				return o1.val - o2.val;
//			}
//		});
//		int left = 0;
//		int right = nums.length - 1;
//
//		while (left < right) {
//			if (pairs[left].val + pairs[right].val == target) {
//				res[0] = pairs[left].index;
//				res[1] = pairs[right].index;
//				return res;
//			}
//			else if (pairs[left].val + pairs[right].val > target) {
//				//2. 当前的最大值加上最小值 都还是大于目标值,说明最大值太大了
//				right--;
//			}
//			else {
//				//3.当前的最小值加上最大值 都还是小于目标值,说明最小值太小了
//				left++;
//			}
//		}
//		return null;
//	}
//}  上述代码暂时无法完全分析，待后续学完c++的继承委托之后再进行深度研究


int* twoSum(int* nums, int numsSize, int target) {
	int i, j = 0;
	int sum = 0;
	int *ret;
	ret = (int *)malloc(sizeof(int) * 2);          /* 一个未初始化的指针分配一个空间 */
	if (nums == NULL)
		return NULL;
	for (i = 0; i < (numsSize - 1); i++) {
		for (j = i + 1; j < numsSize; j++) {
			sum = nums[i] + nums[j];
			if (target == sum) {
				*ret = i;
				*(ret + 1) = j;
				return ret;
			}
		}
	}
	return ret;
}
class Solution {
public:
	int jumpFloor(int number)
	{
		if (number == 1)return 1;
		if (number == 2) return 2;
		return jumpFloor(number - 1) + jumpFloor(number - 2);
	}

};
int main()
{
	Solution s;
	cout << s.jumpFloor(9) << endl;
	return

		struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	class Solution {
	public:
		void deleteNode(ListNode* node) {
			ListNode* temp = node->next;
			node->val = temp->val;
			node->next = temp->next;
			delete temp;
		}
	};

	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	class Solution {
	public:
		bool hasCycle(ListNode *head) {
			unordered_set<ListNode*> seen;
			while (head != nullptr) {
				if (seen.count(head)) {
					return true;
				}
				seen.insert(head);
				head = head->next;
			}
			return false;
		}
	};


	class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int low = 0, high = nums.size() - 1;
			while (low <= high) {
				int mid = (high - low) / 2 + low;
				int num = nums[mid];
				if (num == target) {
					return mid;
				}
				else if (num > target) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
			return -1;
		}
	};

	class Solution {
	public:
		int climbStairs(int n) {
			if (n <= 1) return n;
			vector<int> dp(n + 1);
			dp[1] = 1;
			dp[2] = 2;
			for (int i = 3; i <= n; i++) { // i从3开始
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			return dp[n];
		}
	};

	class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			int left = 0;
			int right = nums.size() - 1;
			while (left <= right) {
				int middle = left + ((right - left) / 2);
				if (nums[middle] > target) {
					right = middle - 1;
				}
				else if (nums[middle] < target) {
					left = middle + 1;
				}
				else {
					return middle;
				}
			}
			return left;
		}
	};
	int main() {
		int a;
		a = 3 / 2;
		cout << a << endl;
		return 0;


		class Solution {
		public:
			int mySqrt(int x) {
				int l = 0;
				int r = x, ans = 9;
				while (l <= r) {
					int m = l + (r - l) / 2;
					if ((long)m*m <= x) {
						ans = m;
						l = m + 1;
					}
					else {
						r = m - 1;
					}
				}
				return ans;
			}
		};

		int main() {
			int x = 22;
			int result;
			Solution sol;
			result = sol.mySqrt(x);
			cout << result << endl;

			return 0;
		}

		class Solution {
		public:
			bool isPerfectSquare(int num) {
				int l = 0, r = num, ans = -1;
				while (l <= r) {
					int m = l + (r - l) / 2;
					if ((long)m*m < num) {
						l = m + 1;
					}
					else if ((long)m*m == num) {
						return true;
					}
					else {
						r = m - 1;
					}
				}
				return false;

			}
		};
		int main() {
			Solution sol;
			bool result;
			result = sol.isPerfectSquare(25);
			cout << result << endl;
			return 0;
		}

		class Solution {
		public:
			int binarySearch(vector<int>& nums, int target, bool lower) {
				int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
				while (left <= right) {
					int mid = (left + right) / 2;
					if (nums[mid] > target || (lower && nums[mid] >= target)) {
						right = mid - 1;
						ans = mid;
					}
					else {
						left = mid + 1;
					}
				}
				return ans;
			}

			vector<int> searchRange(vector<int>& nums, int target) {
				int leftIdx = binarySearch(nums, target, true);
				int rightIdx = binarySearch(nums, target, false) - 1;
				if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
					return vector<int>{leftIdx, rightIdx};
				}
				return vector<int>{-1, -1};
			}
		};

		class Solution {
		public:
			int removeElement(vector<int>& nums, int val) {
				int slowindex = 0;
				for (int fastindex = 0; fastindex < nums.size(); fastindex++) {
					if (val != nums[fastindex]) {
						nums[slowindex] = nums[fastindex];
						slowindex++;
					}
				}
				return slowindex;
			}
		};

		class Solution {
		public:
			int moveZeroes(vector<int>& nums) {
				int n = nums.size(), left = 0, right = 0;
				for (right = 0; right < n; right++) {
					if (nums[right] != 0) {
						swap(nums[left], nums[right]);
						left++;
					}
				}
				return right;
			}
		};

		class Solution {
		public:
			vector<int> sortedSquares(vector<int>& nums) {
				int k = nums.size() - 1;
				vector<int>result(nums.size(), 0);//创建一个相同长度的数组
				//首尾双指针不断比较来排序
				for (int i = 0, j = nums.size() - 1; i <= j;) {
					if (nums[i] * nums[i] < nums[j] * nums[j]) {
						result[k--] = nums[j] * nums[j];
						j--;
					}
					else {
						result[k--] = nums[i] * nums[i];
						i++;
					}
				}
				return result;
			}
		};

		myWidget::myWidget(QWidget *parent)
			: QWidget(parent)
		{
			//创建一个按钮
			QPushButton*btn = new QPushButton;
			//btn->show();//show顶层方式弹出控件
			btn->setParent(this);
			//显示文本
			btn->setText("按钮一号");


			//创建另一个按钮
			QPushButton*btn2 = new QPushButton("按钮2号", this);

			//移动btn2
			btn2->move(100, 100);
			//按钮大小
			btn2->resize(100, 200);

			//重置窗口大小
			resize(600, 400);//宽加高
			//设置固定窗口大小
			setFixedSize(500, 500);
			//设置窗口标题
			setWindowTitle("窗口1号");


			//创建自己按钮对象
			MyPushButton * mybtn = new MyPushButton;
			mybtn->setText("我的按钮");

			mybtn->move(200, 0);
			mybtn->setParent(this);//设置到对象树中




		}

		myWidget::~myWidget()
		{
			qDebug() << "析构构";
		}

