#include <bits/stdc++.h>
using namespace std;
int k;
string a, b;
long long A, B;
int main()
{
	cin >> k >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		A = A * k + a[i] - '0';
	}
	for (int i = 0; i < b.size(); i++)
	{
		B = B * k + b[i] - '0';
	}
	cout << A * B << endl;
	return 0;
}
