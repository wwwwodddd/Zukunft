#include <bits/stdc++.h>
using namespace std;
long long z, a[256][7];
int n, x;
char c;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c >> x;
		a[c][(x % 7 + 7) % 7]++;
	}
	for(int B = 0; B < 7; B++)
	{
		for(int E = 0; E < 7; E++)
		{
			for(int S = 0; S < 7; S++)
			{
				for(int I = 0; I < 7; I++)
				{
					for(int G = 0; G < 7; G++)
					{
						for(int O = 0; O < 7; O++)
						{
							for(int M = 0; M < 7; M++)
							{
								if (((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O)) % 7 == 0)
								{
									z += a['B'][B] * a['E'][E] * a['S'][S] * a['I'][I] * a['G'][G] * a['O'][O] * a['M'][M];
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n",z);
	return 0;
}