class StockPrice {
public:
    map<int, int> g;
    multiset<int> s;
    StockPrice() {
        
    }
    
    void update(int t, int p) {
        if (g.find(t) != g.end())
        {
            s.erase(s.find(g[t]));
            g.erase(t);
        }
        g[t] = p;
        s.insert(p);
    }
    
    int current() {
        return g.rbegin()->second;
    }
    
    int maximum() {
        return *s.rbegin();
    }
    
    int minimum() {
        return *s.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */