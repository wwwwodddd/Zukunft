class MaxStack {
public:
    set<pair<int, int> > a, b;
    int c;
    MaxStack() {
        c = 0;
    }
    
    void push(int x) {
        c++;
        a.insert(make_pair(x, c));
        b.insert(make_pair(c, x));
    }
    
    int pop() {
        auto u = *b.rbegin();
        b.erase(--b.end());
        a.erase(make_pair(u.second, u.first));
        return u.second;
    }
    
    int top() {
        return b.rbegin()->second;
    }
    
    int peekMax() {
        return a.rbegin()->first;
    }
    
    int popMax() {
        auto u = *a.rbegin();
        a.erase(--a.end());
        b.erase(make_pair(u.second, u.first));
        return u.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */