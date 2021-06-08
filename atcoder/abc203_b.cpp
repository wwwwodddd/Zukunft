#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
	cin >> n >> k;
	cout << n * k * (100 * n + k + 101) / 2 << endl;
	return 0;
}
