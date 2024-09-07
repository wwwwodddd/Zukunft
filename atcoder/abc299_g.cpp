#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];
vector<int> b;
int c[200020];
int v[200020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		c[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (!v[a[i]])
		{
			while (b.size() > 0 && a[i] < b.back() && c[b.back()] > 0)
			{
				v[b.back()] = 0;
				b.pop_back();
			}
			v[a[i]] = 1;
			b.push_back(a[i]);
		}
		c[a[i]]--;
	}
	for (int i : b)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}