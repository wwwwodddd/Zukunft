#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<long long> q;
long long z, x;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		x -= i;
		q.push(x);
		q.push(x);
		z += q.top() - x;
		q.pop();
	}
	printf("%lld\n", z);
	return 0;
}