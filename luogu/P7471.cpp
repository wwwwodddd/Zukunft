#include <bits/stdc++.h>
using namespace std;
int t, a[3];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		if (a[0] == 0)
		{
			if (a[1] == 0)
			{
				printf("0\n");
			}
			else if (a[1] == a[2])
			{
				printf("1\n");
			}
			else
			{
				printf("2\n");
			}
		}
		else if (a[0] == a[1] || a[1] == a[2] || a[0] + a[1] == a[2])
		{
			printf("2\n");
		}
		else
		{
			printf("3\n");
		}
	}
	return 0;
}