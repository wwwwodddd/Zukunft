#include <bits/stdc++.h>
using namespace std;
int k;
int main()
{
	scanf("%d", &k);
	printf("%02d:%02d\n", 21 + k / 60, k % 60);
	return 0;
}
