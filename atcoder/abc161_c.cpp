#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main()
{
	cin >> n >> k;
	cout << min(n % k, k - n % k) << endl;
	return 0;
}
