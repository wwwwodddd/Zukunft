#include <bits/stdc++.h>
using namespace std;
int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			ans += max(v[i], v[j]) * abs(x[i] - x[j]);
		}
	}
	return 0;
}
