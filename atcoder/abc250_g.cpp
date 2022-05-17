#include <bits/stdc++.h>
using namespace std;
int n, x;
long long z = 0;
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		z += x;
		q.push(x);
		q.push(x);
		z -= q.top();
		q.pop();
	}
	printf("%lld\n", z);
	return 0;
}