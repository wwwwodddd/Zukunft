#include <bits/stdc++.h>
using namespace std;
long long dp[3][3][3], DP[3][3][3];
int main()
{
	vector<long long> po3{1};
	for (int i = 1; i < 40; ++i)
		po3.push_back(3 * po3.back());
	int Q;
	cin >> Q;
	while (Q--)
	{
		long long d, x, y;
		cin >> d >> x >> y;
		memset(dp, 0, sizeof dp);
		dp[0][0][0] = 1;
		for (int i = 0; i < 39; i++)
		{
			memset(DP, 0, sizeof DP);
			int dd = d / po3[i] % 3, xd = x / po3[i] % 3, yd = y / po3[i] % 3;
			for (int cmp = 0; cmp < 2; cmp++)
			{
				for (int xc = 0; xc < 2; xc++)
				{
					for (int yc = 0; yc < 2; yc++)
					{
						for (int j = 0; j < 3; j++)
						{
							int XD = (xd + xc + j) % 3, XC = (xd + xc + j) / 3;
							int YD = (yd + yc + j) % 3, YC = (yd + yc + j) / 3;
							int CMP = j > dd || j == dd && cmp;
							if (XD % 2 == YD % 2)
								DP[CMP][XC][YC] += dp[cmp][xc][yc];
						}
					}
				}
			}
			swap(dp, DP);
		}
		cout << dp[0][0][0] << "\n";
	}
}