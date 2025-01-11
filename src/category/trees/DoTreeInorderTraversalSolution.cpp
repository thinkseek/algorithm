/**
 * 94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100

进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 */
#include <iostream>
#include <vector>
using namespace std;

// 二叉树节点的定义
struct TreeNode {
    // 数据结构
    int val;
    TreeNode *left;
    TreeNode *right;

    // 构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class DoTreeInorderTraversalSolution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> nums = {};
        if(root == nullptr) {
            return nums;
        }

        // 递归实现方案
        inorderTraversalHelper(root, nums);
        return nums;
    }

private:
    // 中序遍历，递归实现
    void inorderTraversalHelper(TreeNode *node, vector<int>& result) {
        if(node == nullptr) {
            return;
        }

        inorderTraversalHelper(node->left, result); // 遍历左子树
        result.push_back(node->val); // 访问根节点
        inorderTraversalHelper(node->right, result); // 遍历右子树
    }
};


/** ************************** **/
// 测试用例 g++ -std=c++11 DoTreeInorderTraversalSolution.cpp -o DoTreeInorderTraversalSolution
int main()
{
    // 构建一个的二叉树
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 中序遍历实现遍历  4 2 5 1 3
    // 中序遍历（Inorder Traversal）将按照以下顺序访问节点：左子树 -> 根节点 -> 右子树
    DoTreeInorderTraversalSolution solution;
    vector<int> vt = solution.inorderTraversal(root);
    for (int i = 0; i < vt.size(); ++i) {
        cout << vt[i] << " ";
    }
    cout << endl;
    return 0;
}