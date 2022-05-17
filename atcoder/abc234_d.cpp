#include <bits/stdc++.h>
using namespace std;
int n, x, k;
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		q.push(x);
		if (q.size() > k)
		{
			q.pop();
		}
		if (q.size() == k)
		{
			cout << q.top() << endl;
		}
	}
	return 0;
}
