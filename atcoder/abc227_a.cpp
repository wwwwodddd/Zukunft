#include <bits/stdc++.h>
using namespace std;
int n, k, a;
int main()
{
	cin >> n >> k >> a;
	cout << (a + k - 2) % n + 1 << endl; 
	return 0;
}
