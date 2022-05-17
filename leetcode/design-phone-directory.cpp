class PhoneDirectory {
public:
    vector<int> v;
    vector<int> a;
    PhoneDirectory(int n) {
        v.resize(n);
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = i;
        }
    }
    
    int get() {
        if (a.size() == 0)
        {
            return -1;
        }
        int x = a.back();
        a.pop_back();
        v[x] = 1;
        return x;
    }
    
    bool check(int x) {
        return !v[x];
    }
    
    void release(int x) {
        if (v[x])
        {
            v[x] = 0;
            a.push_back(x);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */