class RangeFreqQuery {
public:
    vector<pair<int, int> > b;
    RangeFreqQuery(vector<int>& a) {
        for (int i = 0; i < a.size(); i++)
        {
            b.push_back(make_pair(a[i], i));
        }
        sort(b.begin(), b.end());
    }
    
    int query(int l, int r, int v) {
        return upper_bound(b.begin(), b.end(), make_pair(v, r)) - lower_bound(b.begin(), b.end(), make_pair(v, l));
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */