#include <bits/stdc++.h>
using namespace std;
int n, q, a, b, c;
long long s;
int d[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		d[a]++;
		s += a;
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> b >> c;
		s += (long long)d[b] * (c - b);
		d[c] += d[b];
		d[b] = 0;
		cout << s << endl;
	}
	return 0;
}
