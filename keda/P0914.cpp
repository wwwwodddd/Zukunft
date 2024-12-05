#include <bits/stdc++.h>
using namespace std;
int l, n, o, x, y;
int s1[100020]; // 空穴 的个数，初始为0
int s2[100020]; // 树苗 的个数，初始为0
int b[100020];
// 0 区间内什么都不做
// 1 区间内砍完
// 2 区间内种树
// 3 区间内先砍再种
void kan(int x, int l, int r)
{
	b[x] = 1;
	s1[x] = r - l + 1;
	s2[x] = 0;
}
void zhong(int x, int l, int r)
{
	b[x] |= 2;
	s2[x] += s1[x];
	s1[x] = 0;
}
void push(int x, int l, int r)
{
	int mid = (l + r) / 2;
	if (b[x] & 1)
	{
		kan(x * 2, l, mid);
		kan(x * 2 + 1, mid + 1, r);
		b[x] ^= 1;
	}
	if (b[x] & 2)
	{
		zhong(x * 2, l, mid);
		zhong(x * 2 + 1, mid + 1, r);
		b[x] ^= 2;
	}
}
int change(int x, int l, int r, int L, int R, int v)
{
	if (r < L || R < l)
	{
		return 0;
	}
	if (L <= l && r <= R)
	{
		if (v == 1) // 全都变成空穴，返回砍掉的树苗个数
		{
			int re = s2[x];
			kan(x, l, r);
			return re;
		}
		else // v == 2 空穴种树，返回种的树苗个数
		{
			int re = s1[x];
			zhong(x, l, r);
			return re;
		}
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	int re = change(x * 2, l, mid, L, R, v) + change(x * 2 + 1, mid + 1, r, L, R, v);
	s1[x] = s1[x * 2] + s1[x * 2 + 1];
	s2[x] = s2[x * 2] + s2[x * 2 + 1];
	return re;
}
int main()
{
	cin >> l >> n;
	int ans0 = 0; // 树苗 变 空穴 的次数
	int ans1 = 0; // 空穴 变 树苗 的次数
	for (int i = 0; i < n; i++)
	{
		cin >> o >> x >> y;
		if (o == 0)
		{
			ans0 += change(1, 0, l, x, y, 1); // 全都变成空穴
		}
		else
		{
			ans1 += change(1, 0, l, x, y, 2); // 空穴都变成树苗，如果已经有树/树苗，那么不动
		}
	}
	cout << ans1 - ans0 << endl
		 << ans0 << endl;
	return 0;
}