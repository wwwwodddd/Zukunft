#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	sort(&a, &a + 3);
	puts(b * 2 == a + c ? "Yes" : "No");
	return 0;
}
