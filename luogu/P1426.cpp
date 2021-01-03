#include <bits/stdc++.h>
using namespace std;
double s, x, l, v = 7;
int main()
{
	cin >> s >> x;
	for (; l < s - x; v *= 0.98)
	{
		l += v;
	}
	puts(l + v > s + x ? "n" : "y");
	return 0;
}