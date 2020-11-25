#include <bits/stdc++.h>
using namespace std;
string s;
int z[3] = {1, 0, 0};
int main()
{
	cin >> s;
	for (char c: s)
	{
		swap(z[(c + 1) % 3], z[(c + 2) % 3]);
	}
	printf("%d\n", z[0] + 2 * z[1] + 3 * z[2]);
	return 0;
}