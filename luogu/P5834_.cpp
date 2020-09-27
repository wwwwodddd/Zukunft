#include <bits/stdc++.h>
using namespace std;
int n, a[8] = {-1, 1, 2, 4, 7, 8, 11, 13};
int main()
{
	cin >> n;
	cout << n / 8 * 15 + a[n % 8] << endl;
	return 0;
}