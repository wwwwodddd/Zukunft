#include <bits/stdc++.h>
using namespace std;
int n, q, x, p, l, h;
int z[200020];
int v[200020];
long long k;
long long w[400020];
int main()
{
	cin >> n >> q >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		w[i + n] = w[i];
	}
	for (int i = 1; i <= 2 * n; i++)
	{
		w[i] += w[i - 1];
	}
	for (int i = 1;; i++)
	{
		if (v[p])
		{
			h = v[p];
			l = i - v[p];
			break;
		}
		v[p] = i;
		int d = lower_bound(w, w + 2 * n, w[p] + x % w[n]) - w;
		z[i] = x / w[n] * n + d - p;
		p = d % n;
	}
	for (int i = 0; i < q; i++)
	{
		cin >> k;
		if (k > h)
		{
			k = (k - h) % l + h;
		}
		cout << z[k] << endl;
	}
	return 0;
}
