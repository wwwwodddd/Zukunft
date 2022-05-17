/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int value;
    bool dfs(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (root->val != value) {
            return false;
        }
        return dfs(root->left) && dfs(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        value = root->val;
        return dfs(root);
    }
};