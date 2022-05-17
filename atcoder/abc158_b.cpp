#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
int main()
{
	cin >> n >> a >> b;
	cout << n / (a + b) * a + min(n % (a + b), a) << endl;
	return 0;
}
