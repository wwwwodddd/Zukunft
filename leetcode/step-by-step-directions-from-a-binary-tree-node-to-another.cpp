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
    int s, t;
    vector<char> sp, tp, p;
    void dfs(TreeNode *x)
    {
        if (x == nullptr)
        {
            return;
        }
        if (x->val == s)
        {
            sp = p;
        }
        if (x->val == t)
        {
            tp = p;
        }
        p.push_back('L');
        dfs(x->left);
        p.pop_back();
        p.push_back('R');
        dfs(x->right);
        p.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        s = startValue;
        t = destValue;
        dfs(root);
        int i = 0;
        while (i < sp.size() && i < tp.size() && sp[i] == tp[i])
        {
            i++;
        }
        string z;
        for (int j = i; j < sp.size(); j++)
        {
            z += 'U';
        }
        for (int j = i; j < tp.size(); j++)
        {
            z += tp[j];
        }
        return z;
    }
};