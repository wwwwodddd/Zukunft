#include <bits/stdc++.h>
using namespace std;
int n, m, a[5000000];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	nth_element(a, a + m, a + n);
	printf("%d\n", a[m]);
	return 0;
}