#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	cin >> a >> b;
	cout << (b - a) * (b - a + 1) / 2 - b << endl;
	return 0;
}
