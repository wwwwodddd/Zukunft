#include <bits/stdc++.h>
using namespace std;
long long n;
string s[5] = {"Asad", "Foyj", "Juwel", "Mijan", "Tanmay"};
int main()
{
	while (cin >> n)
	{
		n--;
		for (long long i = 1;; i *= 2)
		{
			if (n < i * 5)
			{
				cout << s[n / i] << endl;
				break;
			}
			n -= i * 5;
		}
	}
	return 0;
}