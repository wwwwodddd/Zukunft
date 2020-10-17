#include <bits/stdc++.h>
using namespace std;
int n;
uint64_t k;
int main()
{
	cin >> n >> k;
	k ^= k >> 1;
	for (int i = n - 1; i >= 0; i--)
	{
		cout << (k >> i & 1);
	}
	cout << endl;
	return 0;
}