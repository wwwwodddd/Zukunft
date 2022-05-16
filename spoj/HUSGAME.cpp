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
		int c = 0;
		for (n--; n > 0 && n % 2 == 0; n /= 2)
		{
			c++;
		}
		puts(c & 1 ? "ZiYES" : "HuseyNO");
	}
	return 0;
}