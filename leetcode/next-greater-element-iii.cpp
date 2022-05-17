class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (next_permutation(s.begin(), s.end()))
        {
            long fuck = stol(s);
            if (fuck > 2147483647)
            {
                return -1;
            }
            else
            {
                return fuck;
            }
        }
        else
        {
            return -1;
        }
    }
};