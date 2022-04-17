#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld", &n);
		while (n % 2 == 0)
		{
			n /= 2;
		}
		cout << (n > 4) << endl;
	}
	return 0;
}
