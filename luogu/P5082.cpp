#include <bits/stdc++.h>
using namespace std;
int n, s, t, x;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		s += x;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		t += x;
	}
	printf("%.6f\n", double(s) / (s - t) + 2);
	return 0;
}