/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int myDepth = 1;
        int rightDepth = 0;
        if (root->right) {
            rightDepth = maxDepth(root->right);
        }
        int leftDepth = 0;
        if (root->left) {
            leftDepth = maxDepth(root->left);
        }
        if (rightDepth > leftDepth) {
            return myDepth + rightDepth;
        } else {
            return myDepth + leftDepth;
        }
    }
};
