#include <bits/stdc++.h>
using namespace std;
int n, x;
long long l, z;
priority_queue<long long, vector<long long>, greater<long long> > q;
int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		q.push(x);
		l -= x;
	}
	if (l > 0)
	{
		q.push(l);
	}
	while (q.size() > 1)
	{
		long long x = q.top();
		q.pop();
		long long y = q.top();
		q.pop();
		z += x + y;
		q.push(x + y);
	}
	cout << z << endl;
	return 0;
}
