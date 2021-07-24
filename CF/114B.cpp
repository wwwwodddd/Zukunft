#include <bits/stdc++.h>
using namespace std;
map<string, int> p;
string str[16];
int g[16][16]={};
int countbit(int n) {
    int k=0;
    while(n>0) {k+=n%2; n/=2;}
    return k;
}
int main(void) {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> str[i];
        p[str[i]] = i;
    }
    for(int i=0;i<m;i++) {
        string x, y;
        cin >> x >> y;
        g[p[x]][p[y]] = g[p[y]][p[x]] = 1;
    }
    int ans=0;
    for(int state=0;state<(1<<n);state++) {
        if(countbit(ans) >= countbit(state)) continue;
        int flag=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if((state&(1<<i)) && (state&(1<<j)) && g[i][j])
                    flag=1;
        if(!flag) ans = state;
    }
    vector<string> w;
    for(int i=0;i<n;i++)
        if((ans&(1<<i)))
            w.push_back(str[i]);
    sort(w.begin(), w.end());
    cout << w.size() << endl;
    for(int i=0;i<(int)w.size();i++)
        cout << w[i] << endl;
    return 0;
}
