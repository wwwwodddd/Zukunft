#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> s;
vector<int> a;
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
	scanf("%d", &n);
	s.resize(n * (n + 1) / 2);
	for (int i = 0; i < n * (n + 1) / 2; i++)
	{
		scanf("%d", &s[i]);
	}
	sort(s.begin(), s.end());
	for (int i = 0, k = 0; i < n; i++)
	{
		while (q.size() && q.top() == s[k])
		{
			q.pop();
			k++;
		}
		a.push_back(s[k]);
		int t = 0;
		for (int j = a.size() - 1; j >= 0; j--)
		{
			t += a[j];
			q.push(t);
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}