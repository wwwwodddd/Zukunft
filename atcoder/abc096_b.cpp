#include <bits/stdc++.h>
using namespace std;
int a, b, c, k;
int main()
{
	cin >> a >> b >> c >> k;
	cout << a + b + c + max(a, max(b, c)) * ((1 << k) - 1) << endl;
}
