#include <bits/stdc++.h>
using namespace std;
long long S, P;
int main()
{
	cin >> S >> P;
	for (long long i = 1; i * i <= P; i++)
	{
		if (P % i == 0 && i + P / i == S)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
