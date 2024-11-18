#include <bits/stdc++.h>
using namespace std;
int n, k;
int t[300020];
long long s[300020];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
	}
	priority_queue<long long, vector<long long>, greater<long long>> q;
	for (int i = 0; i < k; i++)
	{
		q.push(t[i]);
		s[i] = 0;
	}
	for (int i = k; i < n; i++)
	{
		s[i] = q.top();
		q.pop();
		q.push(s[i] + t[i]);
	}
	printf("%lld\n", q.top());
	set<long long> st;
	st.insert(q.top());
	for (int i = n - 1; i >= k; i--)
	{
		if (st.find(s[i] + t[i]) != st.end())
		{
			st.insert(s[i]);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d", st.find(t[i]) != st.end());
	}
	printf("\n");
	return 0;
}