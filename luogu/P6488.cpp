#include <bits/stdc++.h>
using namespace std;
long long l, p, a;
int main()
{
	scanf("%lld%lld", &l, &p);
	for (int i = 0; i < 5; i++)
	{
		scanf("%lld", &a);
		printf("%lld%c", a - l * p, i < 4 ? ' ' : '\n');
	}
	return 0;
}