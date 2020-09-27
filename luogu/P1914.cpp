#include <bits/stdc++.h>
using namespace std;
int n;
char c;
int main()
{
	cin >> n;
	while (cin >> c)
	{
		putchar((c - 'a' + n) % 26 + 'a');
	}
	puts("");
	return 0;
}