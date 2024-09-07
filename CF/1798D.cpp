#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		vector<int> a, b;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x > 0)
			{
				a.push_back(x);
			}
			else
			{
				b.push_back(x);
			}
		}
		if (a.size() == 0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
			int s = 0;
			while (a.size() + b.size())
			{
				if (s >= 0)
				{
					printf("%d ", b.back());
					s += b.back();
					b.pop_back();
				}
				else
				{
					printf("%d ", a.back());
					s += a.back();
					a.pop_back();
				}
			}
			printf("\n");
		}
	}
	return 0;
}