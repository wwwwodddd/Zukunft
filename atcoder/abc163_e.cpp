#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[2020];
long long f[2020][2020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	// 从小到大依次放置
	for (int i = n; i > 0; i--)
	{ 
		for (int j = i; j <= n; j++)
		{
			// f[i][j] 已经放置了 a[1] .. a[j-i+1] 共 j-i+1 个数字，放置到了区间 [i, j] 共 j-i+1 个位置
			// 讨论最后一个数字，也就是 a[j-i+1] 放在了左边 i 还是右边 j
			// 放在了左边 i 的收益是 距离abs(a[l].second - i) * 数字a[l].first + 剩下的区间[i+1,j]
			// 放在了右边 j 的收益是 距离abs(a[l].second - j) * 数字a[l].first + 剩下的区间[i,j-1]
			int l = j - i + 1;
			f[i][j] = max(abs(a[l].second - i) * a[l].first + f[i + 1][j], abs(a[l].second - j) * a[l].first + f[i][j - 1]);
		}
	}
	cout << f[1][n] << endl;
	return 0;
}
