#include <bits/stdc++.h>
using namespace std;
const int p = 1000000000;
string s;
long long f[320][320];
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		f[i][i] = 1;
	}
	for (int l = 2; l < s.size(); l += 2)
	{
		for (int i = 0; i + l < s.size(); i++)
		{
			int j = i + l;
			if (s[i] == s[j])
			{
				for (int k = i; k < j; k += 2)
				{
					if (s[k] == s[j])
					{
						f[i][j] = (f[i][j] + f[i][k] * f[k + 1][j - 1]) % p;
					}
				}
			}
		}
	}
	cout << f[0][s.size() - 1] << endl;
	return 0;
}
