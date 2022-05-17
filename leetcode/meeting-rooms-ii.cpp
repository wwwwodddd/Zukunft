class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        multiset<int> s;
        int z = 0;
        for (auto i: a)
        {
            if (s.size() && i[0] >= *s.begin())
            {
                s.erase(s.begin());
            }
            else
            {
                z++;
            }
            s.insert(i[1]);
        }
        return z;
    }
};