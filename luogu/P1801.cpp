#include <bits/stdc++.h>
using namespace std;
int n, m, x, a[200020];
priority_queue<int, vector<int>, greater<int> > q1;
priority_queue<int, vector<int>, less<int> > q2;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0, j = 0; i < m; i++)
	{
		cin >> x;
		for (; j < x; j++)
		{
			q2.push(a[j]);
			if (q2.size() > i)
			{
				q1.push(q2.top());
				q2.pop();
			}
		}
		cout << q1.top() << endl;
		q2.push(q1.top());
		q1.pop();
	}
	return 0;
}