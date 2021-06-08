#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
	cin >> a >> b >> c;
	cout << a + b + c - max(a, max(b, c)) << endl;
	return 0;
}
