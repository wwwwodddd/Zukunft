#include <bits/stdc++.h>
using namespace std;
string s[200020];
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n);
	cout << (unique(s, s + n) - s) << endl;
	return 0;
}
