#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<pair<int, int> > e[200020];
int c[200020];
int d[200020];
int r[200020];
int s[200020];
int a[200020];
int f[200020];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> c[i] >> r[i] >> d[i] >> s[i];
		e[c[i]].push_back(make_pair(r[i], i));
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sort(e[i].begin(), e[i].end());
	}
	queue<pair<int, int> > q;
	memset(f, 0x3f, sizeof f);
	a[1] = 0;
	q.push(make_pair(1, 0));
	while (q.size())
	{
		pair<int, int> u = q.front();
		q.pop();
		f[u.first] = min(f[u.first], u.second);
		while (e[u.first].size() > 0 && u.second + a[u.first] <= e[u.first].back().first)
		{
			q.push(make_pair(d[e[u.first].back().second], s[e[u.first].back().second]));
			e[u.first].pop_back();
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[i] > 1e9)
		{
			f[i] = -1;
		}
		cout << f[i] << endl;
	}
	return 0;
}