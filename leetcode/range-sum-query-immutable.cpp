class NumArray {
public:
    vector<int> s;
    NumArray(vector<int>& a) {
        s.resize(a.size() + 1);
        for (int i = 0; i < a.size(); i++)
        {
            s[i + 1] = s[i] + a[i];
        }
    }
    
    int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */