#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = unique(s.begin(), s.end()) - s.begin();
    cout << n << endl;
    return 0;
}
