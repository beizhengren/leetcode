
#include<string>
#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
/*整体思路
序列化：先序顺序，根->左子树->右子树。得到包含 "#!"和 "val!"组成的字符串
反序列化：先序顺序，根->左子树->右子树。解析序列化生成的字符串, 返回相应二叉树的根节点。
*/
class Solution {
private:
	void serial(TreeNode* root, string& s) {
		if (root == nullptr) {//根节点为空，或者为叶子节点时，需要存入左右两个nullptr。
			s += "#!";//一定是+=，否则s无法保留之前结果。
			return;
		}

		s += (to_string(root->val) + "!");//把当前节点的值和字符'!'存入s。
		serial(root->left, s);//递归左子树
		serial(root->right, s);//递归右子树
		return;
	}
public:
	char* Serialize(TreeNode* root) {
		string ss = "";
		serial(root, ss);
		//一定要初始化成'\0',否则反序列化的时候找不到终止条件
		//一定是分配在堆上，否则返回局部变量，内存被释放。
		char* res = new char[ss.size() + 1]{ '0' };//多留1个存终止符。
		memcpy(res, &ss[0], sizeof(char) * ss.size());//将字符串拷贝到res的内存空间。
		return res;
	}

	//由于指针str更新后需要在递归中用到，所以传引用
	TreeNode* Deserialize(char*& str) {
		//字符数组终止
		if (*str == '\0')return nullptr;
		//空节点('#')，指针str 跳过'#', '!'.
		if (*str == '#') {
			str += 2;
			return nullptr;
		}
		if (*str != '#') {
			string ss;//用来存储当前节点的值
			//结束位'!'之前都需要存入ss。
			while (*str != '!') {
				ss.push_back(*str);
				++str;
			}
			//str此时指向结束位'!'
			int val = stoi(ss);//字符串转成整型
			TreeNode* node;
			node = new TreeNode(val);
			++str;//指针str指向下一个节点值的开始位置。
			node->left = Deserialize(str);//递归左子树
			node->right = Deserialize(str);//递归右子树
			return node;
		}

	}

};

int main() {
	string ss = "12!2!4!#!#!#!3!5!#!#!6!#!#!";
	char* cs = const_cast<char*>(ss.c_str());
	cout << cs << endl;
	Solution s;
	cout << "De:" << endl;
	auto node = s.Deserialize(cs);
	
	cout << "Se:" << endl;
	char* cs2 = s.Serialize(node);
	cout << cs2 << endl;
}
