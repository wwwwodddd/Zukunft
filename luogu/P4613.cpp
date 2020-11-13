#include <bits/stdc++.h>
using namespace std;
int n;
int a[120];
int b[120];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] > b[i])
		{
			puts("NE");
			return 0;
		}
	}
	puts("DA");
	return 0;
}