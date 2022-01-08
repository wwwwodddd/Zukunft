#include <bits/stdc++.h>
using namespace std;
int n, l;
string s[100];
int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n);
	for (int i = 0; i < n; i++)
	{
		cout << s[i];
	}
	cout << endl;
	return 0;
}
