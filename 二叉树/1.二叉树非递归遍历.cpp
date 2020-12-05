#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	vector<int> res;
public:
	void printRes() {
		for (int i = 0; i < res.size(); ++i) {
			cout << res[i] << endl;
		}
	}

	void pre0rder(TreeNode* cur) {
		if (cur == nullptr) { return; }
    // 构造一个栈， 用来存储 树的节点指针
		stack<TreeNode*> stk;
		stk.push(cur);
		//m l r
		while (!stk.empty()) {
      // 每次判断栈顶的节点指针
			if (stk.top()) {
        //取出栈顶节点指针，暂存
				auto node = stk.top();
				stk.pop();
				
        // 按照遍历的逆序，压入栈中
				// right
				if (node->right != nullptr) {
					stk.push(node->right);
				}
				// left
				if (node->left != nullptr) {
					stk.push(node->left);
				}
				// mid
        //每次push完当前节点，都需要push个nullptr作为标记
        //移动这两行代码的顺序，可以构造出不同的遍历方式。
				stk.push(node);
				stk.push(nullptr);
			}
			else {
        // 弹出 nullptr
				stk.pop();
        // 取栈顶指针
				auto node = stk.top();
				res.push_back(node->val);
				stk.pop();
			}
		}
	}

};


int main() {
	TreeNode* cur = new TreeNode(0);
	cur->left = new TreeNode(1);
	cur->right = new TreeNode(2);
	cur->left->left = nullptr;
	cur->left->right = nullptr;
	cur->right->left = nullptr;
	cur->right->right = nullptr;
	Solution s;
	s.pre0rder(cur);
	s.printRes();
}
