#include <bits/stdc++.h>
using namespace std;
int s = 45, x;
int main()
{
	for (int i = 0; i < 9; i++)
	{
		scanf("%1d", &x);
		s -= x;
	}
	printf("%d\n", s);
	return 0;
}
