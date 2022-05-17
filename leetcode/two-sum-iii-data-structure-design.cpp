class TwoSum {
public:
    multiset<int> t;
    TwoSum() {

    }
    
    void add(int x) {
        t.insert(x);
    }
    
    bool find(int v) {
        if (!t.size())
        {
            return false;
        }
        multiset<int>::iterator s = t.begin(), e = --t.end();
        while (s != e)
        {
            if (*s + *e == v)
            {
                return true;
            }
            if (*s + *e < v)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */