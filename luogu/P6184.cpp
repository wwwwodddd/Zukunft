#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	cin >> n;
	cout << (n-1)*(n-2)*(n-3)/6 - (n/2)*(n/2-1)*(n/2-2)/6*4 << endl;
	return 0;
}