class CountIntervals {
public:
    set<pair<int, int> > s;
    int z = 0;
    CountIntervals() {
        
    }
    
    void add(int l, int r) {
        r++;
        pair<int, int> u(l, r);
        auto it = s.lower_bound(u);
        while (it != s.end() && it->first <= u.second)
        {
            u.first = min(u.first, it->first);
            u.second = max(u.second, it->second);
            z -= it->second - it->first;
            s.erase(it++);
        }
        if (it != s.begin())
        {
            it--;
            if (u.first <= it->second)
            {
                u.first = min(u.first, it->first);
                u.second = max(u.second, it->second);
                z -= it->second - it->first;
                s.erase(it);
            }
        }
        z += u.second - u.first;
        s.insert(u);
    }
    
    int count() {
        return z;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */