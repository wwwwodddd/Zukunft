#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
	cin >> a >> b >> c;
	cout << (a * a + b * b < c * c ? "Yes" : "No") << endl;
	return 0;
}
