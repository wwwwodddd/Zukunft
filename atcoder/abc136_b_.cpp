#include <bits/stdc++.h>
using namespace std;
int S(int x, int y, int n)
{
	return min(n, y) - min(n, x - 1);
}
int main()
{
	int n;
	cin >> n;
	cout << S(1, 9, n) + S(100, 999, n) + S(10000, 99999, n) << endl;
}
