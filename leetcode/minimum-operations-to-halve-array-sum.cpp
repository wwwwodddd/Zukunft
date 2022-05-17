class Solution {
public:
    int halveArray(vector<int>& a) {
        double s = 0, t = 0;
        priority_queue<double> q;
        for (int i: a)
        {
            s += i;
            q.push(i);
        }
        int z = 0;
        while (t < s / 2)
        {
            double u = q.top();
            q.pop();
            t += u / 2;
            q.push(u / 2);
            z++;
        }
        return z;
    }
};