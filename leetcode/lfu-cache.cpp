class LFUCache {
public:
    int c, t = 0;
    map<int, pair<int, int> > g;
    map<int, int> f;
    set<pair<pair<int, int>, int> > s;
    LFUCache(int capacity) {
        c = capacity;
    }
    
    int get(int k) {
        t++;
        if (f.find(k) != f.end())
        {
            s.erase(make_pair(g[k], k));
            g[k].first++;
            g[k].second = t;
            s.insert(make_pair(g[k], k));
            return f[k];
        }
        else
        {
            return -1;
        }
    }
    
    void put(int k, int v) {
        if (c)
        {
            t++;
            if (f.find(k) == f.end() && f.size() == c)
            {
                f.erase(s.begin()->second);
                s.erase(s.begin());
            }
            s.erase(make_pair(g[k], k));
            if (f.find(k) == f.end())
            {
                g[k].first = 1;
            }
            else
            {
                g[k].first++;
            }
            g[k].second = t;
            f[k] = v;
            s.insert(make_pair(g[k], k));
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */