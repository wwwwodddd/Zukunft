#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(i + 2 < s.size() && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
        {
            cout << " ";
            i += 2;
        }
        else
        {
            cout << x[i];
        }
    }
    cout << endl;
    return 0;
}
