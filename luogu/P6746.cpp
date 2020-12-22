#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a + b == 0)
	{
		printf("0\n");
	}
	else if (a * b == 0)
	{
		printf("%d\n", d);
	}
	else
	{
		printf("%d\n", min(a == b ? c : c + d, d * 2));
	}
	return 0;
}