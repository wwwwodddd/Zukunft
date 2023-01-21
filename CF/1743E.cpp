#include <bits/stdc++.h>
using namespace std;
long long p1, p2, h, s, t1, t2;
long long f[5020];
int main()
{
	cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 1;; j++)
		{
			long long k = i + (p1 - s) * j + (p2 - s) * (j * t1 / t2);
			if (j * t1 >= t2)
			{
				k += s;
			}
			k = min(k, h);
			f[k] = min(f[k], f[i] + j * t1);
			if (k == h)
			{
				break;
			}
		}
		for (int j = 1;; j++)
		{
			long long k = i + (p2 - s) * j + (p1 - s) * (j * t2 / t1);
			if (j * t2 >= t1)
			{
				k += s;
			}
			k = min(k, h);
			f[k] = min(f[k], f[i] + j * t2);
			if (k == h)
			{
				break;
			}
		}
	}
	cout << f[h] << endl;
	return 0;
}