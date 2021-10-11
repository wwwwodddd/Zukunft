#include <bits/stdc++.h>
using namespace std;
void print(int x)
{
	if (x != 0 && x != 1)
	{
		print(-(x >> 1));
	}
	cout << (x & 1);
}
int main()
{
	int x;
	cin >> x;
	print(x);
	return 0;
}
