class TimeMap {
public:
    map<string, map<int, string> > g;

    void set(string k, string v, int t) {
        g[k][t] = v;
    }
    
    string get(string k, int t) {
        auto it = g[k].upper_bound(t);
        return it == g[k].begin() ? "" : (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */