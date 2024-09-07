#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[200020];
int v[200020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int s = i;
		while (v[s] == 0)
		{
			v[s] = i;
			s = a[s];
		}
		if (v[s] == i)
		{
			int t = s;
			do
			{
				t = a[t];
				z++;
			}
			while (t != s);
		}
	}
	cout << z << endl;
	return 0;
}