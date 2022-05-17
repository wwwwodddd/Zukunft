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
    bool dfs(TreeNode* &root) {
        if (root == NULL) {
            return false;
        }
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        if (!left && !right && root->val == 0) {
            root = NULL;
            return false;
        } else {
            return true;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};