#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	cin >> n >> s;
	cout << (s.substr(0, n / 2) == s.substr(n / 2) ? "Yes" : "No") << endl;
}
