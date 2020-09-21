#include <bits/stdc++.h>
using namespace std;
int x;
int main()
{
	scanf("%d", &x);
	bool a = x % 2 == 0;
	bool b = 4 < x && x <= 12;
	printf("%d %d %d %d\n", a & b, a | b, a ^ b, !a & !b);
	return 0;
}