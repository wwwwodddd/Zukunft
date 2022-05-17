class LRUCache {
public:
    map<int, int> f;
    map<int, int> g;
    set<pair<int, int> > s;
    int n, c;
    LRUCache(int capacity) {
        n = capacity;
        c = 0;
    }
    
    int get(int k) {
        if (g.find(k) == g.end())
        {
            return -1;
        }
        else
        {
            s.erase(make_pair(f[k], k));
            f[k] = ++c;
            s.insert(make_pair(f[k], k));
            return g[k];
        }
    }
    
    void put(int k, int v) {
        g[k] = v;
        s.erase(make_pair(f[k], k));
        f[k] = ++c;
        s.insert(make_pair(f[k], k));
        if (s.size() > n)
        {
            int t = s.begin()->second;
            s.erase(make_pair(f[t], t));
            f.erase(t);
            g.erase(t);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */