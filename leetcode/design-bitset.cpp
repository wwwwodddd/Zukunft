class Bitset {
public:
    vector<int> a;
    int c, f;
    Bitset(int size) {
        a.clear();
        a.resize(size);
        c = 0;
        f = 0;
    }
    
    void fix(int i) {
        if (f == 0)
        {
            c -= a[i];
            a[i] = 1;
            c += a[i];
        }
        else
        {
            c -= a[i];
            a[i] = 0;
            c += a[i];
        }
    }
    
    void unfix(int i) {
        if (f == 0)
        {
            c -= a[i];
            a[i] = 0;
            c += a[i];        
        }
        else
        {
            c -= a[i];
            a[i] = 1;
            c += a[i];        
        }
    }
    
    void flip() {
        f ^= 1;
    }
    
    bool all() {
        if (f == 0)
        {
            return c == a.size();
        }
        else
        {
            return c == 0;
        }
    }
    
    bool one() {
        if (f == 0)
        {
            return c > 0;
        }
        else
        {
            return c < a.size();
        }
        
    }
    
    int count() {
        if (f == 0)
        {
            return c;
        }
        else
        {
            return a.size() - c;
        }
    }
    
    string toString() {
        string s = "";
        for (int i = 0; i < a.size(); i++)
        {
            s += char('0' + (f ^ a[i]));
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */