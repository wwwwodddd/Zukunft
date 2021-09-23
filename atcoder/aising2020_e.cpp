#include <bits/stdc++.h>
using namespace std;
int t, n, k, l, r;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		long long z = 0;
		vector<pair<int, int> > a, b;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &k, &l, &r);
			z += min(l, r);
			if (l < r)
			{
				a.push_back(make_pair(n - k, r - l));
			}
			else
			{
				b.push_back(make_pair(k, l - r));
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		priority_queue<int, vector<int>, greater<int> > p, q;
		for (pair<int, int> i: a)
		{
			p.push(i.second);
			z += i.second;
			while (p.size() > i.first)
			{
				z -= p.top();
				p.pop();
			}
		}
		for (pair<int, int> i: b)
		{
			q.push(i.second);
			z += i.second;
			while (q.size() > i.first)
			{
				z -= q.top();
				q.pop();
			}
		}
		cout << z << endl;
	}
	return 0;
}