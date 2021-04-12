#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int n, m, x;
long long s;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x;
		q.push(x);
	}
	for (int i = 0; i < m; i++)
	{
		s -= q.top() - q.top() / 2;
		q.push(q.top() / 2);
		q.pop();
	}
	cout << s << endl;
	return 0;
}