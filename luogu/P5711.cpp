#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	printf("%d\n", n % 400 == 0 || n % 100 != 0 && n % 4 == 0);
	return 0;
}