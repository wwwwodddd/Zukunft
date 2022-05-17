class Solution {
    vector<string> res;
public:
    void dfs(int x, int s, string a) {
        if (s > x) {
            return;
        }
        if (x == 0) {
            res.push_back(a);
            return;
        }
        if (s > 0) {
            dfs(x - 1, s - 1, a + ")");
        }
        dfs(x - 1, s + 1, a + "(");
    } 

    vector<string> generateParenthesis(int n) {
        dfs(2 * n, 0, "");   
        return res;
    }
};