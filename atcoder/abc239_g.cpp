#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
int n, m, x, y;
ll inf = 1e18, v;
int main()
{
	cin >> n >> m;
	mf_graph<ll> g(2 * n);
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		g.add_edge(x + n, y, inf);
		g.add_edge(y + n, x, inf);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v;
		g.add_edge(i, i + n, v ? v : inf);
	}
	cout << g.flow(0, 2 * n - 1) << endl;
	auto t = g.min_cut(0);
	vector<int> z;
	for (int i = 0; i < n; i++)
	{
		if (t[i] ^ t[i + n])
		{
			z.push_back(i + 1);
		}
	}
	cout << z.size() << endl;
	for (int i : z)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}