#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		cout << "#" << s << "#" << endl;
	}
	for (int i = 0; i < m + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	return 0;
}
