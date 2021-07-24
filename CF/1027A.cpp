#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    for (int iTest = 1; iTest <= T; ++iTest) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i;
        for (i = 0; i < (n - 1 - i); ++i) {
            int d = abs(s[i] - s[n - 1 - i]);
            if (d != 0 && d != 2) {
                break;
            }
        }
        cout << (i < (n - 1 - i) ? "NO\n" : "YES\n");
    }
    return 0;
}
