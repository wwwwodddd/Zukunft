#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[200020];
string s;
int n, z, c;
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = -s[i];
		if (a[i].second == -'1')
		{
			c++;
		}
	}
	sort(a, a + n);
	z = c;
	for (int i = 0; i < n; i++)
	{
		if (a[i].second == -'0')
		{
			c++;
		}
		else
		{
			c--;
		}
		z = max(z, c);
	}
	cout << z << endl;
	return 0;
}
