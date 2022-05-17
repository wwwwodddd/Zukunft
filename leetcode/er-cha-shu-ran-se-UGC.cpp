struct N {
    int a[12];
};
int kk;
N dfs(TreeNode* root)
{
    N re;
    for (int i = 0; i <= kk; i++)
    {
        re.a[i] = 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        re.a[0] = 0;
        re.a[1] = root->val;
    }
    else if (root->left == NULL && root->right != NULL)
    {
        N ri = dfs(root->right);
        for (int i = 0; i < kk; i++)
        {
            re.a[i + 1] = root->val + ri.a[i];
        }
        for (int i = 0; i <= kk; i++)
        {
            re.a[0] = max(re.a[0], ri.a[i]);
        }
    }
    else if (root->left != NULL && root->right == NULL)
    {
        N le = dfs(root->left);
        for (int i = 0; i < kk; i++)
        {
            re.a[i + 1] = root->val + le.a[i];
        }
        for (int i = 0; i <= kk; i++)
        {
            re.a[0] = max(re.a[0], le.a[i]);
        }
    }
    else if (root->left != NULL && root->right != NULL)
    {
        N le = dfs(root->left);
        N ri = dfs(root->right);
        for (int i = 0; i <= kk; i++)
        {
            for (int j = 0; j <= kk; j++)
            {
                if (i + j + 1 <= kk)
                {
                    re.a[i + j + 1] = max(re.a[i + j + 1], root->val + le.a[i] + ri.a[j]);
                }
                re.a[0] = max(re.a[0], le.a[i] + ri.a[j]);
            }
        }
    }
    return re;
}
class Solution {
public:
    int maxValue(TreeNode* root, int k) {
        kk = k;
        N re = dfs(root);
        int ans = 0;
        for (int i = 0; i <= kk; i++)
        {
            ans = max(ans, re.a[i]);
        }
        return ans;
    }
};