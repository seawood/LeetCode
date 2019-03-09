#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

//�����㷨֮���ң�1.���ֲ���
//1.1��AΪ�������������ظ����֣��������ڷ���-1,
int getPos1(vector<int> A, int n, int val) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (A[mid] == val)
			return mid;
		else if (val < A[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
//1.2��AΪ���������ҿ������ظ����֣��������ڷ���-1�������ڷ��ص�һ�����ֵ��±�
int getPos2(vector<int> A, int n, int val) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (val <= A[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (left < n && A[left] == val)
		return left;
	return -1;
}
//1.3��AΪ���������ҿ������ظ����֣��������ڷ���-1�������ڷ������һ�����ֵ��±�
int getPos3(vector<int> A, int n, int val) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (val >= A[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (right >= 0 && A[right] == val)
		return right;
	return -1;
}

//�����㷨֮������leetcode 75��.Sort ColorsΪ����
/*
*1.ð������
*�㷨���������������У�����Ԫ���������򽻻�λ�ã��ظ���������ֱ������������Ϊ�ջ�����һ�˱�����û�н�������
*ʱ�䣺���ʱ�临�Ӷ�O(n^2),����ʱ�临�Ӷ�O(n)��ƽ��ʱ�临�Ӷ�O(n^2)
*�ռ䣺���踨���ռ�O(1)
*�ȶ��ԣ��ȶ�
*/
void sortColors_BubbleSort(vector<int>& nums) {
	int len = nums.size();
	bool flag = false;//����������־��������ʱ��ǰ�˳�ѭ��
	for (int i = 0; i < len; ++i) {
		flag = false;
		for (int j = len - 1; j > i; --j)
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
				flag = true;
			}
		if (!flag)
			break;
	}
}
/*
*2.ѡ������
*�㷨���ڴ������������ҵ���СԪ�ط���������ʼλ����Ϊ���������У���ʣ�µĴ������������ҵ���СԪ�ط������������е�ĩβ���ظ���������ֱ������������Ϊ��
*ʱ�䣺���ʱ�临�Ӷ�O(n^2),����ʱ�临�Ӷ�O(n^2),ƽ��ʱ�临�Ӷ�O(n^2)
*�ռ䣺���踨���ռ�O(1)
*�ȶ��ԣ����ȶ�
*/
void sortColors_SelectSort(vector<int>& nums) {
	int len = nums.size();
	for (int i = 0; i < len; ++i) {
		int index = i;
		for (int j = i + 1; j < len; ++j)
			if (nums[j] < nums[index])
				index = j;
		if (index != i)
			swap(nums[i], nums[index]);
	}
}

/*
*3.��������
*�㷨����һ��Ԫ����Ϊ������
      ȡ����һ��Ԫ�أ������������дӺ���ǰ��������������Ԫ�ش�����Ԫ�أ���������Ԫ�����Ųһ��λ�ã�ֱ���ҵ���Ԫ��Ӧ�ò����λ�ã�����Ԫ�ز���
	  �ظ��������ֱ������Ԫ������
*ʱ�䣺���ʱ�临�Ӷ�O(n^2),����ʱ�临�Ӷ�O(n),ƽ��ʱ�临�Ӷ�O(n^2)
*�ռ䣺���踨���ռ�O��1��
*�ȶ��ԣ��ȶ�
*/
void sortColors_InsertSort(vector<int>& nums) {
	int len = nums.size();
	for (int i = 1; i <len; ++i) {
		int mark = nums[i];
		int j = i - 1;
		while (nums[j] > mark&&j>=0) {
			nums[j + 1] = nums[j];
			--j;
		}
		nums[j+1] = mark;
	}
}
/*
*4.��������
*�㷨��ѡ��һ��Ԫ����Ϊ��׼ֵ������һ������֮�󣬻�׼ֵλ���ź����λ�ã���׼ֵ��ߵ�Ԫ�ض�С�ڻ�׼ֵ����׼ֵ�ұߵ�Ԫ�ض����ڻ�׼ֵ,�ݹ���������ߵ����н��п�������
      һ�����򣺼�¼ָ��l����Ԫ��ֵΪmark;ָ��l��r�ֱ�ָ������ߺ����ұߵ�Ԫ�أ�ָ��r���������ҵ�һ��С�ڵ��ڻ�׼ֵ��Ԫ�أ���r����Ԫ��ֵ����l��Ԫ�أ�ָ��l���������ҵ�һ�����ڻ�׼ֵ��Ԫ�أ���l����Ԫ��ֵ����r����Ԫ��
	           �ظ��������̣�ֱ��l��rָ��������ָ����������ֵΪmark
*ʱ�䣺���ʱ�临�Ӷ�O(n^2),����ʱ�临�Ӷ�O(nlogn),ƽ��ʱ�临�Ӷ�O(nlogn)
*�ռ䣺���踨���ռ�O(logn)
*�ȶ��ԣ����ȶ�
*/
void sortColors_QuickSortCore(vector<int>& nums, int left, int right) {
	if (right - left <= 0)
		return;
	int mark = nums[left];
	int l = left, r = right;
	while (r > l) {
		while (nums[r] > mark&&r >l)
			r--;
		nums[l] = nums[r];
		while (nums[l] <= mark&&l < r)
			l++;
		nums[r] = nums[l];
	}
	nums[l] = mark;
	sortColors_QuickSortCore(nums, left, l-1);
	sortColors_QuickSortCore(nums, l + 1, right);
}
void sortColors_QuickSort(vector<int>& nums) {
	int len = nums.size();
	if (len < 2)
		return;
	sortColors_QuickSortCore(nums, 0, len - 1);
}

/*
*5.�鲢����
*�㷨���������������й鲢��һ����������
*ʱ�䣺����ʱ�临�Ӷ�O(nlogn),�ʱ�临�Ӷ�O(nlogn),ƽ��ʱ�临�Ӷ�O(nlogn)
*�ռ䣺�����ռ��СO(n)
*�ȶ��ԣ��ȶ�
*/
void merge(vector<int>& nums, int left, int mid, int right) {
	vector<int> numsCopy(nums.begin() + left, nums.begin() + right + 1);
	int i = 0, j = mid - left + 1, walk = left;
	while (i <= mid - left&&j <= right - left) {
		if (numsCopy[i] <= numsCopy[j])
			nums[walk++] = numsCopy[i++];
		else
			nums[walk++] = numsCopy[j++];
	}
	while (i <= mid - left)
		nums[walk++] = numsCopy[i++];
	while (j <= right - left)
		nums[walk++] = numsCopy[j++];
}
void sortColors_mergeSortCore(vector<int>& nums, int left, int right) {
	if (right - left < 1)
		return;
	int mid = (left + right) / 2;
	sortColors_mergeSortCore(nums, left, mid);
	sortColors_mergeSortCore(nums, mid + 1, right);
	merge(nums, left, mid, right);
}
void sortColors_mergeSort(vector<int>& nums) {
	int len = nums.size();
	sortColors_mergeSortCore(nums, 0, len - 1);
}

/*
*6.������
*�㷨�������ѵĶ���Ԫ�����������е����һ��Ԫ�ؽ������ع��������й��ɵ����ѣ��ظ��������裬ֱ���������г���Ϊ1
	   ��α����£�R[i]�ĸ��ڵ�R[(i-1)/2],���ӽڵ�R[2*i+1],R[2*i+2]
*ʱ�䣺����/�/ƽ��ʱ�临�Ӷ�O(nlogn)
*�ռ䣺O(1)
*�ȶ���:���ȶ�
*/
void reconstructHeapTopDown(vector<int>& nums, int j, int right) {
	while (true) {
		int lChild = 2 * j + 1, rChild = 2 * j + 2;
		if (lChild <= right&&rChild <= right&&nums[j] < nums[lChild] && nums[j] < nums[rChild]) {
			if (nums[lChild] > nums[rChild]) {
				swap(nums[j], nums[lChild]);
				j = lChild;
			}
			else {
				swap(nums[j], nums[rChild]);
				j = rChild;
			}
		}
		else if (lChild <= right&&nums[j] < nums[lChild]) {
			swap(nums[j], nums[lChild]);
			j = lChild;
		}
		else if (rChild <= right&&nums[j] < nums[rChild]) {
			swap(nums[j], nums[rChild]);
			j = rChild;
		}
		else
			break;
	}
}
void sortColors_heapSort(vector<int>& nums) {
	int len = nums.size();
	//�������ϳ�ʼ������
	for (int i = len - 1; i >= 0; --i) {
		int parent = (i - 1) / 2;
		if (parent >= 0 && nums[i] > nums[parent]) {
			swap(nums[i], nums[parent]);
			reconstructHeapTopDown(nums, i, len - 1);
		}
	}
	int i = len - 1;
	while (i > 0) {
		swap(nums[0], nums[i]);//�Ѷ��׷ŵ�������е����
		reconstructHeapTopDown(nums, 0, i - 1);//�ع�����
		--i;
	}
}

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
//�����㷨֮����������
//���������leetcode 144)
//1.1��������ݹ��
void preorderTraversalCore(vector<int>& result, TreeNode* root) {
	if (root == nullptr)
		return;
	else {
		result.push_back(root->val);
		preorderTraversalCore(result, root->left);
		preorderTraversalCore(result, root->right);
	}
}
vector<int> preorderTraversal_recursive(TreeNode* root) {
	vector<int> result;
	preorderTraversalCore(result, root);
	return result;
}
//1.2�������������:���������ͨ·�Զ����·�����;�ڵ㣬���Ե��������η�����Щ�ڵ��������
void walkAlongLeftBranch(vector<int>& result,stack<TreeNode*>& s, TreeNode* root) {
	while (root) {
		result.push_back(root->val);
		s.push(root->right);
		root = root->left;
	}
}
vector<int> preorderTraversal_iterative(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> s;
	while (true) {
		walkAlongLeftBranch(result, s, root);
		if (s.empty())
			break;
		root = s.top();
		s.pop();
	}
	return result;
}

//2.��α���
vector<int> LevelTrversal(TreeNode* root) {
	vector<int> result;
	if (root == nullptr)
		return result;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* temp = q.front();
		result.push_back(temp->val);
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(q.front()->right);
		q.pop();
	}
	return result;
}

//3.1�������,�����汾1��Leetcode 94��
void goLeft(TreeNode* root, stack<TreeNode*>& s) {
	while (root) {
		s.push(root);
		root = root->left;
	}
}
vector<int> inorderTraversal_iterative1(TreeNode* root) {
	vector<int> result;
	if (root == nullptr)
		return result;
	stack<TreeNode*> s;
	while (true) {
		goLeft(root, s);
		if (s.empty())
			break;
		result.push_back(s.top()->val);
		root = s.top()->right;
		s.pop();
	}
	return result;
}
//3.2��������������汾2
vector<int> inorderTraversal_iterative2(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> s;
	while (true) {
		if (root) {
			s.push(root);
			root = root->left;
		}
		else if (!s.empty()) {
			result.push_back(s.top()->val);
			root = s.top()->right;
			s.pop();
		}
		else
			break;
	}
	return result;
}
//3.3����������ݹ�汾
vector<int> inorderTraversal_recursive(TreeNode* root) {
	if (!root)
		return vector<int>();
	vector<int> ans = inorderTraversal_recursive(root->left);
	ans.push_back(root->val);
	vector<int> back = inorderTraversal_recursive(root->right);
	ans.insert(ans.end(), back.begin(), back.end());
	return ans;
}

//4.1�������,�����汾��Leetcode 145)
void gotoHL(stack<TreeNode*>& s) {
	while (TreeNode* x = s.top()) {
		if (x->left) {
			if (x->right)
				s.push(x->right);
			s.push(x->left);
		}
		else
			s.push(x->right);
	}
	s.pop();
}
vector<int> postorderTraversal_iterative(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> s;
	if (root)
		s.push(root);
	while (!s.empty()) {
		if (root != s.top()->left&&root != s.top()->right)
			gotoHL(s);
		root = s.top();
		result.push_back(s.top()->val);
		s.pop();
	}
	return result;
}
//4.2����������ݹ�汾
vector<int> postorderTraversal_recursive(TreeNode* root) {
	if (!root)
		return vector<int>();
	vector<int> left = postorderTraversal_recursive(root->left);
	vector<int> right = postorderTraversal_recursive(root->right);
	left.insert(left.end(), right.begin(), right.end());
	left.push_back(root->val);
	return left;
}