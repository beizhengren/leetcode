//1. 先拿到后序数组中的最后一个元素 val
//2. 在中序数组中找到值等于val的idx，作为rootIdx。
//3. 以rootIdx为根的序号，将中序数组切分成左右子数组
//4. 剔除后序数组的最后一个元素，得到新的后序数组（范围）
//5. 由中序数组的左右子树组大小来划分新的后序数组
//6. 递归， root->left = ..., root->right = ...
//7. return root；

// Solution 1
// 递归 每次都创建和释放vector
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.empty() || inorder.empty()) { return nullptr; }
		TreeNode* root = new TreeNode(postorder.back());
		// 递归终止条件
		if (postorder.size() == 1) { return root; }

		int rootIdx = 0;
		for (int i = 0; i < inorder.size(); ++i) {
			if (inorder[i] == root->val) {
				rootIdx = i;
				break;
			}
		}

		vector<int> midLeftVec(inorder.begin(), inorder.begin() + rootIdx);
		vector<int> midRightVec(inorder.begin() + rootIdx + 1, inorder.end());

		postorder.resize(postorder.size() - 1);
		vector<int> postLeftVec(postorder.begin(), postorder.begin() + midLeftVec.size());
		vector<int> postRightVec(postorder.begin() + midLeftVec.size(), postorder.end());

		root->left = buildTree(midLeftVec, postLeftVec);
		root->right = buildTree(midRightVec, postRightVec);

		return root;
	}
};


// Solution 2
// 递归 基于坐标

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree (inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
	}

    TreeNode* buildTree(vector<int>& inorder, int inorderBegin, int inorderEnd,
		vector<int>& postorder, int postorderBegin, int postorderEnd) {
		//一切的返回条件都由坐标判断
        if (inorderBegin > inorderEnd || postorderBegin > postorderEnd) { return nullptr; }
		
		TreeNode* root = new TreeNode(postorder[postorderEnd]);
		// 一定要加递归终止条件
		if (inorderEnd == inorderBegin) { return root; }
		// 根节点在中序数组中的位置
		int rootIdx = 0;
		for (int i = inorderBegin; i <= inorderEnd; ++i) {
			if (inorder[i] == root->val) {
				rootIdx = i;
				break;
			}
		}
		// 划分中序数组为左右子数组
		// [inoderBegin, rootIdx-1], [rootIdx + 1, inorderEnd]
		int leftSize = rootIdx - inorderBegin;
		int rightSize = inorderEnd - rootIdx;

		//去除后序数组的最后一个节点
		--postorderEnd;
		root->left = buildTree(inorder, inorderBegin, rootIdx - 1,
			postorder, postorderBegin, postorderBegin + leftSize - 1);
		root->right = buildTree(inorder, rootIdx + 1, inorderEnd,
			postorder, postorderBegin + leftSize, postorderEnd);

		return root;
	}
};
