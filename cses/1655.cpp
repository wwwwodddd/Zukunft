#include <bits/stdc++.h>
using namespace std;
int t[7000020][2], tt;
int n, m, x, y, z;
void insert(int x)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		if (t[p][x >> i & 1] == 0)
		{
			t[p][x >> i & 1] = ++tt;
		}
		p = t[p][x >> i & 1];
	}
}
int query(int x)
{
	int p = 0, re = 0;
	for (int i = 30; i >= 0; i--)
	{
		if (t[p][~x >> i & 1] > 0)
		{
			p = t[p][~x >> i & 1];
			re += 1 << i;
		}
		else
		{
			p = t[p][x >> i & 1];
		}
	}
	return re;
}
int main()
{
	cin >> n;
	int z = 0, s = 0, x = 0;
	insert(s);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		s ^= x;
		insert(s);
		z = max(z, query(s));
	}
	cout << z << endl;
	return 0;
}