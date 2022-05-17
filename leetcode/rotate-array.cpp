class Solution {
public:
    void rotate(vector<int>& a, int k) {
        k%=a.size();
        ::rotate(a.begin(),a.end()-k,a.end());
    }
};