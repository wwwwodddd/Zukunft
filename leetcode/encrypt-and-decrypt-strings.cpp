class Encrypter {
public:
    vector<string> t;
    map<string, int> g;
    Encrypter(vector<char>& k, vector<string>& v, vector<string>& d) {
        t.resize(26);
        for (int i = 0; i < k.size(); i++)
        {
            t[k[i] - 'a'] = v[i];
        }
        for (string s: d)
        {
            g[encrypt(s)] += 1;
        }
    }
    
    string encrypt(string w) {
        string z;
        for (char c: w)
        {
            z += t[c - 'a'];
        }
        return z;
    }
    
    int decrypt(string w) {
        if (g.find(w) != g.end())
        {
            return g[w];
        }
        else
        {
            return 0;
        }
    }
};


/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */