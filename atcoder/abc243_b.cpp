#include <bits/stdc++.h>
using namespace std;
int a[100020];
int n, b, x, y;
set<int> s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		if (a[i] == b)
		{
			x++;
		}
		else if (s.find(b) != s.end())
		{
			y++;
		}
	}
	cout << x << endl << y << endl;
	return 0;
}
