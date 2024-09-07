#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> s;
		cout << *max_element(s.begin(), s.end()) - 96 << endl;
	}
	return 0;
}
