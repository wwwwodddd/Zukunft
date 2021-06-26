#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[1000];
priority_queue<int, vector<int>, greater<int> > q;
int m, n;
int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		q.push(a[i].second);
		if (q.size() > a[i].first)
		{
			m -= q.top();
			q.pop();
		}
	}
	cout << m << endl;
	return 0;
}