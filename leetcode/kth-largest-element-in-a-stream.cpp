class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > q;
    int k;
    KthLargest(int k, vector<int>& a) {
        this->k = k;
        for (int i: a)
        {
            q.push(i);
        }
        while (q.size() > k)
        {
            q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > k)
        {
            q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */