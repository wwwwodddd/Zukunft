#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	cin >> n;
	int L = 0, R = 1e9;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		(stoll(to_string(M) + to_string(M)) > n ? R : L) = M;
	}
	cout << L << endl;
	return 0;
}
