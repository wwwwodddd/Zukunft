#include <bits/stdc++.h>
using namespace std;
int n, a[100020];
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0, j; i < n; i = j + 1)
	{
		z = 0;
		queue<int> q;
		for (j = i; j < i + n; j++)
		{
			for (int k = 0; k < a[j % n]; k++)
			{
				q.push(j);
			}
			if (q.empty())
			{
				break;
			}
			z += (long long)(q.front() - j) * (q.front() - j);
			q.pop();
		}
		if (j == i + n)
		{
			break;
		}
	}
	printf("%lld\n", z);
	return 0;
}