class WordDistance {
public:
    map<string, vector<int> > g;
    int n;
    WordDistance(vector<string>& a) {
        n = a.size();
        for (int i = 0; i < n; i++)
        {
            g[a[i]].push_back(i);
        }
    }
    
    int shortest(string x, string y) {
        vector<int> &a = g[x];
        vector<int> &b = g[y];
        int i = 0, j = 0;
        int z = n;
        while (i < a.size() && j < b.size())
        {
            z = min(z, abs(a[i] - b[j]));
            if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return z;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */