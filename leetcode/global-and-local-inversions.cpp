class Solution {
public:
    bool isIdealPermutation(vector<int>& a) {
        int mx = -1;
        for (int i = 2; i < a.size(); i++)
        {
            mx = max(mx, a[i - 2]);
            if (mx > a[i])
            {
                return false;
            }
        }
        return true;
    }
};