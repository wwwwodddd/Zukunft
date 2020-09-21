#include <bits/stdc++.h>
using namespace std;
int x;
int main()
{
	scanf("%d", &x);
	printf("Today, I ate %d apple%s.\n", x, x > 1 ? "s" : "");
	return 0;
}