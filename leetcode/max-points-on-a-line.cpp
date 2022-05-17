class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int z = 0;
        for (unsigned i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> g;
            for (unsigned j = 0; j < points.size(); j++) {
                if (j != i) {
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];
                    int t = __gcd(abs(dx), abs(dy));
                    dx /= t;
                    dy /= t;
                    z = max(z, ++g[make_pair(dx, dy)]);
                }
            }
        }
        return z + 1;
    }
};