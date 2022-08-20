#include <bits/stdc++.h>
using namespace std;
int n, x;
int main()
{
	cin >> n >> x;
	cout << char('A' + (x - 1) / n) << endl;
	return 0;
}
