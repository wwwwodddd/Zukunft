#include <bits/stdc++.h>
using namespace std;
double f;
double c[1020][1020]; // c[i][j] 一共 i 个测试点，得分恰好是 j 的概率
double a[1020]; // a[i] 得分大于等于 i 的 概率 之和 (t个测试点)
double b[1020]; // a[i] 得分大于等于 i 的 概率 * 分数 之和 (t个测试点)
int t, n;
int main()
{
	cin >> t >> n;
	c[1][1] = 1;
	for (int i = 2; i <= t; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) / 2;
		}
	}
	for (int i = t; i > 0; i--)
	{
		a[i] = a[i + 1] + c[t][i];
		b[i] = b[i + 1] + c[t][i] * i;
	}
	f = (t + 1) / 2.;
	int j = 0;
	for (int i = 2; i <= n;)
	{
		// 找到最小的j，使得j >= f[i-1]
		while (j <= f)
		{
			j++;
		}
		// 如果随机的结果 >= j，那么就要了
		// 如果随机的结果 < j，那么要f[i-1]
		// cout << "DEBUG j=" << j << " f=" << f << " " << (b[j] / a[j] - j) << " " << (b[j] / a[j] - f) << endl;
		int d = n - i + 1;
		if (j < t)
		{
			int k = int(ceil(log((b[j] / a[j] - j) / (b[j] / a[j] - f)) / log(1 - a[j])));
			d = min(d, k);
		}
		f = b[j] / a[j] - pow(1 - a[j], d) * (b[j] / a[j] - f);
		i += d;
		// f[i] = b[j] / a[j] - (1 - a[j]) ** k * (b[j] / a[j] - f[i - k]);
		// f[i] = b[j] + (1 - a[j]) * f[i - 1];
		// cout << i << " " << f << " " << j << " " << i + k << endl;
	}
	cout << fixed << setprecision(20) << f << endl;
	return 0;
}