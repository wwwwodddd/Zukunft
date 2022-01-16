#include <bits/stdc++.h>
using namespace std;
int n, a;
int d[1000020];
queue<int> q;
int rot(int x)
{
	int y = x, t = 1;
	for (; y > 0; y /= 10)
	{
		t *= 10;
	}
	return x / 10 + x % 10 * t / 10;
}
int main()
{
	cin >> a >> n;
	memset(d, -1, sizeof d);
	d[1] = 0;
	q.push(1);
	while (q.size() > 0)
	{
		int u = q.front();
		q.pop();
		if (u <= 1000000 / a && d[u * a] == -1)
		{
			d[u * a] = d[u] + 1;
			q.push(u * a);
		}
		int v = rot(u);
		if (u % 10 && d[v] == -1)
		{
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	cout << d[n] << endl;
	return 0;
}
