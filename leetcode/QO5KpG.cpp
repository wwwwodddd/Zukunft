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
    vector<int> a;
    vector<int> f;
    vector<int> c;
    void dfs(TreeNode* x)
    {
        if (x == nullptr)
        {
            return;
        }
        dfs(x->left);
        a.push_back(x->val);
        dfs(x->right);
    }
    int F(int x)
    {
        return f[x] != x ? f[x] = F(f[x]) : x;
    }
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        dfs(root);
        int n = a.size();
        c.resize(n);
        f.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            f[i] = i;
        }
        for (int i = ops.size() - 1; i >= 0; i--)
        {
            int o = ops[i][0];
            int x = lower_bound(a.begin(), a.end(), ops[i][1]) - a.begin();
            int y = upper_bound(a.begin(), a.end(), ops[i][2]) - a.begin();
            for (int j = F(x); j < y; j = F(j))
            {
                c[j] = o;
                f[j] = j + 1;
            }
        }
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            z += c[i];
        }
        return z;
    }
};