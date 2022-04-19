#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int> > q;
int n, o, x, c;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> o;
		if (o == 1)
		{
			cin >> x >> c;
			q.push(make_pair(x, c));
		}
		else
		{
			cin >> c;
			long long z = 0;
			while (c > 0)
			{
				int t = min(c, q.front().second);
				c -= t;
				q.front().second -= t;
				z += (long long)q.front().first * t;
				if (q.front().second == 0)
				{
					q.pop();
				}
			}
			cout << z << endl;
		}
	}
}
