#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	cout << max(a + abs(b), a * b) << endl;
	return 0;
}